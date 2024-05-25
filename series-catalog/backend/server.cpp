#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <vector>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

struct Serie {
    int id;
    std::string nome;
    int anoLancamento;
    int temporada;
    int numeroEpisodios;
    std::string atoresPrincipais;
    std::string personagensPrincipais;
    std::string canalStreaming;
    float notaClassificacao;
};

std::vector<Serie> series;
int currentId = 1;

void handle_get(http_request request) {
    json::value response = json::value::array();
    int i = 0;
    for (const auto& serie : series) {
        response[i++] = json::value::object({
            {U("id"), json::value::number(serie.id)},
            {U("nome"), json::value::string(serie.nome)},
            {U("anoLancamento"), json::value::number(serie.anoLancamento)},
            {U("temporada"), json::value::number(serie.temporada)},
            {U("numeroEpisodios"), json::value::number(serie.numeroEpisodios)},
            {U("atoresPrincipais"), json::value::string(serie.atoresPrincipais)},
            {U("personagensPrincipais"), json::value::string(serie.personagensPrincipais)},
            {U("canalStreaming"), json::value::string(serie.canalStreaming)},
            {U("notaClassificacao"), json::value::number(serie.notaClassificacao)}
        });
    }
    request.reply(status_codes::OK, response);
}

void handle_post(http_request request) {
    request.extract_json().then([&request](pplx::task<json::value> task) {
        try {
            auto const &jvalue = task.get();
            Serie newSerie;
            newSerie.id = currentId++;
            newSerie.nome = jvalue.at(U("nome")).as_string();
            newSerie.anoLancamento = jvalue.at(U("anoLancamento")).as_integer();
            newSerie.temporada = jvalue.at(U("temporada")).as_integer();
            newSerie.numeroEpisodios = jvalue.at(U("numeroEpisodios")).as_integer();
            newSerie.atoresPrincipais = jvalue.at(U("atoresPrincipais")).as_string();
            newSerie.personagensPrincipais = jvalue.at(U("personagensPrincipais")).as_string();
            newSerie.canalStreaming = jvalue.at(U("canalStreaming")).as_string();
            newSerie.notaClassificacao = jvalue.at(U("notaClassificacao")).as_double();
            series.push_back(newSerie);
            request.reply(status_codes::Created, json::value::number(newSerie.id));
        } catch (http_exception const &e) {
            request.reply(status_codes::BadRequest, U("Invalid JSON"));
        }
    }).wait();
}

void handle_put(http_request request) {
    auto id = std::stoi(request.relative_uri().path().substr(1));
    request.extract_json().then([&request, id](pplx::task<json::value> task) {
        try {
            auto const &jvalue = task.get();
            for (auto &serie : series) {
                if (serie.id == id) {
                    serie.nome = jvalue.at(U("nome")).as_string();
                    serie.anoLancamento = jvalue.at(U("anoLancamento")).as_integer();
                    serie.temporada = jvalue.at(U("temporada")).as_integer();
                    serie.numeroEpisodios = jvalue.at(U("numeroEpisodios")).as_integer();
                    serie.atoresPrincipais = jvalue.at(U("atoresPrincipais")).as_string();
                    serie.personagensPrincipais = jvalue.at(U("personagensPrincipais")).as_string();
                    serie.canalStreaming = jvalue.at(U("canalStreaming")).as_string();
                    serie.notaClassificacao = jvalue.at(U("notaClassificacao")).as_double();
                    request.reply(status_codes::OK, json::value::number(id));
                    return;
                }
            }
            request.reply(status_codes::NotFound, U("Serie not found"));
        } catch (http_exception const &e) {
            request.reply(status_codes::BadRequest, U("Invalid JSON"));
        }
    }).wait();
}

void handle_delete(http_request request) {
    auto id = std::stoi(request.relative_uri().path().substr(1));
    auto it = std::remove_if(series.begin(), series.end(), [id](const Serie &serie) {
        return serie.id == id;
    });
    if (it != series.end()) {
        series.erase(it, series.end());
        request.reply(status_codes::OK, json::value::number(id));
    } else {
        request.reply(status_codes::NotFound, U("Serie not found"));
    }
}

int main() {
    http_listener listener(U("http://localhost:5000/api/series"));
     listener.support(methods::GET, handle_get);
    listener.support(methods::POST, handle_post);
    listener.support(methods::PUT, handle_put);
    listener.support(methods::DEL, handle_delete);

    try {
        listener
            .open()
            .then([&listener]() { std::cout << "Starting server..." << std::endl; })
            .wait();
        
        std::string line;
        std::getline(std::cin, line);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
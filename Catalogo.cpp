#include "Catalogo.h"
#include <iostream>
#include <algorithm>
using namespace std;

Catalogo::Catalogo(DAO* dao) : dao(dao) {}

void Catalogo::incluirSerie(const SerieDTO& serie) {
    dao->salvar(serie);
}

SerieDTO Catalogo::recuperarSerie(int id) {
    return dao->buscar(id);
}

void Catalogo::editarSerie(const SerieDTO& serie) {
    dao->atualizar(serie);
}

void Catalogo::excluirSerie(int id) {
    dao->remover(id);
}

void Catalogo::listarSeries() const {
    auto series = dao->listarSeries();
    for (const auto& serie : series) {
        serie.display();
        cout << "----------------------" << endl;
    }
}

void Catalogo::listarSeriesOrdenadasPorTitulo() const {
    auto series = dao->listarSeries();
    sort(series.begin(), series.end(), [](SerieDTO a, SerieDTO b) {
        return a.getNome() < b.getNome();
    });
    for (const auto& serie : series) {
        serie.display();
    }
}

void Catalogo::listarSeriesOrdenadasPorCanal() const {
    auto series = dao->listarSeries();
    sort(series.begin(), series.end(), [](SerieDTO a, SerieDTO b) {
        return a.getCanal() < b.getCanal();
    });
    for (const auto& serie : series) {
        serie.display();
    }
}

void Catalogo::listarSeriesOrdenadasPorAno() const {
    auto series = dao->listarSeries();
    sort(series.begin(), series.end(), [](SerieDTO a, SerieDTO b) {
        return a.getAno() < b.getAno();
    });
    for (const auto& serie : series) {
        serie.display();
    }
}

void Catalogo::listarSeriesOrdenadasPorNota() const {
    auto series = dao->listarSeries();
    sort(series.begin(), series.end(), [](SerieDTO a, SerieDTO b) {
        return a.getNota() < b.getNota();
    });
    for (const auto& serie : series) {
        serie.display();
    }
}

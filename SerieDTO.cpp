#include "SerieDTO.h"
#include <iostream>
using namespace std;

SerieDTO::SerieDTO(int id, string nome, int ano, int temporadas, int numEpisodios,
                   string atores, string personagens, string canal, int nota)
    : id(id), nome(nome), ano(ano), temporadas(temporadas), numEpisodios(numEpisodios),
      atores(atores), personagens(personagens), canal(canal), nota(nota) {}

int SerieDTO::getId() const { return id; }
string SerieDTO::getNome() const { return nome; }
int SerieDTO::getAno() const { return ano; }
int SerieDTO::getTemporadas() const { return temporadas; }
int SerieDTO::getNumEpisodios() const { return numEpisodios; }
string SerieDTO::getAtores() const { return atores; }
string SerieDTO::getPersonagens() const { return personagens; }
string SerieDTO::getCanal() const { return canal; }
int SerieDTO::getNota() const { return nota; }

void SerieDTO::setId(int id) { this->id = id; }
void SerieDTO::setNome(const string& nome) { this->nome = nome; }
void SerieDTO::setAno(int ano) { this->ano = ano; }
void SerieDTO::setTemporadas(int temporadas) { this->temporadas = temporadas; }
void SerieDTO::setNumEpisodios(int numEpisodios) { this->numEpisodios = numEpisodios; }
void SerieDTO::setAtores(const string& atores) { this->atores = atores; }
void SerieDTO::setPersonagens(const string& personagens) { this->personagens = personagens; }
void SerieDTO::setCanal(const string& canal) { this->canal = canal; }
void SerieDTO::setNota(int nota) { this->nota = nota; }

void SerieDTO::display() const {
    cout << "ID: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Ano de Lançamento: " << ano << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Número de Episódios: " << numEpisodios << endl;
    cout << "Principais Atores/Atrizes: " << atores << endl;
    cout << "Personagens Principais: " << personagens << endl;
    cout << "Canal/Streaming: " << canal << endl;
    cout << "Nota de Classificação: " << nota << endl;
}

#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie(int id, string nome, int ano, int temporadas, int numEpisodios,
             string atores, string personagens, string canal, int nota)
    : id(id), nome(nome), ano(ano), temporadas(temporadas), numEpisodios(numEpisodios),
      atores(atores), personagens(personagens), canal(canal), nota(nota) {}

int Serie::getId() const { return id; }
string Serie::getNome() const { return nome; }
int Serie::getAno() const { return ano; }
int Serie::getTemporadas() const { return temporadas; }
int Serie::getNumEpisodios() const { return numEpisodios; }
string Serie::getAtores() const { return atores; }
string Serie::getPersonagens() const { return personagens; }
string Serie::getCanal() const { return canal; }
int Serie::getNota() const { return nota; }

void Serie::setId(int id) { this->id = id; }
void Serie::setNome(const string& nome) { this->nome = nome; }
void Serie::setAno(int ano) { this->ano = ano; }
void Serie::setTemporadas(int temporadas) { this->temporadas = temporadas; }
void Serie::setNumEpisodios(int numEpisodios) { this->numEpisodios = numEpisodios; }
void Serie::setAtores(const string& atores) { this->atores = atores; }
void Serie::setPersonagens(const string& personagens) { this->personagens = personagens; }
void Serie::setCanal(const string& canal) { this->canal = canal; }
void Serie::setNota(int nota) { this->nota = nota; }

void Serie::display() const {
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

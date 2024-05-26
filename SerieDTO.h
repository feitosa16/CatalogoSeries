#ifndef SERIEDTO_H
#define SERIEDTO_H

#include <string>
using namespace std;

class SerieDTO {
private:
    int id;
    string nome;
    int ano;
    int temporadas;
    int numEpisodios;
    string atores;
    string personagens;
    string canal;
    int nota;

public:
    SerieDTO(int id, string nome, int ano, int temporadas, int numEpisodios,
             string atores, string personagens, string canal, int nota);

    int getId() const;
    string getNome() const;
    int getAno() const;
    int getTemporadas() const;
    int getNumEpisodios() const;
    string getAtores() const;
    string getPersonagens() const;
    string getCanal() const;
    int getNota() const;

    void setId(int id);
    void setNome(const string& nome);
    void setAno(int ano);
    void setTemporadas(int temporadas);
    void setNumEpisodios(int numEpisodios);
    void setAtores(const string& atores);
    void setPersonagens(const string& personagens);
    void setCanal(const string& canal);
    void setNota(int nota);

    void display() const;
};

#endif // SERIEDTO_H

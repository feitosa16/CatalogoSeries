#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "Serie.h"
using namespace std;

class Catalogo {
private:
    vector<Serie> series; //Vetor para armazenar as séries

public:
//Adiciona uma nova serie no catalogo
    void addSerie(const Serie& serie);
//Recupera a serie pelo ID e retorna um ponteiro apra serie se encontrada 
    Serie* getSerie(int id);
//Edita a serie existente pelo ID, e substitui os novos dados retorna true se encontrada e editada else false
    bool editSerie(int id, const Serie& novaSerie);
//Remove uma serie pelo ID, retorna true se encontrada e removida else false
    bool removeSerie(int id);
//Exibe todas as series do catalogo
    void displaySeries() const;


};

#endif // CATALOGO_H

#include "Catalogo.h"
#include <iostream>
using namespace std;

//Adiciona uma nova série ao catalogo
void Catalogo::addSerie(const Serie& serie) {
    series.push_back(serie);
}
//Recupera uma serie pelo Id e retorna um ponteiro apra serie se encontrada
Serie* Catalogo::getSerie(int id){
    for (auto& serie : series){
        if(serie.getId() == id){
            return &serie;
        }   
        return nullptr;
    }
}

// Edita uma série existente pelo ID, substituindo pelos novos dados da série, retorna true se a série foi encontrada e editada, caso contrário retorna false
bool Catalogo::editSerie(int id, const Serie& novaSerie) {
    for (auto& serie : series) {
        if (serie.getId() == id) {
            serie = novaSerie;
            return true;
        }
    }
    return false;
}

// Remove uma série pelo ID, retorna true se a série foi encontrada e removida, caso contrário retorna false
bool Catalogo::removeSerie(int id) {
    for (auto it = series.begin(); it != series.end(); ++it) {
        if (it->getId() == id) {
            series.erase(it);
            return true;
        }
    }
    return false;
}
//Exibe todas as series no catálogo 
void Catalogo::displaySeries() const {
    for (const auto& serie : series) {
        serie.display();
        cout << "----------------------" << endl;
    }
}

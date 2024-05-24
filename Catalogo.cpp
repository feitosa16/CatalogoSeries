#include "Catalogo.h"
#include <iostream>
using namespace std;

void Catalogo::addSerie(const Serie& serie) {
    series.push_back(serie);
}

void Catalogo::displaySeries() const {
    for (const auto& serie : series) {
        serie.display();
        cout << "----------------------" << endl;
    }
}

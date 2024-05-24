#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "Serie.h"
using namespace std;

class Catalogo {
private:
    vector<Serie> series;

public:
    void addSerie(const Serie& serie);
    void displaySeries() const;
};

#endif // CATALOGO_H

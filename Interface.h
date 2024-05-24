#ifndef INTERFACE_H
#define INTERFACE_H

#include "Catalogo.h"
using namespace std;

class Interface {
private:
    Catalogo catalogo;
    int nextId = 1;

    void exibirMenuPrincipal();
    void exibirSubmenuSeries();
    void incluirSerie();

public:
    void iniciar();
};

#endif // INTERFACE_H

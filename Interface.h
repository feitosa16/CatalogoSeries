#ifndef INTERFACE_H
#define INTERFACE_H

#include "Catalogo.h"
using namespace std;

class Interface {
private:
    Catalogo catalogo; //objeto para gerenciar as series 
    int nextId = 1; //id para a proxima serie adicionada

    void exibirMenuPrincipal();
    void exibirSubmenuSeries();
    void incluirSerie();
    void recuperarSerie();
    void editarSerie();
    void excluirSerie();

public:
    void iniciar();
};

#endif // INTERFACE_H

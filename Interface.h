#ifndef INTERFACE_H
#define INTERFACE_H

#include "Catalogo.h"
using namespace std;

class Interface {
private:
    Catalogo* catalogo; // Objeto para gerenciar as séries 
    int nextId = 1; // ID para a próxima série adicionada

    void exibirMenuPrincipal();
    void exibirSubmenuSeries();
    void incluirSerie();
    void recuperarSerie();
    void editarSerie();
    void excluirSerie();
    void exibirRelatorios();
    void mostrarAjuda();
    void mostrarCreditos();

public:
    Interface(Catalogo* catalogo);
    void iniciar();
};

#endif // INTERFACE_H

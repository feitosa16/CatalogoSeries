#include <iostream>
#include "Interface.h"
#include "MariaDBDAO.h"
#include "MemoriaDAO.h"

int main() {
    MemoriaDAO dao;
    Catalogo catalogo(&dao);
    Interface interface(&catalogo);
    interface.iniciar();

    MariaDBDAO dao;
    Interface interface(dao);
    interface.run();

    return 0;
}
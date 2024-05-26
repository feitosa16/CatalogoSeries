#include "Interface.h"
#include "MemoriaDAO.h"

int main() {
    MemoriaDAO dao;
    Catalogo catalogo(&dao);
    Interface interface(&catalogo);
    interface.iniciar();
    return 0;
}

#ifndef DAO_H
#define DAO_H

#include "SerieDTO.h"
#include <vector>

class DAO {
public:
    virtual void salvar(const SerieDTO& serie) = 0;
    virtual SerieDTO buscar(int id) = 0;
    virtual void atualizar(const SerieDTO& serie) = 0;
    virtual void remover(int id) = 0;
    virtual std::vector<SerieDTO> listarSeries() = 0;
    virtual ~DAO() {}
};

#endif // DAO_H

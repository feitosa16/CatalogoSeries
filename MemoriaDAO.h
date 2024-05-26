#ifndef MEMORIADAO_H
#define MEMORIADAO_H

#include "DAO.h"
#include <vector>

class MemoriaDAO : public DAO {
private:
    std::vector<SerieDTO> series;

public:
    void salvar(const SerieDTO& serie) override;
    SerieDTO buscar(int id) override;
    void atualizar(const SerieDTO& serie) override;
    void remover(int id) override;
    std::vector<SerieDTO> listarSeries() override;
};

#endif // MEMORIADAO_H

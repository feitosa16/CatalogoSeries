#include "MemoriaDAO.h"
#include <stdexcept>  // Adicione esta linha

void MemoriaDAO::salvar(const SerieDTO& serie) {
    series.push_back(serie);
}

SerieDTO MemoriaDAO::buscar(int id) {
    for (const auto& serie : series) {
        if (serie.getId() == id) {
            return serie;
        }
    }
    throw std::runtime_error("Série não encontrada");
}

void MemoriaDAO::atualizar(const SerieDTO& serie) {
    for (auto& s : series) {
        if (s.getId() == serie.getId()) {
            s = serie;
            return;
        }
    }
    throw std::runtime_error("Série não encontrada");
}

void MemoriaDAO::remover(int id) {
    for (auto it = series.begin(); it != series.end(); ++it) {
        if (it->getId() == id) {
            series.erase(it);
            return;
        }
    }
    throw std::runtime_error("Série não encontrada");
}

std::vector<SerieDTO> MemoriaDAO::listarSeries() {
    return series;
}

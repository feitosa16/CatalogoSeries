#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include "SerieDTO.h"
#include "DAO.h"

class Catalogo {
private:
    DAO* dao;

public:
    Catalogo(DAO* dao);
    void incluirSerie(const SerieDTO& serie);
    SerieDTO recuperarSerie(int id);
    void editarSerie(const SerieDTO& serie);
    void excluirSerie(int id);
    void listarSeries() const;

    // Funções de Relatórios
    void listarSeriesOrdenadasPorTitulo() const;
    void listarSeriesOrdenadasPorCanal() const;
    void listarSeriesOrdenadasPorAno() const;
    void listarSeriesOrdenadasPorNota() const;
};

#endif // CATALOGO_H

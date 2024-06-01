#ifndef MARIADB_DAO_H
#define MARIADB_DAO_H

#include "DAO.h"
#include <mariadb/conncpp.hpp>

class MariaDBDAO : public DAO {
public:
    MariaDBDAO();
    ~MariaDBDAO();
    
    void incluirSerie(const SerieDTO& serie) override;
    SerieDTO recuperarSerie(int id) override;
    void editarSerie(const SerieDTO& serie) override;
    void excluirSerie(int id) override;

private:
    sql::Driver* driver;
    std::unique_ptr<sql::Connection> conn;
};

#endif

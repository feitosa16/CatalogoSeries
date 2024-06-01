#include "MariaDBDAO.h"
#include "db_config.h"

MariaDBDAO::MariaDBDAO() {
    driver = sql::mariadb::get_driver_instance();
    conn.reset(driver->connect(DB_HOST, DB_USER, DB_PASS));
    conn->setSchema(DB_NAME);
}

MariaDBDAO::~MariaDBDAO() {
    conn->close();
}

void MariaDBDAO::incluirSerie(const SerieDTO& serie) {
    std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("INSERT INTO SERIES (series_name, release_year, season, episode_count, main_actors, main_characters, network, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?)"));
    pstmt->setString(1, serie.nome);
    pstmt->setInt(2, serie.ano);
    pstmt->setInt(3, serie.temporada);
    pstmt->setInt(4, serie.numeroEpisodios);
    pstmt->setString(5, serie.atores);
    pstmt->setString(6, serie.personagens);
    pstmt->setString(7, serie.canal);
    pstmt->setInt(8, serie.nota);
    pstmt->executeUpdate();
}

SerieDTO MariaDBDAO::recuperarSerie(int id) {
    std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("SELECT * FROM SERIES WHERE internal_id = ?"));
    pstmt->setInt(1, id);
    std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
    
    SerieDTO serie;
    if (res->next()) {
        serie.id = res->getInt("internal_id");
        serie.nome = res->getString("series_name");
        serie.ano = res->getInt("release_year");
        serie.temporada = res->getInt("season");
        serie.numeroEpisodios = res->getInt("episode_count");
        serie.atores = res->getString("main_actors");
        serie.personagens = res->getString("main_characters");
        serie.canal = res->getString("network");
        serie.nota = res->getInt("rating");
    }
    return serie;
}

void MariaDBDAO::editarSerie(const SerieDTO& serie) {
    std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("UPDATE SERIES SET series_name = ?, release_year = ?, season = ?, episode_count = ?, main_actors = ?, main_characters = ?, network = ?, rating = ? WHERE internal_id = ?"));
    pstmt->setString(1, serie.nome);
    pstmt->setInt(2, serie.ano);
    pstmt->setInt(3, serie.temporada);
    pstmt->setInt(4, serie.numeroEpisodios);
    pstmt->setString(5, serie.atores);
    pstmt->setString(6, serie.personagens);
    pstmt->setString(7, serie.canal);
    pstmt->setInt(8, serie.nota);
    pstmt->setInt(9, serie.id);
    pstmt->executeUpdate();
}

void MariaDBDAO::excluirSerie(int id) {
    std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("DELETE FROM SERIES WHERE internal_id = ?"));
    pstmt->setInt(1, id);
    pstmt->executeUpdate();
}

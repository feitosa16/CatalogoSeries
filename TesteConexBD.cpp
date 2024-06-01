#include <iostream>
#include <mariadb/conncpp.hpp>

int main() {
    try {
        sql::Driver* driver = sql::mariadb::get_driver_instance();
        std::unique_ptr<sql::Connection> conn(driver->connect("tcp://143.106.243.64:3306", "seu_usuario", "sua_senha"));
        conn->setSchema("Si300A2024_xx");

        std::cout << "Conectado ao banco de dados MariaDB com sucesso!" << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "Erro ao conectar ao banco de dados: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

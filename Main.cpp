#include <iostream>
#include <stdexcept>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include "Interface.h"
#include "MemoriaDAO.h"

// Prototipos das funções
void showTasks(std::unique_ptr<sql::Connection>& conn);
void addTask(std::unique_ptr<sql::Connection>& conn, const char* task);
void updateTaskStatus(std::unique_ptr<sql::Connection>& conn, int taskId, const char* status);
void deleteTask(std::unique_ptr<sql::Connection>& conn, int taskId);

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Please provide an argument.\n";
        return 1;
    }

    try {
        // Instantiate Driver
        sql::Driver* driver = sql::mariadb::get_driver_instance();

        // Configure Connection
        sql::SQLString url("jdbc:mariadb://localhost:3306/todo");
        sql::Properties properties({{"user", "Si300A2024_04"}, {"password", "ZoDdip5s0Z"}});

        // Establish Connection
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));

        // Use arguments to determine execution next steps
        if (!strcmp(argv[1], "showTasks")) {
            showTasks(conn);
        }
        else if (!strcmp(argv[1], "addTask")) {
            if (argc != 3) {
                std::cout << "Invalid arguments.\n";
                return 1;
            }
            addTask(conn, argv[2]);
        }
        else if (!strcmp(argv[1], "updateTaskStatus")) {
            if (argc != 4) {
                std::cout << "Invalid arguments.\n";
                return 1;
            }
            updateTaskStatus(conn, atoi(argv[2]), argv[3]);
        }
        else if (!strcmp(argv[1], "deleteTask")) {
            if (argc != 3) {
                std::cout << "Invalid arguments.\n";
                return 1;
            }
            deleteTask(conn, atoi(argv[2]));
        }

        // Close Connection
        conn->close();
    }
    catch(sql::SQLException& e) {
        std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
        // Exit (Failed)
        return 1;
    }

    // Continue with normal application logic
    MemoriaDAO dao;
    Catalogo catalogo(&dao);
    Interface interface(&catalogo);
    interface.iniciar();
    return 0;
}

// Funções dummy para mostrar exemplo
void showTasks(std::unique_ptr<sql::Connection>& conn) {
    std::cout << "Showing tasks...\n";
    // Lógica para mostrar tarefas
}

void addTask(std::unique_ptr<sql::Connection>& conn, const char* task) {
    std::cout << "Adding task: " << task << "\n";
    // Lógica para adicionar tarefas
}

void updateTaskStatus(std::unique_ptr<sql::Connection>& conn, int taskId, const char* status) {
    std::cout << "Updating task " << taskId << " to status: " << status << "\n";
    // Lógica para atualizar status de tarefas
}

void deleteTask(std::unique_ptr<sql::Connection>& conn, int taskId) {
    std::cout << "Deleting task " << taskId << "\n";
    // Lógica para deletar tarefas
}

#include "Interface.h"
#include <iostream>

Interface::Interface(Catalogo* catalogo, DAO& dao) : catalogo(catalogo), dao(dao) {}

void Interface::iniciar() {
    int option;
    do {
        exibirMenuPrincipal();
        std::cin >> option;
        switch (option) {
            case 1:
                exibirSubmenuSeries();
                break;
            case 2:
                exibirRelatorios();
                break;
            case 3:
                mostrarAjuda();
                break;
            case 4:
                mostrarCreditos();
                break;
            case 5:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    } while (option != 5);
}

void Interface::exibirMenuPrincipal() {
    std::cout << "1. Gerenciar Séries" << std::endl;
    std::cout << "2. Exibir Relatórios" << std::endl;
    std::cout << "3. Ajuda" << std::endl;
    std::cout << "4. Créditos" << std::endl;
    std::cout << "5. Sair" << std::endl;
    std::cout << "Selecione uma opção: ";
}

void Interface::exibirSubmenuSeries() {
    int option;
    do {
        std::cout << "1. Incluir um novo registro" << std::endl;
        std::cout << "2. Recuperar um registro" << std::endl;
        std::cout << "3. Editar um registro" << std::endl;
        std::cout << "4. Excluir um registro" << std::endl;
        std::cout << "5. Voltar ao menu principal" << std::endl;
        std::cout << "Selecione uma opção: ";
        std::cin >> option;
        switch (option) {
            case 1:
                incluirSerie();
                break;
            case 2:
                recuperarSerie();
                break;
            case 3:
                editarSerie();
                break;
            case 4:
                excluirSerie();
                break;
            case 5:
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }
    } while (option != 5);
}

void Interface::incluirSerie() {
    SerieDTO serie;
    serie.id = nextId++;
    std::cout << "Nome da série: ";
    std::cin.ignore();
    std::getline(std::cin, serie.nome);
    std::cout << "Ano de lançamento: ";
    std::cin >> serie.ano;
    std::cout << "Temporada: ";
    std::cin >> serie.temporada;
    std::cout << "Número de episódios: ";
    std::cin >> serie.numeroEpisodios;
    std::cout << "Principais atores/atrizes: ";
    std::cin.ignore();
    std::getline(std::cin, serie.atores);
    std::cout << "Principais personagens: ";
    std::getline(std::cin, serie.personagens);
    std::cout << "Canal/Streaming: ";
    std::getline(std::cin, serie.canal);
    std::cout << "Nota de classificação (0-10): ";
    std::cin >> serie.nota;

    catalogo->adicionarSerie(serie);
    dao.incluirSerie(serie);

    std::cout << "Série incluída com sucesso!" << std::endl;
}

void Interface::recuperarSerie() {
    int id;
    std::cout << "ID da série a recuperar: ";
    std::cin >> id;

    SerieDTO serie = dao.recuperarSerie(id);
    if (serie.id != 0) {
        std::cout << "ID: " << serie.id << std::endl;
        std::cout << "Nome: " << serie.nome << std::endl;
        std::cout << "Ano: " << serie.ano << std::endl;
        std::cout << "Temporada: " << serie.temporada << std::endl;
        std::cout << "Número de episódios: " << serie.numeroEpisodios << std::endl;
        std::cout << "Atores: " << serie.atores << std::endl;
        std::cout << "Personagens: " << serie.personagens << std::endl;
        std::cout << "Canal: " << serie.canal << std::endl;
        std::cout << "Nota: " << serie.nota << std::endl;
    } else {
        std::cout << "Série não encontrada!" << std::endl;
    }
}

void Interface::editarSerie() {
    int id;
    std::cout << "ID da série a editar: ";
    std::cin >> id;

    SerieDTO serie = dao.recuperarSerie(id);
    if (serie.id != 0) {
        std::cout << "Nome da série [" << serie.nome << "]: ";
        std::cin.ignore();
        std::getline(std::cin, serie.nome);
        std::cout << "Ano de lançamento [" << serie.ano << "]: ";
        std::cin >> serie.ano;
        std::cout << "Temporada [" << serie.temporada << "]: ";
        std::cin >> serie.temporada;
        std::cout << "Número de episódios [" << serie.numeroEpisodios << "]: ";
        std::cin >> serie.numeroEpisodios;
        std::cout << "Principais atores/atrizes [" << serie.atores << "]: ";
        std::cin.ignore();
        std::getline(std::cin, serie.atores);
        std::cout << "Principais personagens [" << serie.personagens << "]: ";
        std::getline(std::cin, serie.personagens);
        std::cout << "Canal/Streaming [" << serie.canal << "]: ";
        std::getline(std::cin, serie.canal);
        std::cout << "Nota de classificação (0-10) [" << serie.nota << "]: ";
        std::cin >> serie.nota;

        catalogo->editarSerie(serie);
        dao.editarSerie(serie);

        std::cout << "Série editada com sucesso!" << std::endl;
    } else {
        std::cout << "Série não encontrada!" << std::endl;
    }
}

void Interface::excluirSerie() {
    int id;
    std::cout << "ID da série a excluir: ";
    std::cin >> id;

    dao.excluirSerie(id);
    catalogo->removerSerie(id);

    std::cout << "Série excluída com sucesso!" << std::endl;
}

void Interface::exibirRelatorios() {
    // Implementação da lógica para exibir relatórios
}

void Interface::mostrarAjuda() {
    std::cout << "Ajuda: Este é um sistema de gerenciamento de catálogo de séries." << std::endl;
}

void Interface::mostrarCreditos() {
    std::cout << "Créditos: Desenvolvido por Gabriel e equipe." << std::endl;
}

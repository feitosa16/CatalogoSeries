#include "Interface.h"
#include <iostream>
using namespace std;

Interface::Interface(Catalogo* catalogo) : catalogo(catalogo) {}

void Interface::exibirMenuPrincipal() {
    cout << "Menu Principal" << endl;
    cout << "1. Séries" << endl;
    cout << "2. Relatórios" << endl;
    cout << "3. Ajuda" << endl;
    cout << "4. Créditos" << endl;
    cout << "5. Sair" << endl;
    cout << "Escolha uma opção: ";
}

void Interface::exibirSubmenuSeries() {
    cout << "Submenu Séries" << endl;
    cout << "1. Incluir um novo registro" << endl;
    cout << "2. Recuperar um registro" << endl;
    cout << "3. Editar um registro" << endl;
    cout << "4. Excluir um registro" << endl;
    cout << "5. Exibir todas as séries" << endl;
    cout << "6. Voltar ao menu principal" << endl;
    cout << "Escolha uma opção: ";
}

void Interface::exibirRelatorios() {
    cout << "Relatórios" << endl;
    cout << "1. Ordenar por Título" << endl;
    cout << "2. Ordenar por Canal/Streaming" << endl;
    cout << "3. Ordenar por Ano" << endl;
    cout << "4. Ordenar por Nota" << endl;
    cout << "5. Voltar ao menu principal" << endl;
    cout << "Escolha uma opção: ";
}

void Interface::incluirSerie() {
    string nome, atores, personagens, canal;
    int ano, temporadas, numEpisodios, nota;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o ano de lançamento: ";
    cin >> ano;
    cout << "Digite o número de temporadas: ";
    cin >> temporadas;
    cout << "Digite o número de episódios: ";
    cin >> numEpisodios;
    cin.ignore();
    cout << "Digite os principais atores/atrizes: ";
    getline(cin, atores);
    cout << "Digite os personagens principais: ";
    getline(cin, personagens);
    cout << "Digite o canal/streaming: ";
    getline(cin, canal);
    cout << "Digite a nota de classificação (0-10): ";
    cin >> nota;

    SerieDTO novaSerie(nextId++, nome, ano, temporadas, numEpisodios, atores, personagens, canal, nota);
    catalogo->incluirSerie(novaSerie);

    cout << "Série adicionada com sucesso!" << endl;
}

void Interface::recuperarSerie() {
    int id;
    cout << "Digite o ID da série a ser recuperada: ";
    cin >> id;

    try {
        SerieDTO serie = catalogo->recuperarSerie(id);
        serie.display();
    } catch (const std::exception& e) {
        cout << "Série não encontrada." << endl;
    }
}

void Interface::editarSerie() {
    int id, ano, temporadas, numEpisodios, nota;
    string nome, atores, personagens, canal;

    cout << "Digite o ID da série a ser editada: ";
    cin >> id;

    try {
        SerieDTO serie = catalogo->recuperarSerie(id);
        cout << "Digite o novo nome: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Digite o novo ano de lançamento: ";
        cin >> ano;
        cout << "Digite o novo número de temporadas: ";
        cin >> temporadas;
        cout << "Digite o novo número de episódios: ";
        cin >> numEpisodios;
        cin.ignore();
        cout << "Digite os novos principais atores/atrizes: ";
        getline(cin, atores);
        cout << "Digite os novos personagens principais: ";
        getline(cin, personagens);
        cout << "Digite o novo canal/streaming: ";
        getline(cin, canal);
        cout << "Digite a nova nota de classificação (0-10): ";
        cin >> nota;

        SerieDTO novaSerie(id, nome, ano, temporadas, numEpisodios, atores, personagens, canal, nota);
        catalogo->editarSerie(novaSerie);

        cout << "Série editada com sucesso!" << endl;
    } catch (const std::exception& e) {
        cout << "Série não encontrada." << endl;
    }
}

void Interface::excluirSerie() {
    int id;
    cout << "Digite o ID da série a ser excluída: ";
    cin >> id;

    try {
        catalogo->excluirSerie(id);
        cout << "Série excluída com sucesso!" << endl;
    } catch (const std::exception& e) {
        cout << "Série não encontrada." << endl;
    }
}

void Interface::iniciar() {
    int opcao = 0;
    while (opcao != 5) {
        exibirMenuPrincipal();
        cin >> opcao;

        switch (opcao) {
        case 1:
            int subopcao;
            do {
                exibirSubmenuSeries();
                cin >> subopcao;

                switch (subopcao) {
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
                    catalogo->listarSeries();
                    break;
                case 6:
                    break;
                default:
                    cout << "Opção inválida!" << endl;
                }
            } while (subopcao != 6);
            break;
        case 2:
            int relatorioOpcao;
            do {
                exibirRelatorios();
                cin >> relatorioOpcao;

                switch (relatorioOpcao) {
                case 1:
                    catalogo->listarSeriesOrdenadasPorTitulo();
                    break;
                case 2:
                    catalogo->listarSeriesOrdenadasPorCanal();
                    break;
                case 3:
                    catalogo->listarSeriesOrdenadasPorAno();
                    break;
                case 4:
                    catalogo->listarSeriesOrdenadasPorNota();
                    break;
                case 5:
                    break;
                default:
                    cout << "Opção inválida!" << endl;
                }
            } while (relatorioOpcao != 5);
            break;
        case 3:
            mostrarAjuda();
            break;
        case 4:
            mostrarCreditos();
            break;
        case 5:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
        }
    }
}

void Interface::mostrarAjuda() {
    cout << "Ajuda: Este programa permite gerenciar um catálogo de séries." << endl;
    cout << "Comandos disponíveis:" << endl;
    cout << "1. Adicionar série" << endl;
    cout << "2. Listar séries" << endl;
    cout << "3. Buscar série" << endl;
    cout << "4. Relatórios" << endl;
    cout << "5. Ajuda" << endl;
    cout << "6. Créditos" << endl;
    cout << "7. Sair" << endl;
}

void Interface::mostrarCreditos() {
    cout << "Desenvolvido por: Camila Lordelo, Gabriela Januario, Geovanne Pereira, Heloisa Feitosa e Thalita Auad" << endl;
    cout << "FT - Unicamp, 2024." << endl;
}

#include "Interface.h"
#include <iostream>
using namespace std;

void Interface::exibirMenuPrincipal() {
    cout << "Menu Principal" << endl;
    cout << "1. Séries" << endl;
    cout << "2. Sair" << endl;
    cout << "Escolha uma opção: ";
}

void Interface::exibirSubmenuSeries() {
    cout << "Submenu Séries" << endl;
    cout << "1. Incluir um novo registro" << endl;
    cout << "2. Exibir todas as séries" << endl;
    cout << "3. Voltar ao menu principal" << endl;
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

    Serie novaSerie(nextId++, nome, ano, temporadas, numEpisodios, atores, personagens, canal, nota);
    catalogo.addSerie(novaSerie);

    cout << "Série adicionada com sucesso!" << endl;
}

void Interface::iniciar() {
    int opcao = 0;
    while (opcao != 2) {
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
                    catalogo.displaySeries();
                    break;
                case 3:
                    break;
                default:
                    cout << "Opção inválida!" << endl;
                }
            } while (subopcao != 3);
            break;
        case 2:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
        }
    }
}

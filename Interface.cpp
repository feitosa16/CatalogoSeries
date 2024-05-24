#include "Interface.h"
#include <iostream>
using namespace std;


//Exibe menu principal
void Interface::exibirMenuPrincipal() {
    cout << "Menu Principal" << endl;
    cout << "1. Séries" << endl;
    cout << "2. Sair" << endl;
    cout << "Escolha uma opção: ";
}
//Exibe o submenu da serie 
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

//Inclui uma nova serie no catalogo
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

// Recupera uma série pelo ID
void Interface::recuperarSerie() {
    int id;
    cout << "Digite o ID da série a ser recuperada: ";
    cin >> id;

    Serie* serie = catalogo.getSerie(id);
    if (serie) {
        serie->display();
    } else {
        cout << "Série não encontrada." << endl;
    }
}
// Edita uma série pelo ID
void Interface::editarSerie() {
    int id, ano, temporadas, numEpisodios, nota;
    string nome, atores, personagens, canal;

    cout << "Digite o ID da série a ser editada: ";
    cin >> id;

    Serie* serie = catalogo.getSerie(id);
    if (serie) {
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

        Serie novaSerie(id, nome, ano, temporadas, numEpisodios, atores, personagens, canal, nota);
        if (catalogo.editSerie(id, novaSerie)) {
            cout << "Série editada com sucesso!" << endl;
        } else {
            cout << "Erro ao editar a série." << endl;
        }
    } else {
        cout << "Série não encontrada." << endl;
    }
}

// Exclui uma série pelo ID
void Interface::excluirSerie() {
    int id;
    cout << "Digite o ID da série a ser excluída: ";
    cin >> id;

    if (catalogo.removeSerie(id)) {
        cout << "Série excluída com sucesso!" << endl;
    } else {
        cout << "Série não encontrada." << endl;
    }
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
                    recuperarSerie();
                    break;
                case 3:
                    editarSerie();
                    break;
                case 4:
                    excluirSerie();
                    break;
                case 5:
                    catalogo.displaySeries();
                    break;
                case 6:
                    break;
                default:
                    cout << "Opção inválida!" << endl;
                }
            } while (subopcao != 6);
            break;
        case 2:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
        }
    }
}

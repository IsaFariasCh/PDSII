#include "Jogo_Truco.hpp"
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <iostream>

Jogo_Truco::Jogo_Truco() {
    std::cout << "Construtor de Jogo_Truco chamado" << std::endl;

    baralho = {"4♣", "5♣", "6♣", "Q♣", "J♣", "K♣", "A♣", "2♣", "3♣", "7♣",
               "4♦", "5♦", "6♦", "Q♦", "J♦", "K♦", "A♦", "2♦", "3♦", "7♦",
               "4♥", "5♥", "6♥", "Q♥", "J♥", "K♥", "A♥", "2♥", "3♥", "7♥",
               "4♠", "5♠", "6♠", "Q♠", "J♠", "K♠", "A♠", "2♠", "3♠", "7♠"};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ordem de grandeza das cartas no Truco
    ordem_grandeza = {
        {"4♣", 1}, {"7♥", 2}, {"A♠", 3}, {"7♦", 4},
        {"3♣", 5}, {"3♦", 5}, {"3♥", 5}, {"3♠", 5},
        {"2♣", 6}, {"2♦", 6}, {"2♥", 6}, {"2♠", 6},
        {"A♣", 7}, {"A♦", 7}, {"A♥", 7},
        {"K♣", 8}, {"K♦", 8}, {"K♥", 8}, {"K♠", 8},
        {"J♣", 9}, {"J♦", 9}, {"J♥", 9}, {"J♠", 9},
        {"Q♣", 10}, {"Q♦", 10}, {"Q♥", 10}, {"Q♠", 10},
        {"7♣", 11}, {"6♣", 12}, {"6♦", 12}, {"6♥", 12}, {"6♠", 12},
        {"5♣", 13}, {"5♦", 13}, {"5♥", 13}, {"5♠", 13},
        {"4♦", 14}, {"4♥", 14}, {"4♠", 14}
    };
}

void Jogo_Truco::explica_jogo() {
    std::cout << "Método explica_jogo chamado" << std::endl;
    std::cout << "Truco: Uma versão brasileira do jogo de cartas, jogada em duplas. As regras principais são...\n"
              << "1. Cada jogador recebe três cartas.\n"
              << "2. O objetivo é ganhar mais rodadas do que o adversário.\n"
              << "3. As cartas têm valores específicos: Zap (4♣) > Sete de Copas (7♥) > Espadilha (A♠) > Sete de Ouros (7♦) > 3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4.\n"
              << "4. Você pode aumentar a aposta dizendo 'Truco!'.\n";
}

void Jogo_Truco::Start() {
    std::cout << "Método Start chamado" << std::endl;
    explica_jogo(); // Chama a explicação do jogo
    std::cout << "Iniciando o jogo de Truco...\n";
    std::cout << "Pressione qualquer tecla para continuar...\n";
    std::cin.ignore(); // Ignorar o '\n' deixado pelo último cin
    std::cin.get();    // Esperar o usuário pressionar uma tecla
    IJogo::clear_screen_jogo(true); // Limpa a tela sem pausa

    distribuir_cartas();
    mostrar_cartas();
    jogar_rodada();
}

void Jogo_Truco::distribuir_cartas() {
    std::cout << "Distribuindo cartas...\n";
    cartas_jogador1.clear();
    cartas_jogador2.clear();

    std::vector<std::string> baralho_temp = baralho;

    for (int i = 0; i < 3; ++i) {
        int index = std::rand() % baralho_temp.size();
        cartas_jogador1.push_back(baralho_temp[index]);
        baralho_temp.erase(baralho_temp.begin() + index);

        index = std::rand() % baralho_temp.size();
        cartas_jogador2.push_back(baralho_temp[index]);
        baralho_temp.erase(baralho_temp.begin() + index);
    }
    std::cout << "Cartas distribuídas\n";
}

void Jogo_Truco::mostrar_cartas() {
    std::cout << "Cartas do Jogador 1: ";
    for (const auto& carta : cartas_jogador1) {
        std::cout << carta << " ";
    }
    std::cout << "\nCartas do Jogador 2: ";
    for (const auto& carta : cartas_jogador2) {
        std::cout << carta << " ";
    }
    std::cout << std::endl;
}

int Jogo_Truco::escolher_carta(int jogador) {
    int escolha;
    if (jogador == 1) {
        std::cout << "Jogador 1, escolha uma carta para jogar (1, 2, ou 3): ";
        std::cin >> escolha;
        while (escolha < 1 || escolha > 3 || cartas_jogador1[escolha - 1] == "") {
            std::cout << "Escolha inválida. Tente novamente: ";
            std::cin >> escolha;
        }
    } else {
        std::cout << "Jogador 2, escolha uma carta para jogar (1, 2, ou 3): ";
        std::cin >> escolha;
        while (escolha < 1 || escolha > 3 || cartas_jogador2[escolha - 1] == "") {
            std::cout << "Escolha inválida. Tente novamente: ";
            std::cin >> escolha;
        }
    }
    return escolha - 1;
}

void Jogo_Truco::jogar_rodada() {
    std::cout << "Jogando uma rodada de Truco...\n";
    int pontos_jogador1 = 0;
    int pontos_jogador2 = 0;

    for (int i = 0; i < 3; ++i) {
        std::cout << "Rodada " << i + 1 << ": " << std::endl;
        int escolha1 = escolher_carta(1);
        int escolha2 = escolher_carta(2);

        std::cout << "Jogador 1 joga: " << cartas_jogador1[escolha1] << std::endl;
        std::cout << "Jogador 2 joga: " << cartas_jogador2[escolha2] << std::endl;

        if (ordem_grandeza[cartas_jogador1[escolha1]] < ordem_grandeza[cartas_jogador2[escolha2]]) {
            std::cout << "Jogador 1 ganha a rodada!" << std::endl;
            pontos_jogador1++;
        } else {
            std::cout << "Jogador 2 ganha a rodada!" << std::endl;
            pontos_jogador2++;
        }

        // Remover a carta jogada
        cartas_jogador1[escolha1] = "";
        cartas_jogador2[escolha2] = "";
    }

    if (pontos_jogador1 > pontos_jogador2) {
        std::cout << "Jogador 1 vence o jogo!" << std::endl;
    } else {
        std::cout << "Jogador 2 vence o jogo!" << std::endl;
    }
    std::cout << "Fim do jogo de Truco" << std::endl;
    std::cout << "Pressione qualquer tecla para retornar ao menu...\n";
    std::cin.ignore();
    std::cin.get(); // Esperar o usuário pressionar uma tecla antes de limpar a tela e retornar ao menu
    IJogo::clear_screen_jogo(true); // Limpa a tela sem pausa
}


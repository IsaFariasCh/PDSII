#ifndef JOGO_TRUCO_HPP
#define JOGO_TRUCO_HPP

#include <iostream>
#include <vector>
#include <string>
#include "jogo.hpp"

class Jogo_Truco : public IJogo {
public:
    Jogo_Truco(); // Construtor para inicializar o jogo
    void explica_jogo();
    void Start();

private:
    void distribuir_cartas();
    void jogar_rodada();
    void mostrar_cartas();

    std::vector<std::string> jogadores;
    std::vector<std::string> baralho;
    std::vector<std::string> cartas_jogador1;
    std::vector<std::string> cartas_jogador2;
};

#endif
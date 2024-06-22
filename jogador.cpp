#include <iostream>

#include "jogador.hpp"

//respectivas funções para o atributo nome
std::string jogador:: Get_nome(){return this->nome;};


    jogador:: jogador(std::string entrada_nome)
    {
        this->nome=entrada_nome;
    };

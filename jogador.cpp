#include <iostream>

#include "jogador.hpp"

//respectivas funções para o atributo nome
std::string jogador:: Get_nome(){return this->nome;};


    jogador:: jogador(std::string entrada_nome)
    {
        this->nome=entrada_nome;
    };


// Atualizações após implementação da programação defensiva
#include <iostream>
#include "jogador.hpp"

// respectivas funções para o atributo nome
std::string jogador::Get_nome() { return this->nome; }

jogador::jogador(std::string entrada_nome)
{
    if (entrada_nome.empty())
    {
        std::cerr << "Nome do jogador não pode ser vazio. Ajustando para 'Jogador'" << std::endl;
        entrada_nome = "Jogador";
    }
    this->nome = entrada_nome;
}

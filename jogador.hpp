 #ifndef JOGADOR_HPP
 #define JOGADOR_HPP

#include <iostream>
#include <string>
#include "casa.hpp"

class casa;

class jogador
{
    friend casa;

    private:
std::string nome;

    protected:

    public:
    std::string Get_nome();
    jogador(std::string );
};

  #endif




// Atualizações após implementação da programação defensiva 
#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <iostream>
#include <string>
#include "casa.hpp"

class casa;

class jogador
{
    friend casa;

private:
    std::string nome;

public:
    std::string Get_nome();
    jogador(std::string entrada_nome)
    {
        if (entrada_nome.empty())
        {
            std::cerr << "Nome do jogador não pode ser vazio. Ajustando para 'Jogador'" << std::endl;
            entrada_nome = "Jogador";
        }
        this->nome = entrada_nome;
    }
};

#endif

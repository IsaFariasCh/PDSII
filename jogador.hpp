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

 #ifndef JOGO_21_HPP
 #define JOGO_21_HPP

#include <iostream>
#include <string>
#include <vector>

#include "jogo.hpp"




class Jogo_21  :  public IJogo {

private:
std::string nomes_jogadores[2];
std::string Dar_carta();

protected:

std::string Get_Nome_Jogador(int n){return nomes_jogadores[n];};

public:

Jogo_21(){};

Jogo_21(string nome1,string nome2)
  {
  nomes_jogadores[0]=nome1;
  nomes_jogadores[1]=nome2;

  };

  void explica_jogo()override; 
  void Start()override;
  void declarar_vencedor(int,int);


};

 #endif

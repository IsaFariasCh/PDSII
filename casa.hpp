/*
Essa é a modularização do Objeto Casa
que será responsável por mexer nas moedas de todos os jogadores 
e o objeto responsável pelo Lobby

 */
#ifndef CASA_HPP
#define CASA_HPP

#include <iostream>
#include <string>
#include <vector>

#include "jogador.hpp"
#include "jogo.hpp"

class jogador;

class Casa
{

  private:
unsigned int Quantidade_de_jogadores=0;

void preencher_jogadores();

void Set_Quantidade_de_jogadores_Jogador_Entrou(bool);

void Set_Quantidade_de_jogadores_Jogador_Entrou();

void Set_Quantidade_de_jogadores_Jogador_Saiu();

  protected:
//Vetor que contém o registro de todos os jogadores
std::vector <jogador> jogadores;

  public:

char select_games(int);

void explica_games();

int Get_Quantidade_de_jogadores();

void Set_Quantidade_de_jogadores();

std::string Get_Nome_Jogador(int);


  Casa(int Input_Quantidade_de_jogadores)
  {
    this->Quantidade_de_jogadores=Input_Quantidade_de_jogadores;
    preencher_jogadores();
  };

  ~Casa(){std::cout<<"Volte sempre!!";};
};
 #endif
  
  

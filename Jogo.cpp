#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>  

#include "jogo.hpp"
#include "jogador.hpp"

using namespace std;


//a função abaixo gera um numero de 0 a 12 que diz respeito à uma das cartas da string constante simbolo
inline int numero_simbolo_aleatorio(){return std::rand() % 12;}

//a função abaixo gera um numero de 0 a 3 que diz respeito à uma das cartas da string constante simbolo
inline int numero_naipe_aleatorio(){return std::rand() % 3;}



   std::vector <char> cartas_usadas_naipes;
   std::vector <char> cartas_usadas_simbolos;



//essa função do TAD Baralho verifica se a carta em questão é repetida
   bool IJogo:: carta_repetida(char naipe,char simbolo)
  {
      int tamanho_vector= cartas_usadas_naipes.size();
    for(int iteracao=0; iteracao<tamanho_vector; iteracao++)
    {
/*Se o elemento do vector cartas usadas naipe for igual o naipe de entrada, 
E o elemento do vector cartas usadas simbolos for igual o simbolo de entrada, então  retorna que afunção é repetida*/
        if(this->cartas_usadas_naipes[iteracao]==naipe&&this->cartas_usadas_simbolos[iteracao]==simbolo)
        {return 1;}
    }
    return 0;
    }//end carta repetida

 inline char converter_valor_para_carta(int valor)
{

  switch(valor)
  {

  case 13:return 'K';
  case 12:return 'Q';
  case 11:return 'J';

  case 10:return '1';
  case 9:return '9';
  case 8:return '8';
  case 7:return '7';
  case 6:return '6';
  case 5:return '5';
  case 4:return '4';
  case 3:return '3';
  case 2:return '2';

  default: return 'A';

  };

};

inline char converter_valor_para_naipe(int valor)
{
switch(valor)
    {
    case 0 : return 'O' ;
    case 1: return  'E'; 
    case 2: return  'P';
    default: return 'C';    
    }

}



// A função carta aleatoria retornara uma string de dois caracteres sendo o primeiro o simbolo e o segundo o naipe
    std::string IJogo:: carta_aleatoria()
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

//Pegue naipes e simbolos aleatorios, e enquanto não der uma carta nova, mantenha pegando cartas aleatorias
        char naipee, simboloo;
  do{

      simboloo = converter_valor_para_carta(numero_simbolo_aleatorio());
       naipee = converter_valor_para_naipe(numero_naipe_aleatorio());

     }while(carta_repetida(naipee,simboloo));
// E antes de terminar, registre a carta no vector de cartas usadas
    this->cartas_usadas_naipes.push_back(naipee);
    this->cartas_usadas_simbolos.push_back(simboloo);


//retorne a carta
    std::string retorno; 
    retorno += simboloo;
    retorno += naipee;
    return retorno;

    }



#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "Jogo_21.hpp"
#include "casa.hpp"

using namespace std;

inline void suspense(){   
      cout<<"O resultado final e: ";
    std::cout << ".";
   std::cout.flush();
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << ".";
   std::cout.flush();
   std::this_thread::sleep_for(std::chrono::seconds(3));
   std::cout << "." << std::endl<<endl;
 std::this_thread::sleep_for(std::chrono::seconds(5));}

 void Jogo_21:: declarar_vencedor(int resultado_jogador1,int resultado_jogador2)
{

//Esses bools servem para simplificar
bool jogador_estourou[2]={0,0};
bool jogador_21[2]={0,0};

    
    if(!(resultado_jogador1>21)){cout<<Get_Nome_Jogador(0)<<" ficou com "<<resultado_jogador1<<endl;}else{jogador_estourou[0]=1; cout<<Get_Nome_Jogador(0)<<" Estorou"<<endl;};

    if(!(resultado_jogador2>21)){cout<<Get_Nome_Jogador(1)<<" ficou com "<<resultado_jogador2<<endl;}else{jogador_estourou[1]=1;cout<<Get_Nome_Jogador(1)<<" Estorou"<<endl;};

     if(resultado_jogador1==21)jogador_21[0]=1;
     if(resultado_jogador2==21)jogador_21[1]=1;


    if((jogador_estourou[1]&&jogador_estourou[0])||resultado_jogador2==resultado_jogador1||(jogador_21[1]&&jogador_21[0]))cout<<"Empate"<<endl;

    else if(jogador_21[0])cout<<Get_Nome_Jogador(0)<<" Ganhou"<<endl;
    else if(jogador_21[1])cout<<Get_Nome_Jogador(1)<<" Ganhou"<<endl;
//Se o jogador 1 estourou, ou o jogador 2 tirou um valor maior e não estourando, então ele é o vencedor
    else if(jogador_estourou[0]||(resultado_jogador1<resultado_jogador2&&!(jogador_estourou[1])))cout<<Get_Nome_Jogador(1)<<" Ganhou"<<endl;
//Se o jogador 2 estourou, ou o jogador 1 tirou um valor maior e não estourando, então ele é o vencedor
    else if(jogador_estourou[1]||(resultado_jogador1>resultado_jogador2&&!(jogador_estourou[0])))cout<<Get_Nome_Jogador(0)<<" Ganhou"<<endl;



    std::this_thread::sleep_for(std::chrono::seconds(10));

};


//Essa função serve para converter um valor, aleatoriamente sorteado pela função numero_simbolo_aleatorio(), para a inicial de uma carta
 inline char converter_valor_para_carta(int valor)
{

  switch(valor)
  {

  case 13: return 'K';
  case 12: return 'Q';
  case 11: return 'J';

  case 10: return '1';
  case 9:  return '9';
  case 8:  return '8';
  case 7:  return '7';
  case 6:  return '6';
  case 5:  return '5';
  case 4:  return '4';
  case 3:  return '3';
  case 2:  return '2';

  case 1:  return 'A';

  default: cout<<"erro"<<endl;return 'e';    
  };

};

//Essa função é util na hora de fazer a conversão de cartas para valores inteiros que será determinante para averiguar o vencedor
 inline int converter_carta_para_valor(char simbolo)
{

  switch(simbolo)
  {

  case '1' :
  case 'K'  : 
  case 'Q'  : 
  case 'J'  : return 10;

  case '9'  : return 9;
  case '8'  : return 8;
  case '7'  : return 7;
  case '6'  : return 6;
  case '5'  : return 5;
  case '4'  : return 4;
  case '3'  : return 3;
  case '2'  : return 2;

  case 'A': return 1;

  default: return 0;    
  };

};


int resultado_jogador(string vectoor)
{
    int resultado=0;


    for(int tamanho_vector=vectoor.size(),iteracao=0; iteracao<tamanho_vector;iteracao++)
    {    
        //Se for um naipe então pule esta iteração
        if(vectoor[iteracao]=='C'||vectoor[iteracao]=='E'||vectoor[iteracao]=='O'||vectoor[iteracao]=='P')continue;


        cout<<"iteracao: "<<iteracao<<" vectoor[iteracao]: "<<vectoor[iteracao]<<endl;
        resultado+=converter_carta_para_valor(vectoor[iteracao]);
        cout<<"resultado: "<<resultado<<endl;

    }
    return resultado;
};

inline std::string converte_naipe_para_palavra(char naipe)
{
    switch(naipe)
    {
        case 'C': return " de Copas";
        case 'P': return " de Paus";
        case 'E': return " de Espadilha";
        default : return " de Ouros";

    }

}


std::string Jogo_21:: Dar_carta()
{
        char S_ou_N; std::string carta_recebida;
    cout<<"Deseja mais cartas?"<<endl;
    cout<<"Sim(S) ou Nao(N)?"<<endl;
    cin>>S_ou_N;

    switch(S_ou_N)
    {
    case 'S' : carta_recebida = carta_aleatoria();

        if(carta_recebida[0]=='1')
        {
            cout<<"10"<<converte_naipe_para_palavra(carta_recebida[1])<<endl;

        }else{ cout<<carta_recebida[0]<<converte_naipe_para_palavra(carta_recebida[1])<<endl;}

               return carta_recebida ;

    case 'N' : return "end";

    default: cout<<"Responda apenas com S ou N por favor"<<endl;return "erro";
    }
};

  void Jogo_21:: explica_jogo()
  {
cout<<"O jogo popularmente chamado de 21  aqui no Brasil no Exterior é chamado BlackJack"<<endl;
cout<<"Aqui ele funciona com dois jogadores"<<endl;
cout<<"O objetivo do jogo e acumular mais pontos que o adversario chegando ou se aproximando o maximo possivel de 21"<<endl;
cout<<"Cada simbolo da familia real valendo 10, o As valendo 1, e as respectivas cartas valendo elas mesmas"<<endl;  
cout<<endl<<endl;  
  }; 

  void Jogo_21:: Start()
  {


std::vector <std::string> Cartas_Jogador[2];


std::string carta_recebida;
std::string sair;

for(int jogador_da_iteracao=0;jogador_da_iteracao<2;jogador_da_iteracao++)
    {
//----------------JOGADOR 1
      cout<<"Jogador "<<Get_Nome_Jogador(jogador_da_iteracao)<<" suas cartas iniciais sao:"<<endl;
carta_recebida = carta_aleatoria();
Cartas_Jogador[jogador_da_iteracao].push_back(carta_recebida);


carta_recebida = carta_aleatoria();
Cartas_Jogador[jogador_da_iteracao].push_back(carta_recebida);


for(auto iteracao : Cartas_Jogador[jogador_da_iteracao])
{   
   //Se o primeiro elemento for '1' então ele é um "10"
    if(iteracao[0]=='1')
    {
        cout<<"10"<<converte_naipe_para_palavra(iteracao[1])<<endl;

    }else{ cout<<iteracao[0]<<converte_naipe_para_palavra(iteracao[1])<<endl;}


}


do{

sair= Dar_carta();
if(sair!="end") Cartas_Jogador[jogador_da_iteracao].push_back(sair);

}while(sair!="end");

IJogo::clear_screen_jogo();
    }    

//---------------Definir vencedor      

      int resultado_jogador[2]={0,0};
/*
    O vector de strings Cartas_jogador tem 3 parametros para acessar os elementos [a][b][c]
    a - diz respeito se é o jogador 1 ou o 2
    b - diz respeito ao simbolo da carta, já que o vector recebeu a cartas como strings
    c - diz respeito ao naipe(esse parametro não sera relevante)

Por exemplo:
jogador a
     b  c
    [S][N]
    [S][N]
    [S][N]

    O for abaixo e resposavel por percorrer o vector Cartas_jogador e converter as cartas para valores inteiros
    Sua lógica é de que se associa os tamanhos dos valores à uma variavel e vai decrementando ela até chegar em -1
    quando chegar em -1 ela para de atribuir os valores
    O loop continua enquanto uma ou outra das duas iterações ainda serem maiores que -1
    E só se faz a atribuição se o valor da variavel for maior que -1
*/      
for(int iteracao_jogador1=Cartas_Jogador[0].size()-1,iteracao_jogador2=Cartas_Jogador[1].size()-1; iteracao_jogador1>-1||iteracao_jogador2>-1;iteracao_jogador1--,iteracao_jogador2--) 
{
  if(iteracao_jogador1>-1)

      resultado_jogador[0] += converter_carta_para_valor(Cartas_Jogador[0][iteracao_jogador1][0]);

  if(iteracao_jogador2>-1)

        resultado_jogador[1] += converter_carta_para_valor(Cartas_Jogador[1][iteracao_jogador2][0]);

};     

//Suspense ;)      
          suspense();
      declarar_vencedor(resultado_jogador[0],resultado_jogador[1]);

      IJogo::clear_screen_jogo();
  };

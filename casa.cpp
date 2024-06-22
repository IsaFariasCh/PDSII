#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>


#include "jogo.hpp"
#include "casa.hpp"
#include "jogador.hpp"
#include "Jogo_21.hpp"
#include "Jogo_Truco.hpp"
#include "Jogo_Paciencia.hpp"

using namespace std;

std::string Casa:: Get_Nome_Jogador(int elemento) 
{

return this->jogadores[elemento].Get_nome();

};


void Casa:: preencher_jogadores()
{

    int Quantidade_de_Jogadores_Local;
     Quantidade_de_Jogadores_Local=this->Quantidade_de_jogadores;

    for(int iterador=0; iterador<Quantidade_de_Jogadores_Local; iterador++)
        {
            Set_Quantidade_de_jogadores_Jogador_Entrou(1);

        }
    IJogo::clear_screen_jogo(1);
}

char Casa:: select_games(int Quantidade_de_jogadores)
{
 char jogoo;
 cout<<"Selecione os jogos disponiveis"<<endl<<"(Somente o primeiro simbolo do nome)"<<endl;

 if(Quantidade_de_jogadores==1)
 {
cout<< "Para 1 jogador temos:"<<endl;
cout<< "Paciencia(P)"<<endl;
 }

else if(Quantidade_de_jogadores==2)
{
cout<< "Para 2 jogadores temos:"<<endl;
cout<< "21(2)"<<endl;
cout<< "Truco(T)"<<endl;
}


 while(1)
 {
    cin>>jogoo;
  switch(jogoo)
    {
   case 't':
   case 'T':  return 't' ;

   case 'p':
   case 'P':  return 'p' ;

   case '2'  :    return 'v' ;
   default: cout<<"Invalido! Selecione novamente"<<endl;break;
    }
 }


};
void Casa:: explica_games()
{
   Jogo_21          vinte_um;
   Jogo_Paciencia   paciencia;
   Jogo_Truco       truco;

vinte_um.explica_jogo();
paciencia.explica_jogo();
truco.explica_jogo();

cout<<endl<<endl<<"Insira qualquer coisa para continuar..."<<endl;char pausa;cin>>pausa;    
};


int Casa:: Get_Quantidade_de_jogadores()
{
    return this->Quantidade_de_jogadores;
};

//As duas funções abaixo tem a mesma função porem uma incrementa a variavel "quantidade_de_jogadores" e a outra não altera, em seus respectivos locais de chamada isso faz toda diferença. No construtor de casa por exemplo eu só preciso registrar o jogador sem necessariamente aumentar quantidade_de_jogadores, no entanto, se eu chamar a função Get_Quantidade_de_jogadores() aqui, ela precisará aumentar quantidade_de_jogadores, por isso a função "Set_Quantidade_de_jogadores_Jogador_Entrou" tem sobrecarga.
void Casa:: Set_Quantidade_de_jogadores_Jogador_Entrou( )
{
 this->Quantidade_de_jogadores++;
 cout<<"Qual o nome do novo jogador?"<<endl;
 std::string nomee;
 cin>>nomee;
 jogador novo_jogador(nomee);
 this->jogadores.push_back(novo_jogador);
};

void Casa:: Set_Quantidade_de_jogadores_Jogador_Entrou(bool nao_decremenatar)
{

 cout<<"Qual o nome do novo jogador?"<<endl;
 std::string nomee;
 cin>>nomee;
 jogador novo_jogador(nomee);
 this->jogadores.push_back(novo_jogador);
};

void Casa:: Set_Quantidade_de_jogadores_Jogador_Saiu()
{
    cout<<"Qual o nome do jogador que saiu?"<<endl;
    std::string nomee; cin>>nomee;
    const int tamanho_vector = this->jogadores.size(); int jogador_inexistente=0;

    //O for abaixo procura o elemento de jogadores onde tem o nome requisitado e então o exclui, e então decrementa a quantidade de jogadores.
    for(int iteracao=0;iteracao<tamanho_vector;iteracao++)
    {
        if(nomee==jogadores[iteracao].Get_nome())
        {this->jogadores.erase(jogadores.begin()+iteracao);this->Quantidade_de_jogadores--;break;}
        jogador_inexistente++;
    }
//A variavel jogador inexistente foi incrementada sempre que o for não encerrou apos encontrar o jogador, então se a variavel for do tamanho do vector significa que ele não achou o jogador, então o jogador não existe.
    if(jogador_inexistente==tamanho_vector){cout<<"Jogador inexistente!"<<endl;std::this_thread::sleep_for(std::chrono::seconds(5));}
    
IJogo::clear_screen_jogo(1);

};


void Casa:: Set_Quantidade_de_jogadores()
{
    cout<<"Aumentar(A) ou Diminuir(D)"<<endl; 
             char Aumentar_ou_Diminuir;
             while(1)
             {
              cin>>Aumentar_ou_Diminuir;
             if(Aumentar_ou_Diminuir=='A')
             {this->Set_Quantidade_de_jogadores_Jogador_Entrou();break;}

             else if(Aumentar_ou_Diminuir=='D')
             {this->Set_Quantidade_de_jogadores_Jogador_Saiu();break;} 

             else{cout<<"Invalido!"<<endl;}

             }
};

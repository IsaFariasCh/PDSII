//---------------INCLUDES
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>  
#include <thread>
#include <chrono>


#include "casa.hpp"
#include "Jogo_21.hpp"
#include "Jogo_Truco.hpp"
#include "Jogo_Paciencia.hpp"

//professora disse que poderiamos usar por este ser um projeto pequeno 
using namespace std;

//---------------DECLARAÇAO DAS FUNÇOES DE MAIN

void entrar_jogo(Casa &casa)
{
    cout<<casa.Get_Quantidade_de_jogadores()<<endl;
if((casa.Get_Quantidade_de_jogadores()!=1)&&(casa.Get_Quantidade_de_jogadores()!=2))
{
    cout<<"Quantidade incompatível com os jogos disponiveis"<<endl;
    cout<<"As quantidades compativeis são: 1 para Paciencia ou 2 Jogadores para Truco ou 21"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(7));
}
    else{
char jogo_selecionado=casa.select_games(casa.Get_Quantidade_de_jogadores());
IJogo::clear_screen_jogo();
//Dentro do Switch declara o objeto e já roda o jogo
switch(jogo_selecionado)
 {
case 'v' : {Jogo_21 vinte_um(casa.Get_Nome_Jogador(0),casa.Get_Nome_Jogador(1)); vinte_um.Start();}; break;
case 't' : {Jogo_Truco Truco; Truco.Start();}; break;
case 'p' : {Jogo_Paciencia pacienciaa; pacienciaa.Start();}; break;
case 'e' : cout<<"Erro. Selecao invalida!"<<endl;
 }

      }
}

//---------------MAIN
int main()
{
//Essa função inicializa a aleatoriedade que será muito usada ao longo do código, especificamente em Jogo.cpp, nas duas funções inline    
std::srand(static_cast<unsigned int>(std::time(nullptr)));

cout<<"Diga quantos jogadores tem inicialmente:"<<endl;
int quantidade_de_jogadoress=0;
cin>>quantidade_de_jogadoress;
//---------------INICIALIZAÇAO DO OBJETO CASA
Casa casa(quantidade_de_jogadoress);

//---------------LOBBY DO CODIGO
while(1)
{
cout<<"Numero de jogadores: "<<casa.Get_Quantidade_de_jogadores()<<endl;
    
    for (int iteracao=0;iteracao<casa.Get_Quantidade_de_jogadores();iteracao++)
    {
        std::cout <<"Jogador: "<< casa.Get_Nome_Jogador(iteracao) <<endl;
    }

    
cout<<endl<<"Selecione o que deseja fazer?(insira de 1 a 4)"<<endl<<endl;
cout<<"1 - Entrar em algum jogo"<<endl;
cout<<"2 - Mudar o numero de jogadores"<<endl;
cout<<"3 - Entender como os jogos funcionam"<<endl;
cout<<"4 - Encerrar "<<endl;

char selecao; bool encerrar=0; std::string pause;
cin>>selecao;

switch(selecao)
{
    case '1' :IJogo::clear_screen_jogo(1); entrar_jogo(casa);break;
    
    case '2' : IJogo::clear_screen_jogo(1);casa.Set_Quantidade_de_jogadores();break;
    
    case '3' : IJogo::clear_screen_jogo(1); casa.explica_games();break;
    
    case '4' :  IJogo::clear_screen_jogo(1);encerrar=1;break;
    
    default:cout<<"Invalido!"; std::this_thread::sleep_for(std::chrono::seconds(2)); cout<<"Insira Novamente"        <<endl;std::this_thread::sleep_for(std::chrono::seconds(5));
    break;
    
}
IJogo::clear_screen_jogo(1);

if(encerrar)break;
}

    return 0;
}

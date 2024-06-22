 #ifndef JOGO_HPP
 #define JOGO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>  

#pragma GCC diagnostic ignored "-Wunused-result"

using namespace std;

//Declaração da superclasse jogo
class IJogo 
{
    private:
    // TAD Baralho
 struct Baralho
 {
  const char naipe[5]={'C','O','E','P'};
  const char simbolo[14]={'A',2,3,4,5,6,7,8,9,10,'K','Q','J'};
 };

   std::vector <char> cartas_usadas_naipes;
   std::vector <char> cartas_usadas_simbolos;

    protected:

 //essa função no TAD Baralho verifica se a carta em questão é repetida
  bool carta_repetida(char ,char );


   std::string carta_aleatoria();
    public:
   IJogo(){};

   virtual void explica_jogo()=0; 
   virtual void Start()=0;

//Essa função apenas limpa a tela com pausa
inline static void clear_screen_jogo()  {
  #ifdef _WIN32 // Verifica se estamos no Windows
    system("cls"); // Comando para limpar a tela no Windows
  #else
    system("clear"); // Comando para limpar a tela no Linux/Unix
  #endif
  cout << "A tela foi limpa. Insira uma letra se ja deseja continuar...";
  char pause;cin>>pause;
  #ifdef _WIN32 // Verifica se estamos no Windows
    system("cls"); // Comando para limpar a tela no Windows
  #else
    system("clear"); // Comando para limpar a tela no Linux/Unix
  #endif
  };

//Essa função apenas limpa a tela sem pausa
inline static void clear_screen_jogo(bool)  {
  #ifdef _WIN32 // Verifica se estamos no Windows
    system("cls"); // Comando para limpar a tela no Windows
  #else
    system("clear"); // Comando para limpar a tela no Linux/Unix
  #endif

  };
};
#endif

# Jogo de Cartas Avançado 
![tela de incio](https://github.com/iaraalvest/PDSII/assets/170683528/31ae8c26-6ad1-4c90-804d-30528c6657c5)
# Situação
> :construction: Projeto em construção :construction:
# Apresentação
Um cliente nos procurou querendo um programa funcional para um sistema de cassino online, estilo Blazer, porém só com cartas de baralho e onde os jogadores tiram dinheiro deles mesmos, porém a casa sempre fica com uma porcentagem do dinheiro total envolvido. E ele implica:

* Jogos de cartas de Cassino e outros jogos populares como truco e 21
* Quer um sistema de monetização
# Solução - visaõ geral
Nós faremos um sistema de cadastro e login com moedas próprias, que tem um banco de dados que armazena nome, senha e moedas (sem valor no mundo real).
Existe 1 jogo individual, e o restante é multiplayer.Cada jogador começa com 100 moedas, e pode ganhar mais moedas ganhando de outros jogadores ou da casa (ganhar da casa dá menos moedas em comparação com ganhar de outros jogadores, pois assim eles ficam vidrados em jogar e competir e se não tiver ninguém eles jogam sozinhos mas ganhando menos, para não quebrar o jogo). A casa pode produzir dinheiro infinito

# Estrutura 
O nosso projeto possui essa estrutura de base:

![Fluxograma](https://github.com/iaraalvest/PDSII/assets/170683528/1bfad947-b295-47cd-96aa-53b8b70378f6)

Onde o jogador entra e cai direto na parte da *casa*, nela possui a parte de login, se o usuario ja for cadastrado segue direto para a seleção de jogos, se não for ele ira ser encaminhado para realizar o cadastro; ela também cotrola as moedas, trasações e é a parte do nosso lobby, pré jogo. Seguindo pra área de *jogos*, nela possui a parte de armazenamento de *dados* dos nossos *jogadores*, assim eles podem verificar seu dados e a quatidade de moedas disponivel, e a parte pricipal que é a seleção dos jogos. Estão disponiveis tres jogos: *21, Truco e Paciencia*,  jogo selecionado basta jogar!. Ao final de cada partida a opção de *sáida* se mostra disponivel, se o usuario desejar sai aparece seu posição e fim de jogo, se desejar uma nova partida, será redirecionado para *casa*.

O nosso programa funciona de forma bem simples, a nossa main principal que dita as principais informações. 

Link da main: https://replit.com/@CauaLuzz/Jogo-de-cartas#main.cpp
Em resumo, este programa configura um sistema de cassino onde os usuários podem selecionar e jogar diferentes jogos de cartas, além de ajustar o número de jogadores e obter explicações sobre os jogos.

Os nossos principais componentes serão encontrados no *replit* e no *github*. 

No *replit* todos os nossos codigos seraão encontrados em seus respectivos arquivos: casa.hpp e casa.cpp; jogador.hpp e jogador.cpp; jogadores.hpp e jogadores.cpp; jogo_paciencia_.hpp e jogo_paciencia.cpp jogo_21.hpp e jogo_21.cpp; jogo_truco.hpp e jogo_truco.cpp, os codigos são detalhados e possuem comentarios para uma melhor compreensão do cliente, o mesmo link da main da acesso aos demais codigos.

No *github* será encontrada nossa documentação, tudo prescrito informando todo o nosso trabalho, nossas ideias, duvidas, soluções etc, um manual completo para o nosso cliente possuindo todas as informações necessarias e detalhadas, nele também será encontrado nossos codigos,  entao o cliente irá possuir dois canais de acesso.

Link:https://github.com/iaraalvest/PDSII/edit/main/README.md

# Instruções de instalação 
 Para que o problema inicial seja solucionado por completo o jogo precisa ser utilizado pelo cliente, sendo assim, seguem as instruções para a instalação do cassino:

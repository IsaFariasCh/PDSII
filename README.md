# Jogo de Cartas Avançado 
![tela de incio](https://github.com/iaraalvest/PDSII/assets/170683528/31ae8c26-6ad1-4c90-804d-30528c6657c5)

# Situação
> :construction: Projeto em construção :construction:

# Apresentação

Um cliente nos procurou querendo um programa funcional para um sistema de jogos de baralho tradicionais brasileiros, porém, só com cartas de baralho. E ele implica:

* 21 Brasileiro
* Truco
* Paciência 


# Solução - visão geral

Com base em um raciocínio em equipe, nós decidimos criar um programa inspirado nos jogos de cassino, entretanto, sem conter apostas monetárias. Contaremos com um sistema de cadastro de login que inclui um banco de dados para armazenar os nomes dos usuários.

A solução geral inclui os jogos citados anteriormente: 21, truco e paciência. Cada jogo com suas particularidades, como quantidade de jogadores e regras específicas. Ao longo da nossa documentação e desenvolvimento, especificaremos o funcionamneto tanto dos jogos como de toda a estrutura main que une todos os detalhes. 

# Estrutura 

Em primeiro lugar, nós fizemos uma reunião para definir como seria feito o projeto, qual parte cada contribuinte iria realizar e organizamos tudo da melhor forma possível.

Dessa forma, dividimos o projeto em duas grandes partes: o código e a documentação. 

O código ficou na seguinte maneira: 

- Cauã: responsável pela main e 21.
- Iara e Kaylane: responsáveis pelo Truco.
- Julia Coelho, Julia Moschen e Isabella: responsáveis pelo Paciência.

A documentação nós definimos com qual tópico cada contribuinte iria ficar responsável, mas com liberdade para alterações caso necessário e sinalizado entre os mesmos, e todas as alterações são possíveis de acompanhar e ver quem realizou pelo commits do GitHub.

O nosso projeto possui essa estrutura de base:

![Fluxograma](https://github.com/iaraalvest/PDSII/assets/170683528/1bfad947-b295-47cd-96aa-53b8b70378f6)

Onde o jogador entra e cai direto na parte da *casa*, nela possui a parte de login; Se o usuário já for cadastrado, segue direto para a seleção de jogos, se não for, ele será encaminhado para realizar o cadastro; é a parte do nosso lobby, pré jogo. Seguindo para a área de *jogos*, nela possui a parte de armazenamento de *dados* dos nossos *jogadores*, assim, podem verificar os nomes dos jogadores e a parte pricipal, que é a seleção dos jogos. Estão disponíveis três jogos: *21, Truco e Paciencia*. Jogo selecionado, basta jogar! Ao final de cada partida, a opção de *saída* se mostra disponível; Se o usuário desejar sair, aparece sua posição e fim de jogo, se desejar uma nova partida, será redirecionado para *casa*.

O nosso programa funciona de forma bem simples, a nossa main principal que dita as principais informações. 

Link da main: https://replit.com/@CauaLuzz/Jogo-de-cartas#main.cpp
Em resumo, esse programa configura um sistema de cassino em que os usuários podem selecionar e jogar diferentes jogos de cartas, além de ajustar o número de jogadores e obter explicações sobre os jogos.

Os nossos principais componentes serão encontrados no *replit* e no *github*. 


# Instruções de instalação 

Para que o problema inicial seja solucionado por completo, o jogo precisa ser utilizado pelo cliente, sendo assim, seguem as instruções para a instalação do cassino:
Para ter acesso ao nosso programa de cassino, o jogador deve ter uma conta do github seguindo as instruções a seguir: 

No *replit* todos os nossos códigos serão encontrados em seus respectivos arquivos: casa.hpp e casa.cpp; jogador.hpp e jogador.cpp; jogadores.hpp e jogadores.cpp; jogo_paciencia_.hpp e jogo_paciencia.cpp; jogo_21.hpp e jogo_21.cpp; jogo_truco.hpp e jogo_truco.cpp, os codigos são detalhados e possuem comentários para uma melhor compreensão do cliente, o mesmo link da main da acesso aos demais codigos.

No *github* será encontrada nossa documentação, tudo prescrito informando todo o nosso trabalho, nossas ideias, dúvidas, soluções, etc, um manual completo para o nosso cliente, possuindo todas as informações necessárias e detalhadas. Nele também será encontrado nossos códigos, então o cliente irá possuir dois canais de acesso.

Link: https://github.com/IsaFariasCh/PDSII

Para acessar os códigos pelo github, o usuário irá acessar o link acima e cai nessa janela:
![image](https://github.com/iaraalvest/PDSII/assets/170683528/27165c6c-4521-439f-9efe-9847bdd10ba3)

Depois, clica onde está *2 branches*, e vai abrir a seguinte janela:
![image](https://github.com/IsaFariasCh/PDSII/assets/170683528/d53ae076-87f9-462c-a511-12984646a10e)

Clica no segundo ou terceiro link da imagem anterior e já tem acesso aos codigos:
![image](https://github.com/IsaFariasCh/PDSII/assets/170683528/782df8f6-43c1-4cfd-82f1-b3bf15dadc1b)

# Instruções gerais de uso 
Este manual fornece instruções sobre como jogar e interagir com diferentes jogos disponíveis no programa. Ele descreve as opções disponíveis no lobby do jogo e como entrar em um jogo específico.

1. *Inicialização de um Jogador*- Cria um novo jogador com um nome especificado.

2. *Lobby do Jogo*- No lobby do jogo, você tem as seguintes opções:
- Entrar em um jogo: Permite que você entre em um dos jogos disponíveis.
- Mudar o número de jogadores: Permite que você altere o número de jogadores.
- Entender como os jogos funcionam: Fornece informações sobre como os jogos disponíveis funcionam.
- Encerrar o programa: Encerra o programa.

2.1- *Entrar em um Jogo*
  - Selecione a opção "Entrar em um Jogo" no lobby.
  - Escolha o jogo desejado digitando o número correspondente ou a primeira letra do nome do jogo.
       - Para Paciencia, digite 'P';
       - Para 21, digite '2';
       - Para Truco, digite 'T';
       - Pressione Enter para confirmar.

 2.2- *Mudando o Número de Jogadores*
  - No lobby do jogo, o usuário seleciona a opção "Mudar o Número de Jogadores".
  - O sistema perguntará se deseja aumentar ou diminuir a quantidade de jogadores. Digite 'A' para adicionar um jogador ou 'D' para remover um jogador. O sistema solicitará o nome do novo jogador e ele será adicionado/removido à lista de jogadores.

  2.3- *Explicação dos Jogos*- Esta funcionalidade fornece uma explicação detalhada dos jogos disponíveis.
    
  - Jogo 21: É jogado com 2 pessoas.
        Objetivo: Chegar o mais próximo possível de 21 pontos sem ultrapassá-lo.
    
  - Jogo Truco: É jogado com 2 pessoas.
        Objetivo: Fazer pontos através de blefes e estratégias para vencer as rodadas.
    
  - Jogo Paciência: É um jogo de cartas para apenas uma pessoa.
        Objetivo: Criar quatro pilhas de cartas, uma para cada naipe, em ordem crescente (do ás ao rei).
    
  2.4- *Encerrar o Programa*
  - Selecione a opção "Encerrar o Programa" no lobby.
  - O programa será finalizado e você sairá da Casa Principal.

# Instruções de uso - Jogo Paciência

*Objetivo do Jogo*
- Mover todas as cartas para as fundações, separando-as por naipes e em ordem crescente (Ás ao Rei). As cartas são dispostas em sete colunas no tableau e podem ser movidas entre colunas seguindo regras específicas: ordem decrescente e alternando cores. Você também pode comprar cartas do monte.

*Início do Jogo*

- Criação do Monte: Um baralho de 52 cartas é criado.
- Embaralhamento do Monte: As cartas são embaralhadas.
- Distribuição das Cartas: As cartas são distribuídas em sete pilhas na parte inferior do tableau.
  
*Jogadas Disponíveis*

Durante o jogo, você pode escolher entre as seguintes ações:
- Ver a próxima carta do monte;
- Mover uma carta de uma pilha a outra;
- Mover uma carta do monte a uma pilha;
- Mover uma carta de uma pilha para a pilha de cima;
- Mover carta do monte para pilha de cima;
- Mover a carta da pilha de cima para a pilha de baixo.

*Regras de Movimentação*
- Ordem Decrescente e Alternando Cores: Cartas devem ser empilhadas em ordem decrescente e alternando cores.
- Fundações: Cartas nas fundações devem ser movidas em ordem crescente e separadas por naipes.
 
*Final do Jogo*
- Vitória: Todas as cartas estão nas fundações.
- Derrota: Não há mais movimentos possíveis.

# Instruções de uso - Jogo Truco

*Objetivo do jogo*
- O objetivo do jogo é vencer mais rodadas que o seu adversário, acumulando o maior número de pontos ao final de todas as partidas. A vitória é alcançada ao demonstrar habilidade e estratégia, garantindo que seus pontos superem os do oponente ao término do jogo.

*Início do jogo*
- Cada jogador receberá três cartas, tais cartas terão valores específicos e cada uma delas têm diferentes funções e valores dentro do jogo.
- Distribuição e exibição das cartas aos 2 usuários.

*Rodadas*
- Cada jogador começará com 0 pontos
- Rodada ocorre baseada na seguinte ordem de grandeza das cartas.

                                       3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4
*Rodada 1*
- Jogador um irá jogar;
- Jogador dois joga em seguida;
- Final da rodada 1: *Se as cartas do jogador um forem maiores que as do jogador dois, consideraremos o jogador um o vencedor dessa rodada. Caso contrário o jogador dois será o ganhador*;
- O mesmo ocorrerá em todas as rodadas de acordo com um número n de partidas escolhidas pelos usuários. 

*Final do jogo*
- Ao final de todas as rodadas os pontos de cada jogador serão acumulados e o jogo acabará.
- O vencedor é declarado de acordo com o maior acumulador de pontos.

*Função:'Truco!'*
- "Truco!" é essencialmente um pedido para aumentar o valor da rodada. Quando um jogador declara "Truco", ele está desafiando o adversário e indicando que acredita ter uma mão forte o suficiente para vencer a rodada, ou que quer blefar para o adversário.
- Opções dessa função:
  
  Aceitar o Truco: O adversário aceita o desafio, e a rodada passa a valer mais pontos.
  
  Não aceitar: O adversário não aceita e as condições são mantidas. 

# Instruções de uso - Jogo 21

*Objetivo do jogo*
- O objetivo principal do jogo 21 é conseguir uma mão de cartas cuja soma dos valores seja o mais próximo possível de 21, sem ultrapassar esse valor.

*Cartas e valores*
- Cartas numeradas de 2 a 10 têm o valor de face.
- Valete (J), Dama (Q) e Rei (K) valem 10 pontos cada.
- Ás (A) pode valer 1 ou 11 pontos, dependendo do que for mais favorável para a mão do jogador.

*Início do jogo*
- O jogo começa com a distribuição de duas cartas para cada jogador

*Rodadas*
- Cada jogador começa com 0 pontos.
- Jogador pode pedir cartas adicionais até decidir parar ou ultrapassar 21 pontos.
- Os jogadores devem tentar alcançar a soma de 21 pontos em suas mãos.

*Fim do jogo*
- O jogo termina após um determinado número de rodadas, conforme escolhido pelos jogadores.
- O vencedor é declarado com base na maior soma de pontos obtida sem ultrapassar 21.

# Principais Dificuldades

- Ao longo da programação, ocorreu um problema com a herança e com os construtores, já que na arquitetura original era para casa ser superclasse dos demais objetos, no entanto, quando compilou o código, deu um erro que dizia que seria necessário redeclarar o construtor de casa. Assim, esse sistema de herança foi removido. 

- Outra parte relevante foi a otimização do código usando um array de vector string ao invés de dois vectors string individuais. Inicialmente não pensava ser possível, mas na prática funcionou e isso otimizou bastantes linhas, já que foi só mudar o elemento do array ao invés de criar todo um novo sistema.

- Sobre o último caso, o mesmo ocorreu na conversão do simbolo das cartas para o valor das cartas. A solução foi, ao invés de usar dois dados individuais, usar apenas 1 for para dois elementos do array, q para cada jogador.

- Ainda sobre otimização de código, especificamente nas condicionais, pode ser feito usando o operador || (ou) para a situação: Condicionais diferentes e saídas iguais.

- Tivemos um pouco de dificuldade com o próprio GitHub por ele ter uma limitação a algumas funcionalidades para um usuário que não seja pró. Como solução, para que todos os integrantes pudessem acessar e editar a documentação, foi feito um fork do repositório. 
  
- A plataforma em questão também não conseguiu compilar o nosso código, levando-nos a utilizar uma outra plataforma (o Replit) para verificarmos os detalhes ao compilar e executar.






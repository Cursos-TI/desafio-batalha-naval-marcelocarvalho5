🛳️ Batalha Naval em C – Desafios Novato, Aventureiro e Mestre
🎯 Objetivo Geral

Este projeto tem como objetivo desenvolver, em três níveis de dificuldade, uma versão simplificada do clássico Batalha Naval, utilizando a linguagem C.
Os desafios exploram vetores, matrizes, loops aninhados, condicionais e boas práticas de organização e documentação de código.

🧱 Estrutura do Projeto
Nível	Arquivo	Descrição
🟢 Novato	batalha_naval_novato.c	Criação do tabuleiro e posicionamento básico de dois navios
🟠 Aventureiro	batalha_naval_aventureiro.c	Adição de navios diagonais e validação de sobreposição
🔴 Mestre	batalha_naval_mestre.c	Implementação de habilidades especiais com áreas de efeito (cone, cruz e octaedro)
🧩 Nível Novato – Posicionando Navios
🎯 Objetivo

Criar um tabuleiro 10x10 e posicionar dois navios — um horizontal e outro vertical — utilizando matrizes e vetores.

🔹 Regras:

O tabuleiro é representado por uma matriz 10x10 preenchida com 0 (água).

Os navios ocupam 3 posições, representadas por 3.

Os navios não podem ultrapassar os limites do tabuleiro nem se sobrepor.

🔹 Exemplo de saída:
=== TABULEIRO DE BATALHA NAVAL ===

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 3 3 3 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 3 0 0
0 0 0 0 0 0 0 3 0 0
0 0 0 0 0 0 0 3 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

Legenda: 0 = Água | 3 = Navio

⚓ Nível Aventureiro – Navios Diagonais
🎯 Objetivo

Expandir o jogo adicionando navios posicionados na diagonal, mantendo o controle de sobreposição e limites.

🔹 Regras:

O tabuleiro continua 10x10.

Quatro navios de 3 posições:

Dois horizontais/verticais.

Dois diagonais (principal \ e secundária /).

Nenhum navio pode ultrapassar os limites do tabuleiro.

Sobreposições são verificadas antes de posicionar.

🔹 Exemplo de saída:
=== TABULEIRO DE BATALHA NAVAL ===

0 0 0 0 0 0 0 0 0 3 
0 0 3 3 3 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 3 0 3 0 0 0 0 0 0 
0 0 3 0 3 0 0 0 0 0 
0 0 0 0 0 0 0 3 0 0 
0 0 0 0 0 0 0 3 0 0 
0 0 0 0 0 0 0 3 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 

Legenda: 0 = Água | 3 = Navio

💥 Nível Mestre – Habilidades Especiais e Áreas de Efeito
🎯 Objetivo

Adicionar habilidades especiais com áreas de efeito (AOE) sobre o tabuleiro:

Cone

Cruz

Octaedro

As habilidades afetam posições no tabuleiro e são exibidas visualmente, sem causar “dano” aos navios.

🔹 Representação:
Valor	Significado
0	Água
3	Navio
5	Área afetada por habilidade
🔹 Matrizes de habilidades (5x5):
🔸 Cone
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 0 0 0 0
0 0 0 0 0

🔸 Cruz
0 0 1 0 0
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0

🔸 Octaedro
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0
0 0 1 0 0

🔹 Exemplo de saída:
=== TABULEIRO DE BATALHA NAVAL ===

0 0 0 5 5 5 0 0 0 0 
0 0 0 5 5 5 0 0 0 0 
0 0 3 3 3 0 0 0 0 0 
0 0 0 5 5 5 0 0 0 0 
0 5 5 5 5 5 0 0 0 0 
5 5 5 5 5 5 0 3 0 0 
0 0 0 5 0 5 0 3 0 0 
0 5 5 5 5 5 0 3 0 0 
0 0 5 5 5 0 0 0 0 0 
0 0 0 5 0 0 0 0 0 0 

Legenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade

🧩 Estrutura das Funções (Nível Mestre)
Função	Descrição
inicializarTabuleiro()	Preenche o tabuleiro com água (0)
posicionarNavioHorizontal() / posicionarNavioVertical()	Posicionam navios de tamanho fixo (3)
criarCone() / criarCruz() / criarOctaedro()	Criam dinamicamente as formas de habilidade
aplicarHabilidade()	Sobrepõe as áreas de efeito no tabuleiro
exibirTabuleiro()	Exibe o estado final do tabuleiro no console
🚀 Como Executar o Projeto

Clone o repositório:

git clone https://github.com/Cursos-TI/desafio-batalha-naval-marcelocarvalho5
cd batalha-naval


Compile o programa desejado:

gcc batalha_naval_novato.c -o batalha_novato
gcc batalha_naval_aventureiro.c -o batalha_aventureiro
gcc batalha_naval_mestre.c -o batalha_mestre


Execute:

./batalha_novato
./batalha_aventureiro
./batalha_mestre

📁 Estrutura de Arquivos
batalha-naval/
├── batalha_naval_novato.c
├── batalha_naval_aventureiro.c
├── batalha_naval_mestre.c
└── README.md

💬 Sugestões de Commits
Etapa	Mensagem sugerida
Nível Novato	feat: cria tabuleiro 10x10 e posiciona dois navios básicos
Nível Aventureiro	feat: adiciona navios diagonais e valida sobreposição
Nível Mestre	feat: adiciona habilidades especiais (cone, cruz e octaedro) com áreas de efeito
🏁 Conclusão

Com estes três desafios, você conclui o desenvolvimento completo do Batalha Naval em C, aplicando os principais conceitos de vetores, matrizes e lógica condicional.

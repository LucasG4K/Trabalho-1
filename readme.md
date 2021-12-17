**Comparação das estruturas tipo árvore**
=

Para esse trabalho, a proposta era que fizéssesmos a implementação de uma Árvore Rubro Negra (RB) funcional e que a partir da junção de outras duas árvores elaboradas anteriormente, a saber: Árvore Binária de Pesquisa Padrão (BST) e a Árvore AVL (AVL), produzíssemos um comparativo para verificarmos a eficiência de cada uma.

## **Instruções e referências para o uso do código**

O algoritmo atual deste repositório foi construído utilizando a linguagem C++, através do sistema operacional Windows 11 operando em ambiente Linux (WSL2 - Ubuntu-20.04). A compilação pode ser feita por meio do comando "make" e executado com "make run". O "output" e objetos (*-o) podem ser removidos com "make clean" em caso de algum erro imprevisto com compilações passadas.

Ao inicializar o programa, é necessário que se faça primeiro a escolha das bases de inserção e assim inicie o preenchimento das árvores. Somente na próxima etapa existe a capacidade de se fazer pesquisas dentro das estruturas carregadas previamente.

**obs:** para gerar novas bases aleatórias de inserção utiliza-se o comando "make gen", sendo que os novos arquivos irão sobrepor os arquivos originais.

## **Explicação sucinta sobre a Árvore Rubro Negra**

A Árvore Rubro Negra (RB), assim como a Árvore AVL, é um tipo de dados derivado da Árvore de Pesquisa Binária Padrão (BST). Assim como a BST, o propósito dessa estrutura é o armazenamento de dados e a disposição de seus valores de forma que se tenha uma resposta para pesquisa bastante eficiente se comparado a outros modelos de armazenamento para pesquisa. Porém, a principal diferença está na necessidade de correções e balanceamentos respeitando regras específicas para esse tipo, assim como acontece também para a árvore AVL. Esses balanceamentos nada mais são que uma tentativa de manter a árvore com um aspecto uniforme, reconstruindo seus "galhos" mais unidos para que assim reduza o tempo de eventuais pesquisas de itens em seu escopo. Além disso, apesar da semelhança entre esse tipo e o tipo AVL (Árvores balanceadas) e uma breve semelhança com a BST, cada estrutura segue sua própria regra e portanto podem vir a ter usos e resultados diferentes, será mostrado ao final da análise.

### Regras para a Árvore Rubro Negra
1. Todo nó da árvore é vermelho ou preto.
2. O nó raiz é preto.
3. Toda folha (nil) é preta.
4. Se um nó é vermelho, então seus filhos são pretos.
5. Para cada nó, todos os caminhos de um nó até seus descendentes possuem o mesmo número de nós pretos.

## **Sobre o desenvolvimento**

Seguindo com o desenvolvimento, a implementação da árvore RB necessitava de regras para que a estrutura final estivesse de acordo com o que foi apresentado acima. Essa estrutura tem grande predisposição a se desbalancear ao fazer operações de inserção e/ou remoção por sua extensão. Porém, apesar disso, a característica forte desse modelo é sua capacidade de se auto balancear e corrigir esse possível problema. Para que esse balanceamento aconteça, é necessário portanto que alguns protocolos sejam seguidos durante o método de inserção:

1. Se a árvore está vazia, crie um nó raiz na cor preta
2. Se a árvore não está vazia, crie um nó folha na cor vermelha
3. Se o pai do novo nó é preto, não são necessárias alterações
4. Se o pai do novo nó é vermelho, é necessário verificar o nó tio deste novo nó
    - Se o nó tio é preto ou nulo, rotacionar e recolorir os nós
    - Se o nó tio é vermelho, recolorir e depois roatacionar. Verificar se o avô do novo nó não é a raiz e então recolorir e revisar

**obs:** as operações de remoção não foram utilizadas e portanto suas regras não serão definidas por esse documento uma vez que o trabalho não fez necessário esse método.

Sendo assim, o principal desafio de implementação eram as regras de rotações que eram a chave para que ao final do processo a estrutura estivesse totalmente de acordo com as regras gerais da RB. Para tanto ao início, fiz a tentativa de implementar utilizando a forma recursiva, assim como foram feitas a BST e AVL, além disso utilizando a estrutura de ponteiros de ponteiro (**) para manipulação da memória, possível nessa linguagem. Porém, a claridade da escrita não era um fator de destaque no código, isso somado as fortes recomendações de sites e fóruns para o abandono do modelo recursivo para esse tipo abstrato de dado. Sendo assim, optei por uma mudança geral que ao final possibilitou a inserção de itens para qualquer caso.
Para tanto, deixei de lado o método recursivo, substituindo por um loop e alterando o acesso a memória para trabalhar apenas com ponteiros simples (*). Fazendo isso, consegui uma melhor claridade na escrita e foi possível melhores observações no código para fazer trocas de endereço e/ou valor da memória e assim definir a posição correta a se fazer as rotações.

Por fim, restava apenas a disposição das três árvores para atender a demanda de armazenar as entradas de 1.000, 10.000 e 1.000.000 de valores, provenientes de uma base de números gerados aleatoriamente do tipo ponto flutuante (double). A fim de localizar essa estrutura geradora de valores, ela pode ser encontrada no arquivo "generate_data.cpp" e deve ser executada separadamente do restante do projeto, utilizando o comando apresentado anteriormente, "make gen".

### **A estrutura dessas três árvores podem ser vistas em:**

**BST:** Definição de funções -> "BST.hpp"; Regras e implementação -> "BST.cpp";

**AVL:** Definição de funções -> "AVL.hpp"; Regras e implementação -> "AVL.cpp";

**RB:** Definição de funções -> "RB.hpp"; Regras e implementação -> "RB.cpp";

## **Respostas sobre a proposta**

1. Qual das estruturas é mais rápida para pesquisa e por quê?

Com base nos dados recolhidos e estruturados, nota-se, pela comparação das médias, uma diferença positiva para a árvore RB, seguida da AVL e por fim a BST em ranking de velocidade de execução durante as pesquisas. 
A explicação para a BST ser a pior base para pesquisa dentre as três apresentadas, fica pela falta de balanceamento da estrutura, que pode fazer com que sua altura chegue a registrar até mesmo um custo O(n), onde n é o número de elementos que a pertence. As árvores RB foram as de maior velocidade para a maioria dos exercícios de pesquisa, isso por ela ser uma árvore que se auto balanceia e como consequência gera dados bem agrupados, porém, não é sempre que seu balanceamento se encontra em perfeito equilíbrio pois suas regras permitem certa flexibilidade para isso, mas ainda assim ela garante um custo computacional de O(log n), sendo n também o número de elementos pertencentes. Por último, a árvore AVL chegando em um resultado intermediário entre BST e RB em função de seu tempo para pesquisas. Apesar deste modelo ter registrado tempos mais lentos em meu comparativo, são grandes o número de fontes que mostram o desempenho superior dessa estrutura se comparada a RB. A explicação para o resultado pode estar relacionado com as entradas definidas e/ou o exercício de outras tarefas durante a execução do programa. Sua vantagem em termos de procura são melhores que os tempos da RB pois o seu balanceamento não permite a mesma flexibilidade se comparado a sua "parente distante". A AVL realiza um número muito alto de rotações ao inserir e remover itens e por isso ela consegue uma maior uniformidade e garante tempos ainda melhores que as demais referenciadas. No entanto, é necessário levar em consideração os resultados recolhidos e eles podem ser observados através da tabela e gráficos abaixo:

![Search Table](https://raw.githubusercontent.com/LucasG4K/Trabalho-1/main/images/avgTime_search.png)

![Search Graph](https://raw.githubusercontent.com/LucasG4K/Trabalho-1/main/images/avgTime_search_graph.png)

2. Há diferença de tempo das inserções, o que afeta cada estrutura em termos de mecanismo de manipulação / balanceamento?

Novamente, observando os dados recolhidos é possível perceber que as estruturas BST e RB são mais eficientes para métodos de inserção. Isso acontece pois a BST não possui métodos de rotação de valores bem como qualquer correções ao inserir e remover dados, o que por outro lado acontece na RB. A estrutura da árvore RB, apesar de possuir um método de balanceamento, ela consegue bons resultados de inserção pois a partir de uma árvore uniforme com rotações pouco rígidas, é possível que se tenha uma altura menor e com isso ganhar tempo para completar esse método em particular. Esse fator atrelado aos balanceamentos feito apenas recolorindo sua estrutura lhe dá uma grande vantagem em se ter uma árvore balanceada com boa velocidade de inserção. Nas árvores AVL, apesar de sua altura não tomar grandes proporções, assim como ocorre também na RB, ela sofre com a necessidade de um balanceamento muito rígido, com várias manipulações durante o processo, logo o tempo para realizar essas tarefas é um pouco mais lento e ela acaba por ser o pior mecanismo para tarefas com foco em inserção de dados se comparado aos dois modelos anteriores. Sendo assim, o destaque para processos de inserção fica com a árvore RB. Veja abaixo na tabela e no gráfico as comparações entre as médias de tempo para cada estrutura nessa modelidade:

![Insert Table](https://raw.githubusercontent.com/LucasG4K/Trabalho-1/main/images/avgTime_insert.png)

![Insert Graph](https://raw.githubusercontent.com/LucasG4K/Trabalho-1/main/images/avgTime_insert_graph.png)

**obs:** os detalhes sobre os dados recolhidos e as medidas feitas para alcançar os valores médios apresentados podem ser conferidos no seguinte link: https://drive.google.com/drive/folders/1eTvFX0JP14Tbwr-a8sYxkgQzQBa9UvCF?usp=sharing
Nele é recomendável que o arquivo xlsx seja executado utilizando o programa Windows Excel para a manutenção dos gráficos, fórmulas dentre outros fatores.

3. Considerando as três bases de entrada, para quais você indica cada uma das estruturas e porquê?

Com os parâmetros levantados observando apenas o tempo real de processamento, é difícil que se tenha um custo computacional preciso, pois seus resultados estão diretamente ligados com os arquivos de entrada gerados e além disso a demanda de processos em segundo plano no qual a máquina está executando. Logo, a recomendação ficará tendo em vista resultados de processos de comparação mais precisos, realizados por pesquisadores da área. 

Sendo assim, as BSTs são indicadas para processos nos quais são necessário uma estrutura de armazenamento com uma elaboração mais simples e ainda assim consiga tempos generosos para inserção e busca de eventuais dados.

Já a árvore AVL pode ser utilizada em processos de armazenamento que necessitam de grandes quantidades de pesquisa de dados.

E por último, a árvore RB deverá ser uma boa referência nos projetos que se tenham uma prioridade maior nas inserções e deleções de dados.

## **Referências**

- https://www.ufjf.br/jairo_souza/files/2012/11/5-Indexa%c3%a7%c3%a3o-Arvore-Vermelho-Preta.pdf
- http://www.facom.ufu.br/~backes/gsi011/Aula12-ArvoreRB.pdf
- https://www.youtube.com/watch?v=qA02XWRTBdw&ab_channel=Jenny%27slecturesCS%2FITNET%26JRF
- https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
- https://www.tutorialandexample.com/red-black-tree-vs-avl-tree/
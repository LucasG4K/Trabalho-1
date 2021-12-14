**Comparação das estruturas tipo árvore**
=

Para esse trabalho, a proposta era que fizéssesmos a implementação de uma Árvore Rubro Negra (RB) funcional e que a partir da junção de outras duas árvores elaboradas anteriormente, a saber: Árvore Binária de Pesquisa Padrão (BST) e a Árvore AVL (AVL), produzíssemos um comparativo para verificarmos a eficiência de cada uma.

## **Instruções e referências para o uso do código**

O algoritmo atual deste repositório foi construído utilizando a linguagem C++, através do sistema operacional Windows 11 operando em ambiente Linux (WSL2 - Ubuntu -20.04). A compilação pode ser feita por meio do comando "make" e executado com "make run". O "output" e objetos (*-o) podem ser removidos com "make clean" em caso de algum erro imprevisto com compilações passadas.

## **Explicação sucinta sobre a Árvore Rubro Negra**

A Árvore Rubro Negra assim como a Árvore AVL são tipos de dados derivados da Árvore de Pesquisa Binária Padrão (BST). Assim como a BST, o propósito dessa estrutura é o armazenamento de dados e a disposição de seus valores de forma que se tenha uma resposta para pesquisa extremamente eficiente. Porém, a principal diferença é que, nesses dois tipos, faz se necessário um balanceamento respeitando regras previstas por cada tipo. Esses balanceamentos nada mais são que uma tentativa de manter a árvore com um aspecto uniforme, reconstruindo seus "galhos" mais unidos para que assim reduza o tempo de pesquisa de itens em seu escopo. Além disso, apesar da semelhança entre esse tipo e o tipo AVL (Árvores balanceadas) e uma breve semelhança com a BST, cada estrutura segue sua própria regra e portanto podem vir a ter usos e resultados diferentes, como veremos ao final da análise.

### Regras para a Árvore Rubro Negra
1. Todo nó da árvore é vermelho ou preto.
2. O nó raiz é preto.
3. Toda folha (nil) é preta.
4. Se um nó é vermelho, então seus filhos são pretos.
5. Para cada nó, todos os caminhos de um nó até seus descendentes possuem o mesmo número de nós pretos.


## **Sobre o desenvolvimento**

Seguindo com o desenvolvimento, a implementação da árvore RB também necessitava de regras para que a estrutura final estivesse de acordo com o que foi apresentado acima. Essa estrutura tem uma grande predisposição a se desbalancear ao fazer alterações de inserção e remoção em seu domínio. Mas apesar disso, a característica forte desse modelo é sua capacidade de se auto balancear. Para que esse balanceamento aconteça, é necessário que siga as seguintes regras:

1. Se a árvore está vazia, crie um nó raiz na cor preta
2. Se a árvore não está vazia, crie um nó folha na cor vermelha
3. Se o pai do novo nó é preto, não são necessárias alterações
4. Se o pai do novo nó é vermelho, é necessário verificar o nó tio deste novo nó
    - Se o nó tio é preto ou nulo, fazer uma rotacionar e recolorir os nós
    - Se o nó tio é vermelho, recolorir e depois roatacionar. Verificar se o avô do novo nó não é a raiz e então recolorir e revisar

Sendo assim, o principal desafio de implementação eram as regras de inserção que eram a chave para que ao final do processo a estrutura estivesse totalmente de acordo com as regras gerais da RB. Para tanto ao início, fiz a tentativa de implementar utilizando a forma recursiva, assim como foram feitas a BST e AVL, além disso utilizando a estrutura de ponteiros de ponteiro (**) para manipulação da memória, possível nessa linguagem. Porém, a claridade da escrita não estava concisa para mim e fiz uma mudança geral que ao final possibilitou a inserção de itens para qualquer caso.
Sendo assim, deixei de lado o método recursivo, substituindo por loop e alterando o acesso a memória para trabalhar apenas com ponteiros (*). Fazendo isso, consegui uma melhor claridade da escrita e foi possível melhores observações no código para fazer trocas de endereço e/ou valor da memória e assim definir a posição correta a se fazer as rotações.

Com isso, restava apenas a disposição das três árvores no trabalho para atender a demanda de armazenar as entradas de 1.000, 10.000 e 1.000.000 de valores, provenientes de um arquivo com base de números gerado aleatoriamente do  tipo ponto flutuante.

## **Discussão sobre os resultados**



Referências

https://www.ufjf.br/jairo_souza/files/2012/11/5-Indexa%c3%a7%c3%a3o-Arvore-Vermelho-Preta.pdf
http://www.facom.ufu.br/~backes/gsi011/Aula12-ArvoreRB.pdf
https://www.youtube.com/watch?v=qA02XWRTBdw&ab_channel=Jenny%27slecturesCS%2FITNET%26JRF
README.txt Specifications 1.0


BSTree = Binary Search Tree (Árvores de Busca Binária)
AVLTree = Árvore AVL
RBTree = Red Black Tree (Árvore Vermelho-Preta)


O código foi totalmente escrito em C e em ambiente Windows usando a IDE Code Blocks.


						~/MAKEFILE INSTRUCTIONS/~

O arquivo Makefile é uma arquivo para compilação em Linux, servindo, o mesmo arquivo, para compilar todas as árvores.


					*Árvore de Busca Binária Geral*

O arquivo default para compilação é o arquivo da Árvore BB Geral. Ou seja, caso nao seja especificado qual arquivo será compilado, este será executado caso os arquivos estejam na mesma pasta. Em caso contrário, para compilar estes arquivos propositalmente, enquanto no terminal, basta entrar no diretório onde os arquivos BSTree.c, BSTreeMain.c e header.h estão localizados, colocar o arquivo Makefile na mesma pasta e executar o comandoÇ
	make BSTree

Para executá-lo basta digitar o comando(enquanto no mesmo diretório)Ç
	./BSTree



						*Árvore AVL*

Para os arquivos da árvore AVL, no terminal, basta entrar no diretório onde os arquivos header.h, AVLTree.c e AVLTreeMain.c estão localizados e colocar o arquivo Makefile na mesma pasta(todos precisam estar na mesma pasta) e, então, executar o comando: 
	make avlTree

Para executá-lo basta digitar o comando (enquanto na mesmo diretório):
	./avlTree


					*Árvore Rubro-Negra(Vermelho-Preta)*

	Para os arquivos da árvore rubro-negra, enquanto no terminal, basta entrar no diretório onde os arquivos RBTree.c, header.h e RBTreeMain.c estão localizados e colocar o arquivo geral Makefile na mesma pasta e, então, executar o comando:
	make RBTree

Para executá-lo, basta digitar o comando(enquanto no mesmo diretório):
	./RBTree

							*HEAP*

	Para os arquivos da heap, enquanto no terminal, basta entrar no diretório onde os arquivos Heap.c, HeapMain.c e header.h estão localizados e colocar o arquivo geral Makefile na mesma pasta e, então, executar o comandoÇ
	make Heap

Para executá-lo, basta digitar o comando(enquanto no mesmo diretório) e seguir as instruções do programa:
	./Heap

O mesmo procedimento é adotado para ambas as Hashes. No hash encadeado, foi utilzado o método da multiplicação para a função. E, na hash por endereçamento aberto, a tentativa linear foi a opção escolhida.


RELATÓRIO:

- AVL Concluída
- Rubro-Negra Concluída com método remover
- Heap Concluída
- Hash Encadeada concluída
- Hash por Endereçamento aberto por tentativa linear concluída
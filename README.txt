README.txt Specifications 1.0


BSTree = Binary Search Tree (�rvores de Busca Bin�ria)
AVLTree = �rvore AVL
RBTree = Red Black Tree (�rvore Vermelho-Preta)


O c�digo foi totalmente escrito em C e em ambiente Windows usando a IDE Code Blocks.


						~/MAKEFILE INSTRUCTIONS/~

O arquivo Makefile � uma arquivo para compila��o em Linux, servindo, o mesmo arquivo, para compilar todas as �rvores.


					*�rvore de Busca Bin�ria Geral*

O arquivo default para compila��o � o arquivo da �rvore BB Geral. Ou seja, caso nao seja especificado qual arquivo ser� compilado, este ser� executado caso os arquivos estejam na mesma pasta. Em caso contr�rio, para compilar estes arquivos propositalmente, enquanto no terminal, basta entrar no diret�rio onde os arquivos BSTree.c, BSTreeMain.c e header.h est�o localizados, colocar o arquivo Makefile na mesma pasta e executar o comando�
	make BSTree

Para execut�-lo basta digitar o comando(enquanto no mesmo diret�rio)�
	./BSTree



						*�rvore AVL*

Para os arquivos da �rvore AVL, no terminal, basta entrar no diret�rio onde os arquivos header.h, AVLTree.c e AVLTreeMain.c est�o localizados e colocar o arquivo Makefile na mesma pasta(todos precisam estar na mesma pasta) e, ent�o, executar o comando: 
	make avlTree

Para execut�-lo basta digitar o comando (enquanto na mesmo diret�rio):
	./avlTree


					*�rvore Rubro-Negra(Vermelho-Preta)*

	Para os arquivos da �rvore rubro-negra, enquanto no terminal, basta entrar no diret�rio onde os arquivos RBTree.c, header.h e RBTreeMain.c est�o localizados e colocar o arquivo geral Makefile na mesma pasta e, ent�o, executar o comando:
	make RBTree

Para execut�-lo, basta digitar o comando(enquanto no mesmo diret�rio):
	./RBTree

							*HEAP*

	Para os arquivos da heap, enquanto no terminal, basta entrar no diret�rio onde os arquivos Heap.c, HeapMain.c e header.h est�o localizados e colocar o arquivo geral Makefile na mesma pasta e, ent�o, executar o comando�
	make Heap

Para execut�-lo, basta digitar o comando(enquanto no mesmo diret�rio) e seguir as instru��es do programa:
	./Heap

O mesmo procedimento � adotado para ambas as Hashes. No hash encadeado, foi utilzado o m�todo da multiplica��o para a fun��o. E, na hash por endere�amento aberto, a tentativa linear foi a op��o escolhida.


RELAT�RIO:

- AVL Conclu�da
- Rubro-Negra Conclu�da com m�todo remover
- Heap Conclu�da
- Hash Encadeada conclu�da
- Hash por Endere�amento aberto por tentativa linear conclu�da
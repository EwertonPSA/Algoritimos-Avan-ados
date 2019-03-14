#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<string>
#include<set>

#define RAINHA 49 // 48(tabela ascii) = '1'
#define VAZIO 48 // 49(tabela ascii) = '0'
#define RESTRITO 50 // 50(tabela ascii) = '2'

using namespace std;
set< string > output;
map< string, int> compute;//utilizado para podar a execucao de recursao repetidas

void bt_search_Recursive(string boardState, int nQueens, int row, int column, int sizeBoard){
	if( boardState[column*sizeBoard + row] == RESTRITO ||
			boardState[column*sizeBoard + row] == RAINHA) 
		return;

	/*Impondo restricoes da rainha*/
	for(int i = column+1, j = row+1; i < sizeBoard && j < sizeBoard; i++, j++)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra direita subindo
	for(int i = column-1, j = row-1; j >= 0 && i >= 0; i--, j--)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra direita descendo
	for(int i = column-1, j = row+1; j < sizeBoard && i >= 0; i--, j++)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra esquerda subindo	
	for(int i = column+1, j = row-1; j >= 0 && i < sizeBoard; i++, j--)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra esquerda subindo
	for(int i = 0; i < sizeBoard; i++){
		boardState[column*sizeBoard + i] = RESTRITO;
		boardState[i*sizeBoard + row] = RESTRITO;
	}

	boardState[column*sizeBoard + row] = RAINHA;//Coloca a rainha
	nQueens++;
	
	if(nQueens == sizeBoard){
		string sequencia = "";
		char aux[1];
		for(int	i = 0; i < sizeBoard; i++)
			for(int j = 0; j < sizeBoard; j++)
				if(boardState[i*sizeBoard + j] == RAINHA){
					aux[0] = (char)(j+1+VAZIO); //"letra"+'0'
					sequencia = sequencia + aux;
				}
		output.insert(sequencia);
		sequencia.clear();
		--nQueens;
		return;
	}

	//Se essa recursao foi computada entao eu podo a chamada
	if(compute.find(boardState) != compute.end()){
		//Se boardState for encontrada no map eh pq ele ja foi computada
		return;
	}else{//Caso a recursao nao tenha sido computada, entao começa a computar as possibilidades
		for(int i = 0; i < sizeBoard; i++)
			for(int j = 0; j < sizeBoard; j++)
				bt_search_Recursive(boardState, nQueens, i, j, sizeBoard);
		--nQueens;
		compute.insert(pair<string, int>(boardState, 1));
	}
}

void bt_search(int row, int column, int sizeBoard){
	string boardState = "";
	string auxiliar = "0";
	string palavra = "";

	//Preenchendo uma palavra com uma coluna do tabuleiro de forma que se encontre vazio
	for(int i = 0; i < sizeBoard; i++)
		palavra = palavra + auxiliar;

	//juntando todas as colunas do tabueleiro pra formar um tabuelrio completo
	for(int i = 0; i < sizeBoard; i++)
		boardState = boardState + palavra;

	/*Impondo restricoes da rainha*/
	for(int i = column+1, j = row+1; i < sizeBoard && j < sizeBoard; i++, j++)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra direita subindo
	for(int i = column-1, j = row-1; j >= 0 && i >= 0; i--, j--)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra direita descendo
	for(int i = column-1, j = row+1; j < sizeBoard && i >= 0; i--, j++)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra esquerda subindo	
	for(int i = column+1, j = row-1; j >= 0 && i < sizeBoard; i++, j--)
			boardState[i*sizeBoard + j] = RESTRITO;//Restringindo na diagonal pra esquerda subindo

	for(int i = 0; i < sizeBoard; i++){/*Preenchendo as horizontais*/
		boardState[column*sizeBoard + i] = RESTRITO;
		boardState[i*sizeBoard + row] = RESTRITO;
	}

	boardState[column*sizeBoard + row] = RAINHA;//Coloca a rainha

	int nQueens = 0;
	for(int i = 0; i < sizeBoard; i++)
		for(int j = 0; j < sizeBoard; j++)
			bt_search_Recursive(boardState, nQueens+1, i, j, sizeBoard);
}

int main( int argc, char* argv [] ) {
	int sizeBoard, row, column;

	while(scanf("%d", &sizeBoard) != EOF){
		/*A cada sizeBoard*sizeof(char) de board temos uma nova coluna do tabuleiro
		 *E cada sizeof(char) de board tem uma nova linha do tabuleiro*/
		scanf("%d %d", &row, &column);
		/*Objetivo eh fazer um backtracking eficiente(COM PODA) ateh 
		 *Que o numero de nQueens(number of queens) chegue ao numero de linhas(sizeBoard)*/
		bt_search(row-1, column-1, sizeBoard);

		printf("Solution\n");
		string aux;
		for(set<string>::iterator it = output.begin(); it != output.end(); ++it){
			aux = *it;

			for(int i = 0; i < (int)aux.size(); i++)
				printf("%c ", aux[i]);
			printf("\n");
		}
		compute.clear();
		output.clear();
	}
}

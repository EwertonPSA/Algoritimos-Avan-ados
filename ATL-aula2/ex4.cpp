#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;

typedef struct ordem ORDENA;
typedef struct{
	int size;//Guarda o tamanho dessa caixa
	int numLigacoes;//Numero de caixas que essa caixa guarda
	int* next;//Sequencia ordenada que contera as caixas ordenada de forma descrescente
}CAIXAS;

struct ordem{//Estrutura auxiliar pra ordenar as caixas
	int id;
	int size;	
};

bool operator<(const ordem& t, const ordem& p){
	return (t.size < p.size);
}

bool operator==(const ordem& t, const ordem& p){
	return (t.size == p.size);
}


bool ordenacao_Maior_Caixa_Na_Frente(ORDENA m1, ORDENA m2){
	return (m1.size > m2.size);
}

void desalocaEspaco(CAIXAS* box, int numPresent){
	for(int i = 0; i < numPresent; i++)
		if(box[i].numLigacoes != 0)
			free(box[i].next);
}

int main(int argc, char* argv [] ) {
	int numPresent, numBox, tired;
	ORDENA temp;
	scanf("%d %d %d", &numPresent, &numBox, &tired);
	CAIXAS box[numPresent];
	priority_queue<ORDENA> ligacoes;
	//Em cada NO do vetor eh registrado o tamanho da caixa
	for(int i = 0; i < numPresent; i++)
		scanf("%d", &box[i].size);

	//Obtendo as ligacoes entre as caixas
	for(int i = 0; i < numPresent; i++){
		scanf("%d", &(box[i].numLigacoes));
		
		if(box[i].numLigacoes != 0){
			//Preciso obter ligacoes de forma sequencial
			//Ordenada
			box[i].next = (int*)malloc(sizeof(int)*(box[i].numLigacoes));
			for(int j = 0; j < box[i].numLigacoes; j++){
				scanf("%d", &temp.id);
				temp.id = temp.id-1;
				temp.size = box[temp.id].size;
				ligacoes.push(temp);
			}

			//Repassando pra aquela caixa a sequencia de ligacoes
			//Em ordem descrescente
			for(int j = 0; j < box[i].numLigacoes; j++){
				box[i].next[j] = (ligacoes.top().id);
				ligacoes.pop();
			}
		}
	}

	//Aqui verifico quais as caixas se encontram em baixo da arvore
	//E busco qual eh a maior pra realizar a busca
	for(int i = 0; i < numBox; i++){
		scanf("%d", &temp.id);
		temp.id = temp.id-1;
		temp.size = box[temp.id].size;
		ligacoes.push(temp);
	}

	int numPresentesAbertos = 0;
	int presentesEncontrados = 0;
	int id;
	while(numPresentesAbertos < tired){			
		numPresentesAbertos++;
		id = ligacoes.top().id;
		ligacoes.pop();
		if(box[id].numLigacoes == 0) //Encontrei um presente
			presentesEncontrados++;
		else{
			for(int i = 0; i < box[id].numLigacoes; i++){
				temp.id = box[id].next[i];
				temp.size = box[temp.id].size;
				ligacoes.push(temp);
			}	
		}
	}
	printf("%d\n", presentesEncontrados);
	desalocaEspaco(box, numPresent);
}

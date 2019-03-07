#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

int main( int argc, char* argv [] ) {
	int num, in_out, number, same, problem = 0;
	queue<int> lista;
	stack<int> pilha;
	priority_queue<int> fila_prioridade;
	int qualificacao[3] = {0,0,0};
	//printf("[0]=queue, [1]=stack, [2]=prio\n");
	while(cin >> num){
		
		for(int i = 0; i < num; i++){
			scanf("%d %d", &in_out, &number);
			if(in_out == 1){
				lista.push(number);
				pilha.push(number);
				fila_prioridade.push(number);
			}else if(in_out == 2){
				int aux;
				if(lista.empty() == true || pilha.empty() == true || fila_prioridade.empty() == true){
			//		printf("EIIIII\n");
					problem = 1;
				}
				if(qualificacao[0] >= 0 && lista.empty() == false){
					aux = lista.front();
					qualificacao[0] = (aux == number) + (-10)*(aux != number);
					lista.pop();
				}
				
				if(qualificacao[1] >= 0 && pilha.empty() == false){
					aux = pilha.top();
					qualificacao[1] = (aux == number) + (-10)*(aux != number);
					pilha.pop();
				}

				if(qualificacao[2] >= 0 && fila_prioridade.empty() == false){
					aux = fila_prioridade.top();
					qualificacao[2] = (aux == number) + (-10)*(aux != number);
					fila_prioridade.pop();
				}

				
			//printf("Quali[0] = %d, [1] = %d, [2] = %d\n------------------------------------------\n", qualificacao[0],qualificacao[1],qualificacao[2]);
			}
		}
		number = same = 0;
		number = number + (qualificacao[0] > 0 && problem != 1) + (qualificacao[1] > 0 && problem != 1) + (qualificacao[2] > 0 && problem != 1);
		same = (qualificacao[0] == 0 && qualificacao[1] == 0 && qualificacao[2] == 0 && problem == 0);

		//printf("Number: %d num: %d problem:%d qual[0]=%d qual[1]=%d qual[2]=%d\n", num, number, problem, qualificacao[0], qualificacao[1], qualificacao[2]);
		if(number > 1 || same == 1)printf("not sure\n");
		else if(problem == 1) printf("impossible\n");
		else if(qualificacao[0] > 0) printf("queue\n");
		else if(qualificacao[1] > 0) printf("stack\n");
		else if(qualificacao[2] > 0) printf("priority queue\n");
		else printf("impossible\n");

		while(lista.empty() == false) lista.pop();
		while(pilha.empty() == false) pilha.pop();
		while(fila_prioridade.empty() == false) fila_prioridade.pop();
		qualificacao[0] = qualificacao[1] = qualificacao[2] = 0;
		problem = 0;
//		printf("\n");
	}

}

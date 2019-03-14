#include<cstdio>
#include<iostream>
#include<list>

using namespace std;

list< list<int> > output;
list<int> sequencia;
bool minha_ordenacao(list<int> m1, list<int> m2){
	return (m1 > m2);
}

void search_bt_recursive(int* vector, int numVector, int sum, int sumRecursive, int pos){
	if(sumRecursive == sum){
		output.push_back(sequencia);
		return;
	}else if(pos >= numVector || sumRecursive > sum)
		return;
	
	for(int i = pos+1; i < numVector; i++){

		sequencia.push_back(vector[i]);
		search_bt_recursive(vector, numVector, sum, sumRecursive+vector[i], i);
		sequencia.pop_back();
	}
}

void search_bt(int* vector, int numVector, int sum){
	int sumRecursive = 0;

	for(int i = 0; i < numVector; i++){
		sequencia.push_back(vector[i]);
		search_bt_recursive(vector, numVector, sum, sumRecursive+vector[i], i);
		sequencia.pop_back();
	}
}

int main( int argc, char* argv [] ) {
	int numVector, sum;

	scanf("%d %d", &sum, &numVector);
	while (numVector != 0 && sum != 0){
		int vector[numVector];
		for(int i = 0; i < numVector; i++)
			scanf("%d", &vector[i]);
		
		search_bt(vector, numVector, sum);

		output.unique();
		output.sort(minha_ordenacao);

		printf("Sums of %d:\n", sum);
		/*Organiza todos numeros em um vetor e realiza um backtracking
		 *Buscando todas as possibilidades no qual a soma resulte em valor(variavel sum)
		 *Em seguir eh organizado todas os resultado na ordem decrescente*/
		if( output.size() != 0){	
			for(list< list<int> >::iterator it = output.begin(); it != output.end(); it++){
				int i = 0;
				for(list<int>::iterator aux = (*it).begin(); aux != (*it).end() ; aux++, i++){
					if(i == 0) printf("%d", *aux);
					else if(i < (int)((*it).size())) printf("+%d", *aux);
					else printf("%d", *aux);
				}
				printf("\n");
			}
		}else printf("NONE\n");

		output.clear();
		scanf("%d %d", &sum, &numVector);
	}
}

#include<list>
#include<set>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(int argc, char* argv [] ) {
	list< set<int> > testando;
	set <int> sequencia;
	list <int> numRepeticoes;
	list <int>::iterator m2, m3;

	list< set<int> >::iterator m1;
	int disciplinas[100];
	int numInscricoes, num;

	/*A ideia desse codigo eh armazenas todas as informacoes em set para nao que eles estajam ordenados
	 *Esses sets sao armazenados na lista, conforme coleto novos set verifico se ele 
	 *ja se encontra na lista(operador == para compara-los). A variavel "discplinas" computa
	 *Quantas vezes aquele set ja apareceu na lista */
	scanf("%d", &numInscricoes);
	do{
		
		for(int j = 0; j < numInscricoes; j++){
			disciplinas[j] = 0;
			for(int i = 0; i < 5; i++){
				scanf("%d", &num);
				sequencia.insert(num);
			}
			
			m1 = testando.begin();
			int position = 0;
			for(; position < (int)testando.size() && 
					 sequencia != (*m1); position++, m1++);
			if(position == (int)testando.size()){
				/*Aqui estamos no final da lista, ou seja, se chegou nesse ponto eh pq nao existe nenhum 
				  set(variavel sequencia) que seja igual a outro set na lista(variavel testando)*/
				testando.push_back(sequencia);
				disciplinas[position]++;
			}else{
				disciplinas[position]++;
			}
			sequencia.clear();
		}
		for(int j = 0; j < numInscricoes; j++){/*Repasso o numero de vezes que as discplinas aparecem*/
			numRepeticoes.push_back((int)disciplinas[j]);
		}
		numRepeticoes.sort();

		m2 = numRepeticoes.end();
		m2--;
		m3 = m2;
		num = 0;
		
		/*Computo a popularidade da discplinas que mais apareceram, 
		 *somando o numero de vezes que as mais populares apareceram*/
		do{
			num = num + *(m3--);
		}while( m3 != numRepeticoes.begin() && *m2 == *m3);
		num = num + (*m3)*(m3 == numRepeticoes.begin());
		printf("%d\n", num);
		numRepeticoes.clear();
		testando.clear();
		scanf("%d", &numInscricoes);

	}while(numInscricoes != 0);
}

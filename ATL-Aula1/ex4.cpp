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

	/*A ideia desse codigo eh armazenas todas as informacoes
	 *Na lista e retirar todos numeros repetidos, como sei que havera
	 *Sempre 5 materias que cada aluno seleciona em cada linha entao
	 *Ao retirar o numero*/
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
				testando.push_back(sequencia);
				disciplinas[position]++;
			}else{
				disciplinas[position]++;
			}
			sequencia.clear();
		}
		for(int j = 0; j < numInscricoes; j++){
			numRepeticoes.push_back((int)disciplinas[j]);
		}
		numRepeticoes.sort();

		m2 = numRepeticoes.end();
		m2--;
		m3 = m2;
		num = 0;
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

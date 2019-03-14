#include<cstdio>
#include<list>
#include<iostream>

using namespace std;

bool ordenacao( const list<int> m1, const list<int> m2){
	return (*m1.begin() < *m2.begin());
}

int main( int argc, char* argv [] ) {
	list< list<int> > resposta;
	list<int> sequencia;
	int a, b, c;
	int eq1[3], eq2[3], eq3[3];
	int num;
	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		scanf("%d %d %d", &a, &b, &c);

		for(int x = 0; x <= 100; x++){
			eq1[0] = eq2[0] = eq3[0] = x;
			eq3[0] = eq3[0]*eq3[0];

			for(int y = 0; y <= 100; y++){
				eq1[1] = eq2[1] = eq3[1] = y;
				eq3[1] = eq3[1]*eq3[1];

				for(int z = 0; z <= 100; z++){
					eq1[2] = eq2[2] = eq3[2] = z;
					eq3[2] = eq3[2]*eq3[2];
					
					if(eq1[0] + eq1[1] + eq1[2] == a &&
						eq2[0]*eq2[1]*eq2[2] == b &&
							eq3[0] + eq3[1] + eq3[2] == c){
						sequencia.push_back(x);
						sequencia.push_back(y);
						sequencia.push_back(z);
						resposta.push_back(sequencia);
						sequencia.clear();
					}
				}
			}
		}
		if(resposta.empty()) printf("No solution.\n");
		else{
			if(resposta.size() > 1)
				resposta.sort(ordenacao);
			sequencia = *(resposta.begin());
			int x, y, z;
			x = *sequencia.begin();
			sequencia.pop_front();
			y = *sequencia.begin();
			sequencia.pop_front();
			z = *sequencia.begin();
			sequencia.pop_front();
			printf("%d %d %d\n", x, y, z);
		}
	}
}

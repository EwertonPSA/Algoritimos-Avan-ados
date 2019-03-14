#include<cstdio>
#include<iostream>

int verifica_Se_Eh_Primo(int num){
	for(int i = 2; i < num; i++)
		if(num%i == 0) return 0;
	return 1;
}

void bt_recursive(int* numeros, int* possibilidade, int num, int preenchidos){
	char verifica = 0;
		//Se os adjacentes nao forem primos entao retorna
	if(preenchidos > 1){
		if(verifica_Se_Eh_Primo(possibilidade[preenchidos-1] + possibilidade[preenchidos-2])== 0) 
			return;
		if(preenchidos == num){
			if(verifica_Se_Eh_Primo(possibilidade[0]+possibilidade[preenchidos-1]) == 1){
				for(int i = 0; i < num; i++) printf("%d ", possibilidade[i]);
				printf("\n");
			}
			return;	
		}
	}
	for(int i = 0; i < num; i++){
		if(numeros[i] != 0){
			int aux = numeros[i];
			numeros[i] = 0;
			possibilidade[preenchidos] = aux;
			
			bt_recursive(numeros, possibilidade, num, preenchidos+1);
			numeros[i] = aux;
		}
	}
}

void bt_search(int* numeros ,int* possibilidade, int num){
	int preenchidos = 0;
	possibilidade[0] = 1;//O exercicio pede que a saida seja numeros que comecem com 1
	numeros[0] = 0;
	preenchidos++;
	for(int i = 1; i < num; i++){
		if(numeros[i] != 0){
			int aux = numeros[i];//Pega o numero disponivel 
			numeros[i] = 0;
			possibilidade[preenchidos] = aux;//Coloca como possibilidade e computa
			
			bt_recursive(numeros, possibilidade, num, preenchidos+1);
			numeros[i] = aux;
		}
	}
}

int main(int argc, char* argv [] ) {

	int num;
	int round = 1;
	while(EOF != scanf("%d", &num)){
		int possibilidades[num];
		int numeros[num];//Guarda os numeros que posso escolher
		for(int i = 1; i <= num; i++)
			numeros[i-1] = i;
		if(round != 1) printf("\nCase %d:\n", round);
		else printf("Case %d:\n", round);
		bt_search(numeros, possibilidades, num);
		round++;
	}
}

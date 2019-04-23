#include<stdio.h>
#include<limits.h>
int validacao(int* paradas, int n, int deslocamento, int k){
	//Continua computando a informaçao enquanto o deslocamento
	//for maior que as distancias entre os acampamentos,
	//Pois se a distancia for menor significa que nao consigo chegar 
	//ao proximo acampamento, necessitando aumentar a distancia(left = centro+1)
	int distanciaTotal = 0, acampar = 0, i;

	for(i = 0; i <= n && paradas[i] < deslocamento; i++){

		//Agora preciso saber quantos acampamentos consigo passar
		//Com esse deslocamento, para isso faço o seguinte esquema:
		//-Se a soma das distancias entre os acampamentos que passei + a
		// distancia entre os acampamento que estou passando for
		//  -MENOR que o deslocamento que faço
		//    ->Entao incluo ela na lista de acampamentos passados
		//  -MAIOR  que o deslocamento que faço
		//    ->Eu paro antes pra acampar(sem percorrer a distancia pro proximo
		//    ->acampamento e avalio depois retomo a viagem
		if(distanciaTotal + paradas[i] < deslocamento) distanciaTotal+=paradas[i];
		else{
			distanciaTotal = paradas[i];
			acampar++;
		}
	}

	//Retorna 0(aumenta o left) => Se nao ocorrer (i <= n) significa que a distancia de deslocamento pra andar 
	//em 1 dia foi inferior a distancia entre acampamentos, isso nao pode ocorrer, ai
	//Devo Aumentar o deslocamento(left = deslocamento+1). 
	//Retorna 1(Reuz o right) => Se o numero de vezes que foi acampado eh menor ou igual a numero permitido e se o deslocamento
	//Esta a cima das distancias entre os acampamentos
	return (!(i <= n) && acampar <= k);
}

int main( int argc, char* argv [] ){
	int n;
	int k;
	while(scanf("%d %d", &n, &k) != EOF){
		int paradas[n+1];
		int rotaTotal = 0;
		for(int i = 0; i <= n; i++){
			scanf("%d", &paradas[i]);
			rotaTotal += paradas[i];
		}

		int left = 0;
		int right = rotaTotal;
		int centro;
		int deslocamento = rotaTotal;//Defini inicialmente o deslocamento como sendo o maximo possivel
		while(left <= right){
			centro = left + (right-left+1)/2;

			//Verifica qual ajuste tem que ser feito na distancia
			if(validacao(paradas, n, centro, k)) {
				//Como o deslocamento foi definido como a rota maxima entao ele soh diminui quando o right for alterado
				if(centro < deslocamento)//Como desejo o menor deslocamento entao seleciono o mais adequado entre o centro ou o deslocamento anteriormente estabelecido
					deslocamento = centro;
				right = centro-1;
			}else left = centro+1;
		}
		printf("%d\n", left-1);
	}
}
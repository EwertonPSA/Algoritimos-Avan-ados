#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main( int argc, char* argv[]){
	double consumoComb, km, auxKm, tank, usoGaz, estrada, leak;
	string evento;
	consumoComb = km = auxKm = tank = usoGaz = leak = 0;

	while(true){
		scanf("%lf", &km);
		cin >> evento;

		estrada = km - auxKm;
		auxKm = km;
		usoGaz = usoGaz + leak*estrada;
		usoGaz = usoGaz + consumoComb*estrada/100;

		//Vazamento(leak) zera se tiver o mecanico
		//Se aparecer mais vazamento(leak) ele apenas eh incrementado
		leak = leak*(!(evento == "Mechanic")) + (evento == "Leak");
		if(evento == "Fuel"){
			cin >> evento;//Retiro a string "consumption"
			scanf("%lf", &consumoComb);
			if(consumoComb == 0) return 0;//Chegou ao fim
		}else if(evento == "Gas"){
			cin >> evento;//Retira a string "station"
			if(usoGaz > tank)
				tank = usoGaz;
			usoGaz = 0;
		}else if(evento == "Goal"){
			if(usoGaz > tank)
				tank = usoGaz;
			usoGaz = 0;
			printf("%.3lf\n", tank);
			tank = leak = auxKm = 0;
		}
	}
}

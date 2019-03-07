#include<cstdio>
#include<map>
#include<list>
#include<cstring>

using namespace std;

typedef struct{
	int id;
	int period;
}REGISTRO;

bool ordenacao_id_first_period_second(REGISTRO m1, REGISTRO m2){
	if(m1.period != m2.period)
		return (m1.period < m2.period);
	return (m1.id < m2.id);
}

int main(int argc, char* argv []) {
	map <int, int> referencia;
	REGISTRO temporario;
	char funcao[9];
	int num, periodo;
	list <REGISTRO> argus;
	list <REGISTRO>::iterator argusAux;
	scanf("%s", funcao);
	while(!strcmp(funcao,"Register")){
		scanf("%d %d", &temporario.id, &temporario.period);
		argus.push_back(temporario);
		referencia.insert(pair<int, int>(temporario.id, temporario.period));
		scanf("%s", funcao);
	}
	if(!strcmp(funcao, "#")){
		scanf("%d", &num);
		argus.sort(ordenacao_id_first_period_second);
		for(int i = 0; i < num; i++){
			argusAux = argus.begin();
			argus.pop_front();

			temporario.id = (*argusAux).id;
			temporario.period = (*argusAux).period;

			printf("%d\n", (*argusAux).id);
			temporario.period = temporario.period + referencia.find(temporario.id)->second;
			argus.push_back(temporario);
			argus.sort(ordenacao_id_first_period_second);
		}
	}
}

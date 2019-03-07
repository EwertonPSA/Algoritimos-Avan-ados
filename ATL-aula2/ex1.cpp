#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

int main( int argc, char* argv [] ) {
	int numV, aux;
	vector<int> v1;
	scanf("%d", &numV);
	char palavra[numV];

	for(int i = 0; i < numV; i++){
		scanf("%d", &aux);
		v1.push_back(aux);
	}

	
	scanf("%s", palavra);


	for(int i = 0; i < numV - 1; i++){
		if(palavra[i] == '1' && v1[i] > v1[i+1]){
			aux = v1[i];
			v1[i] = v1[i+1];
			v1[i+1] = aux;
		}
	}
	int count = 0;
	for(int i = 0; i < numV-1; i++)
		count = count + (v1[i] < v1[i+1]);
	
	if(count == numV - 1) printf("YES\n");
	else printf("NO\n");

}

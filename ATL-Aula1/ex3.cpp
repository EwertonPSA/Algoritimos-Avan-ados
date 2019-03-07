#include<list>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main( int argc, char* argv [] ) {
	list <int> numbers;
	int numOfNumbers, element;
	scanf("%d", &numOfNumbers);
	for(int i = 0; i < numOfNumbers; i++){
		scanf("%d", &element);
		numbers.push_back(element);
	}
	numbers.sort();
	numbers.unique();
	printf("%d\n", (int)numbers.size());	
}

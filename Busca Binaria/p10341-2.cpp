#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

double operation(int p, int q, int r, int s, int t, int u, double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main( int argc, char* argv[]){
	int p, q, r, s, t, u;
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		if(operation(p, q, r, s, t, u, 0)*operation(p, q, r, s, t, u, 1) > 0)
			printf("No solution\n");
		else{
			double left = 0;
			double right = 1;
			double middle = (right + left )/ 2;
			double result = operation(p, q, r, s, t, u, middle);

			for(int i = 0; i < 100; i++){
				middle = (right+left)/2;
				result = operation(p, q, r, s, t, u, middle);
				if(result < 0) right = middle;
				else left = middle;
			}
			printf("%.4lf\n", left);
		}
	}
}

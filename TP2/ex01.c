#include <stdio.h>

float f(float x){
	return x;
}

float  rectangledroite(float(*f)(float),float a, float b, int n){
    float h=(a+b)/n;
    float sum=0;
    for (int i=1;i<=n;i++)
        sum+= (*f)(a+i*h)*h;
    return sum;
    }

float  rectanglegauche(float(*f)(float),float a, float b, int n){
    float h=(a+b)/n;
    float sum=0;
    for (int i=0; i<n; i++)
        sum+= (*f)(a+i*h)*h;
    return sum;
    }

float trapez(float(f)(float), float a, float b, int n){
	float h = (a+b) / n;
	float sum = 0;
	for(int i = 1; i < n; i++){
		sum += f(h*i);
	}
	sum += (f(a)+f(b))/2;
	return sum;
}	


int main()
{
    float droite = rectangledroite(f,0, 1, 10);
    printf("rectangledroite = %f \n", droite);
    float gauche = rectanglegauche(f, 0, 1, 10);
    printf("rectanglegauche = %f \n", gauche);
    float trapezmethod = trapez(f, 0, 1, 10);
    printf("trapez = %f \n", trapezmethod);
    return 0;


}



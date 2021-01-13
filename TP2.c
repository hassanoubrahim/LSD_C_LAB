#include <stdio.h>
#include<math.h>
//exercice 1
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


float simpson(float(*f)(float),float a,float b,int n){
    float h=(b-a)/n,x=a+h,z=a+h/2,I1=0,I2=f(z);
    for(int i=0;i<n-1;i++){
        z+=h;
        I1+=f(x);
        I2+=f(z);
        x+=h;
    }
    return(h/6)*(f(a) + f(b) + 2*I1 + 4*I2);
}

//exercice3
int nb_nec(double(*f)(double),double a, double b,double Err,double (*Methode)(double(*)(double),double,double,int),double exacte)
{
	int n=1;
	while ((Methode(f,a,b,n)-exacte)> Err || (Methode(f,a,b,n)-exacte)< -Err){
		n+=1;
	}
	return n;
}



int main()
{
    float droite = rectangledroite(f,0, 1, 10);
    printf("rectangledroite = %f \n", droite);
    float gauche = rectanglegauche(f, 0, 1, 10);
    printf("rectanglegauche = %f \n", gauche);
    float trapezmethod = trapez(f, 0, 1, 10);
    printf("trapez = %f \n", trapezmethod);
    float simpsonmethode = simpson(f, 0, 1, 10);
    printf("simpson = %f \n", simpsonmethode);
    return 0;


}





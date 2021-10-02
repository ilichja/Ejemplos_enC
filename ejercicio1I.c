/* 
**Ejercicio 1-Intermedio: Calculadora algebraica**
**Hernandez Mendez Jaime Ilich**
**22 de agosto de 2021**
**Descripcion: programa que desplga una calculadora ue permite calcular raices de de ecuaciones
lineales, cuadraticas y cubicas.**
*/

#include<stdio.h>
#include<math.h>

/*estructura que almacena los coeficientes de las funciones cuadraticas y cubicas*/
struct fun{double a0;double a1; double a2; double a3;}; 


// funcion que calcula la raiz de una funcion lineal
int lineal (double a0,double a1){
    double raiz;
    if (a1!=0)
    {
        raiz=-a0/a1;
        printf("La raiz de la funcion es: %lf",raiz);
    } else{ // Si a1 es cero
        if (a0!=0)// y a0 es distinto de cero
        {
            printf("La ecuacion no tiene solucion\n");
        }  else{
            printf("solucion indeterminada\n"); //tanto a0 como a1 iguales a cero
        }
        
    }    
    return 0; 
}


// funcion que calcula las raices de una funcion cuadratica
int cuadra(double a0, double a1,double a2){
    double discriminante, raiz1, raiz2,c1,c2;
    //Calculo del discriminante para determinar si la funcion tiene raices en R o C
    discriminante=pow(a1,2)-(4*a2*a0);
    if (discriminante<0)//si el discriminante es menor a cero, se imprime la parte imaginaria 
    {                   // y la parte real por separado
        discriminante=discriminante*-1;
        c1=-a1/(2*a2);
        c2=sqrt(discriminante)/(2*a2);
        printf("Las raices de la ecuacion son: %lf (+/-) i%lf\n",c1,c2);
    }//La parte del else imprime las raices si estas son reales.
    else{
        raiz1=(-a1+sqrt(discriminante))/(2*a2);
        raiz2=(-a1-sqrt(discriminante))/(2*a2);
        printf("LAs raices de la ecuacion son:\n");
        printf("X1: %lf\n",raiz1);
        printf("X2: %lf\n",raiz2);
    }
    return 0;
}
//funci´on signo, regresa 1, 0 o -1 si el argumento es mayor que 0, 0 o menor que 0, repectivamente.
//usada en la funcion cubi
int sgn(double a){
    int signo;
    if (a>0)
    {
        signo=1;
    } else if (a==0)
    {
        signo=0;
    } else if (a<0)
    {
        signo=-1;
    }
    return signo;
}

/*Funcion para calcular las raices de una ecuacion cubica.
 Algoritmo matematico tomado de:
 William H. Press, Flannery, B. P., Teukolsky, S. A., Vetterling, W. T., & Press, W. H. (1992). 
    Evaluation of functions: quadratic and cubic equations. En Numerical Recipes in C (2.a ed., pp. 183–185). 
    Cambridge University Press.
*/
int cubi(double a0, double a1, double a2, double a3){
    double a,b,c,Q,R,theta,r1,r2,r3,A,B,im;
    const double pi=3;//revisar est´a paerte ooooooooojjjjjjjjjjjjjjjjjjjjjjooooooooooo
    a=a2/a3;
    b=a1/a3;
    c=a0/a3;
    Q=(pow(a,2)-(3*b))/9;
    R=((2*pow(a,3))-(9*a*b)+(27*c))/54;
    if (R*R<Q*Q*Q)
    {
        theta=acos(R/sqrt(Q*Q*Q));
        r1=-2*sqrt(Q)*cos(theta/3)-(a/3);
        r2=-2*sqrt(Q)*cos((theta+(2*pi))/3)-(a/3);
        r3=-2*sqrt(Q)*cos((theta-(2*pi))/3)-(a/3);
        printf("Las raices son:\n");
        printf("raiz 1: %lf\n",r1);
        printf("raiz 2: %lf\n",r2);
        printf("raiz 3: %lf\n",r3);
    } else{
        A=-sgn(R)*pow(abs(R)+sqrt((R*R)-(Q*Q*Q)),1/3);
        if (A!=0)
        {
            B=Q/A;
        } else{
            B=0;
        }
        r1=(A+B)-(a/3);
        r2=-(0.5*(A+B))-(a/3);
        im=(sqrt(3)/2)*(A-B);
        printf("Las raices son:\n");
        printf("raiz 1: %lf\n",r1);
        printf("raiz 2: %lf + i%lf\n",r2,im);
        printf("raiz 3: %lf - i%lf\n",r2,im);
    }
    return 0;
}

int main(){
    int selector;
    do
    {
        int tipo;
        double a,b,c,d;
        printf("Calculadora de raices para funciones lineales, cuadraticas y cubicas.\n");
        printf("De la forma f(x)=a0 + a1x + a2x^2 + a3x^3, con ai coeficientes REALES.\n");
        printf("Selecciona 1, 2 o 3 para el tipo de funcion a la que deseas calcular sus raices:\n");
        printf("1: lineal\t 2: cuadratica\t 3: cubica\t \n");
        scanf("%d",&tipo);
        printf("Introduce los coeficientes en orden a0, a1, a2 y a3 separados por espacios.\n");
        printf("NOTA: En caso de tu funcion no sea cubica o cuadratica, introduce 0 para los coeficientes a2 y a3\n");
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        struct fun valor={a,b,c,d};
        switch (tipo)
        {
        case 1:
            lineal(valor.a0,valor.a1);
            break;
        case 2:
            cuadra(valor.a0,valor.a1,valor.a2);
            break;
        case 3:
            cubi(valor.a0,valor.a1,valor.a2,valor.a3);
            break;
        default:
            printf("Selecciona una opcion\n");
            break;
        }
        printf("Presiona 1 para regresar a la calculadora\n o 0 para salir\n");
        scanf("%d",&selector);
    } while (selector==1);
    

return 0;
}

/* https://www.abrirllave.com/c/ejemplo-menu-de-opciones.php
revisar para mejora el menu de seleccion 
Calculadora online de raices de funiones cubicas
https://es.planetcalc.com/1122/
*/








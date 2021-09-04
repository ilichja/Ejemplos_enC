/* 
**Ejercicio 2: Operaciones aritmetica con variables de diferentes tipos**
**Hernandez Mendez Jaime Ilich**
**22 de agosto de 2021**
**Descripcion: Programa que pide 2 numeros al usuario y
               realiza las cuatro operaciones aritmeticas
               basicas: +, -, * y /**
*/

#include<stdio.h>

int main()
{
    double a,b;
    /*printf("Introduce un numero: ");
    scanf("%lf",&a);
    printf("Introduce otro numero distinto de 0: ");
    scanf("%lf",&b); */
    printf("Introduce dos numeros a, b separadas por un espacio\n para hacer las cuato operaciones aritmeticas basicas:\n");
    scanf("%lf %lf",&a,&b);

        printf(" a + b = %lf\n",a+b);
        printf(" a - b = %lf\n",a-b);
        printf(" a * b = %lf\n",a*b);

    if (b==0)
    {
        printf("Con el valor de b = %lf la division es indeterminada",b);
    }
    
    else
    {
    printf(" a / b = %lf\n",a/b);
    }
    
    return 0;
}
/* 
**Ejercicio 1: Imprimir un menu**
**Hernandez Mendez Jaime Ilich**
**21 de agosto de 2021**
**Descripcion: Programa que despliega un menu con opciones 
y se usa el condicional if para cada una**
*/
#include <stdio.h>

int main()
{
    int n;
    printf("Selecciona una opcion de menu (ingresa el numero 1, 2 o 3):\n");
    printf("Opcion 1\n");
    printf("Opcion 2\n");
    printf("Opcion 3\n");
    scanf("%d",&n);
    if (n==1)
    {
        printf("Has seleccionado la opcion 1.\n");
    };
    if (n==2)
    {
        printf("Has seleccionado la opcion 2.\n");
    };
    if (n==3)
    {
        printf("Has seleccionado la opcion 3.\n1");
    };
    
    
    

}
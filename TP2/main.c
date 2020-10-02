#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#include "ArrayEmployees.h"

int main()
{
    eEmpleado empleados[TAM];
    int opcion;
    int o;
    do{
        printf("\n1-Altas");
        printf("\n2-Modificar");
        printf("\n3-Baja");
        printf("\n4-Informar");
        printf("\n6-Salir\n");
        printf("\nElija un opcion: ");
        scanf("%d",&opcion);

        if(opcion == 1 || o==1){
        switch(opcion)
        {
            case 1:
                darAltas(empleados,TAM);
                o=1;
                break;
            case 2:
                modificar(empleados,TAM);
                break;
            case 3:
                bajar(empleados,TAM);
                break;
            case 4:
                informar(empleados,TAM);
                break;
        }}else{printf("Tienes que dar alta primero\n");}
    }while(opcion != 6);

    return 0;
}

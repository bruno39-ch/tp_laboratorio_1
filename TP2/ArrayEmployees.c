#include <stdio.h>

#include "ArrayEmployees.h"
#define OCUPADO 1
#define LIBRE 0

int iniciarEmpleado(eEmpleado lista[],int len)
{
    int i;
    int espacio = -1;

    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            espacio = 0;
            break;
        }
    }
    return espacio;
}
int agregarEmpleado(eEmpleado lista[], int len, int id, char nombre[],char apellido[], float salario,int sector)
{
    int espacio;
    espacio = iniciarEmpleado(lista,len);

    if(espacio == 0)
    {
        lista[id].id = id+1;
        strcpy(lista[id].nombre,nombre);
        strcpy(lista[id].apellido,apellido);
        lista[id].salario = salario;
        lista[id].sector = sector;
        lista[id].isEmpty = OCUPADO;
    }else
    {
        printf("No hay espacio\n");
    }
    return espacio;
}
int buscarIDEmpleado(eEmpleado lista[], int len,int id)
{
    int i;
    int indice=-1;

    for(i=0;i<len;i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int eliminarEmpleado(eEmpleado lista[],int len,int id)
{
    int indice;

    indice = buscarIDEmpleado(lista,len,id);
    lista[indice].isEmpty = LIBRE;

    return indice;
}
int ordenarEmpleado(eEmpleado lista[], int len, int order)
{
    int i;
    int j;
    eEmpleado empleadoAux;

    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {//de menor a mayor >0
            if(strcmp(lista[i].apellido,lista[j].apellido)>0 && order == 1||
                strcmp(lista[i].apellido,lista[j].apellido)==0 &&
                lista[i].sector>lista[j].sector  && order == 1)
            {
                empleadoAux = lista[i];
                lista[i] = lista[j];
                lista[j] = empleadoAux;
            }else
            {
                if(strcmp(lista[i].apellido,lista[j].apellido)<0 && order == 0||
                strcmp(lista[i].apellido,lista[j].apellido)==0 &&
                lista[i].sector>lista[j].sector  && order == 0)
                {//de mayor a menor<0
                    empleadoAux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = empleadoAux;
                }
            }
        }
    }
    return 0;
}
int mostrarEmpleado(eEmpleado lista[],int len)
{
    int i;

    printf("%s %10s %10s %10s %10s\n","Id","Nombre","Apellido","Salario","Sector");
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            printf("%d %10s %10s %10.2f %10d\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].salario,lista[i].sector);
        }
    }
    return 0;
}
void darAltas(eEmpleado lista[],int len)
{
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    int i;
    int in;
    int espacio;
    int id=0;
    for(i=0;i<len;i++)
    {
        if(lista[i].isEmpty == 0){

        printf("\nIngrese Nombre: ");
        fflush(stdin);
        scanf("%[^\n]",&nombre);
        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%[^\n]",&apellido);
        printf("Ingrese salario: ");
        scanf("%f",&salario);
        printf("Ingrese sector: ");
        scanf("%d",&sector);
        in=agregarEmpleado(lista,len,i,nombre,apellido,salario,sector);
        }
    }
    if(in == 0)
    {
        printf("\nSe ingresaron los datos\n");
    }else
    {
        printf("\nNo hay espacio libre\n");
    }
}
void modificar(eEmpleado lista[],int len)
{
    int id;
    int a;
    int mod;

    a = mostrarEmpleado(lista,len);
    printf("\nIngrese el id del empleado: ");
    scanf("%d",&id);
    int indice;

    indice = buscarIDEmpleado(lista,len,id);

    if(indice > -1)
    {
        printf("\n1-Nombre");
        printf("\n2-Apellido");
        printf("\n3-Salario");
        printf("\n4-Sector");
        printf("\nQue desea modificar: ");
        scanf("%d",&mod);

        switch(mod)
        {
        case 1:
            printf("Nuevo nombre: ");
            fflush(stdin);
            gets(&lista[indice].nombre);
            break;
        case 2:
            printf("Nuevo apellido: ");
            fflush(stdin);
            gets(&lista[indice].apellido);
            break;
        case 3:
            printf("Nuevo salario: ");
            scanf("%f",&lista[indice].salario);
            break;
        case 4:
            printf("Nuevo sector: ");
            scanf("%d",&lista[indice].sector);
            break;
        }
    }else
    {
        fflush(stdin);
        printf("No se encontro id\n");
    }
}
void bajar(eEmpleado lista[],int len)
{
    int id;
    int indice;
    int a;
    a = mostrarEmpleado(lista,len);
    printf("Ingres el id del empleado: ");
    scanf("%d",&id);

    indice = buscarIDEmpleado(lista,len,id);
    if(indice != -1)
    {
        lista[indice].isEmpty = LIBRE;
        printf("Se cambio a %d",lista[indice].isEmpty);
    }else
    {
        printf("\nNo se encontro el id");
    }
}
void informar(eEmpleado lista[],int len)
{
    int mostrar;
    int ordenDevuelto;
    float suma;
    float promedio;
    int cant=0;
    int mayorPromedio=0;
    int orden;
    int j;

    printf("\n0-Ordenar descendente apellido y sector");
    printf("\n1-Ordenar ascendente apellido y sector");
    printf("\nElija la opcion: ");
    scanf("%d",&orden);
    if(orden == 0)
    {
        ordenDevuelto = ordenarEmpleado(lista,len,orden);
    }else{
        ordenDevuelto = ordenarEmpleado(lista,len,orden);
    }
    for(j=0;j<len;j++)
    {
        if(lista[j].isEmpty == 1)
        {
            suma = suma + lista[j].salario;
            cant++;
        }
    }
    promedio = suma / cant;
    for(j=0;j<len;j++)
    {
        if(lista[j].salario > promedio && lista[j].isEmpty == 1)
        {
            mayorPromedio++;
        }
    }
    printf("--------------------------------------\n");
    mostrar = mostrarEmpleado(lista,len);
    printf("\n%17s %13s %15s\n","TOTAL","PROMEDIO","|ARRIBA DEL PROMEDIO");
    printf("SALARIO %10.2f %10.2f %12d\n",suma,promedio,mayorPromedio);
}

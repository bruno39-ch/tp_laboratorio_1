typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

int iniciarEmpleado(eEmpleado lista[],int cantidad);
int agregarEmpleado(eEmpleado lista[], int LEN, int id, char nombre[],char apellido[], float salario,int sector);
int buscarIDEmpleado(eEmpleado lista[], int LEN,int id);
int eliminarEmpleado(eEmpleado lista[],int LEN,int id);

void darAltas(eEmpleado lista[],int len);
void modificar(eEmpleado lista[],int len);
void bajar(eEmpleado lista[],int len);
void informar(eEmpleado lista[],int len);


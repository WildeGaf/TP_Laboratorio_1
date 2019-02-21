#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[31];
    char apellido[31];
    unsigned int dni;
    char clave[31];
}Employee;

typedef struct
{
    int idFichaje;
    int idSocio;
    int hora,minutos,dia,mes,anio;
    char ingresoEgreso[31];
}eFichaje;

Employee* employee_new();

void employee_delete();

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

void employee_setApellido(Employee* this, char* apellido);
char * employee_getApellido(Employee* this);

void employee_setDni(Employee* this, int dni)
int employee_getDni(Employee* this);

void employee_setClave(Employee* this, int clave)
int employee_getClave(Employee* this);

Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4, char* var5);




eFichaje* eFichaje_new();
eFichaje* eFichaje_newParametros(char *var1, char *var2, char *var3, char *var4, char * var5,
                                 char * var6,char * var7,char * var8);



void eFichaje_setidFichaje(eFichaje* this, int idFichaje)



void eFichaje_setidFichaje(eFichaje* this, int idFichaje)








#endif // employee_H_INCLUDEDc

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
    int idEmpleado;
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

void employee_setDni(Employee* this, int dni);
int employee_getDni(Employee* this);

void employee_setClave(Employee* this, char* clave);
char* employee_getClave(Employee* this);

Employee* employee_newParametros(char *var1, char *var2, char *var3, char *var4, char* var5);



/*********************************************************************************/




eFichaje* eFichaje_new();
eFichaje* eFichaje_newParametros(char *var1, char *var2, char *var3, char *var4, char * var5,
                                 char * var6,char * var7,char * var8);



void eFichaje_setIdFichaje(eFichaje* this, int idFichaje);
int eFichaje_getIdFichaje(eFichaje* this);

void eFichaje_setIdEmpleado(eFichaje* this, int idFichaje);
int eFichaje_getIdEmpleado(eFichaje* this);

void eFichaje_setHora(eFichaje* this, int hora);
int eFichaje_getHora(eFichaje* this);

void eFichaje_setMinutos(eFichaje* this, int minutos);
int eFichaje_getMinutos(eFichaje* this);

void eFichaje_setDia(eFichaje* this, int dia);
int eFichaje_getDia(eFichaje* this);

void eFichaje_setMes(eFichaje* this, int mes);
int eFichaje_getMes(eFichaje* this);

void eFichaje_setAnio(eFichaje* this, int anio);
int eFichaje_getAnio(eFichaje* this);

void eFichaje_setIngresoEgreso(eFichaje* this, char* ingresoEgreso);
char * eFichaje_getIngresoEgreso(eFichaje* this);







#endif // employee_H_INCLUDEDc

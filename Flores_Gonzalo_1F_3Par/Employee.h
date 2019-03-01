#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int idComponente;
    char nombre[50];
    char base[50];
}eComponente;

typedef struct
{
    int idColor;
    char nombre[50];
    int idComponente;
    int cantidad;
}eColor;

eComponente* componente_new();


void employee_delete();

void eComponente_setIdComponente(eComponente* this,int idComponente);
int eComponente_getIdComponente(eComponente* this);

void eComponente_setNombre(eComponente* this,char* nombre);
char* eComponente_getNombre(eComponente* this);

void eComponente_setBase(eComponente* this, char* base);
char* eComponente_getBase(eComponente* this);

eComponente* eComponente_newParametros(char *var1, char *var2, char *var3);
int employee_sortByName(void* thisA,void* thisB);



/*********************************************************************************/




eColor* color_new();
eColor* eColor_newParametros(char *var1, char *var2, char *var3, char *var4);

void eColor_setIdComponente(eColor* this, int idFichaje);
int eColor_getIdComponente(eColor* this);

void eColor_setIdColor(eColor* this, int idFichaje);
int eColor_getIdColor(eColor* this);

void eColor_setCantidad(eColor* this, int hora);
int eColor_getCantidad(eColor* this);

void eColor_setNombre(eColor* this, char* nombre);
char * eColor_getNombre(eColor* this);

#endif // employee_H_INCLUDEDc

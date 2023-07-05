#include "buscar.h"

int es_directorio(char *ruta)
{
    struct stat s;
    int resultado = stat(ruta,&s);
    if(resultado < 0)
    {
        perror("stat\n");
        return 0;
    }
    if(S_ISDIR(s.st_mode))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int buscar(char *directorio, char *patron)
{
    int total = 0;
    DIR *d;
    struct dirent *ent;

    d = opendir(directorio);
    if(d==NULL)
    {
        perror("opendir");
        return total;
    }
    while((ent = readdir(d))!=NULL)
    {
        char *ruta = malloc(strlen(directorio)+strlen(ent->d_name)+2);
        strcpy(ruta,directorio);
        strcat(ruta,"/");
        strcat(ruta,ent->d_name);
        if(strstr(ent->d_name,patron)!= NULL)
        {
            printf("Archivo encontrado: %s\n",ruta);
            total = total + 1;
        }
        if(es_directorio(ruta) && strcmp(ent->d_name,".")!=0 &&  strcmp(ent->d_name,"..")!=0)  
        {
            total = total + buscar(ruta, patron);
        } 
    }
    closedir(d);
    return total;

}

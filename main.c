#include "buscar.h"


int main(int argc, char * argv[])
{
    
    if (argc != 3)
    {
        fprintf(stderr,"Debe especificar el directorio de busquedas y el patron\n");
        exit(EXIT_FAILURE);
    }
    printf("Directorio de busqueda: %s\n",argv[1]);
    printf("Patron: %s\n",argv[2]);
    buscar(argv[1],argv[2]);
    exit(EXIT_SUCCESS);
}

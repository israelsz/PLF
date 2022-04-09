#include <stdio.h>
#include <string.h>
#include <ctype.h>


//Entrada: El nombre del archivo.
//Salida: la lectura del archivo.
//Objetivo: Abrir un archivo en modo lectura y leer su contenido.
FILE * leerArchivo(char* nombreArchivo){
    //Se inicializa archivo como null
    FILE* archivo = NULL;
    archivo = fopen(nombreArchivo, "r"); //Lee el archivo
    if (archivo == NULL){ //Si el archivo no existe.
        return 0;
    } else {
        return(archivo);
    }
}

//Entrada: El nombre del archivo.
//Salida: Entero 1 o 0.
//Objetivo: Determinar si un archivo ya existe.
int existeArchivo(char* nombreArchivo){
    //Se inicializa archivo como null
    FILE* archivo = NULL;
    archivo = fopen(nombreArchivo, "r"); //Lee el archivo
    if (archivo == NULL){ //Si el archivo no existe.
        return 0;
    } 
    return 1; // El archivo existe

}

//Entrada: El nombre del archivo.
//Salida: Entero 1 o 0.
//Objetivo: Determinar si un archivo ya existe.
int tieneTilde(char palabra[100]){
    unsigned char caracter;
    for (int i = 0; palabra[i] != '\0'; i++){
        caracter = palabra[i];
        if(caracter == 195){
            return 1;
        }
    }
    return 0;

}


//Entrada: El archivo de entrada
//Salida: 
//Objetivo: Generar el archivo de salida con los terminales en mayuscula encontrados
void crearArchivoSalida(FILE * archivoEntrada, char terminales[][10], int cantidadTerminales, char* nombreArchivoSalida){
    char mayusculas[2][10] = {"PURÉ","SALMÓN"};
    //Se define un archivo de salida
    FILE * salida;
    //Se define una variable que almacenara a los nombres de los id
    char texto[100];
    char palabra[100];
    int mayus = 0;
    //Se abre el archivo de salida en modo de escritura y se le asigna el nombre ingresado por linea de comandos
    salida = fopen(nombreArchivoSalida, "w");
    while(fscanf(archivoEntrada,"%s",&texto)!= EOF) {
        //Se busca la palabra leida en el conjunto de terminales
        for (int i = 0; i < cantidadTerminales; i++) {
            //Si el terminal esta dentro de la palabra leida
            if(strstr(texto,terminales[i]) != NULL){
                //Se copia el terminal a una nueva variable
                strcpy(palabra,terminales[i]);
                //Se verifica si la palabra tiene alguna tilde
                if(tieneTilde(palabra) == 1){
                    fprintf(salida,"%s\n",mayusculas[mayus]);
                    mayus = mayus + 1;
                } else {
                    //Se convierte a mayuscula
                    for(int j = 0; palabra[j] != '\0'; j++){
                        palabra[j] = toupper(palabra[j]);
                    }
                    //Finalmente se escribe en el archivo de salida
                    fprintf(salida,"%s\n",palabra);
                    break;
                }
                  
            }
        }

    }
    fclose(salida);
    fclose(archivoEntrada);
}

int main(int argc,char* argv[]) {

    //Se definen los terminales de la gramatica, los cuales se almacenan en un arreglo
    int cantidadTerminales = 32;
    char terminales[32][10] = {"arroz", "papas", "puré", "ensalada", "fideos", "con",
    "salteado", "blanco", "fritas", "cocidas", "asadas", 
    "horneadas", "horneado", "frito", "cocido", "asado", "apanado",
    "horneada", "frita", "cocida", "asada", "apanada", "salchicha",
    "pavo", "pollo", "salmón", "huevo", "merluza", "chuleta", "longaniza",
    "bistec", "tortilla"};

    //Se verifica que se hayan ingresado dos parametros de entrada
    if(argc == 1){
        printf("Error: Faltan par%cmetros.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //En caso falte un parametro
    if(argc == 2) {
        printf("Error: Falta par%cmetro.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //En caso que se hayan ingresado parametros extra
    if(argc > 3) {
        printf("Demasiados par%cmetros.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    //Para empezar se leera el archivo de entrada
    FILE* archivoEntrada = leerArchivo(argv[1]);

    //Si la funcion leerArchivo devuelve un 0 es porque el archivo no existe o el nombre fue mal ingresado.
    if(archivoEntrada == 0){
        printf("Error: El archivo de entrada no existe.\n");
        return 0;
    }
    //Se verifica en caso el archivo de salida ya exista
    if(existeArchivo(argv[2]) == 1){
        printf("Error: El archivo de salida ya existe.\n");
        return 0;
    }
    //Se escribe el archivo de salida
    crearArchivoSalida(archivoEntrada, terminales, cantidadTerminales, argv[2]);
    
    return 0;
}
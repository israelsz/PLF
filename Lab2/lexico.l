%option noyywrap

%%
"arroz" { fprintf (yyout, "ARROZ\n"); }
"papas" { fprintf (yyout, "PAPAS\n"); }
"puré" { fprintf (yyout, "PURÉ\n"); }
"ensalada" { fprintf (yyout, "ENSALADA\n"); }
"fideos" { fprintf (yyout, "FIDEOS\n"); }
"con" { fprintf (yyout, "CON\n"); }
"salteado" { fprintf (yyout, "SALTEADO\n"); }
"blanco" { fprintf (yyout, "BLANCO\n"); }
"fritas" { fprintf (yyout, "FRITAS\n"); }
"cocidas" { fprintf (yyout, "COCIDAS\n"); }
"asadas" { fprintf (yyout, "ASADAS\n"); }
"horneadas" { fprintf (yyout, "HORNEADAS\n"); }
"horneado" { fprintf (yyout, "HORNEADO\n"); }
"frito" { fprintf (yyout, "FRITO\n"); }
"cocido" { fprintf (yyout, "COCIDO\n"); }
"asado" { fprintf (yyout, "ASADO\n"); }
"apanado" { fprintf (yyout, "APANADO\n"); }
"horneada" { fprintf (yyout, "HORNEADA\n"); }
"frita" { fprintf (yyout, "FRITA\n"); }
"cocida" { fprintf (yyout, "COCIDA\n"); }
"asada" { fprintf (yyout, "ASADA\n"); }
"apanada" { fprintf (yyout, "APANADA\n"); }
"salchicha" { fprintf (yyout, "SALCHICHA\n"); }
"pavo" { fprintf (yyout, "PAVO\n"); }
"pollo" { fprintf (yyout, "POLLO\n"); }
"salmón" { fprintf (yyout, "SALMÓN\n"); }
"huevo" { fprintf (yyout, "HUEVO\n"); }
"merluza" { fprintf (yyout, "MERLUZA\n"); }
"chuleta" { fprintf (yyout, "CHULETA\n"); }
"longaniza" { fprintf (yyout, "LONGANIZA\n"); }
"bistec" { fprintf (yyout, "BISTEC\n"); }
"tortilla" { fprintf (yyout, "TORTILLA\n"); }
. {}
[\r\n]* {}
%%

int main(int argc, char* argv[]) {

    if(argc == 1){
        printf("Error: Faltan par%cmetros.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    
    if(argc == 2) {
        printf("Error: Falta par%cmetro.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }
    
    if(argc > 3) {
        printf("Error: Demasiados par%cmetros.\n", 160);
        printf("Uso: lexico.exe archivo_entrada archivo_salida\n");
        return 0;
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "r");

    if (yyin == NULL){
        printf("Error: El archivo de entrada no existe.\n");
        return 0;
    }
    if (yyout != NULL){
        printf("Error: El archivo de salida ya existe.\n");
        return 0;
    }
    
    yyout = fopen(argv[2],"w");
    yylex();

    return 0;
}
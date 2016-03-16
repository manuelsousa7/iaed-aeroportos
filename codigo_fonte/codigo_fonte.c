/*                                                         .:INSTITUTO SUPERIOR TECNICO:.
                                            Programa Realizado Por:
                                                     - Gonçalo Marques ()
                                                     - Manuel Sousa (84740)
                                            Tema: Redes de Aeroportos
                                            Curso: Licenciatura de Engenharia Informática e Computadores (LEIC-T)
                                            Cadeira: Introdução aos Algoritmos e Estruturas de Dados 
                                            Data de Entrega: 02/04/2016
*/                       

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSTRLEN 100

char leString();

int main()
{
	
	return 0;
}

char leString(){
	char str[MAXSTRLEN], c;
	int i = 0;

	if ((c = getchar()) == '\n')
		c = getchar();
	while (c != '\n' && c != EOF){
		str[i++] = c;
		c = getchar();
	}
	str[i] = '\0';
	
	return str;
}
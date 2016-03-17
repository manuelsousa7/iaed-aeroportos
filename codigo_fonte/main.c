/*                                                         .:INSTITUTO SUPERIOR TECNICO:.
                                            Programa Realizado Por:
                                                     - Gonçalo Marques (84719)
                                                     - Manuel Sousa (84740)
                                            Tema: Redes de Aeroportos
                                            Curso: Licenciatura de Engenharia Informática e Computadores (LEIC-T)
                                            Cadeira: Introdução aos Algoritmos e Estruturas de Dados
                                            Data de Entrega: 02/04/2016
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "constantes.h"
#include "funcoes_comandos.h"
#include "funcoes_auxiliares.h"

int main()
{
	char c, string_input[MAXAEROPORTOID];
	short int num_input;

	switch (c = getchar()){
		case 'A':
			scanf("%s",&string_input);
			scanf("%hd", &num_input);
			adiciona(grafo, numero_aeroportos, string_input, num_input); //o indice em que se inicializam os valores
			//do aeroporto e "numero_aeroportos" depois incrementa-se;			
			numero_aeroportos++;
			
			break;
		case 'I':
			break;
		case 'F':
			break;
		case 'G':
			break;
		case 'R':
			break;
		case 'S':
			break;
		case 'N':
			break;
		case 'P':
			break;
		case 'Q':
			break;
		case 'V':
			break;
		case 'C':
			break;
		case 'O':
			break;
		case 'L':
			break;
		case 'X':
			break;
	}		

	return 0;
}
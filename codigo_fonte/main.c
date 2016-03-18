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
#include <stdlib.h>
#include <math.h>
#include "constantes.h"
#include "funcoes_comandos.h"
#include "funcoes_auxiliares.h"


int main(int argc, char **argv)
{
	short int int1_input,int2_input,index;
	char str1_input[4],str2_input[4];
	char c;
	unsigned short int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS];
	Aeroporto aeroportos[MAXAEROPORTOS];
	while (c = getchar()){
		switch (c){
			case 'A':
				scanf("%s %hd",str1_input,&int1_input);
				aeroportos[numero_aeroportos] = adiciona_aeroporto(int1_input,str1_input);
				numero_aeroportos++;
				break;
			case 'I':
				scanf("%s %hd",str1_input,&int1_input);
				index = PesquisaBinariaAeroportos(aeroportos,str1_input,numero_aeroportos);
				if(index!=-1)
					aeroportos[index].capacidade+=int1_input;
				else
					printf("*Capacidade de %s inalterada\n",str1_input);
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
		}		
		if(c=='X')
			break;
	}
	printf("%s %d\n",aeroportos[0].id,aeroportos[0].capacidade);
	printf("%s %d\n",aeroportos[1].id,aeroportos[1].capacidade);
	printf("%s %d\n",aeroportos[2].id,aeroportos[2].capacidade);
	return 0;
}
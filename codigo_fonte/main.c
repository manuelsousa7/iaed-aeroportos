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


int main()
{
	int int1_input,int2_input,index_1,index_2;
	char str1_input[4],str2_input[4];
	char c;
	int numero_aeroportos = 0, grafo[MAXAEROPORTOS][MAXAEROPORTOS];
	Aeroporto aeroportos[MAXAEROPORTOS];
	while (1){
		c = getchar();
		switch (c){
			case 'A':
				scanf("%s %d",str1_input,&int1_input);
				aeroportos[numero_aeroportos] = CriaAeroporto(int1_input,str1_input, numero_aeroportos);
				numero_aeroportos++;	
				break;
			case 'I':
				scanf("%s %d",str1_input,&int1_input);
				index_1 = PesquisaBinariaAeroportos(aeroportos,str1_input,numero_aeroportos);
				if(index_1!=-1)
					aeroportos[index_1].capacidade += int1_input;
				else
					printf("*Capacidade de %s inalterada\n",str1_input);
				break;
			case 'F':
				//printf("->%d",numero_aeroportos);
				scanf("%s %s", str1_input, str2_input);
				index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
				index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);
				grafo[index_2][index_1] += 1;
				grafo[index_1][index_2] += 1;
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
				scanf("%d",&int1_input);
				if(int1_input==0){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosCronologicamente);
					ImprimeAeroportos(aeroportos,numero_aeroportos);}
				else if(int1_input==1){
					qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
					ImprimeAeroportos(aeroportos,numero_aeroportos);}
				else{//histograma

				}
				break;
		}		
		if(c=='X')
			break;
	}
	printf("%d",numero_aeroportos);
	return 0;
}
#include "funcoes_auxiliares.h"

//Cria um novo aeroporto
Aeroporto CriaAeroporto(int capacidade,char id[],int numero_aeroportos)
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	aeroporto.partem=0;
	aeroporto.chegam=0;
	aeroporto.crono=numero_aeroportos;
	strcpy(aeroporto.id,id);
	return aeroporto;
}
/*
//Altera a capacidade do aeroporto

Aeroporto AlteraCapacidadeAeroporto(int capacidade,char id[])
{

	
}*/

void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos)
{
	int i;
	for (i = 0 ; i < numero_aeroportos ; i++)
		printf("%s:%d:%d:%d\n",aeroportos[i].id,aeroportos[i].capacidade,aeroportos[i].partem,aeroportos[i].chegam);
}

//Adiciona um voo de ida ou de ida e volta
//					               grafo                                 numero de aeroportos  1 se for ida e volta   1 se for remover
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover){

    int index_1, index_2;
    char str1_input[4], str2_input[4];

    scanf("%s %s", str1_input, str2_input);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

    if (index_1 != -1 && index_2 != -1){
    	if (remover)
        	grafo[index_2][index_1] -= 1;
        else
        	grafo[index_2][index_1] += 1;

        if (ida_volta){
            if (remover)
	        	grafo[index_1][index_2] -= 1;
	        else
	        	grafo[index_1][index_2] += 1;
        }
    }

    else {

        if(index_1 == -1){
        	if (remover)
        		printf("*Impossivel remover voo RT %s %s", str1_input, str2_input);
        	else
        		printf("*Impossivel adicionar voo RT %s %s", str1_input, str2_input);
        }

        if(index_2 == -1){
            if (remover)
        		printf("*Impossivel remover voo RT %s %s", str1_input, str2_input);
        	else
        		printf("*Impossivel adicionar voo RT %s %s", str1_input, str2_input);
        }
    }
}

void RetornaVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos){
	int index_1, index_2;
    char str1_input[4], str2_input[4];

    scanf("%s %s", str1_input, str2_input);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

    printf("Voos entre cidades %s : %s : %d : %d", str1_input, str2_input, grafo[index_2][index_1], grafo[index_1][index_2]);
}

void AeroportoPopular(Aeroporto aeroportos[], int numero_aeroportos){
    int iterador, maior = 0, indice = 0;

    for (iterador = 0; iterador < numero_aeroportos; iterador++)
        if (maior < (aeroportos[iterador].partem + aeroportos[iterador].chegam))
            maior = (aeroportos[iterador].partem + aeroportos[iterador].chegam);
            indice = iterador;

    printf("%s", aeroportos[indice].id);
}

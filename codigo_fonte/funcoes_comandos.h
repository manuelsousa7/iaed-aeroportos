
//Cria um novo aeroporto
Aeroporto cria_aeroporto(int capacidade,char id[],int numero_aeroportos)
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	aeroporto.id_n=numero_aeroportos;
	strcpy(aeroporto.id,id);
	return aeroporto;
}

//Altera a capacidade do aeroporto
Aeroporto altera_capacidade_aeroporto(int capacidade,char id[])
{
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
	strcpy(aeroporto.id,id);
	return aeroporto;
}

//Adiciona um voo de ida ou de ida e volta
//					 grafo        numero de aeroportos     1 se for ida e volta    1 se for remover
void AdicionaVoo(int grafo[], int numero_aeroportos, short int ida_volta, short int remover){

    short int index_1, index_2;
    char str1_input[4], str2_input[4];

    scanf("%s %s", str1_input, str2_input);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

    if (index_1 != -1 || index_2 != -1)
    	if (remover)
        	grafo[index_2][index_1] -= 1;
        else
        	grafo[index_2][index_1] -= 1;

        if (ida_volta)
            if (remover)
	        	grafo[index_2][index_1] -= 1;
	        else
	        	grafo[index_2][index_1] -= 1;
    else {
        if(index_1 == -1)
            printf("*Impossivel adicionar voo RT %s %s", str1_input, str2_input);
        if(index_2 == -1)
            printf("*Impossivel adicionar voo RT %s %s", str1_input, str2_input);
    }
}
//Cria um novo aeroporto
void CriaAeroporto(Aeroporto aeroportos[], int numero_aeroportos)
{
    int capacidade;
    char str1_input[MAXID];
    scanf("%s %d",str1_input,&capacidade);
	Aeroporto aeroporto;
	aeroporto.capacidade=capacidade;
	aeroporto.estado=true;
    aeroporto.soma=0;
	aeroporto.partem=0;
	aeroporto.chegam=0;
	aeroporto.crono=numero_aeroportos;
	strcpy(aeroporto.id,str1_input);
    aeroportos[numero_aeroportos] = aeroporto;
}

//Altera a capacidade do aeroporto
void AlteraCapacidadeAeroporto(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos)
{
    int cap, index_1;
    char str1_input[MAXID];
    scanf("%s %d", str1_input, &cap);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    printf("%d %d %d", aeroportos[index_1].soma, aeroportos[index_1].capacidade, cap);

    if(index_1 != -1 && aeroportos[index_1].soma <= (aeroportos[index_1].capacidade + cap) && aeroportos[index_1].estado)
        aeroportos[index_1].capacidade += cap;
    else
        printf("*Capacidade de %s inalterada\n",str1_input);
}

void ImprimeAeroportos(Aeroporto aeroportos[],int numero_aeroportos)
{
	int i;
	for (i = 0 ; i < numero_aeroportos ; i++)
		printf("%s:%d:%d:%d\n",aeroportos[i].id,aeroportos[i].capacidade,aeroportos[i].partem,aeroportos[i].chegam);
}

//Adiciona ou remove um voo de ida ou de ida e volta
void AdicionaRemoveVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos, bool ida_volta, bool remover){

    int index_1, index_2;
    char str1_input[MAXID], str2_input[MAXID];

    scanf("%s %s", str1_input, str2_input);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

    if (index_1 != -1 && index_2 != -1 && aeroportos[index_1].estado && aeroportos[index_2].estado){
    	if (remover){
        	grafo[index_2][index_1] -= 1;
            aeroportos[index_1].partem -= 1;
            aeroportos[index_1].soma -= 1;
            aeroportos[index_2].chegam -= 1;
            aeroportos[index_2].soma -= 1;
        }
        else {
        	grafo[index_2][index_1] += 1;
            aeroportos[index_1].partem += 1;
            aeroportos[index_1].soma += 1;
            aeroportos[index_2].chegam += 1;
            aeroportos[index_2].soma += 1;
        }

        if (ida_volta){
            if (remover) {
	        	grafo[index_1][index_2] -= 1;
                aeroportos[index_2].partem -= 1;
                aeroportos[index_2].soma -= 1;
                aeroportos[index_1].chegam -= 1;
                aeroportos[index_1].soma -= 1;
            }
	        else {
	        	grafo[index_1][index_2] += 1;
                aeroportos[index_2].partem += 1;
                aeroportos[index_2].soma += 1;
                aeroportos[index_1].chegam += 1;
                aeroportos[index_1].soma += 1;
            }
        }
    }

    else {

        if(index_1 == -1){
        	if (remover)
        		printf("*Impossivel remover voo RT %s %s\n", str1_input, str2_input);
        	else
        		printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
        }

        if(index_2 == -1){
            if (remover)
        		printf("*Impossivel remover voo RT %s %s\n", str1_input, str2_input);
        	else
        		printf("*Impossivel adicionar voo RT %s %s\n", str1_input, str2_input);
        }
    }
}

void RetornaVoo(int grafo[][MAXAEROPORTOS], Aeroporto aeroportos[], int numero_aeroportos){
	int index_1, index_2;
    char str1_input[MAXID], str2_input[MAXID];

    scanf("%s %s", str1_input, str2_input);
    index_1 = PesquisaBinariaAeroportos(aeroportos, str1_input, numero_aeroportos);
    index_2 = PesquisaBinariaAeroportos(aeroportos, str2_input, numero_aeroportos);

    printf("Voos entre cidades %s : %s : %d : %d\n", str1_input, str2_input, grafo[index_2][index_1], grafo[index_1][index_2]);
}

void AeroportoPopular(Aeroporto aeroportos[], int numero_aeroportos){
    int iterador, maior = 0, indice = 0;

    for (iterador = 0; iterador < numero_aeroportos; iterador++)
        if (maior < (aeroportos[iterador].partem + aeroportos[iterador].chegam)){
            maior = (aeroportos[iterador].partem + aeroportos[iterador].chegam);
            indice = iterador;
        }

    printf("%s\n", aeroportos[indice].id);
}

void HistogramaImprime(Aeroporto aeroportos[], int numero_aeroportos){
	Histograma hist[MAXAEROPORTOS];
    int n_hist=0;
    int index,i;
    for (i=0;i<numero_aeroportos;i++){
        index=PesquisaBinariaHistograma(hist,aeroportos[i].soma,n_hist);
        if(index==-1){
            hist[n_hist].soma=aeroportos[i].soma;
            hist[n_hist].n=1;
            n_hist++;
        }
        else
            hist[index].n++;
    }
    qsort(hist, n_hist, sizeof(Histograma), OrdenaHistograma);
    for(i=0;i<n_hist;i++)
        printf("%d:%d\n", hist[i].soma,hist[i].n);

}
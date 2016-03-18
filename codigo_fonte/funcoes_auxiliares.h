/*int PesquisaBinaria (int x, int v[], int e, int d){ 
	int i = (e + d)/2;	
	if (v[i] == x)
		return i;	
	if (e == d)
		return -1; 
	else if (v[i] < x)
		return PesquisaBinaria(x, v, i+1, d);
	return PesquisaBinaria(x, v, e, i-1);
}*/


//Ordena os aeroportos por ordem alfabetica
int OrdenaAeroportosNome(const void *a, const void *b) 
{ 
    Aeroporto *ia = (Aeroporto *)a;
    Aeroporto *ib = (Aeroporto *)b;
    return strcmp(ia->id, ib->id);
} 

//Usa pesquisa binaria para procurar o aeroporto com o id correspondente
int OrdenaAeroportosCronologicamente(const void *a, const void *b) 
{ 
    Aeroporto *ia = (Aeroporto *)a;
    Aeroporto *ib = (Aeroporto *)b;
    return ia->id_n > ib->id_n;
} 

int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos){ 
    qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
    int i;
    Aeroporto key, *res;
    strcpy(key.id ,a_procurar);
    res = bsearch(&key, aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
    size_t index = res - aeroportos;
    if (res == NULL)
        return -1;
    else
        return index;
}

/*void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j){
        while(valor[i] < x && i < direita)
            i++;
        while(valor[j] > x && j > esquerda)
            j--;
        if(i <= j){
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
        quickSort(valor, esquerda, j);
    if(i < direita)
        quickSort(valor,  i, direita);
}*/


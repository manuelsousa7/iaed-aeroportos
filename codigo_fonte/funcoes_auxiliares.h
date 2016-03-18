//Ordena os aeroportos por ordem alfabetica
int OrdenaAeroportosNome(const void *a, const void *b) 
{ 
    Aeroporto *ia = (Aeroporto *)a;
    Aeroporto *ib = (Aeroporto *)b;
    return strcmp(ia->id, ib->id);
} 

int OrdenaAeroportosCronologicamente(const void *a, const void *b) 
{ 
    Aeroporto *ia = (Aeroporto *)a;
    Aeroporto *ib = (Aeroporto *)b;
    return ia->crono > ib->crono;
}
int OrdenaHistograma(const void *a, const void *b) 
{ 
    Histograma *ia = (Histograma *)a;
    Histograma *ib = (Histograma *)b;
    return ia->soma > ib->soma;
}

int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos){ 
    qsort(aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
    Aeroporto key, *res;
    strcpy(key.id ,a_procurar);
    res = bsearch(&key, aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
    size_t index = res - aeroportos;
    if (res == NULL)
        return -1;
    else
        return index;
}

int PesquisaBinariaHistograma(Histograma hist[], int n, int n_hist){ 
    qsort(hist, n_hist, sizeof(Histograma), OrdenaHistograma);
    Histograma key, *res;
    key.soma=n;
    res = bsearch(&key, hist, n_hist, sizeof(Histograma), OrdenaHistograma);
    size_t index = res - hist;
    if (res == NULL)
        return -1;
    else
        return index;
}

void InsertionSortAeroporto(Aeroporto aeroportos[], int numero_aeroportos, int crono)
{
    int i, j;
    Aeroporto atual;
    for (i = 1; i < numero_aeroportos; i++)
    {
        atual = aeroportos[i];
        j = i - 1;
        while (((j >= 0) && (atual.crono < aeroportos[j].crono && crono==1)) || ((j >= 0) && (atual.id > aeroportos[j].id && crono==0)))
        {
            aeroportos[j + 1] = aeroportos[j];
            j = j - 1;
        }
        aeroportos[j + 1] = atual;
    }
}
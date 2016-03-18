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
    return ia->crono > ib->crono;
}

int PesquisaBinariaAeroportos (Aeroporto aeroportos[], char a_procurar[], int numero_aeroportos){ 
    Aeroporto key, *res;
    strcpy(key.id ,a_procurar);
    res = bsearch(&key, aeroportos, numero_aeroportos, sizeof(Aeroporto), OrdenaAeroportosNome);
    size_t index = res - aeroportos;
    if (res == NULL)
        return -1;
    else
        return index;
}

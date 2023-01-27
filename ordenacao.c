#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ordenacao.h"

void getNome(char nome[]){
	strncpy(nome, "Joao Pedro Vicente Ramalho", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

void getNome2(char nome2[]){
	strncpy(nome2, "Mardoqueu Freire Nunes", MAX_CHAR_NOME);
	nome2[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20224169;
}

unsigned int getGRR2(){
	return 20211773;
}

int Max (int vetor [], int tam, int *numComparacoes) {
	int i;
	int maior = tam;
	for (i=tam-1; i >= 0; i--) {
		if (vetor[i] >= vetor[maior]) {
			maior = i;
			*numComparacoes = *numComparacoes + 1;
		}
		else {
			*numComparacoes = *numComparacoes + 1;
		}
	}
	return maior;
}

void Troca (int vetor [], int a, int c) {
	int aux = vetor[c];
	vetor[c] = vetor[a];
	vetor[a] = aux; 
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (tam < 0) 
        return -1;
    if (valor == vetor [tam]) {
		*numComparacoes = *numComparacoes + 1;
		return tam;
	}
	else 
		*numComparacoes = *numComparacoes + 1;
	return (buscaSequencial(vetor, tam-1, valor, numComparacoes));
}

int buscaBinaria_aux(int vetor_aux[], int a, int b, int valor, int *numComparacoes){

	if(a > b)
		return -1;

	int m = floor((a+b)/2);

	if(valor == vetor_aux[m]) {
	    *numComparacoes = *numComparacoes + 1;
		return m-1;                                 //<-- necessario porque o "vetor" vai de (0..tam-1) e o "vetor_aux" vai de (1..tam)
	}
	else if(valor < vetor_aux[m]) {
		*numComparacoes = *numComparacoes + 1;
		return buscaBinaria_aux(vetor_aux, a, m-1, valor, numComparacoes);
	}
	
	*numComparacoes = *numComparacoes + 1;
	
	return buscaBinaria_aux(vetor_aux, m+1, b, valor, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes) {
	int vetor_aux[tam];
    int z = 0;
    for (int i = 1; i <= tam; i++) {
        vetor_aux[i] = vetor[z];
        z++;
    }
    
    int a = 1;
    int b = tam;
	int indice = buscaBinaria_aux(vetor_aux, a, b, valor, numComparacoes);

	return indice;
}

int *Insere(int vetor[], int b, int **numComparacoes) {
	int p;
	int i;
	int cont = 0;
	p = vetor[b-1];	            //p = o ultimo elemento de v
	i = b-2;	            // i = o indice o penultimo elemento de v	
	
	/*verefico se o penultimo elemento é maior que o ultimo*/
	while(i >= 0 && vetor[i] > p){
	    cont++;
		vetor[i+1] = vetor[i];	    //se sim ele faz a troca
		i--;		        //perceba que sobrepos um elemento, mas isso é solucionado no fim!
	}
    if(cont == 0){
        **numComparacoes = **numComparacoes + 1;
    }
    else {
        **numComparacoes = **numComparacoes + cont;
	};

	vetor[i+1] = p;	            //aqui soluciono a sobreposição!!
	return vetor;           
}

int *insertionSort_aux(int vetor[], int b, int *numComparacoes){

	if( 0 >= b){
		return vetor;
	}
	
	insertionSort_aux(vetor, b-1, numComparacoes);
	vetor = Insere(vetor, b, &numComparacoes); //como insere devolve um vetor, tenho que ter essa variavel aux!
	return vetor;
}

int insertionSort(int vetor[], int tam){	
	int b = tam;
	int numComparacoes = 0;
	
	vetor = insertionSort_aux(vetor, b, &numComparacoes);

	return numComparacoes-1;
}

int selectionSort_aux (int vetor[], int a, int b, int *numComparacoes) {
    if (b < a) 
		return *numComparacoes;
	int c = Max(vetor,b, numComparacoes);
	Troca(vetor, b, c);
	return (selectionSort_aux(vetor, a, b-1, numComparacoes));  
}

int selectionSort(int vetor[], int tam){
	int a = 0;
    int b = tam - 1;
	int numComparacoes = 0;
	numComparacoes = selectionSort_aux(vetor, a, b, &numComparacoes);
	return numComparacoes;
}

int Intercala (int vetor [], int u[], int a, int m, int b, int *numComparacoes) {
    if (a >= b) 
        return 0;
    int i = a;
    int j = m+1;
    int k;
    for (k = 0; k <= (b-a); k++) {
        *numComparacoes = *numComparacoes + 1;
        if ((j > b) || (i <= m && vetor[i] <= vetor[j])) {
            u[k] = vetor[i];
            i = i + 1;
        }
        else {
            u[k] = vetor[j];  
            j = j + 1;
        }
    }

    for(int l = 0; l < b - a+1; l++){
    	vetor[a + l] = u[l];
    }
    return 0;
}

int mergeSort_aux (int vetor [], int u[], int a, int b, int *numComparacoes) {
    if (a >= b) {
        return 0;
    }
    int m = (a+b)/2;
    mergeSort_aux(vetor, u, a, m, numComparacoes);
    mergeSort_aux(vetor, u, m+1, b, numComparacoes);
    return (Intercala(vetor, u, a, m, b, numComparacoes));
}

int mergeSort(int vetor[], int tam){
	int a = 0;
    int b = tam-1;
    int u [tam];
    int numComparacoes = 0;
    mergeSort_aux(vetor, u, a, b, &numComparacoes);

    return numComparacoes;
}

int Particiona (int vetor[], int a, int b, int x, int *numComparacoes) {
	int m = a - 1;
	int i;
	for( i = a; i <= b; i++){
		*numComparacoes = *numComparacoes + 1;
		if(vetor[i] <= x){
			m++;
			Troca(vetor, m, i);
		}
	}
	return m;
}

int quickSort_aux (int vetor[], int a, int b, int *numComparacoes) {
	int m;
	if(a >= b){
		return *numComparacoes;
	}
	m = Particiona(vetor, a, b, vetor[b], numComparacoes);
	quickSort_aux(vetor, a, m-1, numComparacoes);
	quickSort_aux(vetor, m+1, b, numComparacoes);
	return *numComparacoes;
}

int quickSort (int vetor[], int tam){
	int a = 0;
	int b = tam - 1;
    int numComparacoes = 0;
	
	quickSort_aux(vetor, a, b, &numComparacoes);

	return numComparacoes;
}

void build_max_heapify(int vetor[], int tam, int *numComparacoes) {

	for(int i = floor(tam / 2); i>= 0; i--){
		max_Heapify(vetor, tam, i, numComparacoes);
	}
}

void max_Heapify(int vetor[], int tam, int i, int *numComparacoes) {
	int maior, esq, dir;
	
	//assumindo que o maior elemento esteja na raiz
	maior = i;
	
	//o elemento da da posição 2*i sera o da esquerda
	esq = 2*i+1;

	//o elemento da posicao 2*1+1 sera o da direita
	dir = 2*i+2;
	
	maior = i;
    

	//se o filho da esquerda é maior que a raiz
	if(esq < tam && vetor[esq] > vetor[i])
		maior = esq;


	//seo o filho da direita é maior que a raiz
	if(dir < tam && vetor[dir] > vetor[maior])
		maior = dir;

    // foi incrementado em duas unidades porque houve duas comparacoes: vetor[esq] > vetor[i] e vetor[dir] > vetor[maior]
    *numComparacoes = *numComparacoes + 2; 

	//se o maior elemento não é a raiz
	if(maior != i){
		Troca(vetor, i, maior);
		max_Heapify(vetor, tam, maior, numComparacoes);
	}
}

int heapSort_aux (int vetor[], int tam, int *numComparacoes) {
    if(tam <= 0){
		return *numComparacoes;
	}
	
	build_max_heapify(vetor, tam, numComparacoes);
	Troca(vetor, tam-1, 0);
	max_Heapify(vetor, tam-1, 0, numComparacoes);

	return heapSort_aux(vetor, tam - 1, numComparacoes);
}

int heapSort (int vetor[], int tam){
	int numComparacoes = 0;
	numComparacoes = heapSort_aux(vetor, tam, &numComparacoes);
	
	return numComparacoes;
}

void Desorganizando_vetor (int vetor [], int tam) {
    vetor[0] = 18;
    vetor[1] = 2;
    vetor[2] = 31;
    vetor[3] = 56;
    vetor[4] = 23;
    printf(" Vetor Desorganizado: ");
    for(int i=0; i < tam; i++)
		            printf("%d ", vetor[i]);
	   printf("\n");
}

void Preencher_vetor_aleatorio (int vetor[], int tam) {
    int i;
    srand(time(NULL));
    for (i = 0; i < tam; i++) {
        vetor[i] = rand() % 100;
    }
}

void Preencher_vetor_crescente (int vetor[], int tam) {
    int i;
    for (i = 0; i < tam; i ++) 
        vetor[i] = i;
}

void Preencher_vetor_decrescente (int vetor[], int tam) {
    int i;
    int conteudo = tam;
    for (i = 0; i < tam; i++) {
        vetor[i] = conteudo;
        conteudo--;
    }
}
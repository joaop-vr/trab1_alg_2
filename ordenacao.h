#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50


void getNome(char nome[]);

void getNome2(char nome2[]);

unsigned int getGRR();

unsigned int getGRR2();

int buscaSequencial (int vetor[], int tam, int valor, int* numComparacoes);

int buscaBinaria (int vetor[], int tam, int valor, int* numComparacoes);

int buscaBinaria_aux (int vetor_aux[], int a, int b, int valor, int *numComparacoes);

int insertionSort (int vetor[], int tam);

int *Insere (int vetor[], int b, int **numComparacoes);

int *insertionSort_aux (int vetor[], int b, int *numComparacoes);

int selectionSort (int vetor[], int tam);

int selectionSort_aux (int vetor[], int a, int b, int *numComparacoes);

int mergeSort (int vetor[], int tam);

int mergeSort_aux (int vetor [], int u[], int a, int b, int *numComparacoes);

int Intercala (int vetor [], int u[], int a, int m, int b, int *numComparacoes);

int quickSort (int vetor[], int tam);

int quickSort_aux (int vetor[], int a, int b, int *numComparacoes);

int Particiona (int vetor[], int a, int b, int x, int *numComparacoes);

int heapSort (int vetor[], int tam);

int heapSort_aux (int vetor[], int tam, int *numComparacoes);

void max_Heapify(int vetor[], int tam, int i, int *numComparacoes);

void build_max_heapify(int vetor[], int tam, int *numComparacoes);

void Desorganizando_vetor (int vetor [], int tam);

void Preencher_vetor_aleatorio (int vetor[], int tam);

void Preencher_vetor_crescente (int vetor[], int tam);

void Preencher_vetor_decrescente (int vetor[], int tam);

#endif // ORDENACAO_H_
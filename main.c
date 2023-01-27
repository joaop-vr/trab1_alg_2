#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {
	char nome[MAX_CHAR_NOME];
	char nome2[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;
    
	int tamVetor = 5;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	getNome(nome);
	printf("Trabalho de %s ", nome);
	printf("GRR %u\n", getGRR());

	getNome2(nome2);
	printf("Trabalho de %s ", nome2);
    printf("GRR %u\n", getGRR2());
	
	printf("\n----------------------------------------------------------\n");
    printf(" Executando cada funcao \n");
    for (int cont = 1; cont <= 7; cont ++) {
        switch(cont) {
            case 1: 
                printf("\n *Insetiont Sort* \n");               // <-- INSERTION SORT 
                Desorganizando_vetor(vetor, tamVetor);
	            numComp = insertionSort(vetor, tamVetor);
	            printf(" Vetor Organizado: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Numero de Comparacoes: %d\n", numComp);
                break;
                
            case 2:
                printf("\n *Selection Sort* \n");               // <-- SELECTION SORT 
                Desorganizando_vetor(vetor, tamVetor);
	            numComp = selectionSort(vetor, tamVetor);
	            printf(" Vetor Organizado: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Numero de Comparacoes: %d\n", numComp);
                break;
                
            case 3:
                printf("\n *Merge Sort* \n");                   // <-- MERGE SORT 
                Desorganizando_vetor(vetor, tamVetor);
	            numComp = mergeSort(vetor, tamVetor);
	            printf(" Vetor Organizado: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Numero de Comparacoes: %d\n", numComp);
                break;
                
            case 4:
                printf("\n *Quick Sort* \n");                   // <-- QUICK SORT 
                Desorganizando_vetor(vetor, tamVetor);
	            numComp = quickSort(vetor, tamVetor);
	            printf(" Vetor Organizado: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Numero de Comparacoes: %d\n", numComp);
                break;
                
            case 5:
                printf("\n *Heap Sort* \n");                    // <-- HEAP SORT 
                Desorganizando_vetor(vetor, tamVetor);
	            numComp = heapSort(vetor, tamVetor);
	            printf(" Vetor Organizado: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Numero de Comparacoes: %d\n", numComp);
                break;
                
            case 6:
                printf("\n *Busca Sequencial* \n");             // <-- BUSCA SEQUENCIAL
				selectionSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
                printf(" Vetor: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Valor: 56");
	            idxBusca = buscaSequencial(vetor, 5, 56, &numComp);
	            printf("\n Indice: %d\n", idxBusca);
	            break;
	            
	        case 7:
                printf("\n *Busca Binaria* \n");                // <-- BUSCA BINARIA
				selectionSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
                printf(" Vetor: ");
                for(int i=0; i < tamVetor; i++)
		            printf("%d ", vetor[i]);
	            printf("\n Valor: 31");
	            idxBusca = buscaBinaria(vetor, 5, 31, &numComp);
	            printf("\n Indice: %d\n", idxBusca);	  
	            break;
        }
    }

    printf("\n----------------------------------------------------------\n");
    printf("\n Fase de analise \n");

    int vetor_tam[4];
    vetor_tam[0] = 100;
    vetor_tam[1] = 1000;
    vetor_tam[2] = 5000;
    vetor_tam[3] = 10000;

	clock_t start, end;
    double total;
    int cont;

    /* Analise de Ordenacao de Vetor*/
    for (cont = 0; cont < 4; cont++) {
    
        tamVetor = vetor_tam[cont];
		int* vetor = malloc(tamVetor * sizeof(int));
		printf("\n----------------------------------------------------------\n");
		printf("\n Tamanho do Vetor: %d\n", tamVetor);
        
		/* Analise do Insertion Sort */
        printf("\n *Insertion Sort* \n");
		printf("\n (Vetor Aleatorio)\n");
		Preencher_vetor_aleatorio(vetor, tamVetor);
        start = clock();
	    numComp = insertionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
        start = clock();
	    numComp = insertionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
        start = clock();
	    numComp = insertionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

	    /* Analise do Selection Sort */
	    printf("\n\n *Selection Sort* \n");
		printf("\n (Vetor Aleatorio) \n");
		Preencher_vetor_aleatorio(vetor, tamVetor);
        start = clock();
	    numComp = selectionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
        start = clock();
	    numComp = selectionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
        start = clock();
	    numComp = selectionSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);
	    
		/* analise do Merge Sort */
	    printf("\n\n *Merge Sort* \n");
		printf("\n (Vetor Aleatorio) \n");
		Preencher_vetor_aleatorio(vetor, tamVetor);
        start = clock();
	    numComp = mergeSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
        start = clock();
	    numComp = mergeSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
        start = clock();
	    numComp = mergeSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);
	    
		/* Analise Quick Sort*/
		printf("\n\n *Quick Sort* \n");
		printf("\n (Vetor Aleatorio)\n");
		Preencher_vetor_aleatorio(vetor, tamVetor);
        start = clock();
	    numComp = quickSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Crescente)\n");
		Preencher_vetor_crescente(vetor, tamVetor);
        start = clock();
	    numComp = quickSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente)\n");
		Preencher_vetor_decrescente(vetor, tamVetor);
        start = clock();
	    numComp = quickSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

	    /* analise Heap Sort */
	    printf("\n *Heap Sort* \n");
		printf("\n (Vetor Aleatorio) \n");
		Preencher_vetor_aleatorio(vetor, tamVetor);
        start = clock();
	    numComp = heapSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
        start = clock();
	    numComp = heapSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
        start = clock();
	    numComp = heapSort(vetor, tamVetor);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);
    };
	
	/*analise de Busca em Vetor*/
	for ( int cont = 0; cont < 4; cont++) {
	    
	    tamVetor = vetor_tam[cont];
		int valor = vetor[50];				// <--- como o vetor será criado aleatoriamente, estipulei um valor qualquer

		printf("\n----------------------------------------------------------\n");
		printf("\n Tamanho do Vetor: %d\n", tamVetor);
	    printf("\n Vai procurar vetor[50]: %d \n", valor);
		
		/* Analise Busca Sequencial */
		printf("\n *Busca Sequencial* \n");
		printf(" \n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
		mergeSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
        start = clock();
	    numComp = buscaSequencial(vetor, tamVetor, valor, &numComp);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf(" \n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
		mergeSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
        start = clock();
	    numComp = buscaSequencial(vetor, tamVetor, valor, &numComp);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

	    /* Analise Busca Binaria */
		printf("\n *Busca Binaria* \n");
		printf("\n (Vetor Ordenado Crescente) \n");
		Preencher_vetor_crescente(vetor, tamVetor);
		mergeSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
        start = clock();
	    numComp = buscaBinaria(vetor, tamVetor, valor, &numComp);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n", numComp);

		printf("\n (Vetor Ordenado Decrescente) \n");
		Preencher_vetor_decrescente(vetor, tamVetor);
		mergeSort(vetor, tamVetor);					//especificacao: "Assuma que os vetores estão ordenados ao chamar as funções de busca"
        start = clock();
	    numComp = buscaBinaria(vetor, tamVetor, valor, &numComp);
	    end = clock();
	    total = ((double)end - start)/CLOCKS_PER_SEC;
	    printf(" Tempo total: %f", total);
	    printf("\n Numero de Comparacoes: %d\n\n", numComp);
	};

	free(vetor);
	return 0;
}

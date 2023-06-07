#include<stdio.h>
#include<stdlib.h>
#include "collector.h"

// Variável global do tipo Heap, que será alterada ao decorrer do programa, quando elementos forem referenciados e dereferenciados
Heap *listaMemoria = NULL;

// Função malloc2, realiza a alocação dinâmica e retorna o endereço
void *malloc2(size_t tamanho){
    Heap *novoEndereco = (Heap *)malloc(sizeof(Heap));

    novoEndereco->contagemReferencia = 1;
    novoEndereco->endereco = malloc(tamanho);
    novoEndereco->proximo = NULL; // O próximo sempre começa vazio e será preenchido dependendo se a memória já tiver um elemento inserido

    // Se já tem, insere no próximo
    if(listaMemoria != NULL) 
        novoEndereco->proximo = listaMemoria;

    // Se é vazia, recebe o novo nó alocado
    listaMemoria = novoEndereco;

    return listaMemoria->endereco; // Retorna o endereço da área alocada
}

void coleta(){
    if(listaMemoria == NULL) return;

    Heap *anterior, *atual = listaMemoria;

    while(atual && atual->contagemReferencia == 0){
        listaMemoria = atual->proximo;
        printf("Endereco: %p removido\n", atual->endereco);
        free(atual);
        atual = listaMemoria;
    }

    while(atual){
        if(atual->contagemReferencia != 0){
            anterior = atual;
            atual = atual->proximo;
        }
        else{
            anterior->proximo = atual->proximo;
            printf("Endereco: %p removido\n", atual->endereco);
            free(atual);
            atual = anterior->proximo;
        }
    }
}

void atrib2(void **destino, void *origem){
    Heap *atual = listaMemoria;

    while(atual){
        if(atual->endereco == *destino) atual->contagemReferencia = atual->contagemReferencia - 1;
        if(atual->endereco == origem) atual->contagemReferencia = atual->contagemReferencia + 1;

        atual = atual->proximo;
    }

    *destino = origem;
}

void dump(){
    if(listaMemoria == NULL){
        printf("Heap Nula! Dump mal sucedido\n");
        return;
    }

    Heap *atual = listaMemoria;
    while(atual){
        if(atual->contagemReferencia == 0){
            // Contagem de referências chegou a 0, limpa a memória
            printf("Endereco: %p, Referencias: %d\n", atual->endereco, atual->contagemReferencia);
            atual = atual->proximo;
            coleta();
        }
        else{
            printf("Endereco: %p, Referencias: %d\n", atual->endereco, atual->contagemReferencia);
            atual = atual->proximo;
        }
    }
    printf("\n");
}

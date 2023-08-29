#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;
typedef node *LISTA;

LISTA* criarLista(){
    LISTA *inicio = (LISTA*) malloc(sizeof(LISTA));
    if(inicio != NULL){
        *inicio = NULL;
    } else{
        printf("Error on allocation");
        exit(0);
    }
    return inicio;
}

void insereInicio(LISTA* lista) {
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL) {
        printf("Error on allocation");
        exit(0);
    }
    printf("Informe o novo elemento: ");
    scanf("%d", &novo->num);
    novo->prox = (*lista);
    *lista = novo;
}

void insereFinal(LISTA* lista) {
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL) {
        printf("Error on allocation");
        exit(0);
    }
    printf("Informe o novo elemento: ");
    scanf("%d", &novo->num);
    novo->prox = NULL;
    if((*lista) == NULL) {
        *lista = novo;
    } else {
        node *tmp;
        tmp = *lista;
        while(tmp->prox != NULL)
            tmp =  tmp->prox;
        tmp->prox = novo;
    }
}

void exibeLista(LISTA* lista) {
    if(lista == NULL) {
        printf("Lista vazia");
    } else {
        node *tmp;
        tmp = (*lista);
        while(tmp != NULL){
            printf("%d", tmp->num);
            tmp = tmp->prox;
        }
    } printf("\n");
}

void liberaLista(LISTA* lista) {
    if(lista == NULL) {
        printf("Lista vazia");
    } else {
        node *tmp;
        while((*lista) != NULL){
            tmp = (*lista);
            *lista = (*lista)->prox;
            free(tmp);
        }
    } *lista = NULL;
}

void removeInicio(LISTA* lista) {
    if((*lista) != NULL) {
        node *tmp;
        tmp = *lista;
        *lista = tmp->prox;
        free(tmp);
        printf("Removido com sucesso.");
    } else
        printf("Lista vazia.");
}

void removeFim(LISTA* lista) {
    node *antNode, *tmp;
    tmp = *lista;
    if((*lista) != NULL && tmp->prox == NULL) {
        *lista = NULL;
        free(tmp);
        printf("Elemento removido.");
    } else if((*lista) != NULL) {
        while(tmp->prox != NULL) {
            antNode = tmp;
            tmp = tmp->prox;
        }
        antNode->prox = NULL;
        free(tmp);
        printf("Removido com sucesso.");
    } else
        printf("Lista vazia.");
}

void ordenaLista(LISTA *lista) {
    if (lista == NULL) {
        printf("Lista vazia");
    } else {
        int trocou;
        do {
            trocou = 0;
            node *tmp = (*lista);
            while (tmp->prox != NULL) {
                if (tmp->num > tmp->prox->num) {
                    int aux = tmp->num;
                    tmp->num = tmp->prox->num;
                    tmp->prox->num = aux;
                    trocou = 1;
                }
                tmp = tmp->prox;
            }
        } while (trocou);
    }
}



void main() {
    LISTA *lista = criarLista();
    int op;

    do{
        printf("O que deseja fazer?\n");
        printf("1- Inserir inicio?\n");
        printf("2- Inserir Final?\n");
        printf("3- Exibir lista?\n");
        printf("4- Liberar Lista?\n");
        printf("5- Remove inicio?\n");
        printf("6- remover final?\n");
        printf("7- ordenar vetor\n");
        printf("0- SAIR\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            insereInicio(lista);
            break;
        case 2:
            insereFinal(lista);
            break;
        case 3:
            exibeLista(lista);
            break;
        case 4:
            liberaLista(lista);
            break;
        case 5:
            removeInicio(lista);
            break;
        case 6:
            removeFim(lista);
            break;
        case 7:
            ordenaLista(lista);
            break;
        
        default:
            break;
        }
    } while(op != 0);
}
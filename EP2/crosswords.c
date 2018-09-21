/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Iggor Francis Numata Mathews
 * Numero USP: 10262572
 * Tarefa: EP2 - "Inventando palavras cruzadas"
 * Data: 21/09/2018
 *
 * DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SaO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO DA DISCIPLINA, FORAM DESENVOLVIDAS POR
 * MIM.  DECLARO TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
 * E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS DESTA PROGRAMA.
 *
 *****************************************************************************/


#import <stdio.h>
#import <stdlib.h>

typedef struct{
				char *v;
				int topo;
				int max;
				} pilha;
typedef pilha *Pilha;

int PilhaVazia(Pilha P){
	if (P->topo == 0) return (1);
	return (0);
}

void Empilha (Pilha P, char d){
	if (P->topo == P->max)
		resize(P);
	P->v[P->topo] = d;
	(P->topo)++;
}

void Desempilha (Pilha P){
	if (PilhaVazia(P)){
		printf("Erro!\n");
		return;
	}
	(P->topo)--;
}

Pilha CriaPilha (int max){
	Pilha P = malloc (sizeof(pilha));
	P->v = malloc(max*sizeof(char));
	P->topo = 0;
	P->max = max;
	return (P);
}

void DestroiPilha (Pilha P){
	free (P);
}

void resize (Pilha P){
	int i;
	char *novo = malloc(2*P->max*sizeof(char));
	for (i=0; i < P->max; i++)
		novo[i] = P->v[i];
	P->max = 2*P->max;
	free(P->v);
	P->v = novo;
}

int main(){

	
	
	return 0;
}
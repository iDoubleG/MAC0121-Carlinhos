/******************************************************************************
 *
 * MAC0121 - Algoritmos e Estruturas de Dados I
 * Aluno: Iggor Francis Numata Mathews
 * Numero USP: 10262572
 * Tarefa: EP1 - "Conjectura 3n + 1"
 * Data: 21/08/2018
 *
 * DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.  TODAS AS
 * PARTES DO PROGRAMA, EXCETO AS QUE SaO BASEADAS EM MATERIAL FORNECIDO
 * PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE SEDGEWICK & WAYNE,
 * FORAM DESENVOLVIDAS POR MIM.  DECLARO TAMBEM QUE SOU RESPONSAVEL POR TODAS
 * AS COPIAS DESTE PROGRAMA E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO
 * DE COPIAS DESTA PROGRAMA.
 *
 *****************************************************************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct{
				int *v;
				int max;
				} steps;
typedef steps *Steps;


void resize (Steps S, int new_n){
	int i;
	int *new_v = malloc((new_n+1)*sizeof(int));

	for (i = 0; i <= S->max; i++)
		new_v[i] = S->v[i];
	for (i = i+1; i <= new_n; i++)
		new_v[i] = 0;
	S->max = new_n;
	free(S->v);
	S->v = new_v;
}

int collatz(int n, Steps S){

	int new_n;

	if (S->v[n] != 0)
		return S->v[n];

	else if (n%2 == 1){
		new_n = 3*n + 1;

		if (new_n > S->max)
			resize(S, new_n);
	}
	
	else
		new_n = n/2;

	return S->v[n] = collatz(new_n, S) + 1;
}


int main(){

	int i, f, j, curr;
	Steps S = malloc(sizeof(steps));

	scanf("%d%d", &i, &f);

	S->max = f;
	S->v = malloc((f+1)*sizeof(int));
	S->v[1] = 1;
	for (j = 2; j <= f; j++)
		S->v[j] = 0;

	for (j = i; j<=f; j++){
		curr = collatz(j, S);
		printf("%d\t", curr);
	}

	free(S->v);
	free(S);

	return 0;
}
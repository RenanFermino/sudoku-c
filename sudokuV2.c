//Renan Fermino da Silva RA 1884980

#include <stdio.h>
#include <stdlib.h>

/*criando um TAD*/
typedef struct lista{
	int info;
	_Bool podeAlterar;
	struct lista* prox;
	struct lista* ant;
}ListaD;

typedef struct fila{
	ListaD* ini;
	ListaD* fim;
}Fila;

ListaD* criarLista();
Fila* criarFila();

ListaD* insereFim(ListaD* L, int valor, _Bool podeAlterar);

void imprime(Fila* F);

void concatena(ListaD* L1, ListaD* L2);

void montaPuzzle(Fila* F);
int procuraValorNaLinha(Fila* F, int linha, int valor);

int procuraValorNaColuna(int coluna, int valor, Fila* F);

int procuraValorNoQuadrante(int inicioLinha, int fimLinha, int inicioColuna, int fimColuna, int valor, Fila* F);

int validaQuadrante(int linha, int coluna, int valor, Fila* F);

void printMenu(Fila* F);

void caminhaAteACelulaEInsere(Fila* F, int linha, int coluna, int valor);
void validaValorUsuario(int valor);

int main(){
	 Fila* F = criarFila();	
		montaPuzzle(F);
		printMenu(F);
}

ListaD* criarLista(){return NULL;}

Fila* criarFila(){
	Fila* F = (Fila*)malloc(sizeof(Fila));

	F -> ini = NULL;
	F -> fim = NULL;

	return F;
}

ListaD* insereFim(ListaD* L, int valor, _Bool podeAlterar){
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	ListaD* aux;
		
	novo -> ant = NULL;
	novo -> prox = NULL;
	novo -> info = valor;
	novo -> podeAlterar = 0;
	
	if(L == NULL){
		return novo;
	}else{
		aux = L;
		while(aux -> prox != NULL)
			aux = aux -> prox;
			aux -> prox = novo;
			novo -> ant = aux;
	}
	return L;
}

void imprime(Fila* F){

	ListaD* aux = F -> ini;
	ListaD* t = aux -> ant;
	int i = 1; //variavel auxiliar para montar o desenho
	int linha =0;
	
	printf("*******************************");
	printf("\n");
	
	while(aux != NULL){

		if(i == 1){
			printf("| %i ", aux -> info);
			aux = aux -> prox;
			i++;
		}else if(i == 9){
			printf(" %i |", aux -> info);
			aux = aux -> prox;
			i = 1;
		} else if (i == 4 || i == 7){
			printf("| %i ", aux -> info);
			aux = aux -> prox;
			i++;
		}else{
			printf(" %i ", aux -> info);
			aux = aux -> prox;
			i++;
		}


		if(t != NULL & aux == NULL){
			if(linha == 5 || linha == 2){
				printf("\n*******************************");
			}
			printf("\n");
			aux = t;
			t = aux -> ant;
			linha++;
		}

	}
	printf("\n");
	printf("*******************************\n");
}

void concatena(ListaD* L1, ListaD* L2){
	L1 -> ant = L2;
}

void montaPuzzle(Fila* F){

	ListaD* L1 = criarLista();
	ListaD* L2 = criarLista();
	ListaD* L3 = criarLista();
	ListaD* L4 = criarLista();
	ListaD* L5 = criarLista();
	ListaD* L6 = criarLista();
	ListaD* L7 = criarLista();
	ListaD* L8 = criarLista();
	ListaD* L9 = criarLista();


	L1 = insereFim(L1, 9, 0);
	L1 = insereFim(L1, 7, 0);
	L1 = insereFim(L1, 0, 1);
	L1 = insereFim(L1, 0, 1);
	L1 = insereFim(L1, 0, 1);
	L1 = insereFim(L1, 6, 0);
	L1 = insereFim(L1, 4, 0);
	L1 = insereFim(L1, 5, 0);
	L1 = insereFim(L1, 2, 0);

	L2 = insereFim(L2, 6, 0);
	L2 = insereFim(L2, 0, 1);
	L2 = insereFim(L2, 5, 0);
	L2 = insereFim(L2, 7, 0);
	L2 = insereFim(L2, 4, 0);
	L2 = insereFim(L2, 0, 1);
	L2 = insereFim(L2, 8, 0);
	L2 = insereFim(L2, 3, 0);
	L2 = insereFim(L2, 0, 1);

	L3 = insereFim(L3, 4, 0);
	L3 = insereFim(L3, 8, 0);
	L3 = insereFim(L3, 2, 0);
	L3 = insereFim(L3, 3, 0);
	L3 = insereFim(L3, 0, 1);
	L3 = insereFim(L3, 0, 1);
	L3 = insereFim(L3, 0, 1);
	L3 = insereFim(L3, 1, 0);
	L3 = insereFim(L3, 0, 1);

	L4 = insereFim(L4, 5, 0);
	L4 = insereFim(L4, 2, 0);
	L4 = insereFim(L4, 0, 1);
	L4 = insereFim(L4, 6, 0);
	L4 = insereFim(L4, 7, 0);
	L4 = insereFim(L4, 9, 0);
	L4 = insereFim(L4, 0, 1);
	L4 = insereFim(L4, 0, 1);
	L4 = insereFim(L4, 3, 0);

	L5 = insereFim(L5, 7, 0);
	L5 = insereFim(L5, 3, 0);
	L5 = insereFim(L5, 9, 0);
	L5 = insereFim(L5, 0, 1);
	L5 = insereFim(L5, 0, 1);
	L5 = insereFim(L5, 0, 1);
	L5 = insereFim(L5, 2, 0);
	L5 = insereFim(L5, 8, 0);
	L5 = insereFim(L5, 6, 0);

	L6 = insereFim(L6, 1, 0);
	L6 = insereFim(L6, 0, 1);
	L6 = insereFim(L6, 0, 1);
	L6 = insereFim(L6, 2, 0);
	L6 = insereFim(L6, 8, 0);
	L6 = insereFim(L6, 3, 0);
	L6 = insereFim(L6, 0, 1);
	L6 = insereFim(L6, 7, 0);
	L6 = insereFim(L6, 5, 0);

	L7 = insereFim(L7, 0, 1);
	L7 = insereFim(L7, 9, 0);
	L7 = insereFim(L7, 0, 1);
	L7 = insereFim(L7, 0, 1);
	L7 = insereFim(L7, 0, 1);
	L7 = insereFim(L7, 7, 0);
	L7 = insereFim(L7, 3, 0);
	L7 = insereFim(L7, 2, 0);
	L7 = insereFim(L7, 4, 0);

	L8 = insereFim(L8, 0, 1);
	L8 = insereFim(L8, 5, 0);
	L8 = insereFim(L8, 4, 0);
	L8 = insereFim(L8, 0, 1);
	L8 = insereFim(L8, 2, 0);
	L8 = insereFim(L8, 1, 0);
	L8 = insereFim(L8, 7, 0);
	L8 = insereFim(L8, 0, 1);
	L8 = insereFim(L8, 8, 0);

	L9 = insereFim(L9, 2, 0);
	L9 = insereFim(L9, 6, 0);
	L9 = insereFim(L9, 7, 0);
	L9 = insereFim(L9, 4, 0);
	L9 = insereFim(L9, 0, 1);
	L9 = insereFim(L9, 0, 1);
	L9 = insereFim(L9, 0, 1);
	L9 = insereFim(L9, 9, 0);
	L9 = insereFim(L9, 1, 0);

	concatena(L1, L2);
	concatena(L2, L3);
	concatena(L3, L4);
	concatena(L4, L5);
	concatena(L5, L6);
	concatena(L6, L7);
	concatena(L7, L8);
	concatena(L8, L9);
	F -> ini = L1;
	F -> fim = L9;

}

//Método validando corretamente
int procuraValorNaLinha(Fila* F, int linha, int valor){
	int l = 1;

	//Recebe a primeira lista (L1)
	ListaD* aux = F -> ini;
	//recebe a proxima lista (L2)
	ListaD* ant = aux -> ant;

	//Caminha até a linha desejada
	while(l < linha){
		aux = ant;
		ant = aux -> ant;
		l++;
	}
	//Valida se o numero ja existe
	while(aux != NULL){
		if(aux -> info == valor) {
			printf("valor igual na linha\n");
			return 0;
		}
		aux = aux -> prox;
	}

	return 1;
}

//método validando corretamente
int procuraValorNaColuna(int coluna, int valor, Fila* F){
	int criterioDeParada = 1;
	int caminhaAteAColuna = 1;

	//Recebe a primeira lista (L1)
	ListaD* aux = F -> ini;
	//Recebe a segunda lista (L2)
	ListaD* ant = aux -> ant;

	for(criterioDeParada = 1; criterioDeParada < 9; criterioDeParada++){
		int i = 1;
		while(i < coluna){
			aux = aux -> prox;
			i++;
		}

		if(aux -> info == valor){
			printf("valor igual na coluna\n");
			return 0;
		} else {
			aux = ant;
			ant = aux -> ant;
		}
	}
	return 1;
}

int procuraValorNoQuadrante(int inicioLinha, int fimLinha, int inicioColuna, int fimColuna, int valor, Fila* F){

	//Variaveis responsavels para andar até o ponto determinado
	int linIni = 1;
	int linFim = 1;
	int colIni = 1;
	int colFim = 1;
	//Recebe a primeira lista (L1)
	ListaD* aux = F -> ini;
	//recebe a proxima lista (L2)
	ListaD* ant = aux -> ant;

	//caminha até a linha - Validação ok
	while(linIni < inicioLinha){
		aux = ant;
		ant = aux -> ant;
		linIni++;
	}

	//Caminha ate o inicio do quadrante
	while(colIni < inicioColuna){
		aux = aux -> prox;
		colIni++;
	}

	int i = 1;
	do{
		//caminha até o fim do quadrante
		for(int j = 1; j <= 3; j++){
			if(aux -> info == valor ){
				printf("Valor encontrado no quadrante\n");
				return 0;
			} else {
				aux = aux -> prox; //recebe o proximo valor da mesmalinha
			}

			//pula pra proxima linha do quadrante
			if(j == 3){
				if(ant != NULL){
					aux = ant;
					ant = aux -> ant;
					colIni = 1;
				}
					//printf("Pulou p/ linha: %d valor inicial:  %d\n, prox valor: %d", i, aux -> info, aux -> prox -> info);
				while(colIni < inicioColuna){
					aux = aux -> prox;
					colIni++;
				}
			}
		}

		i++;
	} while(i <=3);

	return 1;
}

int validaQuadrante(int linha, int coluna, int valor, Fila* F){


	int valida = 1;
	if(linha <= 3 && coluna <= 3){
		//Valida quadrante 1
		valida = procuraValorNoQuadrante(1,3,1,3, valor, F);
	} else if(linha <= 3 && coluna >= 4 && coluna <= 6){
		//Valida quadrante 2
		valida = procuraValorNoQuadrante(1,3,4,6, valor, F);
		//Valida quadrante 3
	} else if(linha <= 3 && coluna >= 7 && coluna <= 9){
		valida = procuraValorNoQuadrante(1,3,7,9, valor, F);
	}

	if(linha >= 4 && linha <= 6  && coluna <= 3){
		//Valida quadrante 4
		valida = procuraValorNoQuadrante(4,6,1,3, valor, F);
	} else if(linha >= 4  && linha <= 6 && coluna >= 4 && coluna <= 6){
		//Valida quadrante 5
		valida = procuraValorNoQuadrante(4,6,4,6, valor, F);
		//Valida quadrante 6
	} else if(linha >= 4  && linha <= 6 && coluna >= 7 && coluna <= 9){
		valida = procuraValorNoQuadrante(4,6,7,9, valor, F);
	}

	//Problema aqui
	if(linha >= 7 && linha <= 9 && coluna <= 3){
		//Valida quadrante 7
		valida = procuraValorNoQuadrante(7,9,1,3, valor, F);
	} else if(linha >= 7 && linha <= 9 && coluna >= 4 && coluna <= 6){
		//Valida quadrante 8
		valida = procuraValorNoQuadrante(7,9,4,6, valor, F);
		//Valida quadrante 9
	} else if(linha >= 7 && linha <= 9 && coluna >= 7 && coluna <= 9){
		valida = procuraValorNoQuadrante(7,9,7,9, valor, F);
	}

	if(valida != 0){
		return 1;
	} else{
		return 0;
	}
}

void validaValorUsuario(int valor){
	while(valor <= 0 || valor >= 10){
		printf("Valor inválido, insira um valor entre 1 e 9:");
		scanf("%d", &valor);
	}
}

void printMenu(Fila* F){
	int linha = 0;
	int coluna = 0;
	int valor = 0;

	imprime(F);
	printf("Informe a Linha:");
	scanf("%d", &linha);
		validaValorUsuario(linha);
	printf("\nInforme a Coluna:");
	scanf("%d", &coluna);
		validaValorUsuario(coluna);
	printf("\nInforme o Numero[1-9]:");
	scanf("%d", &valor);
		validaValorUsuario(valor);
	caminhaAteACelulaEInsere(F, linha, coluna, valor);		
	
}

void caminhaAteACelulaEInsere(Fila* F, int linha, int coluna, int valor){
	int l = 1;
	int c = 1;
	//Recebe a primeira lista (L1)
	ListaD* aux = F -> ini;
	//recebe a proxima lista (L2)
	ListaD* ant = aux -> ant;

	while(l < linha){
		aux = ant;
		ant = aux -> ant;
		l++;
	}

	while(c < coluna){
		aux = aux -> prox;
		c++;
	}

	int existeValorNaColuna = procuraValorNaColuna(coluna, valor, F);
	//printf("Coluna %d\n", existeValorNaColuna);
	int existeValorNaLinha = procuraValorNaLinha (F, linha, valor);
	//printf("Linha %d\n", existeValorNaLinha);
	int existeValorNoQuadrante = validaQuadrante(linha, coluna, valor, F);
	//printf("Quadrante %d\n", existeValorNoQuadrante);

	if(existeValorNaLinha == 0 || existeValorNaColuna == 0 || existeValorNoQuadrante == 0){
		printf("Valor não pode ser inserido pois viola as regras do jogo\n");
		//printf("Linha - %d Coluna - %d Quadrante - %d\n", existeValorNaLinha, existeValorNaColuna, existeValorNoQuadrante);
		printMenu(F);
		return;
	} else if(aux -> podeAlterar == 1){
		printf("Não é possivel inserir nessa posição.\n");
		printMenu(F);
		return;
	} else {
		aux -> info = valor;
		printMenu(F);

		return;
	}
}

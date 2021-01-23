typedef struct nodo* ptr_nodo;
struct nodo{
				elemento elem;
				ptr_nodo prox;
};

typedef struct {
				ptr_nodo lista;
				int tamanho;
			} lista_encadeada;

typedef lista_encadeada tipo_pilha;

/* ImplementaÃ§Ãµes */

int tamanho_pilha(lista_encadeada le) {
	return le.tamanho;
}


int obter_elemento_pilha(lista_encadeada le, elemento *e) {
	int j; 
    int i = 1;
	ptr_nodo pnodo;

	if ((i <= le.tamanho) && (i > 0)) {
		pnodo = le.lista;
		for(j=2;j<=i;j++)
			pnodo = pnodo->prox;
		*e = pnodo->elem;
      	return 1;
	}
	else {
		*e = VL_NULO;
      return 0;
	}
}


void inicializa_lista_pilha(lista_encadeada *le) {
	le->tamanho = 0;
	le->lista = NULL;
}


int incluir_elemento_pilha(lista_encadeada *le,  elemento e) {
	int j; 
    int i = 1;
    ptr_nodo pnodo_incluido, pnodo_anterior;

  	if ((i <= le->tamanho+1) && (i > 0)) {
      pnodo_incluido = (ptr_nodo)malloc(sizeof(struct nodo));
    	if (pnodo_incluido == NULL)
			return 0;   /* FALTA MEMÃ“RIA */
    	else {
       		pnodo_incluido->elem = e;
       		if (i == 1) {
       			pnodo_incluido->prox = le->lista;
          		le->lista = pnodo_incluido;
       		}
       		else {
          		pnodo_anterior = le->lista;
               		for (j=2; j<i; j++)
				pnodo_anterior = pnodo_anterior->prox;
          		pnodo_incluido->prox = pnodo_anterior->prox;
          		pnodo_anterior->prox = pnodo_incluido;
				}
       		le->tamanho++;
       		return 1;
    	}
   }
  else
    	return 0;    /* POSIÃ‡ÃƒO INVÃLIDA */
}


int alterar_elemento_pilha(lista_encadeada *le, int i, elemento e) {
	int j; ptr_nodo pnodo;
  	if ((i <= le->tamanho) && (i > 0)) {
     	pnodo = le->lista;
		for (j=2; j<=i;j++)
			pnodo = pnodo->prox;
      	pnodo->elem = e;
      	return 1;
	}
  	else
    		return 0; /* POSIÃ‡ÃƒO INVÃLIDA */
}


int excluir_elemento_pilha(lista_encadeada *le) {
    int i = 1;
	 int j; ptr_nodo pnodo_excluido, pnodo_anterior;
  	if ((i <= le->tamanho) && (i > 0)) {
    		if (i == 1) {
       			pnodo_excluido = le->lista;
       			le->lista = pnodo_excluido->prox;
		}
    		else {
       			pnodo_anterior = le->lista;
               		for (j=2;j<i; j++)
			pnodo_anterior =  pnodo_anterior->prox;
       			pnodo_excluido = pnodo_anterior->prox;
       			pnodo_anterior->prox = pnodo_excluido->prox;
		}
    		free(pnodo_excluido);
    		le->tamanho = le->tamanho - 1;
    		return 1;
	}
  	else
    		return 0; /* POSIÃ‡ÃƒO INVÃLIDA */
}


int tamanho_quantidade_nodos_pilha(lista_encadeada le){
	int j = 0;
	
	if(le.lista == NULL)
		return j;

	
	while(le.lista != NULL){
		le.lista = le.lista->prox;
		j++;
	}
	return j;
}


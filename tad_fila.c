typedef struct tipo_nodo* ptr_nodo_f;
struct tipo_nodo{
				elemento elem;
				ptr_nodo_f prox;
};

typedef struct {
				ptr_nodo_f lista;
				int tamanho;
			} lista_encadeada_f;

typedef lista_encadeada_f tipo_fila;

/* ImplementaÃ§Ãµes */

int tamanho_fila(lista_encadeada_f le) {
	return le.tamanho;
}


int obter_elemento_fila(lista_encadeada_f le, elemento *e) {
	int j; 
    int i = 1;
	ptr_nodo_f pnodo;

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


void inicializa_lista_fila(lista_encadeada_f *le) {
	le->tamanho = 0;
	le->lista = NULL;
}

int tamanho_quantidade_nodos_fila(lista_encadeada_f le){
	int j = 0;
	
	if(le.lista == NULL)
		return j;

	
	while(le.lista != NULL){
		le.lista = le.lista->prox;
		j++;
	}
	return j;
}

int incluir_elemento_fila(lista_encadeada_f *le,  elemento e) {
	int j; 
    int i = (tamanho_quantidade_nodos_fila(*le))+1;
    ptr_nodo_f pnodo_incluido, pnodo_anterior;

  	if ((i <= le->tamanho+1) && (i > 0)) {
      pnodo_incluido = (ptr_nodo_f)malloc(sizeof(struct tipo_nodo));
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


int alterar_elemento_fila(lista_encadeada_f *le, int i, elemento e) {
	int j; ptr_nodo_f pnodo;
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


int excluir_elemento_fila(lista_encadeada_f *le) {
    int i = 1;
	 int j; ptr_nodo_f pnodo_excluido, pnodo_anterior;
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






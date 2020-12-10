#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct LISTA{

    float notas;
    struct LISTA*NEXT;
    struct LISTA*LAST;
    
};

typedef struct dados{
	int data;
	char categoria[20];
	char materia[200];
	int codigo;
}Dados;

struct Fila {
 
    int capacidade;
    Dados *dados;
    int primeiro;
    int ultimo;
    int nItens; 
 
};





void provas(){ // calculo da media do aluno ou de quanto ele necessita para ser aprovado
	
	int nt,nf,i;
	int *pesos;
	float mnf=0,mf=0,np;
	int pnf =0,ps=0,pt=0;

	system("clear");

	printf("Número total de provas: ");
	scanf("%d" ,&nt);
	
	pesos = malloc(nt * sizeof(int));
	
	struct LISTA *lista;
    
	lista = calloc(1, sizeof(struct LISTA));
    
        if(lista == NULL){
        printf("Erro de alocação da memoria");
    	}
 
    	lista->NEXT = NULL;
    
    	lista->LAST=NULL;
	
	for(i=0;i<nt;i++){
		
		printf("Peso prova %d: ",(i+1));
		scanf("%d" ,&pesos[i]);
	}
	
	printf("Número de provas já feitas: ");
	scanf("%d" ,&nf);
	

	for(i=0;i<nf;i++){
		
		struct LISTA*atual;

		printf("Nota prova %d: " ,(i+1));
		scanf("%f" ,&(lista->notas));
		
		lista->NEXT = calloc(1, sizeof(struct LISTA));
        
		atual = lista;
		lista = lista->NEXT;
		lista->NEXT = NULL;
		lista->LAST = atual;
	
	}
	
	lista = lista->LAST;
	free(lista->NEXT);
	lista->NEXT=NULL;
	
	
	for(i=0;i<nt;i++){
		pt = pt + pesos[i];	
	}
	
	if(nf == nt){
		i = (nt-1);
		while(1){
			
			mf = mf + (lista->notas)*pesos[i];
      		  	
             
 	  	 	if(lista->LAST == NULL){
 	       		break;
 	   	
 	   		}
 	   		lista = lista->LAST;
			
			i--;
		}
		
		mf = mf/pt;
	
		printf("\nSua média final será de %.2f\n" ,mf);
	}
	
	else{
		i=(nf-1);
		
		while(1){
			
	
			mnf = mnf + ((lista->notas)*pesos[i]);
			pnf = pnf + pesos[i];	
			
			
			if(lista->LAST == NULL){
 	       		break;
 	   		}
 	   
 	   		lista = lista->LAST;
 	
			i--;
		}
	
		for(i=nf;i<nt;i++){
			ps = ps + pesos[i];	
		}
	
	
		np = ((6*pt) - mnf)/ps;
	
		printf("É necessário tirar no minímo %.2f na(s) %d prova(s) restante(s) para passar \n" ,np,(nt-nf));
		
	
	
	}

	while(lista != NULL){
		
		struct LISTA*next;
		next = lista->NEXT;
		free(lista);
		lista = NULL;
		lista = next;
	}
	
	free(pesos);
	

}

int faltas(int carga){ // calcula quantas faltas o aluno pode ter

	int numfal;

	numfal = 0.25 * carga;

	return numfal;

}

void criarFila( struct Fila *f, int c ) { 

	f->capacidade = c;
	f->dados = (Dados*) malloc (f->capacidade * sizeof(Dados));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void excluir(struct Fila *f, Dados dados){}

void inserir(struct Fila *f, Dados dados) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->dados[f->ultimo] = dados; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido

}

void mostrarFila(struct Fila *f,struct Fila *d, FILE* pont_arq){
	struct tm *data_hora_atual;       
  time_t segundos;
  time(&segundos);     
  data_hora_atual = localtime(&segundos);
	printf("\nData de hoje : %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano  
	int cont, i, cont2, i2, k2;
	int k, h=1, h2=1;
	
	k = d->primeiro;

	fprintf(pont_arq,"\nAtividades:\n");

	for ( cont=0, (i= f->primeiro); cont < f->nItens; cont++){	
		
		fprintf(pont_arq, "%d | %s - %s: %d/%d\n", h, f->dados[i++].categoria,d->dados[i].materia, f->dados[i].data, d->dados[k++].data);
		f->dados[i].codigo = h;
		if (i == f->capacidade)
			i=0;
			h++;

	}
	
	k2 = d->primeiro;

	printf("\nAtividades:\n");
	printf("\n");
	for ( cont2=0, (i2= f->primeiro); cont2 < f->nItens; cont2++){	
		
		printf("%d | %s - %s: %d/%d\n", h2, f->dados[i2++].categoria,d->dados[i2].materia, f->dados[i2].data, d->dados[k2++].data);
		f->dados[i2].codigo = h2;
		if (i2 == f->capacidade)
			i2=0;
			h2++;

	}
	printf("\n");

}




void atividades(FILE* pont_arq){
	
	int v,c,i;
	struct Fila umaFila;
	struct Fila doisFila;
	Dados dados;
	int d,m,e;
	int w=1;
	char materia[200];
	char categoria[20];

	while(1){
		printf("\n1 - Inserir atividades\n");
		printf("2 - Ver atividades\n");
		printf("3 - Excluir atividade\n");
		printf("4 - Encerrar\n");
		printf("\n");

		scanf("%d",&e);

		if(e==1){
			system("clear");				
			printf("Quantas atividades?\n");
			scanf("%d" ,&c);

			criarFila(&umaFila, c);
			criarFila(&doisFila,c);
	
			for(i=0;i<c;i++){
				printf("Data de entrega da atividade %d:  ",i+1);
				scanf("%d/%d" ,&d,&m);

				printf("Categoria (Prova, Tarefa, Trabalho...): ");
				scanf("%s", categoria);

				printf("Matéria: ");
				scanf("%s", materia);

				dados.data = d;
				strcpy(dados.categoria, categoria);
				strcpy(dados.materia, materia);

				inserir(&umaFila,dados);

				dados.data = m;
				strcpy(dados.categoria, categoria);
				strcpy(dados.materia, materia);

				inserir(&doisFila,dados);
	
			}

		}

		if(e==2){
			system("clear");
			mostrarFila(&umaFila,&doisFila,pont_arq);
		}
		if(e==3){

		}
		if(e==4) break;

	}
	
	
	
	


}

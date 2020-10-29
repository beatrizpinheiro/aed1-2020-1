#include <stdio.h>
#include <stdlib.h>

struct LISTA{

    float notas;
    struct LISTA*NEXT;
    struct LISTA*LAST;
    
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
	
		printf("Sua média final será de %.2f\n" ,mf);
	}
	
	else{
		i=(nf-1);
		
		while(1){
			
	
			mnf = mnf + ((lista->notas)*pesos[i]);
			pnf = pnf + pesos[i];	
			
			printf("notas : %f\n" ,lista->notas);
			
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





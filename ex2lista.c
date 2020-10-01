#include <stdio.h>
#include <malloc.h>


typedef struct{

	int inim;


} lista;


void cria_lista(lista *x, int n){

	int i;
	
	for(i=0;i<n;i++){
		scanf("%d",&x[i].inim); 
	}


}

void numeros_lista(lista *x, int n){

	int i;
	
	for(i=0;i<n;i++){
		printf("%d ",x[i].inim);
	}



}

void inserir(lista *x, int n, int p, int e){

	int i,k;

	for(i=0;i<n;i++){
		if( x[i].inim == e){
			k = i;
		}
		
	}	
	
	for(i=(n+1);i>k;i--){
		x[i].inim = x[i-1].inim;
	}	
	
	x[k+1].inim = p;
	
	printf("inserido %d\n" ,p);

}

void remover(lista *x, int n, int p){

	int i,k;

	for(i=0;i<n;i++){
		if( x[i].inim == p){
			k = i;
		}	
	}	
	
	for(i=k;i<n;i++){
		x[i].inim = x[i+1].inim;	
	}
	
	printf("removido %d\n" ,p);
	
	

}

int quantidade(lista *x,int n, int p, int e){
	
	int i,k;
	int cont = 0;

	for(i=0;i<n;i++){
		if( x[i].inim == p || x[i].inim == e ){
			k = i;
			
			break;
		}	
	}	
	
	for(i=(k+1);i<n;i++){
		if(x[i].inim == p || x[i].inim == e){
			break;
		}
		else{
			cont++;
		}
	
	}
	
	return cont;

}

int main(){

	int n,i;
	char a;
	int p,e;
	
	scanf("%d",&n);

	lista *x = (lista*) malloc (10*n * sizeof (lista));
	
	cria_lista(x,n);	
	
	
	
	while(1){
		scanf("%c",&a);
		
		if(a == 'I'){
			scanf("%d %d" ,&p,&e);
			inserir(x,n,p,e);
			n = n+1;
		}
		if(a == 'M'){
			numeros_lista(x,n);
		}
		if(a == 'F'){
			printf("fim\n");
			return 0;
		}
		if(a == 'R'){
			scanf("%d",&p);
			remover(x,n,p);
			n = n-1;
		}
		if(a == 'C'){
			scanf("%d %d" ,&p,&e);
			printf("quantidade %d\n" ,(quantidade(x,n,p,e)));
		}
	
	
	
	}


	free(x);


  return 0;
}

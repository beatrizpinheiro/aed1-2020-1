#include <stdio.h>
#include <stdlib.h>


void provas(){

	int nt,nf,i;
	int *pesos;
	float *notas;
	float mnf=0,mf=0,np;
	int pnf =0,ps=0,pt=0;

	printf("Número total de provas: ");
	scanf("%d" ,&nt);
	
	pesos = malloc(nt * sizeof(int));
	
	for(i=0;i<nt;i++){
		
		printf("Peso prova %d: ",(i+1));
		scanf("%d" ,&pesos[i]);
	}
	
	printf("Número de provas já feitas: ");
	scanf("%d" ,&nf);
	
	notas = malloc(nf * sizeof(float));
	
	for(i=0;i<nf;i++){
		
		printf("Nota prova %d: " ,(i+1));
		scanf("%f" ,&notas[i]);
	}
	
	for(i=0;i<nt;i++){
		pt = pt + pesos[i];	
	}
	
	if(nf == nt){
		for(i=0;i<nt;i++){
			mf = mf + notas[i]*pesos[i];
		}
		
		mf = mf/pt;
	
		printf("Sua média final será de %.2f\n" ,mf);
	}
	
	else{
	
		for(i=0;i<nf;i++){
	
			mnf = mnf + notas[i]*pesos[i];
			pnf = pnf + pesos[i];		
	
		}
	

	
		printf("%f\n" ,mnf);
	
		for(i=nf;i<nt;i++){
			ps = ps + pesos[i];	
		}
	
	
		printf("%d\n" ,pt);
	
		np = ((6*pt) - mnf)/ps;
	
		printf("É necessário tirar no minímo %.2f na(s) %d prova(s) restante(s) para passar \n" ,np,(nt-nf));
	
	
	}
}



int main(){

	provas();




	return 0;
}

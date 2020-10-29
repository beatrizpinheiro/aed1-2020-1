#include <stdio.h>
#include <stdlib.h>

typedef struct{

	char nome[100];  
	int matricula; 
	char curso[100];
	int quantMaterias;

} ALUNO; // dados do aluno

typedef struct{

	char nomeAula[50];
	char diaAula[10];
	int cargaH;
	int quantDiasSemana; 
	int quantAulaSemana;
	int numAulasDia;	
	int horario;
	char turno[20];
	char** diasSemana;


} AULA; // dados das aulas


int faltas(int carga){ // calcula quantas faltas o aluno pode ter

	int numfal;

	numfal = (25/100) * carga;

	return numfal;

}

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
	
	
		for(i=nf;i<nt;i++){
			ps = ps + pesos[i];	
		}
	
	
		np = ((6*pt) - mnf)/ps;
	
		printf("É necessário tirar no minímo %.2f na(s) %d prova(s) restante(s) para passar \n" ,np,(nt-nf));
	
	
	}

	
	free(notas);
	free(pesos);

}

ALUNO cadastro(ALUNO *x, AULA *y){
    ALUNO x;
	int i,k,d;
	FILE *pont_arq;

	pont_arq = fopen("EAD.txt", "a");
	

	system("clear");

	printf("Nome: ");
	
	scanf("%[^\n]s" ,x.nome);
	getchar();
	fprintf(pont_arq, "%s\n", x.nome);
	
	printf("Matricula: ");
	scanf("%d%*c" ,&x.matricula);
	fprintf(pont_arq, "%d\n", x.matricula);
	
	printf("Curso: ");
	scanf("%[^\n]s" ,x.curso);
	getchar();
	fprintf(pont_arq, "%s\n", x.curso);
	
	system("clear");
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x.quantMaterias);
	fprintf(pont_arq, "%d\n", x.quantMaterias);
	
	
	AULA* y = (AULA*) malloc(x.quantMaterias * sizeof(AULA));
	
	

	for(i=0;i<(x.quantMaterias);i++){

		printf("Nome da matéria %d: " ,(i+1));
		scanf("%s" ,y[i].nomeAula);
		getchar();
			
		printf("Carga horária: ");
		scanf("%d" ,&y[i].cargaH);
			
		y[i].quantAulaSemana = y[i].cargaH/16; //quantas aulas tem essa materia por semana

		printf("Quantos dias da semana você tem essa aula?: ");
		scanf("%d" ,&y[i].quantDiasSemana);

		y[i].numAulasDia = y[i].quantAulaSemana/y[i].quantDiasSemana;
			
		y[i].diasSemana = (char**) malloc(y[i].quantDiasSemana * 10 * sizeof(char*));
			
		for(k=0;k<y[i].quantAulaSemana;k++){
				
			for(d=0;d<y[i].quantDiasSemana;d++){
				y[i].diasSemana[d] = (char**) malloc(10 * sizeof(char*));
				printf("Em quais dias da semana você tem essa aula? Separe com espaços.");
				scanf("%s" ,&y[i].diasSemana[d]); //exemplo: segunda e quarta
			}
			getchar();

			printf("Turno %d: ",k+1);
			scanf("%s",y[k].turno);
			printf("\n");

 			getchar();

			printf("Horario da aula %d: ",k+1);
			scanf("%d",&y[k].horario);
			printf("\n");
		}
			
		free(y[i].diasSemana);
		free(y);	
	}
}

int main(){
    
	
	
	
	
			
			


	return 0;
}

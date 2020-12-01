#include <stdio.h>
#include <stdlib.h>
#include "provas.h"

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


/*ALUNO cadastro(ALUNO *x){
	int i,k,d;
	FILE *pont_arq;

	pont_arq = fopen("EAD.txt", "a");
	

	

	printf("Nome: ");
	
	scanf("%[^\n]s" ,x->nome);
	getchar();
	fprintf(pont_arq, "%s\n", x->nome);
	
	printf("Matricula: ");
	scanf("%d%*c" ,&x->matricula);
	fprintf(pont_arq, "%d\n", x->matricula);
	
	printf("Curso: ");
	scanf("%[^\n]s" ,x->curso);
	getchar();
	fprintf(pont_arq, "%s\n", x->curso);
	
	system("clear");
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x->quantMaterias);
	fprintf(pont_arq, "%d\n", x->quantMaterias);
	
	
	AULA* y = (AULA*) malloc(x->quantMaterias * sizeof(AULA));
	
	

	for(i=0;i<(x->quantMaterias);i++){

		printf("Nome da matéria %d:" ,(i+1));
		scanf("%s" ,y[i].nomeAula);
		getchar();
			
		printf("Carga horária: ");
		scanf("%d" ,&y[i].cargaH);
			
		y[i].quantAulaSemana = y[i].cargaH/16; //quantas aulas tem essa materia por semana

		printf("Quantos dias da semana você tem essa aula?:\n");
		scanf("%d" ,&y[i].quantDiasSemana);


		y[i].numAulasDia = y[i].quantAulaSemana/y[i].quantDiasSemana; //número de aulas da matéria por dia
			
		y[i].diasSemana = (char**) malloc(y[i].quantDiasSemana * 10 * sizeof(char*)); //dias em que a pessoa tem essa aula
			
		for(k=0;k<y[i].quantAulaSemana;k++){
			
			printf("Em quais dias da semana você tem essa aula? Separe com enter\n");
			for(d=0;d<y[i].quantDiasSemana;d++){
				y[i].diasSemana[d] = (char**) malloc(10 * sizeof(char*));
				printf("Dia 1: ");
				scanf("%s" ,&y[i].diasSemana[d]); //exemplo: segunda e quarta
				printf("\n");
			}
			getchar();

			printf("Turno %d:\n",k+1);
			scanf("%s",y[k].turno);
			printf("\n");

 			getchar();

			printf("Horario da aula %d:\n",k+1);
			scanf("%d",&y[k].horario);
			printf("\n");
		}
			
	}
}*/

int main(){
    
	int a,h,c;
	int i,k,d;
	char matcarg[100];
	
	
	ALUNO *x = (ALUNO*) malloc(sizeof(ALUNO));
	
	printf("Faça seu cadastro:\n");
	
	FILE *pont_arq;

	pont_arq = fopen("EAD.txt", "a");
	

	printf("Nome: ");
	
	scanf("%[^\n]s" ,x->nome);
	getchar();
	fprintf(pont_arq, "Nome do aluno: %s\n", x->nome);
	
	printf("Matricula: ");
	scanf("%d%*c" ,&x->matricula);
	fprintf(pont_arq, "Matrícula: %d\n", x->matricula);
	
	printf("Curso: ");
	scanf("%[^\n]s" ,x->curso);
	getchar();
	fprintf(pont_arq, "Curso: %s\n", x->curso);
	
	system("clear");
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x->quantMaterias);
	fprintf(pont_arq, "%d matérias\n", x->quantMaterias);
	
	
	AULA* y = (AULA*) malloc(x->quantMaterias * sizeof(AULA));
	
	

	for(i=0;i<(x->quantMaterias);i++){

		printf("Nome da matéria %d:" ,(i+1));
		scanf("%s" ,y[i].nomeAula);
		getchar();
		fprintf(pont_arq, "%s", y[i].nomeAula);
			
		printf("Carga horária: ");
		scanf("%d" ,&y[i].cargaH);
		fprintf(pont_arq, "- %d horas", y[i].cargaH);
			
		y[i].quantAulaSemana = y[i].cargaH/16; //quantas aulas tem essa materia por semana

		printf("Quantos dias da semana você tem essa aula?:\n");
		scanf("%d" ,&y[i].quantDiasSemana);
		fprintf(pont_arq, "- %d dias por semana\n", y[i].quantDiasSemana);
	}
	
	
	while(1){
		printf("1- Calcular média das provas\n2- Calcular presença\n3-Finalizar\n");
		
		scanf("%d" ,&a);
		
		if(a==1)provas();
		if(a==2){
			printf("Escolha a matéria para calcular preseça\n");	
			for(h=0;h<(x->quantMaterias);h++){
				
				printf("%d-%s\n" ,(h+1),y[h].nomeAula);
			}
			scanf("%d" ,&c);
			printf("Pode ter até %d faltas\n " ,faltas(y[c-1].cargaH));
			fprintf(pont_arq, "Pode ter até %d faltas em %s\n" ,faltas(y[c-1].cargaH),y[c-1].nomeAula);
		}	
		if(a==3){
			fprintf(pont_arq, "\n\n");
			break;
		}	
	
	
			
			
	}

	return 0;
}


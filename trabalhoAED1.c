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



int main(){

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
			
			y->diasSemana = (char*) malloc(y[i].quantDiasSemana * sizeof(char*));
			y[i].diasSemana = (int*) malloc(10 * sizeof(int)); 			
			
			for(k=0;k<y[i].quantAulaSemana;k++){
				
				for(d=0;d<y[i].quantDiasSemana;d++){
					printf("Em quais dias da semana você tem essa aula? Separe com espaços.");
					scanf("%s" ,&y[d].diasSemana);
				}
				getchar();

				printf("Turno %d: ",k+1);
				scanf("%s",&y[k].turno);
				printf("\n");

 				getchar();

				printf("Horario da aula %d: ",k+1);
				scanf("%d",&y[k].horario);
				printf("\n");
			}
			
			free(y[i].diasSemana);
			free(y);
		}
	
	
			
			


	return 0;
}

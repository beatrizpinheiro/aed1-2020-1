#include <stdio.h>
#include <stdlib.h>

typedef struct{

	char nome[100];  
	int matricula; 
	char curso[100];
	char aula[50];
	int quantaula;
	char diaaula[10];
	int cargah;
	int aulasemana;
	int horario[10];
	int dia[10];


} ALUNO; // dados do aluno



int faltas(int carga){ // calcula quantas faltas o aluno pode ter

	int numfal;

	numfal = (25/100) * carga;

	return numfal;

}



int main(){

	ALUNO x;
	int i,k;
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
	scanf("%d" ,&x.quantaula);
	fprintf(pont_arq, "%d\n", x.quantaula);
	
	ALUNO* y = (ALUNO*) malloc(x.quantaula * sizeof(ALUNO));
	
	
	

	for(i=0;i<(x.quantaula);i++){

			printf("Nome da matéria %d: " ,(i+1));
			scanf("%s" ,y[i].aula);
			getchar();
			
			printf("Carga horária: ");
			scanf("%d" ,&y[i].cargah);
			
			y[i].aulasemana = y[i].cargah/16; //quantas aulas tem essa materia por semana
			
			
			for(k=0;k<y[i].aulasemana;k++){
				
				printf("Dia da aula %d: " ,k+1);
				// scanf("%d" ,// onde guardar os dias de cada materia?);
				 
				printf("Horario da aula %d: ",k+1);
				// scanf("%d" ,// onde guardar os horarios de cada materia?);
				printf("\n");
			}
			
		}
	
	
			
			






	return 0;
}

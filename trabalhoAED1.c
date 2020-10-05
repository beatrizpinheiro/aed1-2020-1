#include <stdio.h>
#include <stdlib.h>

typedef struct{

	char nome[100];  
	int matricula; 
	char curso[100];
	char aula[50][50];
	int quantaula;
	char diaaula[10];
	


} ALUNO; // dados do aluno





int main(){

	ALUNO x;
	ALUNO y[200];
	int i;


	system("clear");

	printf("Nome: ");
	
	scanf("%[^\n]s" ,x.nome);
	getchar();
	
	printf("Matricula: ");
	scanf("%d%*c" ,&x.matricula);
	
	printf("Curso: ");
	scanf("%[^\n]s" ,x.curso);
	getchar();
	
	system("clear");
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x.quantaula);
	
	
	printf("%s\n",x.nome);
	printf("%d\n",x.matricula);
	printf("%s\n",x.curso);
	printf("%d\n",x.quantaula);

	

	for(i=0;i<(x.quantaula);i++){
		for(k=0;k<(x.quantaula);i++){

			printf("Nome da matéria: %d" ,(i+1));
			scanf("%[^\n]s" ,y.aula[i][k]);
			getchar();
	
		}
	
	
	}
	







	return 0;
}

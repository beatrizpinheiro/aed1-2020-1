#include <stdio.h>


typedef struct{

	char nome[100];  
	int matricula; 
	char curso[100];
	char aula[50];
	int quantaula;
	char diaaula[10];
	


} ALUNO; // dados do aluno





int main(){

	ALUNO x;


	printf("Nome: ");
	
	scanf("%[^\n]s" ,x.nome);
	getchar();
	
	printf("Matricula: ");
	scanf("%d%*c" ,&x.matricula);
	
	printf("Curso: ");
	scanf("%[^\n]s" ,x.curso);
	getchar();
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x.quantaula);
	
	
	printf("%s\n",x.nome);
	printf("%d\n",x.matricula);
	printf("%s\n",x.curso);
	printf("%d\n",x.quantaula);











	return 0;
}

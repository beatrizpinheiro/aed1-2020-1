#include <stdio.h>
#include <stdlib.h>
#include "provas.h"
#include <string.h>

typedef struct{

	char nome[100];  
	int matricula; 
	char curso[100];
	int quantMaterias;
	char turno2[20];

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
	char segundac[20];
	char tercac[20];
	char quartac[20];
	char quintac[20]; 
	char sextac[20];
	


} AULA; // dados das aulas



void formar(AULA *z, ALUNO *x){

	int i;
	
		if(x->turno2[0] == 'n' || x->turno2[0] == 'N'){ 
	
			strcpy(z[0].segundac, "Descanso");
			strcpy(z[5].segundac, "Estudo");
			strcpy(z[5].tercac, "Estudo");
			strcpy(z[0].tercac, "Descanso");
			strcpy(z[5].quartac, "Estudo");
			strcpy(z[0].quartac, "Descanso");
			strcpy(z[5].quintac, "Estudo");
			strcpy(z[0].quintac, "Descanso");
			strcpy(z[5].sextac, "Estudo");
			strcpy(z[0].sextac, "Descanso");
		}
		else{
		
			strcpy(z[5].segundac, "Descanso");
			strcpy(z[0].segundac, "Estudo");
			strcpy(z[0].tercac, "Estudo");
			strcpy(z[5].tercac, "Descanso");
			strcpy(z[0].quartac, "Estudo");
			strcpy(z[5].quartac, "Descanso");
			strcpy(z[0].quintac, "Estudo");
			strcpy(z[5].quintac, "Descanso");
			strcpy(z[0].sextac, "Estudo");
			strcpy(z[5].sextac, "Descanso");
		
		
		}	
		
		
		strcpy(z[1].segundac, "Estudo");
		strcpy(z[2].segundac, "Almoço");
		strcpy(z[3].segundac, "Estudo");
		strcpy(z[4].segundac, "Estudo");
		
		strcpy(z[1].tercac, "Estudo");
		strcpy(z[2].tercac, "Almoço");
		strcpy(z[3].tercac, "Estudo");
		strcpy(z[4].tercac, "Estudo");
	
		strcpy(z[1].quartac, "Estudo");
		strcpy(z[2].quartac, "Almoço");
		strcpy(z[3].quartac, "Estudo");
		strcpy(z[4].quartac, "Estudo");
		
		strcpy(z[1].quintac, "Estudo");
		strcpy(z[2].quintac, "Almoço");
		strcpy(z[3].quintac, "Estudo");
		strcpy(z[4].quintac, "Estudo");
		
		strcpy(z[1].sextac, "Estudo");
		strcpy(z[2].sextac, "Almoço");
		strcpy(z[3].sextac, "Estudo");
		strcpy(z[4].sextac, "Estudo");
		
		
		
	

	


}

void Estudo(ALUNO *x, AULA *y, AULA *z, FILE *pont_arq){

	int i,k,l,d=(-1),g,s;
	int segunda[6] = {8,10,12,14,16,18};


	for(i=0;i<(x->quantMaterias);i++){
		for(g=0;g<6;g++){
			if(y[i].horario == segunda[g]){
				s = g;
			}
			
		}
		
		
		for(l=0;l<=y[i].quantDiasSemana;l++){
			
			d++;	
			if(y[d].turno[0] == 's' || (y[d].turno[0] == 'S')){
				if(y[d].turno[2] == 'g'){
					strcpy(z[s].segundac, y[i].nomeAula);
				}
				if(y[d].turno[2] == 'x'){
					strcpy(z[s].sextac, y[i].nomeAula);
				}
			} 
			
			if(y[d].turno[0] == 'q'|| y[d].turno[0] == 'Q'){
				if(y[d].turno[2] == 'a'){
					strcpy(z[s].quartac, y[i].nomeAula);
					
		
				}
				if(y[d].turno[2] == 'i'){
					strcpy(z[s].quintac, y[i].nomeAula);
					
				
				}
			} 
			if(y[d].turno[0] == 't' || y[d].turno[0] == 'T'){
				strcpy(z[s].tercac, y[i].nomeAula);
			} 
				
			
		}
	}
	system("clear");
	
	
	printf("\t\tSEGUNDA\tTERÇA\tQUARTA\tQUINTA\tSEXTA\n");
	fprintf(pont_arq,"\n\t\tSEGUNDA\tTERÇA\tQUARTA\tQUINTA\tSEXTA\n");
	
	int f=8;
	
	for(i=0;i<6;i++){
		printf("%d:00-%d:40:\t" ,f,f+1);
		fprintf(pont_arq,"%d:00-%d:40:\t" ,f,f+1);
		f = f+2;
		printf("%s   ",z[i].segundac);
		fprintf(pont_arq, "%s   "   ,z[i].segundac);
		printf("%s   ",z[i].tercac);
		fprintf(pont_arq, "%s   "   ,z[i].tercac);
		printf("%s   ",z[i].quartac);
		fprintf(pont_arq, "%s   "   ,z[i].quartac);
		printf("%s   ",z[i].quintac);
		fprintf(pont_arq, "%s   "   ,z[i].quintac);
		printf("%s\n",z[i].sextac);
		fprintf(pont_arq, "%s   "   ,z[i].sextac);	
	}



}


int main(){
    
	int a,h,c;
	int i,k,d,l,o=(-1);
	
	
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
	
	printf("Turno(Ex: Noturno,Integral.): ");
	scanf("%s" ,x->turno2);
	getchar();
	fprintf(pont_arq, "Turno: %s\n", x->turno2);
	
	printf("Quantidade de materias: ");
	scanf("%d" ,&x->quantMaterias);
	fprintf(pont_arq, "%d matérias\n", x->quantMaterias);
	
	
	
	AULA* y = (AULA*) malloc(x->quantMaterias * sizeof(AULA));
	AULA* z = (AULA*) malloc(36 * sizeof(AULA));
	
	system("clear");

	
	for(i=0;i<(x->quantMaterias);i++){

				printf("Nome da matéria %d (Ex: AED, Fisíca):" ,(i+1));
				scanf("%s" ,y[i].nomeAula);
				getchar();
				fprintf(pont_arq, "%s", y[i].nomeAula);
					
				printf("Carga horária(em horas): ");
				scanf("%d" ,&y[i].cargaH);
				fprintf(pont_arq, "- %d horas", y[i].cargaH);
					
				y[i].quantAulaSemana = y[i].cargaH/16; //quantas aulas tem essa materia por semana

				printf("Quantos dias da semana você tem essa aula?\n");
				scanf("%d" ,&y[i].quantDiasSemana);
				fprintf(pont_arq, "- %d dias por semana\n", y[i].quantDiasSemana);
				
				printf("Qual o horario da aula?\n");
				scanf("%d" ,&y[i].horario);
				
				printf("Em quais dias da semana?\n");
				
				for(l=0;l<y[i].quantDiasSemana;l++){
					
					o++;
					scanf("%s" ,y[o].turno);			
					getchar();
				}
				o++;
				
			}
		
	
	while(1){
		printf("1- Calcular média das provas;\n");
		printf("2- Calcular Presença;\n");
		printf("3- Consultar Cronograma de Estudos;\n");
		printf("4- Organizar Atividades;\n");
		printf("5-Finalizar.\n");
		
		scanf("%d" ,&a);
		
		if(a==1)provas();
		
		if(a==2){
			printf("Escolha a matéria para calcular preseça\n");	
			for(h=0;h<(x->quantMaterias);h++){
				
				printf("%d-%s\n" ,(h+1),y[h].nomeAula);
			}
			scanf("%d" ,&c);
			printf("Pode ter até %d faltas\n" ,faltas(y[c-1].cargaH));
			fprintf(pont_arq, "Pode ter até %d faltas em %s\n" ,faltas(y[c-1].cargaH),y[c-1].nomeAula);
		}	
		
		if(a==3){
			
			formar(z,x);
			Estudo(x,y,z,pont_arq);
		}
		
		if(a==4){
			system("clear");
			atividades(pont_arq);
		}
		
		if(a==5){
			fprintf(pont_arq, "\n\n");
			break;
		}			
			
	}
	
	
	

	return 0;
}


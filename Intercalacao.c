#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <string.h>
#include <locale.h>
#define MAX 1000
clock_t tempoInicial;

FILE *numeros;
FILE *fitaum;
FILE *fitadois;
FILE *fitatres;
FILE *fitaquatro;
FILE *fitacinco;
FILE *fitaseis;
FILE *ordem;

void mostraArquivo(){
	int x;
	rewind(numeros);
	if(numeros==NULL){
		printf("\nVazio!\n");
		exit(1);
	}
	printf("\nMostra Arquivos:\n");
	while( !feof(numeros) ){
		fscanf(numeros,"%d", &x);
		printf("\n %d \n", x);
		system("pause");
	}
}

void resetaVetor(int v[], int n){
	int i;
	for(i=0;i<n;i++){
		v[i]=-1;	
	}
	
}

void geraArquivo(int n){
	int i,ale;
	rewind(numeros);
	for(i=0;i<n;i++){
		ale = rand()%MAX;
		fprintf(numeros,"%d\n",ale);
		printf("\n %d \n", ale);
		
	}
}

void insertion(int v[],int tam){
	int i,j,aux;
	tempoInicial = clock();
	for(i=0;i<tam;i++){
		aux=v[i];
		j=i-1;
		while(j>=0 && v[j]>aux){
			v[j+1]=v[j];
			j=j-1;
		}
		v[j+1]=aux;
	}
	tempoInicial = clock() - tempoInicial;
	//printf("\n\t INSERTION: \t\n");
	//printf("\nN=%d ; TEMPO:%6.8f mS\n", tam, ((double)tempoInicial) / ((CLOCKS_PER_SEC/1000)) );
	//system("pause");	
}

void organiza(){
	
}

void distribui(int tam){
	int i,j,cont=0,num;
	int v[10];
	
	resetaVetor(v,10);//inicia vetor auxiliar
	//reinicia os ponteiros dos arquivos
	rewind(numeros);
	rewind(fitaum);
	rewind(fitadois);
	rewind(fitatres);
	//laço para percorrer toda a lista de números
	while( !feof(numeros) ){
		cont++;
	}
	for(j=0;j<cont;j++ ){
		
		i=0;
		while(num>=0 && i<tam) {//preenche o vetor
			
			fflush(stdin);
			fscanf(numeros,"%d\n",&num);
			printf("\n Vamos:%d\n",num);
			v[i]=num;
			i++;
		}
		insertion(v,i);//ordena o vetor na "memória principal"
		for(i=0;i<tam;i++){//preenche a 1
			if(v[i]!=-1)
				fprintf(fitaum,"%d:",v[i]);
		}
		fprintf(fitaum,"|\n");
		
		i=0;
		while(num>=0 && i<tam){//preenche o vetor
			fflush(stdin);
			fscanf(numeros,"%d\n",&num);
			printf("\n Vamos:%d\n",num);
			v[i]=num;
			i++;
		}
		insertion(v,i);//ordena o vetor na "memória principal"
		for(i=0;i<tam;i++){//preenche a 2
			if(v[i]!=-1)
				fprintf(fitadois,"%d:",v[i]);
		}
		fprintf(fitadois,"|\n");
		
		i=0;
		while(num>=0 && i<tam){//preenche o vetor
			fflush(stdin);
			fscanf(numeros,"%d\n",&num);
			printf("\n Vamos:%d\n",num);
			v[i]=num;
			i++;
		}
		insertion(v,i);//ordena o vetor na "memória principal"
		for(i=0;i<tam;i++){//preenche a 3
			if(v[i]!=-1)
				fprintf(fitatres,"%d:",v[i]);
		}
		fprintf(fitatres,"|\n");
		
		system("pause");
	}
	
}

int main (){
	int ale,i,tamanhoMemoria=0,opc=0,quant=0;
	
	int fita1[1000];
	int fita2[1000];
	int fita3[1000];
	int fita4[1000];
	int fita5[1000];
	int fita6[1000];
	
	int memoria[10];
	
	srand(time(NULL));
	
	numeros = fopen("numeros.txt","w+");
	if( numeros == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}
	
	ordem = fopen("ordem.txt","r+");
	if( ordem == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}


	fitaum = fopen("fita1.txt","w+");
	if( fitaum == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	fitadois = fopen("fita2.txt","w+");
	if( fitadois == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	fitatres = fopen("fita3.txt","w+");
	if( fitatres == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	fitaquatro = fopen("fita4.txt","w+");
	if( fitaquatro == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	fitacinco = fopen("fita5.txt","w+");
	if( fitacinco == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	fitaseis = fopen("fita6.txt","w+");
	if( fitaseis == NULL){
	        printf("\n Nao foi possivel abrir o arquivo.\n");
	        //system("pause");
	        exit(1);
	}

	
	while(tamanhoMemoria<1 || tamanhoMemoria>11){
		printf("\n Digite o tamanho da memoria: (MAX 10) \n");
		scanf("%d", &tamanhoMemoria);
	}
	resetaVetor(memoria, tamanhoMemoria);//inicia


	while(quant<1 || quant>1000000){
		printf("\n Digite o tamanho da lista: (MAX 1 milhao) \n");
		scanf("%d", &quant);
	}
	geraArquivo(quant);
	
	
	while(opc!=-1){
		system("cls");
		printf("\n---MENU---\n");
		printf("\n[1] para gerar novamente lista de arquivos:\n");
		printf("\n[2] para ordenar lista de arquivos:\n");
		printf("\n[-1] para sair:\n");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				printf("\nGerando....\n");
				geraArquivo(quant);
				system("pause");
				break;
			case 2:
				printf("\nHora da Pitomba!\n");
				//mostraArquivo();
				//system("pause");
				distribui(tamanhoMemoria);
				system("pause");
				break;
			case -1:
				break;
			default:
				printf("\nEntrada inválida!\n");
				system("pause");
				break;
			
		}
	
	}

	printf("\nSaindo...\n");
	
	fclose (numeros);
	fclose (ordem);
	fclose (fitaum);
	fclose (fitadois);
	fclose (fitatres);
	fclose (fitaquatro);
	fclose (fitacinco);
	fclose (fitaseis);
	
	return 0;
}

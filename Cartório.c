#include <stdio.h>// biblioteca de comunica��o do usu�rio
#include <stdlib.h>// Aloca espa�os na mem�ria
#include <locale.h>// biblioteca de textos por regi�o
#include <string.h> // Biblioteca para armazenar string
int registro()// responsavel por cadastrar usu�rios no sistema
{
	printf ("voc� selecionou registro de usu�rios\n");
	//inicio da cria��o de v�riaveis/ string
	char arquivo [40];
	char CPF [40];
	char Nome [40];
	char Sobrenome [40];
	char cargo [40];
	//final da cria��o de v�riaveis/ string
	printf ("Digite o cpf a ser cadastrado:  "); // Digite o cpf
	scanf ("%s",CPF); //%s refere-se a string
	//coletando informa��es do usu�rio
	
	strcpy (arquivo, CPF); // responsavel por copiar as string
	
	FILE *file; // cria o arquivo no banco de dados
    file = fopen (arquivo, "w"); //cria o arquvo "w" significa escrever
	fprintf (file,CPF);// salvo o valor da variavel
	fclose (file); // fecho o arquivo
	
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualizar
	fprintf (file, ",");
	fclose (file);
	
	printf ( "Digite o nome a ser cadastrado:  "); // digite o nome
	scanf ("%s", Nome);
	//coletando informa��es do usu�rio
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file,Nome);
	fclose (file);
	
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, ",");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: "); // digite o sobrenome
	scanf ("%s", Sobrenome);
	//coletando informa��es do usu�rio
	file = fopen ( arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file,Sobrenome);
	fclose (file);
	
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, ",");
	fclose (file);
	
	printf ("digite o cargo:  ");
	scanf ("%s",cargo);
	//coletando informa��es do usu�rio
	file = fopen ( arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, cargo);
	fclose (file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // sele��o da linguagem
	
	printf ("voc� selecionou consulta de usu�rios\n");
	
	char CPF [40];
	char resultado [200];
	
	printf("digite seu cpf para a consulta:");
	scanf ("%S",CPF);
	//coletando informa��es do usu�rio
	FILE *file;
	file= fopen (CPF,"r");
	
	if (file == NULL)
	{
		printf ("N�o foi poss�vel encontrar o usu�rio\n");
    }
    
    
    while(fgets(resultado,200,file)!=NULL)
	 {
	 printf ("\n essas s�o as informa��es do usu�rio:  ");
	 printf ("%s", resultado);
	 printf ("\n\n");
     }
		
	system("pause");
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese"); // sele��o da linguagem
	
	printf("voc� selecionou excluir usu�rio\n");
	
	char CPF [40];
	
	printf("Digite o cpf do usu�rio que deseja excluir: ");
	scanf("%s", CPF);
	//coletando informa��es do usu�rio
	remove (CPF); // deletando o cpf digitado
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf("O usu�rio j� n�o existe mais. \n");
	}
	
	system("pause");	
}


int main ()
	
{
	int opcao=0; //armazenamento das vari�veis
	 int laco=1; //armazenamento de ciclos
	 	  	  
     for(laco=1;laco=1;) // fun��o de ciclos
   	{
	    system("cls");
	    
     	setlocale(LC_ALL, "Portuguese"); // sele��o da linguagem
	
	    printf("\tBEM VINDO AO CART�RIO DA EBAC\n\n"); //come�o do menu 
	    printf("Escolha a op��o desejada:\n\n");
	    printf("\t1-Inclus�o de Usu�rio\n");
     	printf("\t2-Consulta de Usu�rio\n");
    	printf("\t3-Excluir Usu�rio\n\n");
    	printf("digite a op��o:  "); // fim do menu
	
	    scanf ("%d",  &opcao);  // armazenamento das informa��es do usu�rio
	
	    system ("cls"); // responsavel por limpar a tela
	    
	    
	    
	    
	    switch(opcao) // inicio da sele��o do menu
	    {
		    case 1:
	     	registro(); //chamada de fun��es/ fun��o registro
	        break;
	        
	        case 2:
         	consulta();//chamada de fun��es/ fun��o consulta
	    	break;
	    	
	        case 3:
	   	    deletar();//chamada de fun��es/ fun��o deletar
	        break;
	        
	        default:
	     	printf("essa op��o n�o est� dispon�vel\n"); // fim das sele��es
   		    system("pause");	
   		    break;
    	}
   }
}

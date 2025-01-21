#include <stdio.h>// biblioteca de comunicação do usuário
#include <stdlib.h>// Aloca espaços na memória
#include <locale.h>// biblioteca de textos por região
#include <string.h> // Biblioteca para armazenar string
int registro()// responsavel por cadastrar usuários no sistema
{
	printf ("você selecionou registro de usuários\n");
	//inicio da criação de váriaveis/ string
	char arquivo [40];
	char CPF [40];
	char Nome [40];
	char Sobrenome [40];
	char cargo [40];
	//final da criação de váriaveis/ string
	printf ("Digite o cpf a ser cadastrado:  "); // Digite o cpf
	scanf ("%s",CPF); //%s refere-se a string
	//coletando informações do usuário
	
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
	//coletando informações do usuário
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file,Nome);
	fclose (file);
	
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, ",");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: "); // digite o sobrenome
	scanf ("%s", Sobrenome);
	//coletando informações do usuário
	file = fopen ( arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file,Sobrenome);
	fclose (file);
	
	file= fopen (arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, ",");
	fclose (file);
	
	printf ("digite o cargo:  ");
	scanf ("%s",cargo);
	//coletando informações do usuário
	file = fopen ( arquivo, "a");//abre o arquvo "a" significa atualiza
	fprintf (file, cargo);
	fclose (file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // seleção da linguagem
	
	printf ("você selecionou consulta de usuários\n");
	
	char CPF [40];
	char resultado [200];
	
	printf("digite seu cpf para a consulta:");
	scanf ("%S",CPF);
	//coletando informações do usuário
	FILE *file;
	file= fopen (CPF,"r");
	
	if (file == NULL)
	{
		printf ("Não foi possível encontrar o usuário\n");
    }
    
    
    while(fgets(resultado,200,file)!=NULL)
	 {
	 printf ("\n essas são as informações do usuário:  ");
	 printf ("%s", resultado);
	 printf ("\n\n");
     }
		
	system("pause");
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese"); // seleção da linguagem
	
	printf("você selecionou excluir usuário\n");
	
	char CPF [40];
	
	printf("Digite o cpf do usuário que deseja excluir: ");
	scanf("%s", CPF);
	//coletando informações do usuário
	remove (CPF); // deletando o cpf digitado
	
	FILE *file;
	file = fopen(CPF, "r");
	
	if (file == NULL)
	{
		printf("O usuário já não existe mais. \n");
	}
	
	system("pause");	
}


int main ()
	
{
	int opcao=0; //armazenamento das variáveis
	 int laco=1; //armazenamento de ciclos
	 	  	  
     for(laco=1;laco=1;) // função de ciclos
   	{
	    system("cls");
	    
     	setlocale(LC_ALL, "Portuguese"); // seleção da linguagem
	
	    printf("\tBEM VINDO AO CARTÓRIO DA EBAC\n\n"); //começo do menu 
	    printf("Escolha a opção desejada:\n\n");
	    printf("\t1-Inclusão de Usuário\n");
     	printf("\t2-Consulta de Usuário\n");
    	printf("\t3-Excluir Usuário\n\n");
    	printf("digite a opção:  "); // fim do menu
	
	    scanf ("%d",  &opcao);  // armazenamento das informações do usuário
	
	    system ("cls"); // responsavel por limpar a tela
	    
	    
	    
	    
	    switch(opcao) // inicio da seleção do menu
	    {
		    case 1:
	     	registro(); //chamada de funções/ função registro
	        break;
	        
	        case 2:
         	consulta();//chamada de funções/ função consulta
	    	break;
	    	
	        case 3:
	   	    deletar();//chamada de funções/ função deletar
	        break;
	        
	        default:
	     	printf("essa opção não está disponível\n"); // fim das seleções
   		    system("pause");	
   		    break;
    	}
   }
}

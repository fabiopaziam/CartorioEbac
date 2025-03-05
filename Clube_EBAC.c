#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o resposanvel por cadastrar usu�rios no sitema
{
    //inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variav�l
	fclose(file); // fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");   
    
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
    char conteudo[200];
    
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
	   printf("N�o foi possivel abrir o arquivo, n�o localizado.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
    
    system("pause");
}



int deletar()
{
    char cpf[40];
  
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);   
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
	   printf("O usu�rio n�o se encontra no sistema!.\n");
	   system("pause");
	}
    
}

int main()
{
	int opcao=0; //Definindo as variasveis 
    int laco=1;
    
	for(laco=1;laco=1;)
    {
    
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
        printf("### Clube de Membros EBAC ###\n\n"); //Inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar Nomes\n");
        printf("\t2 - Consultar Nomes\n");
        printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Obrigado por usar o sistema.\n\n"); 
	    printf("Op��es: "); //Final do menu
    
        scanf("%d", &opcao); // Armazenando a esccolha do usuario
		printf("\t4 - Sair do sistema\n\n");
		system("cls"); //responsavel por limpar a tela
		
		
		switch(opcao) //incio da sel��o do menu
		{
		    case 1:
		    registro();	// chamada de fun��es
    	    break;
    	    
    	    case 2:
    	    consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            case 4:
            printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;	
            
            default:
            printf("Essa op��o n�o est� disponivel\n");
	        system("pause");
			break;	
            
            } //fim da sel��o
        

    }
}

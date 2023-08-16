#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //boblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,nome); //inserindo a informa��o
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,","); //inserindo a informa��o
	fclose(file); //fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,sobrenome); //inserindo a informa��o
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,","); //inserindo a informa��o
	fclose(file); //fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informa��o
	fprintf(file,cargo); //inserindo a informa��o
	fclose(file); //fechando o arquivo
	
	system("cls");
	
	printf("Cadastro realizado com sucesso!\n");
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" abre o arquivo para ler informa��o

	
	if(file == NULL) //resposta para usu�rio n�o encontrado
	{
		printf("\nN�o foi possovel abrir o arquivo, usu�rio n�o encontrado.\n\n");
		fclose(file); //fechando o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //resposta para usu�rio encontrado
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //exibindo a informa��o
		printf("\n\n");
		fclose(file); //fechando o arquivo
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	system("cls"); //limpando a tela
		
	FILE *file;
	file = fopen(cpf,"r"); //"r" abre o arquivo para ler informa��o
	fclose(file); //fechando o arquivo

	if(file == NULL) //resposta para usu�rio n�o encontrado
	{
		printf("Usu�rio com o cpf n�mero ");
		printf("%s",cpf);
		printf(" n�o encontrado no sistema!\n\n");
		system("pause");
	}
	
	else //resposta para usu�rio encontrado
	{
		remove(cpf);
		printf("Usu�rio com o cpf n�mero ");
		printf("%s",cpf);
		printf(" deletado com sucesso!\n\n");
		system("pause");
	}

	
}


int main()
{
	
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //criando repeti��o
	{
	
		system("cls"); //limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Ecolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf ("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //limpando a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��o
			break;
			
			case 2:
			consulta(); //chamada de fun��o
			break;
			
			case 3:
			deletar(); //chamada de fun��o
			break;
			
			case 4:
			printf("Sair para desktop?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- N�o\n\n");
			printf("Op��o: ");
			scanf("%d", &opcao);
					
			if(opcao == 1)
			{
				return 0; //encerra o programa
			}
			
			else
			{
				main(); //retorna ao in�cio
			}
			break;
			
			default:
			printf("essa op��o n�o est� disponivel\n");
			system("pause");
			break;
		}	//fim da sele��o
		
	}	
	
}

#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //boblioteca responsável por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o aquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,nome); //inserindo a informação
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,","); //inserindo a informação
	fclose(file); //fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,sobrenome); //inserindo a informação
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,","); //inserindo a informação
	fclose(file); //fechando o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //"a" abre o arquivo para inserir informação
	fprintf(file,cargo); //inserindo a informação
	fclose(file); //fechando o arquivo
	
	system("cls");
	
	printf("Cadastro realizado com sucesso!\n");
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"r" abre o arquivo para ler informação

	
	if(file == NULL) //resposta para usuário não encontrado
	{
		printf("\nNão foi possovel abrir o arquivo, usuário não encontrado.\n\n");
		fclose(file); //fechando o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL) //resposta para usuário encontrado
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //exibindo a informação
		printf("\n\n");
		fclose(file); //fechando o arquivo
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s",cpf);
	system("cls"); //limpando a tela
		
	FILE *file;
	file = fopen(cpf,"r"); //"r" abre o arquivo para ler informação
	fclose(file); //fechando o arquivo

	if(file == NULL) //resposta para usuário não encontrado
	{
		printf("Usuário com o cpf número ");
		printf("%s",cpf);
		printf(" não encontrado no sistema!\n\n");
		system("pause");
	}
	
	else //resposta para usuário encontrado
	{
		remove(cpf);
		printf("Usuário com o cpf número ");
		printf("%s",cpf);
		printf(" deletado com sucesso!\n\n");
		system("pause");
	}

	
}


int main()
{
	
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //criando repetição
	{
	
		system("cls"); //limpando a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Ecolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: "); //fim do menu
		
		scanf ("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpando a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de função
			break;
			
			case 2:
			consulta(); //chamada de função
			break;
			
			case 3:
			deletar(); //chamada de função
			break;
			
			case 4:
			printf("Sair para desktop?\n\n");
			printf("\t1- Sim\n");
			printf("\t2- Não\n\n");
			printf("Opção: ");
			scanf("%d", &opcao);
					
			if(opcao == 1)
			{
				return 0; //encerra o programa
			}
			
			else
			{
				main(); //retorna ao início
			}
			break;
			
			default:
			printf("essa opção não está disponivel\n");
			system("pause");
			break;
		}	//fim da seleção
		
	}	
	
}

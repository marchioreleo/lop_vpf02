# VPF 02 - Lógica de Programação
Verificação Prática Formativa 02

## Contextualização
Você faz parte de uma equipe de desenvolvimento de software e foi designado para criar automações nos processos manuais e análise de dados. Foi designado a um projeto e precisa resolver o desafio proposto, a tabela a seguir apresenta os desafios propostos para cada aluno.
## Desafio 4
O arquivo a seguir contém dados de funcionários de uma empresa. Você deve criar um programa em C que leia o arquivo, processe os dados e gere um relatório resumido dos funcionários.

funcionarios.csv

``` C
Nome,Cargo,Salário
Ana Silva,Gerente,5000.00
Carlos Oliveira,Analista,3000.00
Maria Santos,Assistente,2000.00
Pedro Costa,Supervisor,4000.00
João Lima,Diretor,8000.00
```

O programa deve ler os dados dos funcionários, armazená-los em uma estrutura e exibir um relatório formatado na tela, mostrando o nome, o cargo e o salário de cada funcionário, contar o total de funcionários e calcular a média salarial da empresa.

# Código

```C
#include <stdio.h>
#include <windows.h>

struct Funcionario{
	char nome[100];
	char cargo[100];
	float salario;
};

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	struct Funcionario funcionarios[5] = {
		{"Ana Silva","Gerente",5000.00},
		{"Carlos Oliveira","Analista",3000.00},
		{"Maria Santos","Assistente",2000.00},
		{"Pedro Costa","Supervisor",4000.00},
		{"João Lima","Diretor",8000.00}
	};
	
	FILE *arquivo = fopen("funcionarios.csv", "w");
	if(arquivo == NULL){
		printf("Erro ao gravar arquivo");
		return 0;
	}
	
		fprintf(arquivo,"Nome;Cargo;Salário\n");
		for(int i = 0; i < 5; i++){
		fprintf(arquivo,"%s; %s; %f\n",funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
	}
		fclose(arquivo);
		printf("Arquivo criado com sucesso.");
		
	return 0;
}
```

# Relatório

```C
#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Funcionarios{
	char nome[50];
	char cargo[50];
	int salario;
};

void main(){
	SetConsoleOutputCP(CP_UTF8);
	int qtdLinhas = 0;
	struct Funcionarios func[MAX_LINHAS];
	FILE *arquivo = fopen("funcionarios.csv","r");
	if(arquivo == NULL){
		printf("Arquivo não encontrado.\n");
		getch();
		return 0;
	}
	char linha[MAX_LETRAS];
	while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){
		linha[strcspn(linha,"\n")] = '\0';
		qtdLinhas++;
		if(qtdLinhas > 1){
			sscanf(linha,"%49[^;], %49[^;], %d",
			func[qtdLinhas - 2].nome,
			func[qtdLinhas - 2].cargo,
			&func[qtdLinhas - 2].salario
			);
		}
	}
	fclose(arquivo);
	
	double mediasal = 0;
	int contsal = 0;
	
	printf("Nome\tCargo\tSalario\n");
	for(int i = 0; i < qtdLinhas - 1; i++){
		printf("%s\t %s\t %d\n",func[i].nome, func[i].cargo, func[i].salario);
		mediasal += func[i].salario;
		contsal++;
	}
	mediasal = mediasal / 7;
	printf("\nForam analizados %d funcionarios\n", contsal);
	printf("A média de salario dos funcionarios é %.2lf\n", mediasal);
	getch();
}
```

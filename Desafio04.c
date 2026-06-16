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
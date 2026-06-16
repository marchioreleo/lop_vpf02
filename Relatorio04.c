#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Funcionarios{
	char nome[50];
	char cargo[50];
	float salario;
};

int main(){ 
	SetConsoleOutputCP(CP_UTF8);
	
	int qtdFuncionarios = 0; 
	struct Funcionarios func[MAX_LINHAS];
	
	FILE *arquivo = fopen("funcionarios.csv", "r");
	if(arquivo == NULL){
		printf("Arquivo não encontrado.\n");
		getch();
		return 1; 
	}
	
	char linha[MAX_LETRAS];
	int primeiraLinha = 1; 
	
	while(fgets(linha, sizeof(linha), arquivo) != NULL && qtdFuncionarios < MAX_LINHAS){
		linha[strcspn(linha, "\n")] = '\0';
		
		if(primeiraLinha){
			primeiraLinha = 0;
			continue;
		}
	
		sscanf(linha, "%49[^;]; %49[^;]; %f",
			func[qtdFuncionarios].nome,
			func[qtdFuncionarios].cargo,
			&func[qtdFuncionarios].salario
		);
		
		qtdFuncionarios++;
	}
	fclose(arquivo);
	
	if (qtdFuncionarios == 0) {
		printf("Nenhum funcionário encontrado ou arquivo vazio.\n");
		getch();
		return 0;
	}
	
	double mediasal = 0;
	printf("Nome\t\t\tCargo\t\t\tSalario\n");
	printf("--------------------------------------------------------\n");
	for(int i = 0; i < qtdFuncionarios; i++){
		printf("%-20s\t%-15s\t%.2f\n", func[i].nome, func[i].cargo, func[i].salario);
		mediasal += func[i].salario;
	}
	
	mediasal = mediasal / qtdFuncionarios;
	printf("\nForam analisados %d funcionarios\n", qtdFuncionarios);
	printf("A média de salario dos funcionarios é %.2lf\n", mediasal);
	
	getch();
	return 0;
}
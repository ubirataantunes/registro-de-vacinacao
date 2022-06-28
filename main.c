#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct patient {	
	int code;
	char name[50];
	char cpf[15];
	char vaccine[15];
	char date[11];
	char lotNumber[11];	
};

int Menu() {
	int chosenNumber = 0;	
	while (chosenNumber != 1 && chosenNumber != 2 && chosenNumber != 3 && chosenNumber != 4) {
		printf("Escolha uma das opções do menu e digite o número.\n\n1 - Cadastrar Vacina\n2 - Listar Aplicações\n3 - Consultar por CPF\n4 - Sair\n");
		fflush(stdin);
		scanf("%d", &chosenNumber);
		if (chosenNumber !=  1 && chosenNumber != 2 && chosenNumber != 3 && chosenNumber != 4) { 
			printf("Escolha inexistente!\n\n");
			system("pause");
		};
		system("cls");
	};
	return chosenNumber;
}; 



int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
		
	int i = 0, j;
	struct patient newPatient[999];
	
	int chosenMenu;
	do {
		chosenMenu = Menu();
		if (chosenMenu == 1) {
					newPatient[i].code = i;
					printf("Cadastrando paciente %d\n", i);			
					printf("\nDigite o nome do paciente\n");
					fflush(stdin);
					gets(newPatient[i].name);
					
						
					// o problema está aqui		
					printf("\nDigite o CPF do paciente\n");
					fflush(stdin);
					gets(newPatient[i].cpf);	
						
					
						
					printf("\nDigite a vacina que o paciente irá tomar\n");
					fflush(stdin);
					gets(newPatient[i].vaccine);				
					printf("\nDigite a data que a vacina será aplicada\n");
					fflush(stdin);
					gets(newPatient[i].date);			
					printf("\nDigite o número do lote da vacina\n");
					fflush(stdin);
					gets(newPatient[i].lotNumber);
					system("cls");
					i++;
		};
		if (chosenMenu == 2) {
					for (j = 0; j < i; j++) {
						printf("Código: %d\n", newPatient[j].code);
						printf("Nome: %s\n", newPatient[j].name);						
						printf("CPF: %s\n", newPatient[j].cpf);		
						printf("Vacina: %s\n", newPatient[j].vaccine);
						printf("Data: %s\n", newPatient[j].date);
						printf("Número do lote: %s\n", newPatient[j].lotNumber);
						printf("=======================================\n");
					};
					system("pause");
					system("cls");
		};
		if (chosenMenu == 3) {			
					int s, control, loopControl;
					char cpfSearch[15];
					printf("Digite o cpf que deseja buscar:\n");
					fflush(stdin);
					gets(cpfSearch);
					loopControl = 0;
					for (s = 0; s <= i; s++) {
							control = strcmp(newPatient[s].cpf, cpfSearch);
							if (control == 0) {
								printf("\nCódigo: %d\n", newPatient[s].code);
								printf("Nome: %s\n", newPatient[s].name);
								printf("CPF: %s\n", newPatient[s].cpf);
								printf("Vacina: %s\n", newPatient[s].vaccine);
								printf("Data: %s\n", newPatient[s].date);
								printf("Número do lote: %s\n", newPatient[s].lotNumber);
								loopControl = 1;
								system("pause");
								system("cls");
							} 			
					} 
					if (loopControl == 0) {
						printf("\nCPF não encontrado!\n");
						system("pause");
						system("cls");
					}
		}
		if (chosenMenu == 4) {
				printf("Encerrando aplicação");
		};
	} while (chosenMenu != 4); 
	return 0;
}

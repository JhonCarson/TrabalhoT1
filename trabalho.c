#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações de um aluno
struct Aluno {
    char nome[50];
    int ra;
    char dataNascimento[11]; // Formato: dd/mm/yyyy
    char endereco1[100];
    char endereco2[100];
    float notas[5];
};

// Função para encontrar um aluno pelo RA
int encontrarAluno(struct Aluno alunos[], int ra, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (alunos[i].ra == ra) {
            return i; // Retorna o índice do aluno encontrado
        }
    }
    return -1; // Retorna -1 se o aluno não for encontrado
}

int main() {
    struct Aluno alunos[20];
    int numAlunos = 0; // Contador do número de alunos armazenados

    int opcao;
    do {
        printf("\nMenu de Operacoes:\n");
        printf("1. Adicionar novo aluno\n");
        printf("2. Apagar informacoes de um aluno\n");
        printf("3. Mostrar informacoes de um aluno pelo RA\n");
        printf("4. Mostrar informacoes de todos os alunos\n");
        printf("5. Sair\n");
        printf("Escolha a operacao (1-5): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (numAlunos < 20) {
                    struct Aluno novoAluno;
                    printf("Informe o nome do aluno: ");
                    scanf("%s", novoAluno.nome);
                    printf("Informe o RA do aluno: ");
                    scanf("%d", &novoAluno.ra);

                    // Verifica se o RA já está armazenado
                    if (encontrarAluno(alunos, novoAluno.ra, numAlunos) == -1) {
                        printf("Informe a data de nascimento (dd/mm/yyyy): ");
                        scanf("%s", novoAluno.dataNascimento);
                        printf("Informe o primeiro endereco (rua, numero, bairro, cidade, estado): ");
                        scanf("%s", novoAluno.endereco1);
                        printf("Informe o segundo endereco (rua, numero, bairro, cidade, estado): ");
                        scanf("%s", novoAluno.endereco2);
                        printf("Informe as notas das 5 disciplinas: ");
                        for (int i = 0; i < 5; i++) {
                            scanf("%f", &novoAluno.notas[i]);
                        }

                        // Adiciona o novo aluno ao vetor de alunos
                        alunos[numAlunos] = novoAluno;
                        numAlunos++;
                        printf("Aluno adicionado com sucesso!\n");
                    } else {
                        printf("O RA ja esta armazenado. Nao foi possivel adicionar o aluno.\n");
                    }
                } else {
                    printf("Nao ha espaco para adicionar mais alunos.\n");
                }
                break;

            case 2:
                // Implemente a operacao de apagar informacoes de um aluno aqui
                break;

            case 3:
                // Implemente a operacao de mostrar informacoes de um aluno pelo RA aqui
                break;

            case 4:
                // Implemente a operacao de mostrar informacoes de todos os alunos aqui
                break;

            case 5:
                printf("Saindo da aplicacao. Ate logo!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
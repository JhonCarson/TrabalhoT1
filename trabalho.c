#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar o endereço
struct endereco {
    char rua [30];
    int num;
    char bairro [30];
    char cidade [40];
    char estado [40];
};

struct materia {
    char nome[30];
    float media;
};


// Estrutura para armazenar informações de um aluno
struct Aluno {
    char nome[50];
    int ra;
    char dataNascimento[11]; // Formato: dd/mm/yyyy
    struct endereco endereco[2];
    struct materia materia[5];
};

//Imprimir a Struct

void listarAlunos(struct Aluno aluno) {

    printf("\nNome do Aluno: %s", aluno.nome);
    printf("\nRA do Aluno: %d", aluno.ra);
    printf("\nData de Nascimento do Aluno: %s", aluno.dataNascimento);
    printf("\nEndereco 1 do Aluno: %s", aluno.endereco);
    printf("\nEndereco 2 do Aluno: %s", aluno.endereco);

    /*for (int i = 0; i < 5; i++) {
    
        printf("\nNome da Materia: %s e Media %.2f\n", materia[i].nome, materia[i].media);
    }*/
    
}

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
        printf("\nEscolha a operacao (1-5): ");
        scanf("%d", &opcao);
        printf("\n ");

        switch (opcao) {
            case 1:
                if (numAlunos < 20) {
                    struct Aluno novoAluno;
                    printf("\nInforme o nome do aluno: ");
                    setbuf(stdin, NULL); // Limpar o buffer de entrada
                    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
                    
                    printf("\nInforme o RA do aluno: ");
                    scanf("%d", &novoAluno.ra);

                    // Verifica se o RA já está armazenado
                    if (encontrarAluno(alunos, novoAluno.ra, numAlunos) == -1) {
 
                        printf("\nInforme a data de nascimento (dd/mm/yyyy): ");
                        scanf("%s", &novoAluno.dataNascimento);

                    //Preencher Endereços
                        for (int i = 0; i < 2; i++) {
                            
                            setbuf(stdin, NULL);

                            printf("\nInforme a rua do endereco %d: ", i+1);
                            fgets(novoAluno.endereco[i].rua, sizeof(novoAluno.endereco[i].rua), stdin);
                        
                            printf("\nInforme o numero do endereco %d: ", i+1);
                            scanf("%d", &novoAluno.endereco[i].num);

                            setbuf(stdin, NULL);

                            printf("\nInforme o bairro do endereco %d: ", i+1);
                            fgets(novoAluno.endereco[i].bairro, sizeof(novoAluno.endereco[i].bairro), stdin);

                            setbuf(stdin, NULL);
                        
                            printf("\nInforme a cidade do endereco %d: ", i+1);
                            fgets(novoAluno.endereco[i].cidade, sizeof(novoAluno.endereco[i].cidade), stdin);   

                            setbuf(stdin, NULL);                   

                            printf("\nInforme o estado do endereco %d: ", i+1);
                            fgets(novoAluno.endereco[i].estado, sizeof(novoAluno.endereco[i].estado), stdin);      
                        }                                    

                        /*printf("Informe o primeiro endereco: ");
                        scanf("%s", &novoAluno.endereco[0]);
                        printf("Informe o segundo endereco: ");
                        scanf("%s", &novoAluno.endereco[1]);*/

                        for (int i = 0; i < 5; i++) {
                            
                            setbuf(stdin, NULL);    

                            printf("\nInforme o nome da disciplina %d: ", i+1);
                            fgets(novoAluno.materia[i].nome, sizeof(novoAluno.materia[i].nome), stdin);

                            printf("\nInforme a media da disciplina %d: ", i+1);
                            scanf(" %f", &novoAluno.materia[i].media);
                        }

                        // Adiciona o novo aluno ao vetor de alunos
                        alunos[numAlunos] = novoAluno;
                        numAlunos++;
                        printf("\nAluno adicionado com sucesso!\n");
                    } else {
                        printf("\nO RA ja esta armazenado. Nao foi possivel adicionar o aluno.\n");
                    }
                } else {
                    printf("\nNao ha espaco para adicionar mais alunos.\n");
                }
                break;

            case 2:
                // Implemente a operacao de apagar informacoes de um aluno aqui
                break;

            case 3:
                // Implemente a operacao de mostrar informacoes de um aluno pelo RA aqui
                break;

            case 4:
                //4. Mostrar informacoes de todos os alunos

                for (int i = 0; i < numAlunos; i++) {
                
                    listarAlunos(alunos[i]);
                }

                break;

            case 5:
                printf("\nSaindo da aplicacao. Ate logo!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
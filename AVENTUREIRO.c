
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} territorio;

void ataque (territorio *t, int at, int def) {
  int dadocante = rand() % 6 + 1;
  int dadoensor = rand() % 6 + 1; 
printf("\n--- Batalha ---\n");
printf("%s ataca %s!\n", t[at].nome, t[def].nome);
    printf("Dado Atacante: %d\n", dadocante);
    printf("Dado Defensor: %d\n", dadoensor);
if (dadocante >= dadoensor) {
        printf("Atacante vence! Defensor perde 1 tropa.\n");
        t[def].tropas--;
if (t[def].tropas <= 0) {
            printf("O atacante conquistou o territorio!\n");
            strcpy(t[def].cor, t[at].cor);
            t[def].tropas = 1;
        }
    } else {
        printf("Defensor segura o ataque!\n");
    }
}
void mostrarMapa(territorio *t) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", t[i].nome);
        printf("Cor: %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);
    }
}
int main() {
    srand(time(NULL));

    territorio *t = calloc(5, sizeof(territorio));

    printf("=== Cadastro dos Territorios ===\n");
    for (int i = 0; i < 5; i++) {
        printf("\nterritorio %d:\n", i + 1);

        printf("Nome: ");
        fgets(t[i].nome, 30, stdin);
        t[i].nome[strcspn(t[i].nome, "\n")] = '\0';

        printf("Cor do exercito: ");
        fgets(t[i].cor, 10, stdin);
        t[i].cor[strcspn(t[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &t[i].tropas);
        getchar();
    }

    int at, def;

    while (1) {
        mostrarMapa(t);

        printf("\nEscolha o atacante (1 a 5, 0 para sair): ");
        scanf("%d", &at);
        if (at == 0) break;

        printf("Escolha o defensor (1 a 5): ");
        scanf("%d", &def);

        at--; 
        def--;

        if (at < 0 || at >= 5 || def < 0 || def >= 5 || at == def) {
            printf("Opcao invalida!\n");
            continue;
        }

        ataque(t, at, def);
    }

    free(t);
    return 0;
}

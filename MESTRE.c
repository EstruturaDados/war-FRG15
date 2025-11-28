#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// -------- Funções --------
void inicializarTerritorios(Territorio *t) {
    char *nomes[5] = {"Alfa", "Bravo", "Charlie", "Delta", "Echo"};
    char *cores[5] = {"Vermelho", "Azul", "Verde", "Amarelo", "Preto"};

    for (int i = 0; i < MAX; i++) {
        strcpy(t[i].nome, nomes[i]);
        strcpy(t[i].cor, cores[i]);
        t[i].tropas = rand() % 5 + 3;
    }
}

void mostrarMapa(const Territorio *t) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < MAX; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", t[i].nome);
        printf("Cor: %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);
    }
}

void atacar(Territorio *t) {
    int at, def;

    mostrarMapa(t);

    printf("\nAtacante (1-5): ");
    scanf("%d", &at);
    printf("Defensor (1-5): ");
    scanf("%d", &def);

    at--; def--;

    if (at < 0 || at >= MAX || def < 0 || def >= MAX || at == def) {
        printf("Opcao invalida!\n");
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\n%s ataca %s!\n", t[at].nome, t[def].nome);
    printf("Dado A: %d | Dado D: %d\n", dadoA, dadoD);

    if (dadoA >= dadoD) {
        printf("Atacante vence! Defensor perde 1 tropa.\n");
        t[def].tropas--;

        if (t[def].tropas <= 0) {
            printf("Territorio conquistado!\n");
            strcpy(t[def].cor, t[at].cor);
            t[def].tropas = 1;
        }
    } else {
        printf("Defensor segura!\n");
    }
}

int verificarMissao(const Territorio *t, int tipoMissao) {
    if (tipoMissao == 1) { 
        // destruir exército verde
        for (int i = 0; i < MAX; i++)
            if (strcmp(t[i].cor, "Verde") == 0)
                return 0;
        return 1;
    }
    else if (tipoMissao == 2) {
        // conquistar 3 territórios pela mesma cor
        int cont = 0;
        for (int i = 0; i < MAX; i++)
            if (strcmp(t[i].cor, t[0].cor) == 0)
                cont++;
        return cont >= 3;
    }
    return 0;
}

// -------- MAIN --------
int main() {
    srand(time(NULL));
    Territorio t[MAX];

    inicializarTerritorios(t);

    int missao = rand() % 2 + 1;

    printf("=== MISSAO ===\n");
    if (missao == 1) printf("Destruir o exercito VERDE.\n");
    if (missao == 2) printf("Conquistar 3 territorios com a mesma cor.\n");

    int opc;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opc);

        if (opc == 0) break;
        if (opc == 1) atacar(t);
        if (opc == 2) {
            if (verificarMissao(t, missao)) {
                printf("\nMISSAO CUMPRIDA! VOCE VENCEU!\n");
                break;
            } else {
                printf("\nMissao ainda nao concluida.\n");
            }
        }
    }

    return 0;
}


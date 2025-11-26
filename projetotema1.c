#include <stdio.h>
#include <string.h>

typedef struct {
  char [30];
  cor [10];
  int tropas;
} territorio;

int main () {
  territorio t[5];

printf("Insira um território:");

for (int i = 0; i < 5; i++) {
printf ("Território: %d", i + 1);

printf ("nome:");
fgets(t[i].nome, 50, stdin);
t[i].nome[strcspn(t[i].nome,"\n")] = '\0';

printf("cor do exercito:");
scanf("%d", &t[i].tropas);
getchar();
}

printf("MAPA ATUAL");
for (int i = 0; i < 5; i++) {
printf("territorio %d", i+1);
printf("nome: %s", t[i].nome);
printf("cor: %s", t[i].cor);
printf("Tropas: %d", t[i].tropas);
}

return 0; }


  

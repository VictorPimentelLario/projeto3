#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

int criarTarefa(ListadeTarefas *lt) {
    printf("\nCriar tarefa\n");
    printf("\nQual a prioridade (0 - 10): ");
    scanf("%d", &lt->t[lt->qtd].prioridade); //escanea a prioridade que o usuario digitou
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
    printf("\nCategoria da Tarefa: ");
    fgets(lt->t[lt->qtd].categoria, 100, stdin); //escanea a categoria que o usuario digitou
    lt->t[lt->qtd].categoria[strcspn(lt->t[lt->qtd].categoria, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
//    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nDescricao da Tarefa: ");
    fgets(lt->t[lt->qtd].descricao, 300, stdin);//escanea a descricao que o usuario digitou
    lt->t[lt->qtd].descricao[strcspn(lt->t[lt->qtd].descricao, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
  printf("\nQual o Estado (1 = Completo ; 2 = Em Andamento ; 3 = Nao Iniciado): ");
  scanf("%d", &lt->t[lt->qtd].estado); //escanea o estado que o usuario digitou
  
    lt->t[lt->qtd].numero = lt->qtd + 1;
    lt->qtd = lt->qtd + 1; //aumenta em 1 a quantidade de tarefas na lista
    return 0;
}

int deletarTarefa(ListadeTarefas *lt) {
    printf("\nDeletar tarefa\n");
    if(lt->qtd == 0){ //caso a quantidade de tarefas na lista for 0, imprime a mensagem de lista vazia
        printf("A lista de tarefas esta vazia. Nao ha nada para deletar.\n");
        return 0;
    }
    printf("\nDigite o numero do lembrete: ");
    int numLembrete;
    scanf("%d", &numLembrete); //escanea qual o lembrete (a tarefa) que o usuario deseja deletar

    if (numLembrete < 1 || numLembrete > lt->qtd){ //caso o numero do lembrete nao for encontrado, imprime a mensagem de numero invalido
        printf("\nNumero invalido!\n");
    } else{ //caso o numero do lembrete é encontrado
        for (int i = numLembrete - 1; i < lt->qtd - 1; i++){ //seleciona todos os lembretes a partir do numero escolhido
            lt->t[i] = lt->t[i + 1];//substitui todos os lembretes criados apos o lembrete do numero digitado pelo lembrete posterior a eles
        }
        lt->qtd--; //diminui em 1 a quantidade de tarefas na lista de tarefas
        printf("\nLembrete %d deletado com sucesso!\n", numLembrete); //imprime a mensagem de sucesso ao deletar o lembrete (tarefa)
    }
    return 0;
}

int listarTarefas(ListadeTarefas lt) {
    printf("\nListar tarefas\n");
    for (int i = 0; i < lt.qtd; i++){ //para cada struct de tarefa, imprime cada uma de suas variaveis com seus valores
        printf("\nLembrete %d:\n", i + 1);
        printf("Prioridade: %d\n", lt.t[i].prioridade);
        printf("Categoria: %s\n", lt.t[i].categoria);
        printf("Descricao: %s\n", lt.t[i].descricao);
        if (lt.t[i].estado == 1){
          printf("Estado: Completo\n");
        }
        else if (lt.t[i].estado == 2){
          printf("Estado: Em Andamento\n");
        }
        else if (lt.t[i].estado == 3){
          printf("Estado: Nao Iniciado\n");
        }
    }
    return 0;
}

int buscaTarefa(ListadeTarefas lt, int lembreteNumero){ // funcao de buscar a tarefa a partir do seu numero
  int index = 0;
  for (index; index < 100; index++){ // percorre por toda a lista de tarefas ate achar o numero digitado
    if (lt.t[index].numero == lembreteNumero){
    return index; // retorna o index da tarefa
    }  
  }
  return -1; // caso nao encontre, retorna -1
  }

int alterarTarefa(ListadeTarefas *lt) {
  // Altera um campo de uma tarefa na lista de tarefas.
  int lembreteNumero;
  printf("\nAlterar tarefa\n");
  
  printf("\nDigite o numero da tarefa: ");
  scanf("%d", &lembreteNumero);
  int index = buscaTarefa(*lt, lembreteNumero);
  // if (index < 1 || index > lt->qtd) {
  //     printf("\nNumero invalido!\n");
  //     return 0;
  // }

  int opcao;
  printf("\nQual campo deseja alterar?\n[1] Prioridade\n[2] Descricao\n[3] Categoria\n[4] Estado\nOpcao: ");
  scanf("%d", &opcao);

  switch (opcao) {
      case 1:
          printf("\nNova prioridade: ");
          scanf("%d", &lt->t[index].prioridade);
          printf("\nPrioridade alterada com sucesso!\n");
          break;
      case 2:
          printf("\nNova descricao: ");
          int c;
          while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
          fgets(lt->t[index].descricao, 300, stdin);
          lt->t[index].descricao[strcspn(lt->t[index].descricao, "\n")] = '\0';
          printf("\nDescrição alterada com sucesso!\n");
          break;
      case 3:
          while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
          printf("\nNova categoria: ");
          fgets(lt->t[index].categoria, 100, stdin); //escanea a categoria que o usuario digitou
          lt->t[index].categoria[strcspn(lt->t[index].categoria, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
          printf("\nCategoria alterada com sucesso!\n");
      case 4:
          printf("\nNovo estado: ");
          scanf("%d", &lt->t[index].estado);
          printf("\nEstado alterado com sucesso!\n");
          break;
  }
}

int filtrarTarefasPorPrioridade(ListadeTarefas *lt){  // Filtra as tarefas por prioridade.
  int prioridade;
  printf("\nFiltra tarefas por prioridade\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nTarefas com prioridade %d:\n", prioridade);
  for (int i = 0; i < lt->qtd; i++){
    if (lt->t[i].prioridade == prioridade){
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %s\n", lt->t[i].estado);
    }
  }  
}

int filtrarTarefasPorEstado(ListadeTarefas *lt){// Filtra as tarefas por estado.
  int estado;
  printf("\nFiltra tarefas por estado\n");
  printf("\nDigite o estado (1 = Completo ; 2 = Em Andamento ; 3 = Nao Iniciado): ");
  scanf("%d", &estado);
  printf("\nTarefas com estado %d:\n", estado);
  for (int i = 0; i < lt->qtd; i++){
    if (lt->t[i].estado == estado){
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %d\n", lt->t[i].estado);
    }
  }    
}

int filtrarTarefasPorCategoria(ListadeTarefas lt){
  printf("\nFiltra tarefas por Categoria\n");
  int c;
  char categoria[100];
  while ((c = getchar()) != '\n' && c != EOF) {}
  printf("\nDigite a categoria: ");
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int i = 0; i < lt.qtd; i++) {
    for (int j = 10; j > -1; j--){
      int CategoriaVerificar = strcmp(lt.t[i].categoria, categoria);
      if (CategoriaVerificar == 0){
        if (lt.t[i].prioridade == j){
          printf("\nLembrete %d:\n", lt.t[i].numero);
          printf("Prioridade: %d\n", lt.t[i].prioridade);
          printf("Categoria: %s\n", lt.t[i].categoria);
          printf("Descricao: %s\n", lt.t[i].descricao);
          if (lt.t[i].estado == 1) { // caso o estado seja igual a 1, mostra o estado como completo
            printf("Estado: Completo\n");
          } else if (lt.t[i].estado == 2) { // caso o estado seja igual a 2, mostra o estado como em andamento
            printf("Estado: Em andamento\n");
          } else if (lt.t[i].estado == 3) { // caso o estado seja igual a 3, mostra o estado como nao iniciado
            printf("Estado: Nao iniciado\n");
          }
        }
      }
    }
  }
  return 0;
}

int filtrarTarefasPorPrioridadeECategoria(ListadeTarefas *lt){
  int prioridade;
  printf("\nFiltra tarefas por prioridade e categoria\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nDigite a categoria: ");
  char categoria[100];
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  printf("\nTarefas com prioridade %d e categoria %s:\n", prioridade,
    categoria);
  for (int i = 0; i < lt->qtd; i++){
    if (lt->t[i].prioridade == prioridade && strcmp(lt->t[i].categoria, categoria) == 0){
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %d\n", lt->t[i].estado);
    }
  }      
} 

void printMenu() { //imprime o menu com as opcoes
    printf("\nMenu:\n[1] Criar Tarefa\n[2] Deletar Tarefa\n[3] Listar Tarefas\n[4] Alterar Tarefa\n[5] Filtrar Tarefas Por Prioridade\n[6] Filtrar Tarefas Por Estado\n[7] Filtrar Tarefas Por Categoria\n[8] Filtrar Tarefas Por Prioridade E Categoria\n[9] Exportar Tarefas Por Prioridade\n[10] Exportar Tarefas Por Categoria\n[11] Exportar Tarefas Por Prioridade E Categoria\nEscolha uma opcao: ");
}

int salvarLista(ListadeTarefas lt, char arquivo[]){
    FILE *f = fopen(arquivo, "wb"); //abre o arquivo em binario com a funcao de digitar
    if (f == NULL){ //caso o arquivo nao consiga ser aberto ou criado, retorna a mensagem de erro
        return 1;
    }
    fwrite(&lt, sizeof(ListadeTarefas), 1, f); //escreve a lista de tarefas no arquivo
    fclose(f); //fecha o arquivo
    return 0;
}

int carregarLista(ListadeTarefas *lt, char arquivo[]){
    FILE *f = fopen(arquivo, "rb"); //abre o arquivo em binario com a funcao de ler
    if (f == NULL){ //caso o arquivo nao consiga ser aberto, retorna o valor para zerar a quantidade de tarefas
        return 1;
    }
    fread(lt, sizeof(ListadeTarefas), 1, f); //le a lista de tarefas no arquivo
    fclose(f); //fecha o arquivo
    return 0;
}
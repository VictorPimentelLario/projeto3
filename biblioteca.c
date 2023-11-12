#include "biblioteca.h"
#include <string.h>
#include <stdio.h>

int criarTarefa(ListadeTarefas *lt) {
    printf("\nCriar tarefa\n");
    printf("\nQual a prioridade (0 - 10): ");
    scanf("%d", &lt->t[lt->qtd].prioridade); //escanea a prioridade que o usuario digitou
    int c; //variavel auxiliar para limpar o buffer
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
        if (lt.t[i].estado == 1){  //caso o estado da tarefa seja 1, imprime a mensagem de tarefa completa
          printf("Estado: Completo\n");
        }
        else if (lt.t[i].estado == 2){ //caso o estado da tarefa seja 2, imprime a mensagem de tarefa em andamento
          printf("Estado: Em Andamento\n");
        }
        else if (lt.t[i].estado == 3){ //caso o estado da tarefa seja 3, imprime a mensagem de tarefa nao iniciada
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

int alterarTarefa(ListadeTarefas *lt) { // funcao de alterar a tarefa
  int lembreteNumero; // numero do lembrete que o usuario deseja alterar
  printf("\nAlterar tarefa\n");
  printf("\nDigite o numero da tarefa: ");
  scanf("%d", &lembreteNumero);
  int index = buscaTarefa(*lt, lembreteNumero); // busca a tarefa a partir do numero digitado
  // if (index < 1 || index > lt->qtd) {
  //     printf("\nNumero invalido!\n");
  //     return 0;
  // }

  int opcao;
  printf("\nQual campo deseja alterar?\n[1] Prioridade\n[2] Descricao\n[3] Categoria\n[4] Estado\nOpcao: "); 
  scanf("%d", &opcao);

  switch (opcao) { // switch para escolher qual campo alterar
      case 1: // altera a prioridade
          printf("\nNova prioridade: ");
          scanf("%d", &lt->t[index].prioridade);
          printf("\nPrioridade alterada com sucesso!\n");
          break;
      case 2: // altera a descricao
          printf("\nNova descricao: ");
          int c; // variavel auxiliar para limpar o buffer
          while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
          fgets(lt->t[index].descricao, 300, stdin);
          lt->t[index].descricao[strcspn(lt->t[index].descricao, "\n")] = '\0';
          printf("\nDescrição alterada com sucesso!\n");
          break;
      case 3: // altera a categoria
          while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
          printf("\nNova categoria: ");
          fgets(lt->t[index].categoria, 100, stdin); //escanea a categoria que o usuario digitou
          lt->t[index].categoria[strcspn(lt->t[index].categoria, "\n")] = '\0'; //substitui o "\n" no final da sentenca por um "\0"
          printf("\nCategoria alterada com sucesso!\n");
      case 4: // altera o estado
          printf("\nNovo estado: ");
          scanf("%d", &lt->t[index].estado);
          printf("\nEstado alterado com sucesso!\n");
          break;
  }
  return 0;
}

int filtrarTarefasPorPrioridade(ListadeTarefas *lt){  // Filtra as tarefas por prioridade.
  int prioridade; // variavel para armazenar a prioridade digitada pelo usuario
  printf("\nFiltra tarefas por prioridade\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nTarefas com prioridade %d:\n", prioridade);
  for (int i = 0; i < lt->qtd; i++){ // percorre a lista de tarefas
    if (lt->t[i].prioridade == prioridade){ // se a prioridade for igual a digitada, imprime a tarefa
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %d\n", lt->t[i].estado);
    }
  }
  return 0;
}

int filtrarTarefasPorEstado(ListadeTarefas *lt){// Filtra as tarefas por estado.
  int estado; // variavel para armazenar o estado digitado pelo usuario
  printf("\nFiltra tarefas por estado\n");
  printf("\nDigite o estado (1 = Completo ; 2 = Em Andamento ; 3 = Nao Iniciado): ");
  scanf("%d", &estado);
  printf("\nTarefas com estado %d:\n", estado);
  for (int i = 0; i < lt->qtd; i++){ // percorre a lista de tarefas
    if (lt->t[i].estado == estado){ // se o estado for igual ao digitado, imprime a tarefa
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %d\n", lt->t[i].estado);
    }
  }
  return 0;
}

int filtrarTarefasPorCategoria(ListadeTarefas lt){ // Filtra as tarefas por categoria.
  printf("\nFiltra tarefas por Categoria\n");
  int c;
  char categoria[100]; // variavel para armazenar a categoria digitada pelo usuario
  while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer
  printf("\nDigite a categoria: ");
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int i = 0; i < lt.qtd; i++) { // percorre a lista de tarefas
    for (int j = 10; j > -1; j--){ // percorre a lista de caracteres da categoria
      int CategoriaVerificar = strcmp(lt.t[i].categoria, categoria); // compara a categoria digitada com a categoria da tarefa
      if (CategoriaVerificar == 0){ // se a categoria for igual, imprime a tarefa
        if (lt.t[i].prioridade == j){ // se a prioridade da tarefa for igual a categoria, imprime a tarefa
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

int filtrarTarefasPorPrioridadeECategoria(ListadeTarefas *lt){ // Filtra as tarefas por prioridade e categoria.
  int prioridade; // variavel para armazenar a prioridade digitada pelo usuario
  printf("\nFiltra tarefas por prioridade e categoria\n");
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nDigite a categoria: ");
  char categoria[100]; // variavel para armazenar a categoria digitada pelo usuario
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  printf("\nTarefas com prioridade %d e categoria %s:\n", prioridade,
    categoria);
  for (int i = 0; i < lt->qtd; i++){ // percorre a lista de tarefas
    if (lt->t[i].prioridade == prioridade && strcmp(lt->t[i].categoria, categoria) == 0){ // se a prioridade da tarefa for igual a prioridade digitada e a categoria da tarefa for igual a categoria digitada, imprime a tarefa
      printf("\nLembrete %d:\n", i + 1);
      printf("Prioridade: %d\n", lt->t[i].prioridade);
      printf("Categoria: %s\n", lt->t[i].categoria);
      printf("Descricao: %s\n", lt->t[i].descricao);
      printf("Estado: %d\n", lt->t[i].estado);
    }
  }
  return 0;
}

int exportarTarefasPorPrioridade(ListadeTarefas *lt) { // Exporta as tarefas por prioridade
  FILE *f = fopen("exportar.txt", "w"); // abre o arquivo exportar.txt para escrita
  printf("\nExportar tarefas por prioridade\n");
  int prioridade; // variavel para armazenar a prioridade digitada pelo usuario
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  for (int i = 0; i < lt->qtd; i++) { // percorre a lista de tarefas
    if (lt->t[i].prioridade == prioridade) { // se a prioridade da tarefa for igual a prioridade digitada, imprime a tarefa no arquivo
      fprintf(f, "\n(Prioridade: %d) %s: %d | %s\n", lt->t[i].prioridade , lt->t[i].categoria , lt->t[i].estado ,lt->t[i].descricao);
    }
  }
  fclose(f); // fecha o arquivo
  return 0;
}

int exportarTarefasPorCategoria(ListadeTarefas *lt){ // Exporta as tarefas por categoria
  FILE *f = fopen("exportar.txt", "w"); // abre o arquivo exportar.txt para escrita
  printf("\nFiltra tarefas por Categoria\n");
  int c;
  char categoria[100]; // variavel para armazenar a categoria digitada pelo usuario
  while ((c = getchar()) != '\n' && c != EOF) {} //limpa o buffer
  printf("\nDigite a categoria: ");
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int i = 0; i < lt->qtd; i++) { // percorre a lista de tarefas
    for (int j = 10; j > -1; j--){ // percorre a lista de caracteres da categoria
      int CategoriaVerificar = strcmp(lt->t[i].categoria, categoria); // compara a categoria digitada com a categoria da tarefa
      if (CategoriaVerificar == 0){ // se a categoria for igual, imprime a tarefa
        if (lt->t[i].prioridade == j){ // se a prioridade da tarefa for igual a categoria, imprime a tarefa
          if (lt->t[i].estado == 1) { // caso o estado seja igual a 1, mostra o estado como completo
            fprintf(f,"Prioridade: %d | Categoria: %s | Estado: Completo | Descricao: %s", lt->t[i].prioridade, lt->t[i].categoria, , lt->t[i].descricao);
          } else if (lt->t[i].estado == 2) { // caso o estado seja igual a 2, mostra o estado como em andamento
            fprintf(f,"Prioridade: %d | Categoria: %s | Estado: Em andamento | Descricao: %s", lt->t[i].prioridade, lt->t[i].categoria, , lt->t[i].descricao);
          } else if (lt->t[i].estado == 3) { // caso o estado seja igual a 3, mostra o estado como nao iniciado
            fprintf(f,"Prioridade: %d | Categoria: %s | Estado: Nao iniciado | Descricao: %s", lt->t[i].prioridade, lt->t[i].categoria, , lt->t[i].descricao);
          }
        }
      }
    }
  }
  return 0;
}

int exportarTarefasPorPrioridadeECategoria(ListadeTarefas *lt){ // Exporta as tarefas por prioridade e categoria
  FILE *f = fopen("exportar.txt", "w"); // abre o arquivo exportar.txt para escrita
  printf("\nExportar tarefas por prioridade e categoria\n");
  int prioridade; // variavel para armazenar a prioridade digitada pelo usuario
  printf("\nDigite a prioridade: ");
  scanf("%d", &prioridade);
  printf("\nDigite a categoria: ");
  char categoria[100]; // variavel para armazenar a categoria digitada pelo usuario
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } //limpa o buffer
  fgets(categoria, 100, stdin);
  categoria[strcspn(categoria, "\n")] = '\0';
  for (int i = 0; i < lt->qtd; i++) { // percorre a lista de tarefas
    if (lt->t[i].prioridade == prioridade && strcmp(lt->t[i].categoria, categoria) == 0) { // se a prioridade da tarefa for igual a prioridade digitada e a categoria da tarefa for igual a categoria digitada, imprime a tarefa no arquivo
      fprintf(f, "\n(Prioridade: %d) %s: %d | %s\n", lt->t[i].prioridade , lt->t[i].categoria , lt->t[i].estado ,lt->t[i].descricao);
    }
  }
  fclose(f); // fecha o arquivo
  return 0;
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
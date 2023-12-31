#ifndef PROJETO_1_BIBLIOTECA_H
#define PROJETO_1_BIBLIOTECA_H

typedef struct tarefa { //struct com as variaveis para cada tarefa
    int prioridade; //variavel para armazenar o conteudo relacionado a prioridade
    char descricao[300]; //variavel para armazenar o conteudo relacionado a descricao
    char categoria[100]; //variavel para armazenar o conteudo relacionado a categoria
    int estado;//variavel para armazenar o conteudo relacionado a estado
    int numero;
} Tarefa;

typedef struct { //struct com a lista de tarefas
    Tarefa t[100]; //lista de tarefas, sendo 100 o limite
    int qtd; //numero de tarefas na lista
} ListadeTarefas;

int criarTarefa(ListadeTarefas *lt); //funcao de criar a tarefa
int deletarTarefa(ListadeTarefas *lt); //funcao de listar as tarefas
int listarTarefas(ListadeTarefas lt); //funcao de deletar a tarefa

void printMenu(); //funcao de imprimir o menu com as opcoes

int salvarLista(ListadeTarefas lt, char nome[]); //funcao de salvar a lista de tarefas

int carregarLista(ListadeTarefas *lt, char nome[]); //funcao de carregar a lista de tarefas

int alterarTarefa(ListadeTarefas *lt); //funcao de alterar as tarefas

int filtrarTarefasPorPrioridade(ListadeTarefas *lt); //funcao de filtrar as tarefas por prioridade

int filtrarTarefasPorEstado(ListadeTarefas *lt); //funcao de filtrar as tarefas por estado

int filtrarTarefasPorCategoria(ListadeTarefas lt); //funcao de filtrar as tarefas por categoria

int filtrarTarefasPorPrioridadeECategoria(ListadeTarefas *lt); //funcao de filtrar as tarefas por prioridade e categoria

int exportarTarefasPorPrioridade(ListadeTarefas *lt); //funcao de exportar as tarefas por prioridade

int exportarTarefasPorCategoria(ListadeTarefas *lt); //funcao de exportar as tarefas por categoria

int exportarTarefasPorPrioridadeECategoria(ListadeTarefas *lt); //funcao de exportar as tarefas por prioridade e categoria


#endif //PROJETO_1_BIBLIOTECA_H

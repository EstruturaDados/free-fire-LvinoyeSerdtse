#include <stdio.h>
#include <string.h>

// constantes:
#define TAM_MAXIMO 10

// the codigo comeca 

struct Item {
    char nome [50];
    char tipo [50];
    int quantidade;
};

void AdicionarItem(struct Item mochila[], int *i);
void ListarItem(struct Item mochila[], int total);
void RemoverItem(struct Item mochila[], int *i);
void MenuPrincipal();

int main() {
    MenuPrincipal();
    return 0;
}


// SEPARANDO DA FUNCAO MAIN



void MenuPrincipal() 
{   
    struct Item mochila[TAM_MAXIMO];
    int opcao = 0;
    int i = 0;
    do {  
        printf("=========================\nFRI FAIRI\n=========================\n");
        printf("Escolha uma ação:\n1 - PEGAR ITEM\n2- REMOVER ITEM\n3 - LISTAR ITENS\n0 - SAIR DO JOGO\n\nOPCAO SELECIONADA:");
        scanf("%d", &opcao);

        getchar(); 

        switch (opcao) {
            
            case 1:
            AdicionarItem(mochila, &i);
            break; 
        
            case 2:
            RemoverItem(mochila, &i);
            break;

            case 3:
            ListarItem(mochila, i);
            break;

            case 0:
            printf("Vacilao, vai correr da guerra? kkkkk");

            default:
            printf("OPCAO INVALIDA!\n");
            break;
            }
    } while (opcao != 0);
}

void AdicionarItem(struct Item mochila[], int *i) { 
    if (*i>= TAM_MAXIMO) {
    printf("Mochila cheia!\n");
    return;
    } else {
    // NOME DO ITEM
        printf("Adicionando Item...\n");
        printf("Digite o nome do item que voce deseja adicionar à mochila: ");
        fgets(mochila[*i].nome, 50, stdin);
        mochila[*i].nome[strcspn(mochila[*i].nome, "\n")] = 0;

        // TIPO DO ITEM
        printf("\nQual o tipo desse item (municao, medkit, lancaveis, ...)? ");
        fgets(mochila[*i].tipo, 50, stdin);
        mochila[*i].tipo[strcspn(mochila[*i].tipo, "\n")] = 0;

        // QUANTIDADE DO ITEM
        printf("\nQual a quantidade desse item?");
        scanf("%d", &mochila[*i].quantidade);
        getchar();

        (*i)++;
    }
}

void ListarItem(struct Item mochila[], int total) {
    printf("\nItens dentro da mochila...\n");
    if (total == 0) {
    printf("A mochila esta vazia!\n");
    } else {
        for (int j = 0; j < total; j++) {
        printf("=========================\n");
        printf("%d - NOME: %s\n (TIPO: %s)\n QUANTIDADE: %d\n", j+1, mochila[j].nome, mochila[j].tipo, mochila[j].quantidade);
        printf("=========================\n");
        }
        // sera que alguem realmente esta lendo o que estou fazendo?
    }
}


void RemoverItem(struct Item mochila[], int *i) {

    // 1. SE N TEM NADA, N DA PRA ESVAZIAR NEH
    if (*i == 0) {
        printf("=========================\n");
        printf("\n[!] A mochila ja esta vazia!\n");
        printf("=========================\n");
        return;
    }

    // 2. FUNCAO CHAMADA PARA QUE O USUARIO NAO TENHA CARGA COGNITIVA DE PRECISAR LEMBRAR QUAL ERA A POSICAO DO ITEM, BASTA VER.
    ListarItem(mochila, *i);

    int posicao;
     printf("=========================\n");
    printf("Removendo Item...\n");
    printf("Digite o numero do item que deseja remover (1 a %d): ", *i);
    scanf("%d", &posicao);
    getchar();

    // 3. Ajusta o número que o usuário digitou para o índice do C (começa em 0)
    int indice = posicao - 1;

    // 4. Verifica se a posição escolhida é válida
    if (indice >= 0 && indice < *i) {
        
        // Este loop pega todos os itens que estão DEPOIS do removido e puxa para trás
        for (int j = indice; j < (*i) - 1; j++) {
            mochila[j] = mochila[j + 1]; 
        }

        // 5. Atualiza o contador oficial lá no MenuPrincipal usando o ponteiro
        (*i)--; 
        
        printf("\n[OK] Item removido com sucesso.\n");
         printf("=========================\n");
    } else {
        printf("\n[!] Posicao invalida!\n");
         printf("=========================\n");
    }
}









// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.

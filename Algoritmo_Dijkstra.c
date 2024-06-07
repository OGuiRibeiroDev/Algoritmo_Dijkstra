#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define INT_MAX 4581295123

int distancia_minima(int distancia[], int conjunto_caminho_minimo[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int grafo[V][V], int indice, int distancia[], int caminho_anterior[]) {
    int conjuntoCaminhoMinimo[V]; // sptSet[i] sera verdadeiro se o vertice i estiver incluido no caminho mais curto

    // Inicializa todas as distancias como INFINITO e sptSet[] como falso
    for (int i = 0; i < V; i++) {
        distancia[i] = INT_MAX;
        conjunto_caminho_minimo[i] = 0;
        caminho_anterior[i] = -1; // Inicializa o parent de todos os vertices como -1
    }

    // A distancia do vertice de origem para ele mesmo e sempre 0
    distancia[indice] = 0;

    // Encontra o caminho mais curto para todos os vertices
    for (int count = 0; count < V - 1; count++) {
        // Pega o vertice de distancia minima da lista de vertices ainda nao processados
        int u = minDistance(dist, conjunto_caminho_minimo);

        // Marca o vertice como processado
        conjunto_caminho_minimo[u] = 1;

        // Atualiza o valor de dist[] dos vertices adjacentes do vertice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza dist[v] apenas se nao estiver em sptSet, houver uma aresta de u para v,
            // e o peso total do caminho de origem para v atraves de u e menor que o valor atual de dist[v]
            if (!conjunto_caminho_minimo[v] && grafo[u][v] && distancia[u] != INT_MAX && distancia[u] + grafo[u][v] < distancia[v]) {
                caminho_anterior[v] = u;
                distancia[v] = distancia[u] + grafo[u][v];
            }
        }
    }
}


int main()


    int grafo[V][V] = { { 0, 5, 6, 0, 0, 0, 2 },
                        { 5, 0, 10, 8, 0, 0, 0 },
                        { 6, 10, 0, 0, 0, 5, 3 },
                        { 0, 8, 10, 0, 12, 0, 0 },
                        { 0, 0, 7, 12, 0, 1, 0 },
                        { 0, 0, 5, 0, 1, 0, 4 },
                        { 2, 0, 3, 0, 0, 4, 0 } };

    int indice = 0;
    int distancia[V];
    int caminho_anterior[V];


{
 int op;

 do
 {
 system("cls");
 printf("SISTEMA ALGORITMO DIJKSTRA\n");
 printf("-----------------------------------------------------\n\n");
 printf("//SISTEMA PARA CONFERIR ROTAS DE ENTREGA \n\n");
 printf("Selecione a opcao: \n\n");
 printf("//[1] Selecionar o destino. \n\n");
 printf("//[2] Conferir o mapa. \n\n");
 printf("//[3] Algoritmo utilizado \n\n");
 printf("//[4] Caracteristicas do grafo \n\n");
 printf("//[5] Estruturas necessárias para implementar \n\n");
 printf("//[0] Sair \n\n");
 printf("Opcao: ");
 scanf("%d", &op);

 switch(op)
 {
 case 1:
 printf("");//SELECIONAR PONTO DE ROTA
 break;
 case 2:
 printf("///////////////////////////////////// \n\n");
 printf("\n\n");
 printf("/       /------------(6)---------\\       / \n\n");
 printf("/      /             |           |       / \n\n");
 printf("/    /               |          (5)      / \n\n");
 printf("/  (7)--------- \\    |          /|       / \n\n");
 printf("/   \\            \\--(3)-------/  |       / \n\n");
  printf("/    \\                          (4)      / \n\n");
 printf("/     \\-(1)---------(2)----------/       / \n\n");
 printf("O NUMERO 1 REPRESENTA A SEDE DA EMPRESA. \n\n");
 printf("///////////////////////////////////// \n\n");
 break;
 case 3:
 printf("O algoritmo utilizado no projeto foi o algoritmo de Djikstra\nA escolha desse algoritmo foi pelo fato de que ele seria a melhor opção para ser utilizada em um sistema de entregas e mapa. O sistema utilizando este algoritmo ira percorer um grafo ponderado, verificando quais são os caminhos mais curtos de um vertice a outro, de acordo com os seus pesos, comparando as arestas.\n\n ");
 break;
 case 4:
 printf("O grafo utilizado tem 6 vertices, conexo e ponderado, com valores em suas arestas, não direcionado. \n\n");
 break;
 case 5:
 printf("As estruturas necessárias para a implementaçao do algoritmo foram as estruturas de grafos, vertices e arestas, e a estrutura de fila \n\n.");
 break;
 case 6:
 	// Funcao para imprimir o caminho a partir da origem ate j
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j + 1);  // Adiciona 1 para exibir os vertices na base 1
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j + 1);  // Adiciona 1 para exibir os vertices na base 1
}
break;
 case 0:
 printf("Encerrando o programa! \n\n");
 break;
 default:
 printf("OPÇAO INVALIDA! \n\n");
 }
 system("pause");
 }
 while(op != 0);
 return 0;
}


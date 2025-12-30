#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 200

typedef struct {
    int matrix[MAXN][MAXN];
    int visited[MAXN];
    int num_nodes;
} Graph;

void init_graph(Graph *g, int n) {
    g->num_nodes = n;
    memset(g->visited, 0, sizeof(g->visited));
    memset(g->matrix, 0, sizeof(g->matrix));
}

void dfs(Graph *g, int u, int comp_id) {
    g->visited[u] = comp_id;

    for (int v = 0; v < g->num_nodes; v++) {
        if (g->matrix[u][v] && g->visited[v] == 0) {
            dfs(g, v, comp_id);
        }
    }
}

int main() {
    Graph g;
    int n;
    printf("lutfen sayilarinizi giriniz: klavyeden sayi disinda bir sey girerseniz sayi alma islemi biter");

    if (scanf("%d", &n) != 1 || n > MAXN) return 1;

    init_graph(&g, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g.matrix[i][j]);
        }
    }

    int comp_count = 0;
    for (int i = 0; i < n; i++) {
        if (g.visited[i] == 0) {
            comp_count++;
            dfs(&g, i, comp_count);
        }
    }

    printf("Cluster sayisi (bagli bilesen): %d\n", comp_count);

    for (int c = 1; c <= comp_count; c++) {
        printf("Cluster %d: ", c);
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (g.visited[i] == c) {
                if (!first) printf(" ");
                printf("%d", i);
                first = false;
            }
        }
        printf("\n");
    }

    return 0;
}

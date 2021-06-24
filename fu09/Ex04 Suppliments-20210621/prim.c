/*

author : your name
id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

void printMST(int);
void Prim(int, int);

int **D; // Distance Matrix
int *label, *visited;
int *cost, *adj, *d;

int main() {
    int i, j;
    int start;
    int n; //|V|

    /* input data */
    printf("Input the number of data: ");
    scanf("%d", &n);

    D = (int **)malloc(sizeof(int *) * n);
    label = (int *)malloc(sizeof(int) * n);
    visited = (int *)malloc(sizeof(int) * n);
    cost = (int *)malloc(sizeof(int) * n);
    adj = (int *)malloc(sizeof(int) * n);
    d = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
        D[i] = (int *)malloc(sizeof(int) * n);

    printf("Input the Distance matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    printf("Input the initial node: ");
    scanf("%d", &start);

    Prim(start - 1, n); // Main routine of Prim's Algorithm

    printMST(n); // Show the result of minimum spanning tree

    for(i = 0; i < n; i++)
        free(D[i]);
    free(D);
    free(label);
    free(visited);
    free(cost);
    free(adj);
    free(d);
}

void Prim(int root, int n) {
    int i, j;
    int distance, w;
    int c; // current node
    int visited_order = 1;

    /*
       label[i] = 0 denotes vertex i has not been visited
       and label[i] >= 1 denotes i has been "label[i]"-th visited.
    */

    //初期化・前処理
    for(i = 0; i < n; i++) {
        if(i == root) { /* Assume vertex "root" has already visited */
            label[root] = visited_order;
            adj[root] = -1;
        } else {
            label[i] = 0;
            d[i] = D[root][i];
            adj[i] = root;
        }
    }

    /*
      以下、Prim本体

      現在の部分木TからV-Tへ向かって最小コストで探索できる頂点を調べる
      最小コストで探索可能な頂点を調べる部分（２重ループの前半部分）は、理論上ヒープ構造に置き換えれば
      データ数によっては高速化されることが期待できる。ひとまずここでは、線形探索をする。

      配列 d[]： T から V-T の各点への最小コストが記録されている
      配列 adj[]： T から V-T の各点へ最小コストで行けるTの頂点番号が記されている
      新しくV-Tの頂点をTへ移すたびに、dとadjは更新される。⇒ 管理は一次元配列で十分
    */

    c = root;
    for(i = 0; i < n; i++) {

        /* find the edge (c, w) s.t. d[w] = min{d[x]|x in V-T} */
        distance = INFTY;
        for(j = 0; j < n; j++) {
            if(/* Complete Here !! */) {
                distance = d[j];
                w = j;
            }
        }

        /* Visit w, and add the edge (c,w) to T */
        label[w] = visited_order++;
        c = /* Complete Here !! */

            /* update distance to V-T */
            for(j = 0; j < n; j++) {
            if(/* Complete Here !! */) {
                d[j] = /* Complete Here !! */       // The minimum distance to T
                    adj[j] = /* Complete Here !! */ // From which vertex c in T?
            }
        }
    }
}

void printMST(int n) {
    int i;
    int weight = 0;

    printf("\n[Result]\n");
    printf("Edges in this MST:\n");
    for(i = 0; i < n; i++) {
        if(adj[i] != -1) {
            // Change here if you want to show the vertex_name as not Alphabet but Numbers.
            // printf("(%c,%c) :  %d  (visited_order: %d)\n", 97+(adj[i]-1), 97+(i-1), D[adj[i]][i] , label[i] );
            printf("(%d,%d) :  %d  (visited_order: %d)\n", adj[i] + 1, i + 1, D[adj[i]][i], label[i]);
            weight += D[adj[i]][i];
        }
    }
    printf("Total weight: %d\n", weight);
}

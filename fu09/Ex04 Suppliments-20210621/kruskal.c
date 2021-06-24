/*

author : your name
id     : your id

*/

#include <stdio.h>
#include <stdlib.h>

#define INFTY 99999

typedef struct { //辺(v_1,v_2)を管理する構造体
    int v_1;     //辺の頂点その１の頂点番号
    int v_2;     //辺の頂点その２の頂点番号
    int cost;    //辺(v_1,v_2)のコストｗ
} Edge;

struct Node {   // Union Find用の連結リスト
    int vertex; //頂点番号
    int num_v;  //ぶら下がっているノード数
    struct Node *next;
};
typedef struct Node *NodePointer;

//クラスカル本体
int Kruskal(Edge *, int);
// ヒープ用
void downheap(Edge *, int, int);
void construct_2(Edge *, int);
Edge delete_root(Edge *, int *);
// Union Find本体
int Find_tree(int);
int Union_tree(int, int);
//連結リスト用
NodePointer make_1node(int, NodePointer); //メモリ空間上にノードを１個生成する
NodePointer insert_node(int, int);        //生成したノードを所定のリストの末尾に接続する
void listprint(int);                      //リスト１つ分を全て表示

NodePointer *heads; // N個の連結リストの各先頭ノード(head)

int main() {
    int i, j;
    int dist, num_edges, n;
    int total_cost;
    Edge *E; //辺を格納する構造体配列

    printf("Input the number of vertex:"); /* input data*/
    scanf("%d", &n);
    E = (Edge *)malloc((n * n + 1) * sizeof(Edge));

    printf("Input the Distance matrix:\n");
    for(i = 0, j = 1; i < n * n; i++) {
        scanf("%d", &dist);
        if(dist == INFTY)
            continue;
        E[j].cost = dist;
        if(i / n < i % n) { // 辺を選ぶときに、頂点番号の小さい方から大きい方へ向かうようにする。
            E[j].v_1 = i / n; // 出力を統一するためのもので、本質的にはアルゴリズムと無関係なので
            E[j].v_2 = i % n; // 気にする必要はない。
        } else {
            E[j].v_1 = i % n;
            E[j].v_2 = i / n;
        }
        j++;
    }
    num_edges = j-1;

    heads = (NodePointer *)malloc(sizeof(NodePointer) * num_edges);
    for(i = 0; i < n; i++) {
        heads[i] = make_1node(-1, NULL);
        insert_node(i, i);
    }

    total_cost = Kruskal(E, num_edges);
    printf("Total weight: %d\n", total_cost);

    free(E);
    free(heads);
    return 0;
}

int Kruskal(Edge *E, int Esize) {
    int i, j;
    int S1, S2, costs = 0;
    Edge minimum; //最小の辺

    /* Complete Here !! */ //辺の集合Eを、辺のコストを基準にminimum heap化する

    while(Esize > 0) {                   //部分木に取り込んでいない辺の数
        minimum = /* Complete Here !! */ // heapから最小コストの辺を取り出す

            S1 = /* Complete Here !! */ //最小コストの辺の頂点１はどこに繋がっているか？（どの部分木に属するか）
            S2 = /* Complete Here !! */ //最小コストの辺の頂点２はどこに繋がっているか？（どの部分木に属するか）

            if(S1 != S2) {         //もし、２つの頂点が同じ部分木に属していないのであれば
            /* Complete Here !! */ //その２頂点を結ぶ辺を採用し、部分木同士を結合する
            printf("Selected Edge: (%d,%d), cost=%d\n", minimum.v_1 + 1, minimum.v_2 + 1,
                   minimum.cost);  //採用した辺を表示(出力の都合、添字+1)
            costs += minimum.cost; //採用した辺のコストを計上する
        }
    }
    return costs;
}

/* Heap Operations for the edge which has minimum cost (Almost same as Ex02) */
void downheap(Edge *A, int k, int n) { // downheapによってヒープチェック・メンテナンスを行う関数
    int j;
    Edge v; //一時退避用の変数

    v = A[k];
    while(k <= n / 2) {
        j = k + k;
        if(j < n && A[j].cost > A[j + 1].cost)
            j++; //２つの子ノードのうち、どちらと比較すればいいか
        if(v.cost <= A[j].cost)
            break;

        A[k] = A[j];
        k = j;
    }
    A[k] = v;
}

void construct_2(Edge *A, int n) { // downheap
    int i, j;

    for(i = n / 2; i > 0; i--) {
        downheap(A, i, n);
    }
}

Edge delete_root(Edge *A, int *n) { //根の値の削除
    Edge v = A[1];

    A[1] = A[*n];
    (*n)--;
    downheap(A, 1, *n);

    return v; //戻り値：ヒープから削除された値
}

/*Union Find Tree construction (By Linked List)*/
NodePointer make_1node(int value, NodePointer dest) {
    NodePointer n;

    if((n = (NodePointer)malloc(sizeof(struct Node))) == NULL) {
        printf("Error in memory allocation\n");
        exit(8);
    }

    n->vertex = value;
    n->num_v = 1;
    n->next = dest;
    return n;
}

NodePointer insert_node(int value, int source) {
    NodePointer newnode, n;

    for(n = heads[source]; n->next != NULL; n = n->next)
        ;                                 //リスト末尾に接続するためにループ空回し
    newnode = make_1node(value, n->next); //新しいノードを、現在のリストの末尾へ繋ぐ
    n->next = newnode; //現在の末尾の１個前のノードから、今作ったノードへの接続をする

    return newnode;
}

void listprint(int id) {
    NodePointer n;

    printf("V%-2d is adjacent to ", id);
    for(n = heads[id]->next; n != NULL; n = n->next) {
        printf("%-2d ", (n->vertex));
    }
    printf("\n");
}

/*Union Find operations*/
int Union_tree(int a, int b) {
    int S1, S2;

    S1 = Find_tree(a); // この辺はバグ対策（エラー処理）
    S2 = Find_tree(b); // このKruskalのプログラムについてのみ言えば、
    if(S1 == S2)
        return -1; //無くても問題は無い．（Kruskal()内でどうせ行う）
    //ここがunionの処理（木のバランスが悪くならないように、内部節点の個数で繋ぎ方を調整する）
    if(heads[S1]->next->num_v > heads[S2]->next->num_v) {
        heads[S1]->next->next = heads[S2]->next;
        heads[S2]->next->num_v += heads[S1]->next->num_v; // connect S1 to S2
    } else {
        heads[S2]->next->next = heads[S1]->next;
        heads[S1]->next->num_v += heads[S2]->next->num_v; // connect S2 to S1
    }

    return 0; // union成功
}

int Find_tree(int data) { //同じ部分木にいることを「同値関係」とするならば
    NodePointer n;        //リストを辿ることによって、その部分木の「代表元」を取り出す

    for(n = heads[data]->next; n->next != NULL; n = n->next)
        ;
    return n->vertex; //結局"data"が繋がっている先頭の頂点（代表元）は？
}

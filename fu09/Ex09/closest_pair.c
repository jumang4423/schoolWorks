/*

author : your name
id     : your id

*/
#define N 16 //頂点数
#define INF 9999999
#define BASE 2

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { //頂点情報格納用
    double x, y;
    int v; //頂点番号を持っておくと、Divide and Conquerで散り散りになっても値を追える
} Vertex;

typedef struct { //最近点対（距離と頂点番号）格納用
    int i, j;
    double length;
} Result;

void init(Vertex *);
Result n2_search(Vertex *, int);     //力任せな解法
double Get_Distance(Vertex, Vertex); //距離を求める（力任せ用）
Result DC(Vertex *, int, int);       //分割統治法による解法

void mergesort(Vertex *, int, int);

Vertex *B;

int main() {
    Vertex *V;
    Result res;

    V = (Vertex *)malloc(sizeof(Vertex) * N);
    B = (Vertex *)malloc(sizeof(Vertex) * N); // V mergesorted

    init(V);

    //どちらでも正しい答えになることを確認すること
    res = n2_search(V, N); //通常版
    printf("min_dist:%f (%d,%d)\n", res.length, res.i, res.j);

    res = DC(V, 0, N); // Divide and Conquer
    printf("min_dist:%f (%d,%d)\n", res.length, res.i, res.j);

    free(V);

    return 0;
}

void init(Vertex *V) { //乱数でデータ生成
    int i;

    srand(time(NULL));
    for(i = 0; i < N; i++) {
        V[i].x = 100 * (double)rand() / RAND_MAX;
        V[i].y = 100 * (double)rand() / RAND_MAX;
        V[i].v = i;
        printf("%d) %f, %f \n", V[i].v, V[i].x, V[i].y);
    }

    printf("****************************************\n");
}

Result n2_search(Vertex *V, int n) { //力任せ
    int i, j;
    double min_dist = INF, dist;
    Result res;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(i == j)
                continue;
            dist = Get_Distance(V[i], V[j]);
            if(dist < min_dist) {
                min_dist = dist;
                res.i = V[i].v;
                res.j = V[j].v;
            }
        }
    }

    res.length = min_dist;
    return res;
}

double Get_Distance(Vertex V1, Vertex V2) {
    double dist;

    dist = sqrt((V2.x - V1.x) * (V2.x - V1.x) + (V2.y - V1.y) * (V2.y - V1.y));

    return dist;
}
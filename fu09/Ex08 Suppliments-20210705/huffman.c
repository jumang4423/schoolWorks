/*

author : Ryoma Okuda
id     : s1270174

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_PER_CHAR 8
#define SIZE 256

/* Heap structure */
typedef struct
{
    char word;          // Character
    int count;          // Appearance
    int visited;        // Visited flag (for DFS)
    char bincode[SIZE]; // Encoded
    int bits;
    int articulation; // Articulation flag (for Huffman binary tree creation)
} Node;

/* Linked list structure declaration */
struct list
{
    Node vertex;          // Contains of "Node" structure (Nested structure)
    struct list *c_left;  // A pointer for left child in the binary tree
    struct list *c_right; // A pointer for right child in the binary tree
};
typedef struct list *NodePointer;

NodePointer make_1node(Node);
NodePointer *head; // Global Variable head

void construct_2(Node *, int);
void downheap(Node *, int, int);
Node delete_min(Node *, int *);

void upheap(Node *, int);
void insert(Node *, Node, int *);

int Huffman_DFS(NodePointer, char *);

int num_of_newroot = 0, label = 1;

int main()
{

    /* IO variables for Huffman Encoding */
    FILE *fp;
    char filename[100], c;

    /* Variables used in Huffman Encoding */
    int i;                // Loop Counter
    int n = 0;            // Length of the inputed string
    int num_of_chars = 0; // How many kinds of character?

    char *S;                             // Inputed string
    int *index;                          // Counter for the character appearance
    Node newnode = {'\0', 0, -1}, *data; // Nodes for Huffman binary tree creation
    Node couple[2];                      // A pair of minimum nodes in the set of characters

    NodePointer left, right; // Temporary variables for Huffman binary tree creation
    char encode[SIZE] = "";
    int result;

    /************* Do not edit here!! (For Input-Output) **************/
    /***** You don't have to concern about here on this Exercise. *****/

    printf("Enter the filename :\n=>");
    scanf("%100s", filename);
    printf("\n");

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("error: file not found.\n");
        exit(1);
    }

    while (c != EOF)
    {
        c = fgetc(fp);
        n++;
    }

    index = (int *)malloc(SIZE * sizeof(int));
    S = (char *)malloc((n + 1) * sizeof(char));
    data = (Node *)malloc((n + 1) * sizeof(Node));
    head = (NodePointer *)malloc((n + 1) * sizeof(NodePointer));

    fclose(fp);
    fp = fopen(filename, "r");

    fgets(S, n + 1, fp);
    fclose(fp);

    printf("Input string: %s\n", S);
    printf("Expressed in %d bits\n", (n - 1) * BITS_PER_CHAR);

    /* (Step. 1) Compute the appearance of each character */
    for (i = 0; i < SIZE; i++)
        index[i] = 0; // Initialize (
                      // indexは256個の配列。以下の行で現れた文字の「文字コードに対応する添字番号」の配列要素をカウントする )

    for (i = 0; S[i] != '\0'; i++)
        index[S[i]]++; // Count the appearance of each character

    for (i = 0; i < SIZE; i++)
    {
        if (index[i] > 0)
        { //存在する文字の分だけ、ノードを作る（ヒープのための準備）
            ++num_of_chars;
            data[num_of_chars].word = i;
            data[num_of_chars].count = index[i];
            data[num_of_chars].visited = 0;
            data[num_of_chars].articulation = -1;
        }
    }

    for (i = 1; i <= num_of_chars; i++)
    {
        printf("ho ID:%d  character:%c  appearance:%d\n", i, data[i].word, data[i].count);
    }
    printf("\n");

    // ここからがHuffman Encodingのメインルーチン（貪欲法が絡んでくる）
    /* (Step. 2) Create a Huffman binary tree based on the table made at Step. 1 */
    i = num_of_chars;
    construct_2(data, i); //E

    //出現数を持った文字たちをヒープに入れる（「親は子より出現頻度の値が小さい」という順序関係に基づいてヒープ化する＝minimum heap）

    while (i > 1)
    {

        /* Pick up the 2 minimum appearance characters */
        couple[0] = delete_min(data, &i); //ヒープから？？？
        couple[1] = delete_min(data, &i); //ヒープから？？？

        /* Create the nodes for the picked up characters  木の左側により小さいものを置くようにする*/
        if (couple[0].articulation == -1)
            left = make_1node(couple[0]); //左側に繋ぐ候補として、取り出したものが文字単体であればノードを作成する
        else
            left = head[couple[0].articulation]; //文字たちを集めた「木」であれば、その根に繋ぐ準備をする
        if (couple[1].articulation == -1)
            right = make_1node(couple[1]);
        else
            right = head[couple[1].articulation];

        /* Create the articulation node to combine the nodes for the picked up characters*/
        newnode.count = right->vertex.count + left->vertex.count; // 取り出した2つの節点の値（出現回数）の合計
        newnode.articulation = num_of_newroot;
        newnode.visited = 0;

        /* Construct a linked-list for Huffman binary tree expressions */
        head[num_of_newroot] = make_1node(newnode);
        head[num_of_newroot]->c_left = left;   //作成した左側用ノードを木の左側に接続する
        head[num_of_newroot]->c_right = right; //作成した右側用ノードを木の右側に接続する

        num_of_newroot++;
        insert(data, newnode, &i); //作成したノードをヒープに戻す
    }

    /*Output Huffman binary tree*/
    printf("\n");
    result = Huffman_DFS(head[num_of_newroot - 1], encode);
    printf("\nResult: The string \"%s\" \n", S);
    printf("        can be expressed in \"%d bits\" by Huffman Encoding.\n", result);

    /*Free allocated memory*/
    free(index);
    free(S);
    free(data);
    free(head);

    return 0;
}

void construct_2(Node *A, int n)
{ // 無秩序に並んだ配列をヒープにする
    int i, j;
    for (i = n / 2; i >= 1; i--)
    {
        downheap(A, i, n);
    }
}

void downheap(Node *A, int k, int n)
{
    int j;
    Node v;

    v = A[k];

    while (k <= n / 2)
    {
        j = k + k;

        if (j < n)
        {
            if (A[j].count > A[j + 1].count || (A[j].count == A[j + 1].count && A[j].word > A[j + 1].word))
            { //ヒープ条件の確認（Ex02とほぼ同じ）
                j++;
            }
        }

        if (v.count <= A[j].count || (v.count == A[j].count && v.word > A[j].word))
            break;

        A[k] = A[j];
        k = j;
    }
    A[k] = v;
}

Node delete_min(Node *A, int *i)
{
    Node v = A[1];
    int n;

    n = *i;

    A[1] = A[n];
    downheap(A, 1, n - 1); //ヒープに戻す（Ex02とほぼ同じ）

    (*i)--;
    return v;
}

void upheap(Node *A, int k)
{
    Node v;
    v = A[k];

    while (k > 1 && A[k / 2].count >= v.count)
    { //ヒープ条件の確認（Ex02とほぼ同じ）
        A[k] = A[k / 2];
        k = k / 2;
    }

    A[k] = v;
}

void insert(Node *A, Node v, int *i)
{
    int n;

    n = ++(*i);

    A[n] = v;
    upheap(A, n); //ヒープに戻す（Ex02とほぼ同じ）
}

NodePointer make_1node(Node K)
{
    NodePointer n;

    if ((n = malloc(sizeof(struct list))) == NULL)
    {
        printf("Error in memory allocation\n");
        exit(8);
    }

    n->vertex = K;
    n->c_left = NULL;
    n->c_right = NULL;
    return n;
}

int Huffman_DFS(NodePointer p, char *bin)
{
    static int i = 0, totalbits;

    while (1)
    {

        if (p->vertex.visited == 0)
        {
            if (p->vertex.articulation != -1)
                printf("%x [%3d]::  Left:%x [%3d]  Right:%x [%3d]\n", p, p->vertex.count, p->c_left,
                       p->c_left->vertex.count, p->c_right, p->c_right->vertex.count);
            else
            {
                strcpy(p->vertex.bincode, bin);
                p->vertex.bits = strlen(p->vertex.bincode) * p->vertex.count;
                printf("%x [%3d]: <Terminal> %c  Code: %8s (%2dbits)\n", p, p->vertex.count, p->vertex.word,
                       p->vertex.bincode, p->vertex.bits);
                totalbits += p->vertex.bits;
            }
            p->vertex.visited = label++;
        }

        if (p->c_left != NULL && p->c_left->vertex.visited == 0)
        { // DFSの要領で二分木を左側優先でたどる（もし、左側の子が探索可能で、かつ未到達であるならば。                           // Ex03とほぼ同じ）
            strcat(bin, "1");
            i++;
            totalbits = Huffman_DFS(p->c_left, bin);
        }
        else if (p->c_right != NULL && p->c_right->vertex.visited == 0)
        { // DFSの要領で二分木を右側にたどる（もし、右側の子が探索可能で、かつ未到達であるならば。
            // Ex03とほぼ同じ）
            strcat(bin, "0");
            i++;
            totalbits = Huffman_DFS(p->c_right, bin);
        }
        else
            break;
    }

    bin[--i] = '\0';

    return totalbits;
}
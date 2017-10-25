#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_E 1600
#define V 40

struct edge {
    int a;
    int b;
    int w;
    int in; //1 an h akmh xrhsimopoieitai
};

static int cost[V][V];
static struct edge akmes[MAX_E]; //pinakas akmwn
static int parent[V]; //pinakas gonewn

//http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
void quick_sort(struct edge *a, int n) {
    if (n < 2)  return;

    int p = a[n / 2].w;
    struct edge *l = a;
    struct edge *r = a + n - 1;
    
    while (l <= r) {
        if (l->w > p) {
            l++;
            continue;
        }
        if (r->w < p) {
            r--;
            continue;
        }
        struct edge t = *l;
        *l++ = *r;
        *r-- = t;
    }

    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}
 
//epistrefei ton patera enos komvou
int findParent(int p) {
    if (parent[p] < 0) return p;
    return parent[p] = findParent(parent[p]);
}

//ennwnei 2 3ena synola 
void unionThis(int p, int q) {
    if (parent[p] < parent[q] ) {
        parent[p] += parent[q];
        parent[q] = p;
    }
    else {
        parent[q] += parent[p];
        parent[p] = q;
    }
}

//algori8mos tou kruskal gia na vroume to varytero synektiko dentro
void kruskal(int N) {
    int i, p, q;

    for (i = N-1; i >= 0; i--) {	
        p = findParent(akmes[i].a);
        q = findParent(akmes[i].b);

        if (p != q) {
            akmes[i].in = 1;
            unionThis(p, q);
        }
    }
}

int main(void) {
    int E = 0, i, j;
    memset (parent, -1, sizeof(parent));
    
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    for (i = 0; i < V; i++)
        for (j = i; j < V; j++) {
            if (cost[i][j] == -1) continue;
            akmes[E].in = 0;
            akmes[E].a  = i;
            akmes[E].b  = j;
            akmes[E].w  = cost[i][j];
            E++;
        }


    quick_sort(akmes, E);
    kruskal(E);

    int total_sum = 0, spanning_sum = 0;
	for (j = 0; j < E; total_sum += akmes[j].w, j++)
		if (akmes[j].in == 1)
            spanning_sum += akmes[j].w;
			//printf("%d %d %lld\n", akmes[j].a, akmes[j].b, akmes[j].w);

    printf("%d %d %d\n", total_sum, spanning_sum, total_sum - spanning_sum);
	return 0;
}

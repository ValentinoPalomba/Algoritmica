//
//  eserc2.c
//  Grafi
//
//  Created by Valentino Palomba on 14/05/2019.
//  Copyright © 2019 Valentino Palomba. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
struct grafo{
    int num_archi;
    int *archi;
};
typedef struct grafo Grafo;


void dfs_visit(Grafo *G,int x, int *colors){
    int dim=G[x].num_archi;
    int i;
    for(i=0;i<dim;i++){
        if(colors[G[x].archi[i]]==0){
            colors[G[x].archi[i]]=1;
            dfs_visit(G, G[x].archi[i], colors);
        }
    }
}


void dfs(Grafo *G, int dim, int *colors){
    int i=0;
    for(i=0;i<dim;i++){
        colors[i]=0;
    }
    dfs_visit(G,0, colors);
    for(i=0;i<dim;i++){
        if(colors[i]==0){
            printf("0\n");
            exit(0);
        }
    
    }
}

void bfs(Grafo *G, int src){
    
}









int main(){
    int N;
    int num_archi;
    int x;
    int i, j;
    scanf("%d", &N);
    Grafo *G=(Grafo *)malloc(N*sizeof(Grafo));
    for(i=0;i<N;i++){
        scanf("%d", &num_archi);
        G[i].archi=malloc(sizeof(int)*num_archi);
        G[i].num_archi=num_archi;
        for(j=0;j<num_archi;j++){
            scanf("%d", &x);
            G[i].archi[j]=x;
        }
    }
    int *colors=malloc(sizeof(int)*N);
    dfs(G, N,colors);
    printf("1\n");
}

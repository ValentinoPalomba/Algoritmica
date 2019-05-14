//
//  main.c
//  Grafi
//
//  Created by Valentino Palomba on 14/05/2019.
//  Copyright © 2019 Valentino Palomba. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
struct grafo{
    int num_archi;
    int *archi;
};
typedef struct grafo Grafo;

void print(Grafo *G, int dim){
    int i, j;
    for(i=0;i<dim;i++){
        printf("%d: ", i);
        for(j=0;j<G[i].num_archi;j++){
            printf("%d ", G[i].archi[j]);
        }
        printf("\n");
    }
}
void bicolours_dfs(Grafo *G, int N, int s, int* colours){
    int i;
    for(i=0;i<G[s].num_archi;i++){
        if(colours[G[s].archi[i]]==0){
            colours[G[s].archi[i]]=colours[s]*(-1);
            bicolours_dfs(G, N, G[s].archi[i], colours);
        }
        else if(colours[G[s].archi[i]]==colours[s]){
            printf("0\n");
            exit(0);
        }
    }
    
}






int isBipartite(Grafo *G, int dim){
    int src=0, i;
    int *colours=malloc(dim*sizeof(int));
    for(i=0;i<dim;i++){
        colours[i]=0;
    }
    colours[src]=1;
    bicolours_dfs(G, dim, src, colours);
    for(i=0;i<dim;i++){
        if(colours[i]==0){
            return 0;
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
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
//    print(G, N);
    printf("%d", isBipartite(G, N));
    return 0;;
}

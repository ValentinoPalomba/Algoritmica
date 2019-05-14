//
//  main.c
//  Alberi
//
//  Created by Valentino Palomba on 07/05/2019.
//  Copyright © 2019 Valentino Palomba. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"
struct nodo{
    int val;
    struct nodo *dx;
    struct nodo *sx;
};
typedef struct nodo Nodo;


int cercaRic(Nodo *t, Nodo *p, int k){
    if (t==NULL || p==NULL) return -1; //nodo nullo
    if(k==t->val==p->val){ //caso in cui l'ho trovata
        return 0;
    }
    
    int found=-1; //variabile found che mi dirà se l'ho trovata
    if(k>t->val){   /*chiamate ricorsive su figlio destro e sinistro*/
        found=cercaRic(t->dx, p->dx, k);
    }
    else{
        found=cercaRic(t->sx,p->sx, k);
    }
    if(found>=0) return 1+found; /* ritorno il valore di found se l'ho trovata almeno una volta */
}

int cerca(Nodo *t, int k){ /*Versione iterative di CercaRic */
    int p=0;
    Nodo *curr=t;
    while(curr!=NULL){
        if(k==curr->val)return p;
        if(k>curr->val){
            curr=curr->dx;
        }
        else{
            curr=curr->sx;
        }
        p++;
    }
    return -1;
}


Nodo *inserisciRic(Nodo *t, int k){
    if(t==NULL){ /* caso radice inserisco normalmente */
        Nodo *new=(Nodo*) malloc(sizeof(Nodo));
        new->val=k;
        new->dx=NULL;
        new->sx=NULL;
        new->cx=NULL;
        return new;
    }
    if(t->val > k){ /* Caso minore scendo a sinistra */
        t->sx=inserisciRic(t->sx, k);
    }
    else if((t->val)%k==0){
        t->cx=inserisciRic(t->cx, k);
    }
    else{ /* Caso maggiore scendo a destra */
        t->dx=inserisciRic(t->dx, k);
        
    }
    return t;
}
int max(int a, int b){
    if(a>=b)return a;
    else return b;
}
int altezza(Nodo *t){
    if(t==NULL){
        return 0;
    }
    int sx, dx;
    sx=altezza(t->sx);
    dx=altezza(t->dx);
    return 1+max(sx, dx);
}
void stamp_ordinata(Nodo *t){
    if(t!=NULL){
    stamp_ordinata(t->sx);
    printf("%d", t->val);
    stamp_ordinata(t->dx);
    
}
    
    
    
    
}
int confronto(Nodo *t, Nodo *p, int k){
    if(t->val==k && p->val==k){
        return 1;
    }
    int sx, dx;
    if(t->val==p->val){
        sx=confronto(t->sx, p->sx, k);
        dx=confronto(t->dx, p->dx, k);
    }
    return -1;
}


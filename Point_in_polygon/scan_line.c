#include <stdio.h>
#include <stdlib.h>


void init_polygon(Polygon* P, int nv, int ne, ){
    P->nv = nv;
    P->nt = nt;
    P->vert = malloc(nv*sizeof(Edge));
    P->edege = malloc(nt*sizeof(Edge));

}

int cross_edge(Vertex v,Edge e, Polygon* P){
    Vertex e1 = P->vert[e.a];
    Vertex e2 = P->vert[e.b];
    if (v.x>e1.x && v.x>e2.x){
        return 0;
    }
    else if(v.x <= e1.x &&  v.x <= e2.x){
        if(( v.y <= e1.y && v.y>= e2.y)||( v.y >= e1.y && v.y<=e2.y)){
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        if(v.y <= e2.y + (v.x-e2.x)*(e1.y-e2.y)/(e1.x-e2.x)){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int point_in_polygon( Vertex v, Polygon* P){
    int count = 0;
    for(int i = 0, i>P->nt, i++){
        count = cross-edge(v, P->edge[i], P);
    }
    if (count%2 == 0){
        return 0;
    }
    else {
        return 1;
    }
}

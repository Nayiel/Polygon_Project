#include <stdio.h>
#include <stdlib.h>
#include "scan_line.h"

void init_polygon(Polygon* P, int nv, int ne){
    P->nv = nv;
    P->ne = ne;
    P->vert = malloc(nv*sizeof(Vertex));
    P->edge = malloc(ne*sizeof(Edge));

}
void dispose_polygon(Polygon* P){
    free(P->vert);
    free(P->edge);
    free(P);
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
            return 0;
    }
}



int point_in_polygon( Vertex v, Polygon* P){
    int count = 0;
    for(int i = 0; i<P->ne;i++){
        count = cross_edge(v, P->edge[i], P);
    }
    if(count%2 == 0){
        printf(" Not a polygon \n");
        return 0;
    }
    else {
        printf("Is a polygon\n");
        return 1;
    }
}

int read_geojson(Polygon* P, const char * filename){
    FILE* f = fopen(filename,'r');
    char line[300];
    int nt;
    int nvert;
    int np;
    int count;
    while(!feof(f)){
        fgets(line,300,f);
        if(sscanf(line,"Total %d Polygon %d",&nt, &np)==1){
            count =0;
            P->nv=nt;
            P->ne = nt + np -1;
            P->vert = malloc(P->nv*sizeof(Vertex));
            P->edge = malloc(P->ne*sizeof(Edge));
            
        }
        else if(sscanf(line, "Vertices %d", &nvert)==1){
            for(int i = 0; i<nvert; i++){
				fgets(line, 300,f);
				sscanf(line, "%lf %lf", &P->vert[i].x, &P->vert[i].y);
                P->edge[count].a = count;
                P->edge[count].b = count+1;
                count++;   
			}
            P->edge[count-1].b = count-nvert;
        }
    }
    fclose(f);
    return 0;
}
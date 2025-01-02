#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    double x;
    double y;

}Vertex;

typedef struct Edge{
    int a;
    int b;
};

typedef struct Polygon{
    int nv ;
    int ne;
    Vertex* vert;
    Edge* edge;
}Polygon;

Polygon* init_polygon(int nv, int ne );
void dispose_polygon(Polygon* P);
int cross_edge(Vertex v,Edge e, Polygon* P);
int point_in_polygon( Vertex v, Polygon* P);
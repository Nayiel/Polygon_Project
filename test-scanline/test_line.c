#include <stdio.h>
#include <stdlib.h>
#include "scan_line.h"

int main(){
   Polygon * P = init_polygon(4,4) ;
   Vertex v = {1,1};
   Vertex v1 = {0,0};
   Vertex v2 = {0,2};
   Vertex v3 = {2,0}; 
   Vertex v4 = {2,2};
   P->vert[0]=v1;
   P->vert[1]=v2;
   P->vert[2]=v3;
   P->vert[3]=v4;
   Edge e1 = {0,1};
   Edge e2 = {1,2};
   Edge e3 = {2,3};
   Edge e4 = {3,0};
   P->edge[0]=e1;
   P->edge[1]=e2;
   P->edge[2]=e3;
   P->edge[3]=e4;
   int res = point_in_polygon(v,P);
   printf("%d \n",res);
   return 0;
}
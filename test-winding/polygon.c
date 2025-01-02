
#include <math.h>
#include <raylib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"



Polygon *initPolygonFromList(Vector2 *verts, int nvert) {
  Polygon *poly = (Polygon*)malloc(sizeof(Polygon));

  poly->capacity = nvert;
  poly->nvert = nvert;
  poly->verts = verts;
  return poly;
}

void drawPolygon(Polygon *poly) {
  for (int i = 0; i < poly->nvert - 1; i++) {
    DrawLineV(poly->verts[i], poly->verts[i + 1], RED);
    DrawCircleV(poly->verts[i], 5, RED);
  }
}


int sign(Vector2 R, Vector2 A, Vector2 B) {
  float orientation = (A.x-R.x)*(B.y-R.y) - (A.y-R.y)*(B.x-R.x);

  if (orientation > 0) return 1;
  if (orientation == 0) return 0;
  return -1;
}



int isInside(Polygon *poly, Vector2 R) {
  int n = poly->nvert;
  int *quad = (int*)malloc(n * sizeof(int));

  for (int i=0; i<n; i++){
    if (poly->verts[i].x>R.x  && poly->verts[i].y>=R.y) {quad[i]=0;}
    else if (poly->verts[i].x<=R.x && poly->verts[i].y>R.y)  {quad[i]=1;}
    else if (poly->verts[i].x<R.x  && poly->verts[i].y<=R.y) {quad[i]=2;}
    else if (poly->verts[i].x>=R.x && poly->verts[i].y<R.y) {quad[i]=3;}
  }
  quad[n] = quad[0];

  int wind = 0;
  for (int i=0; i<n; i++){
    int qi = quad[i+1]-quad[i];
    if (qi==1 || qi==-3) {wind += 1;}
    else if (qi==-1 || qi==3) {wind += -1;}
    else if (qi==2 || qi==-2) {wind += 2*sign(R, poly->verts[i], poly->verts[i+1]);}
  }
  
  return wind/4;
}


#include <math.h>
#include <raylib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"



void initPolygon(Polygon *poly, int capacity) {
    poly->verts = (Vector2 *)malloc(capacity * sizeof(Vector2));
    poly->capacity = capacity;
    poly->nvert = 0;
}

void addVertex(Polygon *poly, double x, double y) {
    if (poly->nvert >= poly->capacity) {
        poly->capacity *= 2;
        poly->verts = (Vector2 *)realloc(poly->verts, poly->capacity * sizeof(Vector2));
    }
    poly->verts[poly->nvert].x = x;
    poly->verts[poly->nvert].y = y;
    poly->nvert++;
}

void printPolygon(Polygon *poly) {
  for (int i = 0; i < poly->nvert; i++) {
    printf("Vertex %d: (%f, %f)\n", i, poly->verts[i].x, poly->verts[i].y);
  }
}


// Free polygon memory
void freePolygon(Polygon *poly) {
    free(poly->verts);
}




int sign(Vector2 R, Vector2 A, Vector2 B) {
  float orientation = (A.x-R.x)*(B.y-R.y) - (A.y-R.y)*(B.x-R.x);

  if (orientation > 0) return 1;
  if (orientation == 0) return 0;
  return -1;
}


int parseFile(Polygon *P, const char *filename) {
  FILE *f = fopen(filename, "r");
  char line[300];
  int total = 0;

  if (fgets(line, sizeof(line), f)){
    if (sscanf(line, "Vertices %d", &total) != 1) {
      fprintf(stderr, "Invalid file format: expected 'Vertices <number>'\n");
      fclose(f);
      return -1;
    }
  }

  P->capacity = 2*total;
  P->verts = malloc(2*total*sizeof(Vector2));
  double x,y;

  while (!feof(f)) {
    if (fgets(line, sizeof(line), f)) {
      if (sscanf(line, "%lf %lf", &x, &y) == 2) addVertex(P, 150*x-300, 150*y-8000+600);
      else {
	fprintf(stderr, "Invalid coordinate format: %s\n", line);
      }
    }
  }

  fclose(f);
  return 0;
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
  
  /* free(quad); */
  return wind/4;
}


void drawPolygon(Polygon *poly) {
  for (int i = 0; i < poly->nvert - 1; i++) {
    DrawLineV(poly->verts[i], poly->verts[i + 1], RED);
    /* DrawCircleV(poly->verts[i], 5, RED); */
  }
}

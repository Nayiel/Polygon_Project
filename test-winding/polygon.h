#pragma once


/* #include <raylib.h> */

typedef struct Polygon {
  Vector2 *verts;
  int capacity;
  int nvert;
} Polygon ;


/* Polygon* initPolygon(int capacity); */

void initPolygon(Polygon *poly, int capacity) ;
void addVertex(Polygon *poly, double x, double y);
void freePolygon(Polygon *poly);
void printPolygon(Polygon *poly);


int parseFile(Polygon *P, const char *filename);

// function for winding number
int sign(Vector2 R, Vector2 A, Vector2 B);
int isInside(Polygon *poly, Vector2 R);


// for rendering
void drawPolygon(Polygon *poly);

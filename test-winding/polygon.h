#pragma once


#include <raylib.h>
typedef struct Polygon {
  Vector2 *verts;
  int capacity;
  int nvert;
} Polygon ;


Polygon *initPolygonFromList(Vector2 *verts, int nvert);
void drawPolygon(Polygon *poly);
int sign(Vector2 R, Vector2 A, Vector2 B);
int isInside(Polygon *poly, Vector2 R);

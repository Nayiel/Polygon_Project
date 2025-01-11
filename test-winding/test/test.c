

#include <math.h>
#include <raylib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LINE 1024


typedef struct Polygon {
  Vector2 *verts;
  int capacity;
  int nvert;
} Polygon ;

Polygon *initPolygon(int capacity) {
  Polygon *poly = malloc(sizeof(Polygon));
  poly->capacity = capacity;
  poly->verts = (Vector2 *)malloc(capacity * sizeof(Vector2));
  poly->nvert = 0;
  return poly;
}

void addVertex(Polygon *poly, double x, double y) {
  if (poly->nvert >= poly->capacity) {
    poly->capacity *= 2;
    poly->verts =
	(Vector2 *)realloc(poly->verts, poly->capacity * sizeof(Vector2));
  }
  poly->verts[poly->nvert].x = x;
  poly->verts[poly->nvert].y = y;
  poly->nvert++;
}

void freePolygon(Polygon *poly) {
    free(poly->verts);
}

int parseWKT(const char *filename, Polygon *poly) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Could not open file");
    return -1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, "POLYGON")) {
      char *start = strchr(line, '(');
      if (!start)
        continue;

      char *end = strchr(start, ')');
      if (!end)
        continue;

      // Extract coordinate data
      char *coords = start + 1;
      *end = '\0'; // Null-terminate the coordinate string

      char *token = strtok(coords, ",");
      while (token) {
        double x, y;
        if (sscanf(token, " %lf %lf", &x, &y) == 2)
	  addVertex(poly, x, y);
        token = strtok(NULL, ",");
      }
    }
  }
  fclose(file);
  return 0;
}

void printPolygon(Polygon *poly) {
  for (int i = 0; i < poly->nvert; i++) {
    printf("Vertex %d: (%f, %f)\n", i, poly->verts[i].x, poly->verts[i].y);
  }
}


/* int parseList(const char *filename, Polygon *poly) { */
/*   FILE *f = fopen(filename, "r"); */
/*   char line[LINE]; */

/*   do { */
/*     fgets(line, LINE, f) */
/*   } while (strncmp(line, "Vertex", 64) != 0); */
/*   fgets(line, LINE, f); */
/*   sscanf(line, "%d", &poly->nvert); */
/*   poly->verts = malloc(m->nvert * sizeof(struct Vertex)); */
/*   for (int i = 0; i < m->nvert; ++i) { */
/*     fgets(line, LINE, f); */
/*     sscanf(line, "%lf %lf %lf", &m->vertices[i].x, &m->vertices[i].y, */
/* 	   &m->vertices[i].z); */
/*   } */

/*   return 0; */
/* } */


int main() {

  Polygon *poly = initPolygon(10);

  if (parseWKT("data/test.csv", poly) == 0) {
    printPolygon(poly);
  }

  /* addVertex(poly, 300, 200); */

  /* printPolygon(poly); */

  return 0;
  }

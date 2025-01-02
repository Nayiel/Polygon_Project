
#include <math.h>
#include <raylib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"

#define MAX_POINTS 50
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50







int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  Vector2 testPoint = {-1, -1};

  int nvert = 7;
  Vector2 *verts = (Vector2 *)malloc(7 * sizeof(Vector2));
  verts[0].x = 500; verts[0].y= 30; 
  verts[1].x = 600; verts[1].y = 70;
  verts[2].x = 550; verts[2].y = 300;
  verts[3].x = 400; verts[3].y = 500;
  verts[4].x = 200; verts[4].y = 400;
  verts[5].x = 250; verts[5].y = 200;
  verts[6].x = 500; verts[6].y = 30;
  Polygon *poly = initPolygonFromList(verts, 7);

  printf("winding (R, Poly): %d\n\n", isInside(poly, testPoint));



  InitWindow(screenWidth, screenHeight, "Dynamic Polygon Drawer");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      testPoint = GetMousePosition();
    }

    /*--------------------------------------------------*/
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // draw poly and testpoint
    drawPolygon(poly);
    DrawCircleV(testPoint, 5, BLUE);
    DrawText("R", testPoint.x + 10, testPoint.y - 10, 20, BLACK);

    DrawText(TextFormat("Inside: %d", isInside(poly,testPoint)), 10, 10, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

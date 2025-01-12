
#include <raylib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "polygon.h"




int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  Vector2 testPoint = {400, 300};
  Polygon *P = malloc(sizeof(Polygon));
  if (0 == parseFile(P, "data/belhalf.data")){
    printPolygon(P);
    /* printf("\nwinding (R, P): %d\n\n", isInside(P, testPoint)); */
    /* continue; */
  }


  InitWindow(screenWidth, screenHeight, "Belgium");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      testPoint = GetMousePosition();
    }

    drawPolygon(P);
    DrawText("here", testPoint.x + 10, testPoint.y - 10, 20, BLACK);
    DrawCircleV(testPoint, 5, BLUE);
    /* DrawText(TextFormat("Inside: %d", isInside(P,testPoint)), 10, 10, 20, DARKGRAY); */

    /*--------------------------------------------------*/
    BeginDrawing();
    ClearBackground(RAYWHITE);


    EndDrawing();
  }

  CloseWindow();
  return 0;
}




/* #define MAX_POINTS 50 */
/* #define BUTTON_WIDTH 200 */
/* #define BUTTON_HEIGHT 50 */

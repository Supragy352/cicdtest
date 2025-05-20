#include <raylib.h>

int main(int argc, char const *argv[])
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "CI/CD Test");
    
    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
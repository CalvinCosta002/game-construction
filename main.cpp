#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "My First Game");
    SetTargetFPS(60);

    // Ball 1
    float x = 480.0f;
    float y = 340.0f;
    float speedX = 120.0f;   // pixels per second
    float speedY = 102.0f;
    const float radius = 20.0f;

    // Ball 2
    float x2 = 210.0f;
    float y2 = 213.0f;
    float speedX2 = 150.0f;
    float speedY2 = 120.0f;
    const float radius2 = 45.0f;

    while (!WindowShouldClose()) {
        // --- UPDATE ---
        float dt = GetFrameTime();   // one dt shared by everything

        x += speedX * dt;
        y += speedY * dt;
        if (x - radius < 0 || x + radius > screenWidth)  speedX = -speedX;
        if (y - radius < 0 || y + radius > screenHeight) speedY = -speedY;

        x2 += speedX2 * dt;
        y2 += speedY2 * dt;
        if (x2 - radius2 < 0 || x2 + radius2 > screenWidth)  speedX2 = -speedX2;
        if (y2 - radius2 < 0 || y2 + radius2 > screenHeight) speedY2 = -speedY2;

        // --- DRAW ---
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle((int)x, (int)y, radius, SKYBLUE);
        DrawCircle((int)x2, (int)y2, radius2, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

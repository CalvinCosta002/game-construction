#include "raylib.h"
#include <vector>

struct Ball {
    Vector2 pos;     // raylib's built-in {x, y} pair
    Vector2 speed;   // pixels per second
    float radius;
    Color color;
};

void UpdateBall(Ball& b, float dt, int w, int h) {
    b.pos.x += b.speed.x * dt;
    b.pos.y += b.speed.y * dt;

    if (b.pos.x - b.radius < 0 || b.pos.x + b.radius > w) b.speed.x = -b.speed.x;
    if (b.pos.y - b.radius < 0 || b.pos.y + b.radius > h) b.speed.y = -b.speed.y;
}

void DrawBall(const Ball& b) {
    DrawCircleV(b.pos, b.radius, b.color);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Structs");
    SetTargetFPS(60);

    std::vector<Ball> balls = {
        { {480, 340}, {120, 102}, 20, SKYBLUE },
        { {210, 213}, {150, 120}, 45, RAYWHITE },
    };

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        for (Ball& b : balls) UpdateBall(b, dt, screenWidth, screenHeight);

        BeginDrawing();
        ClearBackground(BLACK);
        for (const Ball& b : balls) DrawBall(b);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

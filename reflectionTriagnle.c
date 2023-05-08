#include <stdio.h>
#include <graphics.h>
#include <math.h>

void draw_line_bresenham(int x1, int y1, int x2, int y2);

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the triangle
    int x1 = 100, y1 = 100, x2 = 150, y2 = 200, x3 = 200, y3 = 100;
    int triangle[][3] = { { x1, y1, 1 }, { x2, y2, 1 }, { x3, y3, 1 } };

    // Define the reflection matrix
    int reflection[][3] = { { -1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

    // Reflect the triangle
    int i, j, k;
    int new_triangle[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            new_triangle[i][j] = 0;
            for (k = 0; k < 3; k++) {
                new_triangle[i][j] += triangle[i][k] * reflection[k][j];
            }
        }
    }

    // Draw the original triangle
    draw_line_bresenham(x1, y1, x2, y2);
    draw_line_bresenham(x2, y2, x3, y3);
    draw_line_bresenham(x3, y3, x1, y1);

    // Draw the transformed triangle
    draw_line_bresenham(new_triangle[0][0], new_triangle[0][1], new_triangle[1][0], new_triangle[1][1]);
    draw_line_bresenham(new_triangle[1][0], new_triangle[1][1], new_triangle[2][0], new_triangle[2][1]);
    draw_line_bresenham(new_triangle[2][0], new_triangle[2][1], new_triangle[0][0], new_triangle[0][1]);

    getch();
    closegraph();
    return 0;
}

void draw_line_bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int x_inc = (x2 > x1) ? 1 : -1;
    int y_inc = (y2 > y1) ? 1 : -1;
    int error = dx - dy;

    while (x != x2 || y != y2) {
        putpixel(x, y, WHITE);
        int error2 = error * 2;
        if (error2 > -dy) {
            error -= dy;
            x += x_inc;
        }
        if (error2 < dx) {
            error += dx;
            y += y_inc;
        }
    }
    putpixel(x, y, WHITE);
}

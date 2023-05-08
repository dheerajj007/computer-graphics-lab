#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void drawEllipse(int xCenter, int yCenter, int xRadius, int yRadius);
void drawCircle(int xCenter, int yCenter, int radius);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xCenter = getmaxx() / 2; // x-coordinate of center point
    int yCenter = getmaxy() / 2; // y-coordinate of center point
    int xRadius = 100; // horizontal radius of ellipse/circle
    int yRadius = 70; // vertical radius of ellipse/circle
    int radius = 50; // radius of circle

    // Draw an ellipse
    drawEllipse(xCenter, yCenter, xRadius, yRadius);

    // Draw a circle
    drawCircle(xCenter, yCenter, radius);

    getch();
    closegraph();
    return 0;
}

void drawEllipse(int xCenter, int yCenter, int xRadius, int yRadius) {
    int x = 0, y = yRadius;
    int p1 = yRadius * yRadius - xRadius * xRadius * yRadius + xRadius * xRadius / 4;
    int dx = 2 * yRadius * yRadius * x;
    int dy = 2 * xRadius * xRadius * y;

    while (dx < dy) {
        putpixel(xCenter + x, yCenter + y, WHITE);
        putpixel(xCenter - x, yCenter + y, WHITE);
        putpixel(xCenter + x, yCenter - y, WHITE);
        putpixel(xCenter - x, yCenter - y, WHITE);

        x++;
        dx += 2 * yRadius * yRadius;
        if (p1 < 0) {
            p1 += dx + yRadius * yRadius;
        } else {
            y--;
            dy -= 2 * xRadius * xRadius;
            p1 += dx - dy + yRadius * yRadius;
        }
    }

    int p2 = yRadius * yRadius * (x + 0.5) * (x + 0.5) + xRadius * xRadius * (y - 1) * (y - 1) - xRadius * xRadius * yRadius * yRadius;
    while (y >= 0) {
        putpixel(xCenter + x, yCenter + y, WHITE);
        putpixel(xCenter - x, yCenter + y, WHITE);
        putpixel(xCenter + x, yCenter - y, WHITE);
        putpixel(xCenter - x, yCenter - y, WHITE);

        y--;
        dy -= 2 * xRadius * xRadius;
        if (p2 > 0) {
            p2 += xRadius * xRadius - dy;
        } else {
            x++;
            dx += 2 * yRadius * yRadius;
            p2 += dx - dy + xRadius * xRadius;
        }
    }
}

void drawCircle(int x, int y, int r)
{
    int x_c = 0, y_c = r;
    int p = 1 - r;

    while (x_c <= y_c)
    {
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, y - y_c, WHITE);
        putpixel(x - x_c, y + y_c, WHITE);
        putpixel(x - x_c, y - y_c, WHITE);
        putpixel(x + y_c, y + x_c, WHITE);
        putpixel(x + y_c, y - x_c, WHITE);
        putpixel(x - y_c, y + x_c, WHITE);
        putpixel(x - y_c, y - x_c, WHITE);

        if (p < 0)
        {
            p += 2 * x_c + 3;
        }
        else
        {
            p += 2 * (x_c - y_c) + 5;
            y_c--;
        }
        x_c++;
    }
}

#include <stdio.h>
#include <graphics.h>

void drawEllipse(int x_center, int y_center, int x_radius, int y_radius)
{
    int x = 0, y = y_radius;
    int p1 = y_radius * y_radius - x_radius * x_radius * y_radius + 1 / 4 * x_radius * x_radius;
    int dx = 2 * y_radius * y_radius * x;
    int dy = 2 * x_radius * x_radius * y;

    while (dx < dy)
    {
        putpixel(x + x_center, y + y_center, WHITE);
        putpixel(-x + x_center, y + y_center, WHITE);
        putpixel(x + x_center, -y + y_center, WHITE);
        putpixel(-x + x_center, -y + y_center, WHITE);

        if (p1 < 0)
        {
            x++;
            dx += 2 * y_radius * y_radius;
            p1 += dx + y_radius * y_radius;
        }
        else
        {
            x++;
            y--;
            dx += 2 * y_radius * y_radius;
            dy -= 2 * x_radius * x_radius;
            p1 += dx - dy + y_radius * y_radius;
        }
    }

    int p2 = y_radius * y_radius * (x + 1 / 2) * (x + 1 / 2) + x_radius * x_radius * (y - 1) * (y - 1) - x_radius * x_radius * y_radius * y_radius;

    while (y >= 0)
    {
        putpixel(x + x_center, y + y_center, WHITE);
        putpixel(-x + x_center, y + y_center, WHITE);
        putpixel(x + x_center, -y + y_center, WHITE);
        putpixel(-x + x_center, -y + y_center, WHITE);

        if (p2 > 0)
        {
            y--;
            dy -= 2 * x_radius * x_radius;
            p2 += x_radius * x_radius - dy;
        }
        else
        {
            y--;
            x++;
            dx += 2 * y_radius * y_radius;
            dy -= 2 * x_radius * x_radius;
            p2 += dx - dy + x_radius * x_radius;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_center = 300, y_center = 300;
    int x_radius = 100, y_radius = 50;

    drawEllipse(x_center, y_center, x_radius, y_radius);

    getch();
    closegraph();

    return 0;
}

#include <stdio.h>
#include <graphics.h>

void bresenham_line(int x1, int y1, int x2, int y2)
{
    int dx, dy, x, y, p;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    x = x1;
    y = y1;
    p = 2 * dy - dx;
    while (x <= x2)
    {
        putpixel(x, y, WHITE);
        x++;
        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * (dy - dx);
            y++;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    bresenham_line(100, 100, 300, 300);
    getch();
    closegraph();
    return 0;
}

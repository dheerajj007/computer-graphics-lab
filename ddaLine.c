#include <stdio.h>
#include <graphics.h>

void dda_line(int x1, int y1, int x2, int y2)
{
    int i;
    float x, y, dx, dy, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }
    dx = dx / steps;
    dy = dy / steps;
    x = x1;
    y = y1;
    i = 1;
    while (i <= steps)
    {
        putpixel(x, y, WHITE);
        x = x + dx;
        y = y + dy;
        i = i + 1;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    dda_line(100, 100, 300, 300);
    getch();
    closegraph();
    return 0;
}

#include <stdio.h>
#include <graphics.h>

void midpoint_circle(int x, int y, int r)
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

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    midpoint_circle(250, 250, 100);
    getch();
    closegraph();
    return 0;
}

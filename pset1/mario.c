#include <stdio.h>
#include <cs50.h>

bool setblock(int height, int line, int position);

int main(void)
{
    int h;
    do {
        h = get_int("height:");
    } while (h < 0 || h > 23);
    int w = 2*h + 2;  //width
    for(int l = 1; l <= h; l++)
    {
        for(int p = 1; p <= w; p++)
        {
            if (setblock(h, l, p) == true) {
                printf("#"); }
            else {
                printf(" "); }
        }
        printf("\n");
    }
}
bool setblock(int height, int line, int position)
{
    if (position >= height + 1 - line && position <= height) {
        return true; }
    else if (position >= height + 3 && position <= height + 2 + line) {
        return true; }
    else {
        return false; }
}
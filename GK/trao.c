#include <stdio.h>

void trao(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("%d %d\n", x, y);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    trao(a, b);
    printf("%d %d", a, b);

}
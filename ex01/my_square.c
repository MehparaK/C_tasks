#include <stdio.h>
#include <stdlib.h>
void my_square(int x, int y)
{
    if (x <= 0 || y <= 0)
    {
        return;
    };
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if ((i == 0 || i == y - 1) && (j == 0 || j == x - 1))
            {
                putchar('o');
            }
            else if (i == 0 || i == y - 1)
            {
                putchar('-');
            }
            else if (j == 0 || j == x - 1)
            {
                putchar('|');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        return 0;
    }
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    my_square(x, y);
    return 0;
}
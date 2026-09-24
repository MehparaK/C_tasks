#include <stdio.h>
#include <stdlib.h>

char* my_spaceship(char* param_1)
{
    int x = 0;
    int y = 0;
    char* directions[] = {"up", "right", "down", "left"};
    int current_direct = 0;
    for (int i = 0; param_1[i] != '\0'; i++)
    {
        if (param_1[i] == 'R')
        {
            current_direct = (current_direct + 1) % 4;
        }
        else if (param_1[i] == 'L')
        {
            current_direct = (current_direct + 3) % 4;
        }
        else if (param_1[i] == 'A')
        {
            if (current_direct == 0)
                y--;
            else if (current_direct == 1)
                x++;
            else if (current_direct == 2)
                y++;
            else if (current_direct == 3)
                x--;
        }
    }
    char* result = malloc(sizeof(char) * 100);
    snprintf(result, 100, "{x: %d, y: %d, direction: '%s'}", x, y,
             directions[current_direct]);
    return result;
}

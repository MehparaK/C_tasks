
#include <stdio.h>
#include <stdlib.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

int my_strlen(char* param_1)
{
    int a = 0;
    while (param_1[a] != '\0')
    {
        a++;
    }
    return a;
}

char* my_strcpy(char* param_1, char* param_2)
{
    int i;
    for (i = 0; param_2[i] != '\0'; i++)
    {
        param_1[i] = param_2[i];
    }
    param_1[i] = '\0';
    return param_1;
}

char* my_join(string_array* param_1, char* param_2)
{
    if (param_1->size == 0)
    {
        return NULL;
    }

    int total_length = (param_1->size - 1) * my_strlen(param_2);
    for (int i = 0; i < param_1->size; i++)
    {
        total_length += my_strlen(param_1->array[i]);
    }
    total_length += 1;

    char* result = (char*)malloc(sizeof(char) * total_length);
    if (result == NULL)
    {
        return NULL;
    }

    result[0] = '\0';

    for (int i = 0; i < param_1->size; i++)
    {
        my_strcpy(result + my_strlen(result), param_1->array[i]);

        if (i < param_1->size - 1)
        {
            my_strcpy(result + my_strlen(result), param_2);
        }
    }

    return result;
}

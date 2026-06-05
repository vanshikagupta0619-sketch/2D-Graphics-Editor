#include <stdio.h>

#define WIDTH 20
#define HEIGHT 10

char picture[HEIGHT][WIDTH];

void clearPicture()
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            picture[i][j] = '_';
        }
    }
}

void displayPicture()
{
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            printf("%c", picture[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    clearPicture();
    displayPicture();

    return 0;
}

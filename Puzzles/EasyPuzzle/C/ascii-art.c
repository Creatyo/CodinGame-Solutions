#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[257];
    scanf("%[^\n]", T); fgetc(stdin);
    int Tl = strlen(T);
    int k = 0;
    char answer[1025] = "";
    int value = 0;

    for (int i = 0; i < H; i++) {
        char ROW[1025];
        scanf("%[^\n]", ROW); fgetc(stdin);
        for(int l = 0; l < Tl; l++)
        {
            value = 0;
            if(((int)toupper(T[l])<65)||(((int)toupper(T[l])>91)))
            {
                value = 26;
            }
            else
            {
                value = (int)toupper(T[l]) - 65;
            }
            for (int j = L*value; j < L*(value+1); j++)
            {
                answer[k++] = ROW[j];
            }
        }
        printf("%s\n", answer);
        k = 0;
    }
    //printf("%s\n", answer);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");


    return 0;
}
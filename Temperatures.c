#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // the number of temperatures to analyse
    int n;
    scanf("%d", &n);
	
	int best = (n == 0) ? 0 : 5526;
    for (int i = 0; i < n; i++)
    {
        // a temperature expressed as an integer ranging from -273 to 5526
		int temp;
        scanf("%d", &temp);
        
        if  ( (abs(temp) < abs(best)) 
                || ((abs(temp) == abs(best)) && temp > best)
            )
        {
            best = temp;
        }
    }
	
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
	
    printf("%d\n", best);
	
    return 0;
}
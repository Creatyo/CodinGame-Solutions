#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

static int compare (void const *a, void const *b)
{
   /* definir des pointeurs type's et initialise's
      avec les parametres */
   int const *pa = a;
   int const *pb = b;

   /* evaluer et retourner l'etat de l'evaluation (tri croissant) */
   return *pa - *pb;
}

int main()
{
    int N;
    scanf("%d", &N);
    int p[N];
    int diff = 10000000;
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }

    qsort(p, sizeof(p)/sizeof(*p), sizeof(*p), compare);

    for (int i = 0; i < N-1; i++) {
        if((p[i+1] - p[i]) < diff)
        {
            diff = p[i+1] - p[i];
        }
    }

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", diff);

    return 0;
}
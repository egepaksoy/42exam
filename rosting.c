#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return 0;
    }    
    int a = 0;

    char *first;
    int f = 1;
    int b = 0;
    int writed = 0;
    
    while (argv[1][a] == 32 || argv[1][a] == 9)
        a++;
    while (argv[1][a])
    {
        if (f)
        {
            while (argv[1][a] && !(argv[1][a] == 32 || argv[1][a] == 9))
                a++;
            first = malloc(sizeof(char) * a + 1);
            if (!first)
            {
                free(first);
                return (0);
            }
            b = a - 1;
            while(b >= 0)
            {
                first[b] = argv[1][b];
                b--;
            }
            first[a] = "\0";
        }
        while (!(argv[1][a] == 32 || argv[1][a] == 9) && argv[1][a])
        {
            write(1, &argv[1][a], 1);
            a++;
            writed = 1;
        }
        while ((argv[1][a] == 32 || argv[1][a] == 9) && argv[1][a])
            a++;
        if (argv[1][a])
        {
            if (!f)
                write(1, " ", 1);
        }
        f = 0;
    }
    if (writed)
        write(1, " ", 1);
    int c = 0;
    while (first[c])
    {
        write(1, &first[c], 1);
        c++;
    }
    free(first);
}
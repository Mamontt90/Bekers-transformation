#include <stdio.h>
#include <time.h>
#include <windows.h>

bool tab[20000][20000];
bool tabv[10000][40000];
bool tabg[40000][10000];
bool tab1[20000][20000];
int a, m;
long tin, tout;

int inpfunc();
int gorperfunc();
int verperfunc();
int outpfunc();
int rightfunc();
int leftfunc();

int main()
{
    printf("How long is the array? ");
    scanf("%d", &a);
    printf("How many times to mix? ");
    scanf("%d", &m);

    inpfunc();

    for(long i = 0; i < m; i++)
    {
        gorperfunc();
        verperfunc();
        leftfunc();
        gorperfunc();
        verperfunc();
        rightfunc();

        printf("%d\n", i + 1);
    }
    outpfunc();

    tout = clock();

    printf("Mixing time: %d", tout - tin);

    return 0;
}

int inpfunc()
{
    FILE* input;
    input = fopen ("Big_sq.bin", "r");

    for (int x = 0; x < a; x++)
    {
        for (int y = 0; y < a; y++)
        {
            fscanf(input, "%c", &tab[x][y]);
        }
    }

    fclose (input);
}

int outpfunc()
{
    FILE* output;
    output = fopen ("sq.dat", "w");

    for (int x = 0; x < a; x++)
    {
        for (int y = 0; y < a; y++)
        {
            fprintf (output, "%c", tab[x][y]);
        }
    }

    fclose (output);
}

int gorperfunc()
{
    //������� � �������������� ������
    for (int y = 0; y < a / 2; y++)
    {
        for (int x = 0; x < a; x++)
        {
            tabg[2 * x][y] = tab[x][y];
        }
    }

    for (int y = a / 2; y < a; y++)
    {
        for (int x = 0; x < a; x++)
        {
            tabg[2 * x + 1][y - a / 2] = tab[x][y];
        }
    }

    //������� ������� � �������

    for (int y = 0; y < a / 2; y++)

    {
        for (int x = a ; x < a * 2; x++)
        {
            tab[x - a][y] = tabg[x][y];
        }
    }

    for (int y = 0; y < a / 2; y++)
    {
        for (int x = 0 ; x < a; x++)
        {
            tab[x][y + a / 2] = tabg[x][y];
        }
    }
}

int verperfunc()
{
    //������� � ������������ ������

    for (int y = 0; y < a; y++)
    {
        for (int x = 0 ; x < a / 2; x++)
        {
            tabv[x][2 * y + 1] = tab[x][y];
        }
    }

    for (int y = 0; y < a; y++)
    {
        for (int x = a / 2 ; x < a; x++)
        {
            tabv[x - a / 2][y * 2] = tab[x][y];
        }
    }

    //������ �������� �������

    for (int y = 0; y < a; y++)
    {
        for (int x = 0 ; x < a / 2; x++)
        {
            tab[x][y] = tabv[x][y];
        }
    }

    for (int y = a; y < a * 2; y++)
    {
        for (int x = 0 ; x < a / 2; x++)
        {
            tab[x + a / 2][y - a] = tabv[x][y];
        }
    }
}

int rightfunc()
{
    // _______������� ������_________

    for(int y=0;y < a;y++)
    {
        for(int x = 0;x < a;x++)
        {
            tab1[a-y-1][x] = tab[x][y];
        }
    }

    for(int y = 0;y < a;y++)
    {
        for(int x = 0 ;x < a;x++)
        {
            tab[x][y] = tab1[x][y];
        }
    }
}

int leftfunc()
{
    // _______������� �����_________
    for(int y=0;y < a;y++)
    {
        for(int x=0 ;x < a;x++)
        {
            tab1[y][a-x-1] = tab[x][y];
        }
    }

    for(int y=0;y < a;y++)
    {
        for(int x=0 ;x < a;x++)
        {
            tab[x][y] = tab1[x][y];
        }
    }
}

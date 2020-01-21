#include <TXLib.h>

bool tab[20000][20000];
bool tabv[10000][40000];
bool tabg[40000][10000];
bool tab1[20000][20000];
int a = 20000;

int inpfunc();
int gorperfunc();
int verperfunc();
int outpfunc();
int rightfunc();
int leftfunc();

int main()
{
    inpfunc();
    for(int i = 0; i < 100; i++)
    {
        gorperfunc();
        verperfunc();
        leftfunc();
        gorperfunc();
        verperfunc();
        rightfunc();
    }
    outpfunc();

    return 0;
}

int inpfunc()
{
    FILE* input;
    input = fopen ("int8_0_8_A.dat", "r");

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
    //Перевод в горизонтальный массив
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

    //Перевод обратно в квадрат

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
    //Перевод в вертикальный массив

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

    //Превод обратнов квадрат

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
    // _______Поворот вправо_________

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
    // _______Поворот влево_________
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

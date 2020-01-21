#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <tlhelp32.h>

struct dn
{
bool tab0[20000][20000];
bool tab1[20000*2][20000/2];
bool tab2[20000/2][20000*2];
bool tab3[20000][20000];
}one;

/*
int tab0[10000][10000];
int tab1[10000*2][10000/2];
int tab2[10000/2][10000*2];
int tab3[10000][10000];
*/
int main()
{
    // Инициализация файлов
    FILE * time;
    FILE * input;
    FILE * output;

    time = fopen("time.txt","w");
    input = fopen("Big_sq.bin","rb");
    output = fopen("output.bin","wb");
/*
    a-сторона массива
    t0-время перед премешиванием
    t1-время после перемешикания
    kur=0 - отвеч за перенос курсора на строку ниже
    k-количество циклов перемешивания
*/
    long a=4,t0,t1,k=1,s=0;

    //srand(time(NULL));

    // Цикл ввода массива
    for(long y=0;y<a;y++)
    {
        for(long x = 0;x<a;x++)
        {
            /*
            if(x =! 0)
            {
                fscanf(input,"%c",&tab0[x][y]);
            }else
            {
                fscanf(input,"\n%c",&tab0[x][y]);

            }
            */

            if(rand() % 2 == 0)
            {
                tab0[x][y] = true;
            }else
            {
                tab0[x][y] = false;
            }

            /*
            s++;
            tab0[x][y]=s;
            */

        }
    }
/*
  //Тестовый вывод
    for(int y=0;y<a;y++)
    {

        for( int x=0;x<a;x++)
        {
            if(y > kur)
            {
                fprintf(output,"\n%d ",tab0[x][y]);
                printf("\n%d ",tab0[x][y]);
                kur++;
            }else
            {
                fprintf(output,"%d ",tab0[x][y]);
                printf("%d ",tab0[x][y]);
            }
        }
    }
*/
    printf("\nTab is OK\n");

    t0=clock();

    for(long i=0;i<k;i++)
    {

    //       ____________Горизонтальное перемешивание__________

        //Перевод в горизонтальный массив

        for(long y=0;y<a/2;y++)
        {
            for(long x=0;x<a;x++)
            {
                tab1[2*x][y]=tab0[x][y];
            }
        }

        for(long y=a/2;y<a;y++)
        {
            for(long x=0;x<a;x++)
            {
                tab1[2*x+1][y-a/2]=tab0[x][y];
            }
        }

/*
        //Тестовый вывод
        for(int y=0;y<a/2;y++)
        {

            for( int x=0;x<a*2;x++)
            {
                if(y > kur)
                {
                    printf("\n%d ",tab1[x][y]);
                    kur++;
                }else
                {
                    printf("%d ",tab1[x][y]);
                }
            }
        }
*/

        //Перевод обратно в квадрат

        for(long y=0;y < a/2;y++)

        {
            for(long x=a ;x < a*2;x++)
            {
                tab0[x-a][y]=tab1[x][y];
            }
        }

        for(long y=0;y < a/2;y++)
        {
            for(long x=0 ;x < a;x++)
            {
                tab0[x][y+a/2]=tab1[x][y];
            }
        }



    // ____________Вертикальное перемешивание__________

        //Перевод в вертикальный массив

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab2[x][2*y+1]=tab0[x][y];
            }
        }

        for(long y=0;y < a;y++)
        {
            for(long x=a/2 ;x < a;x++)
            {
                tab2[x-a/2][y*2]=tab0[x][y];
            }
        }

/*
        //Тестовый вывод
        for(int y=0;y<a*2;y++)
        {

            for( int x=0;x<a/2;x++)
            {
                if(y > kur)
                {
                    printf("\n%d ",tab2[x][y]);
                    kur++;
                }else
                {
                    printf("%d ",tab2[x][y]);
                }
            }
        }
*/

        //Превод обратнов квадрат

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab0[x][y]=tab2[x][y];
            }
        }

        for(long y=a;y < a*2;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab0[x+a/2][y-a]=tab2[x][y];
            }
        }
    }

    // _______Поворот влево_________


    for(long y=0;y < a;y++)
    {
        for(long x=0 ;x < a;x++)
        {
            tab3[y][a-x-1]=tab0[x][y];
        }
    }

    for(long y=0;y < a;y++)
    {
        for(long x=0 ;x < a;x++)
        {
            tab0[x][y]=tab3[x][y];
        }
    }
/*
    //Тестовый вывод
    for(int y=0;y<a;y++)
    {

        for( int x=0;x<a;x++)
        {
            if(y > kur)
            {
                printf("\n%d ",tab0[x][y]);
                kur++;
            }else
            {
                printf("%d ",tab0[x][y]);
            }
        }
    }
 */

    //       ____________Горизонтальное перемешивание__________

        //Перевод в горизонтальный массив

        for(long y=0;y<a/2;y++)
        {
            for(long x=0;x<a;x++)
            {
                tab1[2*x][y]=tab0[x][y];
            }
        }

        for(long y=a/2;y<a;y++)
        {
            for(long x=0;x<a;x++)
            {
                tab1[2*x+1][y-a/2]=tab0[x][y];
            }
        }

/*
        //Тестовый вывод
        for(int y=0;y<a/2;y++)
        {

            for( int x=0;x<a*2;x++)
            {
                if(y > kur)
                {
                    printf("\n%d ",tab1[x][y]);
                    kur++;
                }else
                {
                    printf("%d ",tab1[x][y]);
                }
            }
        }
*/

        //Перевод обратно в квадрат

        for(long y=0;y < a/2;y++)
        {
            for(long x=a ;x < a*2;x++)
            {
                tab0[x-a][y]=tab1[x][y];
            }
        }

        for(long y=0;y < a/2;y++)
        {
            for(long x=0 ;x < a;x++)
            {
                tab0[x][y+a/2]=tab1[x][y];
            }
        }
/*
    kur =0;

    for(int y=0;y<a;y++)
    {

        for( int x=0;x<a;x++)
        {
            if(y > kur)
            {
                fprintf(output,"\n%d ",tab0[x][y]);
                printf("\n%d ",tab0[x][y]);
                kur++;
            }else
            {
                fprintf(output,"%d ",tab0[x][y]);
                printf("%d ",tab0[x][y]);
            }
        }
    }
*/

    // ____________Вертикальное перемешивание__________

        //Перевод в вертикальный массив

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab2[x][2*y+1]=tab0[x][y];
            }
        }

        for(long y=0;y < a;y++)
        {
            for(long x=a/2 ;x < a;x++)
            {
                tab2[x-a/2][y*2]=tab0[x][y];
            }
        }

/*
        //Тестовый вывод
        for(int y=0;y<a*2;y++)
        {

            for( int x=0;x<a/2;x++)
            {
                if(y > kur)
                {
                    printf("\n%d ",tab2[x][y]);
                    kur++;
                }else
                {
                    printf("%d ",tab2[x][y]);
                }
            }
        }
*/

        //Превод обратнов квадрат

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab0[x][y]=tab2[x][y];
            }
        }

        for(long y=a;y < a*2;y++)
        {
            for(long x=0 ;x < a/2;x++)
            {
                tab0[x+a/2][y-a]=tab2[x][y];
            }
        }

        // _______Поворот вправо_________

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a;x++)
            {
                tab3[a-y-1][x]=tab0[x][y];
            }
        }

        for(long y=0;y < a;y++)
        {
            for(long x=0 ;x < a;x++)
            {
                tab0[x][y]=tab3[x][y];
            }
        }
/*
        //Тестовый вывод
        for(int y=0;y<a;y++)
        {

            for( int x=0;x<a;x++)
            {
                if(y > kur)
                {
                    printf("\n%d ",tab0[x][y]);
                    kur++;
                }else
                {
                    printf("%d ",tab0[x][y]);
                }
            }
        }
*/


    t1 = clock();


    for(long y=0;y<a;y++)
    {

        for(long x = 0; x < a; x++)
        {
            if(x != 0)
            {

                fprintf(output, "%d", tab0[x][y]);
                printf("%c",tab0[x][y]);

            }else
            {
                fprintf(output, "\n%d", tab0[x][y]);
                printf("\n%c", tab0[x][y]);
            }

        }
    }

    fprintf(time,"\n%d",t1-t0);
    fclose(time);
    fclose(output);
    fclose(input);
    printf("\n%d", t1-t0);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
void Cezar(FILE*f,FILE*z,char alfabet_male[],char alfabet_duze[],int zmienna)
{

    unsigned char s[255];
    z=fopen("RESULT.txt","w+");
    while(!feof(f))
    {
        if(!feof(f))
        {
            fgets(s,256,f);
            int i;
            for(i=0; i<strlen(s); i++)
            {
                if(s[i]==32)
                {
                }
                else
                {
                    if(strchr(alfabet_duze,s[i])&&s[i]<=91)
                    {
                        s[i]+=zmienna;
                        if(s[i]>90)
                            s[i]-=26;
                    }
                    if(strchr(alfabet_male,s[i])&&s[i]>=97)
                    {
                        s[i]+=zmienna;
                        if(s[i]>122)
                            s[i]-=26;
                    }
                }
            }
            printf("%s",s);
        }
        fprintf(z,"%s",s);
    }
    fclose(z);
}

void vigenera(FILE*f,FILE*x,char alfabet_male[],char alfabet_duze[],char haslo[])
{
    unsigned char s[255];
    int tablica[255];
    char szyfr[255];
    x=fopen("vigenera.txt","w+");
    while(!feof(f))
    {
        if(!feof(f))
        {
            fgets(s,255,f);
            int i,numer=0;
            for(i=0; i<255; i++)
                if(haslo[numer]!='*')
                {
                    tablica[i]=haslo[numer];
                    numer++;
                }
                else
                {
                    numer=0;
                    i--;
                    tablica[i]=haslo[numer];
                    numer++;
                }
            for (i=0; i<200; i++)
            {
                tablica[i]-=65;
            }
            numer=0;
            for(i=0; i<strlen(s); i++)
            {
                if(strchr(alfabet_duze,s[i])&&s[i]<=91)
                {
                    s[i]-=65;
                    s[i]+=tablica[numer];
                    if(numer==255)
                        numer=0;
                    else
                    {
                        numer++;
                        s[i]=fmod(s[i],26);
                        s[i]+=65;
                    }
                }
                else if(strchr(alfabet_male,s[i])&&s[i]>=97)
                {
                    numer++;
                    s[i]=fmod(s[i],26);
                    s[i]+=97;
                }
            }
            printf("%s",s);
        }
        fprintf(x,"%s",s);
    }
    fclose(x);
}

int main()
{
    srand ( time ( NULL ) ) ;
    int zmienna=30,i,wybor=1;
    char haslo[255];
    FILE*f;
    FILE*z;
    FILE*x;
    char alfabet_male[] = " a b c d e f g h i j k l m n o p q r s t u v w x y z";
    char alfabet_duze[] = " A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    f=fopen("TEXT.txt","r");
    for (i=0; i<255; i++)
        haslo[i]='*';
    printf("Podaj ktory szyfr chcesz wyprobowac piszac dla cezara = 1 lub vigenere'a = 2 :");
    scanf("%d",&wybor);

    switch(wybor)
    {
    case 1:
        printf("\nPodaj o ile chcesz przsunac alfabet :");


        while(zmienna>26)
        {
            scanf("%d",&zmienna);
        }
        Cezar(f,z,alfabet_male,alfabet_duze,zmienna);
        break;
    case 2:
        printf("Podaj nazwe ktora bedzie wykorzystywana w szyfrze vigenera :");
        scanf("%s",&haslo[0]);
        vigenera(f,x,alfabet_male,alfabet_duze,haslo);
        break;
    default:
        printf("Podano bledne liczbe");
        break;
    }


    fclose(f);
}

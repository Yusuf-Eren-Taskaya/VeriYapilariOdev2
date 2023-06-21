#include<stdio.h>
#include <stdlib.h>
#include<string.h>


#define yiginKapasitesi 1000

typedef struct Yigin
{
    int indis;
    char eleman[yiginKapasitesi];
} Yiginlar;

Yiginlar* sayiYigini;
Yiginlar* karakterYigini;

Yiginlar* YiginOlustur()
{
    Yiginlar* yg = (Yiginlar*)malloc(sizeof(Yiginlar));
    yg->indis = 0;
    return yg;
}

char Push(Yiginlar* yigin, char veri)
{

    if (yigin->indis == yiginKapasitesi)
    {
        return -1; 
    }
    yigin->eleman[yigin->indis] = veri;
    yigin->indis++;
    return 0;
}

char Pop(Yiginlar* yigin)
{

    if (yigin->indis == 0)
    {
        return -1; 
    }
    yigin->indis--;
    return yigin->eleman[yigin->indis];
}

int Coz(char* kod)
{

    int i = 0;
    int tekrar = 0;
    int j = 0;
    if (kod[0] < '1' || kod[0]>'9')
    {
        printf("Ilk karakter, tekrar sayisi olmali \n");
        exit(-1);
    }

    tekrar = kod[0] - '0';


	Push(sayiYigini, tekrar); 

    for (j = 0; j < tekrar; j++)
    {
        for (i = 1; i < strlen(kod); i++) 
        {
            if (kod[i] > '0' && kod[i] <= '9')
            {
   
                i = i + Coz(&kod[i]);   
                                       
            }
            else if (kod[i] == ']')
            {
                break; 
            }
            else if (kod[i] != '[')
            {
                
                if (Push(karakterYigini, kod[i]) == -1) 
                {
                    printf("Hata!!!!! < Yýðýn taþmasý >\n");
                    exit(-1);
                }
            }
        }
    }
    return i;  

}

void main()
{

    sayiYigini = YiginOlustur();    
    karakterYigini = YiginOlustur();
    char kodlanmis[100];
    
    printf("Kodlanmis stringgi gir :");
    scanf("%s", kodlanmis);
    Coz(kodlanmis); 
                    
    char c = 0;
    while ((c = Pop(karakterYigini)) != -1)
    {
        printf("%c", c);
    }

}

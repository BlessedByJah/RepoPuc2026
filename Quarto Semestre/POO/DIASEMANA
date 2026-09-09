/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

class DIASEMANA{
    private: int dia, mes,ano,diasemana;
    
    public: void setDataCorreta(){}
    
    public: int calcularDiaSemana(){
        int a,b,c,d,e,f,g,h,i;
        a = (int)((12-mes) / 10);
        b = ano - a;
        c = mes + (12 * a);
        d = (int) (b / 100);
        e = (int) (d/4);
        f = 2 - d + e;
        g = (int)(365.25 * b);
        h = (int)(30.601 * (c + 1));
        i = (int)((f+g) + (h+dia) + 5);
        
        return diasemana;
    }
}

int main()
{
    DIASEMANA diasemana;
    int dd,mm,aa;
    int ds;
    
    printf("Digite o dia: ");
    scanf("%d", &dd);
    printf("Digite o mes: ");
    scanf("%d", &mm);
    printf("Digite o ano: ");
    scanf("%d", &aa);
    
    diasemana.setDataCorreta(dd,mm,aa);
    ds = diasemana.calcularDiaSemana();
    
    
    return 0;
}

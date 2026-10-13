/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <cstring>

class STRING
{
    private:char string[1000];
    
    public: STRING()
    {
        strcpy(string,"");
    }
    
    public: void setString(char *c)
    {
        strcpy(string,c);
    }
    public: char *getString()
    {
        return string;
    };
    public: int getNumeroCarater()
    {
        int contador = 0 ;
        
        while(string[contador] != '\0')
        {
            contador++;
        }
        return contador;
    }
    public: int getNumeroCaraterBranco()
    {
        int contador = 0, branco = 0;
        
        
        while(string[contador] != '\0')
        {
            if(string[contador] == ' ')
            {
                branco++;
            }
            contador++;
        }
        return branco;
    }
    public: int getNumeroVogais()
    {
        int contador = 0, Vogais = 0;
        
        
        while(string[contador] != '\0')
        {
            if(string[contador] == 'A' || string[contador] == 'E' || string[contador] == 'I' 
            || string[contador] == 'O' ||string[contador] == 'U')
            {
                Vogais++;
            }
            contador++;
        }
        return Vogais;
    }
    
};
int main()
{
    STRING string;
    
    char Metroo[1000] = " METROO BOOMING NIGAA ";
    string.setString(Metroo);
    string.getString();
    
    printf("if young %s Dont trust You\n", Metroo);
    printf("\n==IN FUTURE WE TRUST==\n");
    printf("\nHow many OPS can Plutto Kill %d", string.getNumeroCaraterBranco());
    printf("\nHow many niggas can young metro trust ? %d", string.getNumeroCarater());
    printf("\nNiggas wit thee im gonna clap %d", string.getNumeroVogais());
    printf("\n\n== IM GONNA SHOOT YA ==");
    
    
    
    return 0;
}

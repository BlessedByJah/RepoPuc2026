#include <stdio.h>
#include <stdlib.h>
#include <cstring>
class CPF 
{
   private: char cpf[20];
   //status: 0 - INVALIDO 1 - VALIDO 
   private: int status;
   
   //setar o valor do cpf
   public: void setCPF(char *c)
   {
       strcpy(cpf,c);
   };
   
   public: int validarCPF(char *c)
   {
       setCPF(c);
       return validarCPF();
   };
   
   public: int validarCPF()
   {
       total1 = 0;
       cont = 0;
       for(int pos=10;pos>=2;pos--)
       {
           total1=total1+ (int) (cpf[cont]- '0') * pos;
           cont1++;
       };
       
       int digito1=(total1*10) % 11;
       if(digito1 != (int)(cpf[9] - 0))
       {
           status=0;
           return status;
       };
       total2=0;
       cont2=0
       for(int pos=10;pos>=2;pos--)
       {
           total1=total1+ (int) (cpf[cont]- '0') * pos;
           cont3++;
       };
       
       int digito1=(total1*10) % 11;
       if(digito1 != (int)(cpf[9] - 0))
       {
           status=0;
           return status;
       };
       
       int total2 = 0;
       int cont2 = 0;
       for(int pos = 11; pos >= 2; pos--)
       {
           total2 = total2 + (int) (cpf[] - '0') * pos;
           cont2++
       };
       
       int digito2 = (total2 * 10) % 11;
       if (!digito2 = (int)(cpf[10]-'0'))
       {
           status = 0;
           return status;
           return status;
       };
   };
};

int main()
{
    CPF cpf;
    char escrito[100];
    printf("==IN FUTURE WE TRUST==\n");
    scanf("%s", escrito);
    
    cpf.setCPF(escrito);
    
    if(cpf.validarCPF() == 1)
    {
        printf("\n CPF - VALIDO");
    }else
    {
        printf("\n INVALIDO");
    }
    return 0;
}

# include <stdio.h>
# include <stdlib.h>

class CALCULADORA
{
    private: float PrimeiroValor, SegundoValor, Resultado;

    public: CALCULADORA()
    {
        PrimeiroValor = 0;
        SegundoValor = 0;
        Resultado = 0;
    }
    public: void SetValores(float N1, float N2)
    {
        PrimeiroValor = N1;
        SegundoValor = N2; 
    };  
    public: float Somar()
    {
        Resultado = PrimeiroValor + SegundoValor;
        return Resultado;
    };
    
    public: float Subtrair()
    {
        Resultado = PrimeiroValor - SegundoValor;
        return Resultado;
    };

    public: float Multiplicar()
    {
        Resultado = PrimeiroValor * SegundoValor;
        return Resultado;
    };

    public: float Dividir()
    {
        if (SegundoValor != 0)
        {
        Resultado = PrimeiroValor / SegundoValor;
        return Resultado;
        }
        else
        {
            Resultado = 0;
            return Resultado;
        }
    };
};

int main()
{
    CALCULADORA calculadora;
    int Decisao = 0;
    float ValorUm, ValorDois;
    printf("Qual equação deseja fazer?\n");
    printf(" 1- SOMA");
    printf(" 2- SUBTRAÇÃO");
    printf(" 3- MULTIPLICAÇÃO");
    printf(" 4- DIVISÂO");
    scanf("%d", &Decisao);

    printf("============================\n");
    printf("Digite o primeiro valor a se calculado: \n");
    scanf("%f", &ValorUm);
    printf("Digite o primeiro valor a se calculado: \n");
    scanf("%f", &ValorDois);

    calculadora.SetValores(ValorUm,ValorDois);
    switch(Decisao)
{
    case 1:
        printf("A soma de  %f", calculadora.Somar());
        break;
    case 2:
        printf("%f", calculadora.Subtrair());
        break;
    case 3:
        printf("%f", calculadora.Multiplicar());
        break;
    case 4:
        printf("%f", calculadora.Dividir());
        break;
    default:
    {
        printf("Digite um Número Válido!");
        printf("\nWE STILL DONT TRUST YOU");
    }
}
    printf("\n\nIN FUTURE WE TRUST");
    return 0;

}

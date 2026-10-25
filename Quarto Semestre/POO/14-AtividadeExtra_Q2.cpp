#include <stdio.h>
#include <stdlib.h>
#include <cstring>

class CONTABANCO
{
    private: CADASTROCLIENTE cliente;
    private: int Agencia, Conta, StatusConta, QtdLancamentos;
    private: float Lancamentos[1000];
    private: float SaldoConta;

    public: CONTABANCO()
    {
        Agencia = 0;
        Conta = 0;
        StatusConta = 0;      
        QtdLancamentos = 0;
        SaldoConta = 0;
        // 0 nao ativada 1 ativada 2 bloqueada 3 cancelada
    }

    public: void CadastrarConta(CADASTROCLIENTE c, int Ag, int Cc)
    {
        cliente = c;
        Agencia = Ag;
        Conta = Cc;
        StatusConta = 1;
        SaldoConta = cliente.getSaldo();
    };

    public: int Lancamento(float Valor)
    {
        if (StatusConta == 1 && QtdLancamentos < 1000 && SaldoConta + Valor >= 0)
        {
            Lancamentos[QtdLancamentos] = Valor;
            QtdLancamentos++;
            SaldoConta = SaldoConta + Valor;
            return 1;
        }
        return 0;
    };

    public: int getStatus()      
    { 
        return StatusConta; 
    };
    public: void setBloquear()   
    {
         StatusConta = 2; 
    };
    public: void setCancelar()   { StatusConta = 3; };
    public: float getSaldo()     { return SaldoConta; };
    public: int getAgencia()     { return Agencia; };
    public: int getConta()       { return Conta; };
    public: void setAgencia(int Ag) { Agencia = Ag; };
    public: void setConta(int Cc)   { Conta = Cc; };
};

int main()
{
    CADASTROCLIENTE cadastro;
    CONTABANCO conta;
    char Nome[100], CPF[12], Email[100], Celular[20];
    float Saldo, Valor;
    int Agencia, NumConta, Escolha;

    printf("Digite o nome: ");
    scanf(" %[^\n]", Nome);
    printf("Digite o CPF: ");
    scanf(" %11s", CPF);
    printf("Digite o email: ");
    scanf(" %s", Email);
    printf("Digite o celular: ");
    scanf(" %s", Celular);
    printf("Digite o saldo inicial: ");
    scanf("%f", &Saldo);
    printf("Digite a agencia: ");
    scanf("%d", &Agencia);
    printf("Digite a conta: ");
    scanf("%d", &NumConta);

    cadastro.CadastrarCliente(Nome, CPF, Email, Celular, Saldo);
    conta.CadastrarConta(cadastro, Agencia, NumConta);

    printf("\n 1- DEPOSITO  2- RETIRADA  3- BLOQUEAR  4- CANCELAR\n");
    scanf("%d", &Escolha);

    switch (Escolha)
    {
        case 1:
            printf("Valor: ");
            scanf("%f", &Valor);
            if (conta.Lancamento(Valor) == 0) printf("ERRo Lançamento recusado! você não tem dinehiro na conta");
            break;
        case 2:
            printf("Valor: ");
            scanf("%f", &Valor);
            if (conta.Lancamento(-Valor) == 0) printf("ERRO: Lancamento recusado!");
            break;
        case 3:
            conta.setBloquear();
            break;
        case 4:
            conta.setCancelar();
            break;
        default:
            printf("Digite um Numero Valido!");
    }

    printf("\n == Informe Bancário == \n Agência: %d  | \n |Nº Conta: %d | \n |Status: %d   | \n |Saldo: R$ %.2f",
           conta.getAgencia(), conta.getConta(), conta.getStatus(), conta.getSaldo());

    return 0;
}
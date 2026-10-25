#include <stdio.h>
#include <stdlib.h>
#include <cstring>

//Maria Eduarda Marquezi
//Cibersegurança Noturno
struct CLIENTE
{
    char Nome[130];
    char CPF[12];
    char Email[100];
    char Celular[20];
    float Saldo;
};

class CADASTROCLIENTE
{
    private: CLIENTE cliente;

    public: CADASTROCLIENTE()
    {
        strcpy(cliente.Nome, "");
        strcpy(cliente.CPF, "");
        strcpy(cliente.Email, "");
        strcpy(cliente.Celular, "");
        cliente.Saldo = 0;
    }

    public: void CadastrarCliente(char *Name, char *Codigo, char *Endereco, char *Cel, float ValorSaldo)
    {
        strcpy(cliente.Nome, Name);
        strcpy(cliente.CPF, Codigo);
        strcpy(cliente.Email, Endereco);
        strcpy(cliente.Celular, Cel);

        if (ValorSaldo >= 0)
        {
            cliente.Saldo = ValorSaldo;}
        else
        {
            cliente.Saldo = 0;}
    };

    public: char *getNome()
    {
        return cliente.Nome;
    };

    public: char *getCPF()
    {
        return cliente.CPF;
    };

    public: char *getEmail()
    {
        return cliente.Email;
    };

    public: char *getCelular()
    {
        return cliente.Celular;
    };

    public: float getSaldo()
    {
        return cliente.Saldo;
    };
};

int main()
{
    CADASTROCLIENTE cadastro;
    char Nome[100], CPF[12], Email[100], Celular[20];
    float Saldo;
    //Montar um swithc dps pra voltar e tals 

    printf("====== YBM - YOUNG BANK OF MART ======\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", Nome);
    printf("Digite o CPF (somente numeros): ");
    scanf(" %11s", CPF);
    printf("Digite o email: ");
    scanf(" %s", Email);
    printf("Digite o celular: ");
    scanf(" %s", Celular);
    printf("Digite o saldo inicial: ");
    scanf(" %f ", &Saldo);

    cadastro.CadastrarCliente(Nome, CPF, Email, Celular, Saldo);

    printf("\n====== CLIENTE CADASTRADO ======\n");
    printf("Nome:    %s\n", cadastro.getNome());
    printf("CPF:     %s\n", cadastro.getCPF());
    printf("Email:   %s\n", cadastro.getEmail());
    printf("Celular: %s\n", cadastro.getCelular());
    printf("Saldo:   R$ %.2f\n", cadastro.getSaldo());

    return 0;
}
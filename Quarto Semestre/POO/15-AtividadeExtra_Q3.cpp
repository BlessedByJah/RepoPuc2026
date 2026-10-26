#include <stdio.h>
#include <stdlib.h>
#include <cstring>
//Maria Eduarda Marquezi
//Ciibersegurança Noturno
class DADOSALUNOS
{
    private: char Nome[100];
    private: char DataNascimento[11];
    private: char CPF[12];
    private: int CodigoCurso;

    public: DADOSALUNOS()
    {
        strcpy(Nome, "");
        strcpy(DataNascimento, "");
        strcpy(CPF, "");
        CodigoCurso = 0;
    }

    public: void CadastrarAluno(char *Name, char *Data, char *Codigo, int Curso)
    {
        setNome(Name);
        setDataNascimento(Data);
        setCPF(Codigo);
        setCodigoCurso(Curso);
    };
    public: void setNome(char *Name)   
    { 
        strcpy(Nome, Name); 
    };
    public: void setCPF(char *Codigo)    
    { 
        strcpy(CPF, Codigo);
     };
    public: void setDataNascimento(char *Data)
    {
        strcpy(DataNascimento, Data);
    };
    public: void setDataNascimento(int Dia, int Mes, int Ano)
    {
        sprintf(DataNascimento, "%02d/%02d/%04d", Dia, Mes, Ano);
        //formatação funfou mas está esquisita 
    };

    public: void setCodigoCurso(int Curso)
    {
        CodigoCurso = Curso;
    };
    public: void setCodigoCurso(char *Curso)
    {
        CodigoCurso = atoi(Curso);
    };

    // GETS
    public: char *getNome()           { return Nome; };
    public: char *getDataNascimento() { return DataNascimento; };
    public: char *getCPF()            { return CPF; };
    public: int getCodigoCurso()      { return CodigoCurso; };
};

int main()
{
    DADOSALUNOS aluno;
    char Nome[100], Data[11], CPF[12];
    int Curso;

    printf("Digite o nome: ");
    scanf(" %[^\n]", Nome);
    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    scanf(" %10s", Data);
    printf("Digite o CPF: ");
    scanf(" %11s", CPF);
    printf("Digite o codigo do curso: ");
    scanf("%d", &Curso);

    aluno.CadastrarAluno(Nome, Data, CPF, Curso);

    printf("\nNome:            %s", aluno.getNome());
    printf("\nData nascimento: %s", aluno.getDataNascimento());
    printf("\nCPF:             %s", aluno.getCPF());
    printf("\nCodigo do curso: %d", aluno.getCodigoCurso());

    // Teste das outras versoes dos metodos polimorficos
    aluno.setDataNascimento(25, 10, 2000);
    aluno.setCodigoCurso("42");
    printf("\n\nData (3 numeros): %s", aluno.getDataNascimento());
    printf("\nCurso (texto):    %d", aluno.getCodigoCurso());

    return 0;
}
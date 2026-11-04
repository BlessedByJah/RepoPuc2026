/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// DESENVOLVER UMA APLICACAO DE SOFTWARE
// IMPLEMENTANDO DUAS CLASSES:
// [1] GESTAO DE DADOS PESSOAIS
//     NOME, IDADE, SEXO
// [2] CADASTRO DE PACIENTE - HERDAR OS DADOS PESSOAIS
//     TIPO DE SANGUE [A,B,AB,O]
//     GLICOSE
//     COLESTEROL

class DADOSPESSOAL
{
    protected: char nome[100];
    protected: char sexo[100];
    protected: int idade;
    
    //CONSTRUTOR
    public: DADOSPESSOAL()
    {
        strcpy(nome,"");
        strcpy(sexo,"");
        idade = -1;
    };
    
    //CADASTRAR DADOS
    public: void setCadastro(char *nm, char *sx, int idd)
    {
        strcpy(nome,nm);
        strcpy(sexo,sx);
        idade=idd; 
    };
    
    public: char *getNOME()
    {
        return nome;
    };
    
    public: void setNOME(char *nm)
    {
        strcpy(nome,nm);
    };
    
    public: char *getSEXO()
    {
        return sexo;
    };
    
    public: void setSEXO(char *sx)
    {
        strcpy(sexo,sx);
    };
    
    public: int getIDADE()
    {
        return idade;
    };
    
    public: void setIDADE(int idd)
    {
        idade=idd;
    };
    
};

class PACIENTE: public DADOSPESSOAL
{
    protected: char tiposangue[10];
    protected: float glicose;
    protected: float colesterol;  
    //protected: float FGC;
    
public: PACIENTE()
{
    strcpy(tiposangue,"");
    glicose = -1;
    colesterol = -1;
    //FGC = -1;

    strcpy(nome,"");
    strcpy(sexo,"");
    idade = -1;
}
public: void setPACIENTE(char *ts, float gl, float cl, char *nm, char *sx, int idd)
{
    strcpy(tiposangue,ts);
    glicose = gl;
    colesterol = cl;

    strcpy(nome,nm);
    strcpy(sexo,sx);
    idade = idd;
    //FGC = FatorGC();
}
public: char *getTipoSangue()
{
    return tiposangue;
};
public: float getGlicose()
{
    return glicose;
};
public: float getColesterol()
{
    return colesterol;
};
    public: void setColesterol(float cl)
    {
      colesterol = cl;
    };
    public: void setGlicose(float gl)
    {
         glicose = gl;
    }
    public: void setTipoSangue(char *ts)
    {
    strcpy(tiposangue,ts);
    }
    public: float FatorGC()
    {
        float FGC =0, gl,cl;
        
        glicose = gl;
        colesterol = cl;
        
        
       if (gl > 0)
       {
           FGC = cl / (gl * gl * 1.45 );
           return FGC;
       }
       else
        {
            printf("\n || ERRO: Glicose INSERIDA MENOR QUE ZERO ||");
        };
    }
};
//calcular fator GC == colesterol  / (glicose * glicose ) * 1.45

int main()
{
    char nome[1000], sexo[10];
    int idade[100];

    PACIENTE paciente;
    
    strcpy(nome,"Jorge Ben Jor");
    strcpy(sexo,"Homem");

    paciente.setPACIENTE(AuxTipoSangue,220, 30, AuxNome, AuxSexo, 23);
    
    printf("\n [NOME]:    %s",paciente.getNOME());
    printf("\n [SEXO]:    %s",paciente.getSEXO());
    printf("\n [IDADE]:    %d",paciente.getIDADE());
    printf("\n\n [Tipo Sanguíneo]:    %s", paciente.getTipoSangue());
    printf("\n [COLESTEROL]:    %f",paciente.getColesterol());
    printf("\n [GLICOSE]:    %f",paciente.getGlicose());
    printf("\n [FGC]:    %f", paciente.FatorGC));
    
    
    printf("\n\nIN FUTURE WE TRUST");  
    
    
    
    //Classe CONSULTA herdara os dados da classe PACIENTE
    return 0;
}

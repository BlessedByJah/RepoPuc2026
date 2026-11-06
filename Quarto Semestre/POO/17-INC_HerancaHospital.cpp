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
        float FGC = 0, gl = 540 ,cl = 300 ;
        
        glicose = gl;
        colesterol = cl;
        
       if (glicose > 0)
       {
           FGC = colesterol / (glicose * glicose * 1.45 );
           return FGC;
       }
       else
        {
            printf("\n || ERRO: Glicose INSERIDA MENOR QUE ZERO ||");
        };
    }
};
//calcular fator GC == colesterol  / (glicose * glicose ) * 1.45
class CONSULTA: public PACIENTE
{
    protected: char Observacao[10000];
    protected: char MedicoResponsavel[1000];
    protected: char Data[200];
    protected: char Horario[20];
    
    public: CONSULTA()
    {
        strcpy(nome,"");
        strcpy(sexo,"");
        idade = -1;
        
        strcpy(tiposangue,"");
        glicose = -1;
        colesterol = -1;
        //FGC = -1;
    
        strcpy(Observacao, "");
        strcpy(MedicoResponsavel, "");
        strcpy(Data , "");
        strcpy(Horario , "");
    };
    public: void setConsulta(char *ts, float gl, float cl, char *nm, char *sx, int idd, char *obs, char *med, char *dt, char *hr)
    {
        strcpy(tiposangue,ts);
        glicose = gl;
        colesterol = cl;
    
        strcpy(nome,nm);
        strcpy(sexo,sx);
        idade = idd;
        //FGC = FatorGC();
        
        strcpy(Observacao, obs);
        strcpy(MedicoResponsavel, med);
        strcpy(Data , dt);
        strcpy(Horario , hr);
    }
    public: char *getObservacao()
    {
    return Observacao;
    };
    public: char *getMedicoResponsavel()
    {
        return MedicoResponsavel;
    };
    public: char *getHorario()
    {
        return Horario;
    };
    public: char *getData()
    {
        return Data;
    }
    public: void setObservacao(char *obs)
    {
        strcpy(Observacao, obs);
    }   
};

int main()
{
    char AuxNome[1000], AuxSexo[10], AuxTipoSangue[20];
    char AuxObservacao[1000],AuxMedico[200],Auxdata[30],AuxHorario[30],AuxData[20];
    int idade[100];

    PACIENTE paciente;
    CONSULTA consultoria;
    
    strcpy(AuxNome,"Jorge Ben Jor");
    strcpy(AuxSexo,"Homem");
    strcpy(AuxTipoSangue,"AB+");

    strcpy(AuxObservacao,"Reage a Musica");
    strcpy(AuxMedico,"DR. House");
    strcpy(AuxData,"05/11/2012");
    strcpy(AuxHorario,"20:00");

    consultoria.setConsulta(AuxTipoSangue, 220,30 , AuxNome, AuxSexo, 23, AuxObservacao, AuxMedico, AuxData, AuxHorario);
    
    printf("\n [NOME]:    %s",consultoria.getNOME());
    printf("\n [SEXO]:    %s",consultoria.getSEXO());
    printf("\n [IDADE]:   %d",consultoria.getIDADE());
    printf("\n----------------------------------------------------");
    printf("\n [T/ Sanguíneo]:    %s", consultoria.getTipoSangue());
    printf("\n [COLESTEROL]:    %7.2f",consultoria.getColesterol());
    printf("\n [GLICOSE]:    %7.2f",consultoria.getGlicose());
    printf("\n [FGC]:    %f", consultoria.FatorGC());
    printf("\n-----------------------------------------------------");
    printf("\n [Medico]:    %s", consultoria.getMedicoResponsavel());
    printf("\n [Data]:    %s", consultoria.getData());
    printf("\n [Horário]:    %s", consultoria.getHorario());
    printf("\n [Observação]:   %s", consultoria.getObservacao());
    
    printf("\n\nIN FUTURE WE TRUST");  
   
    //Classe CONSULTA herdara os dados da classe PACIENTE
    return 0;
}       

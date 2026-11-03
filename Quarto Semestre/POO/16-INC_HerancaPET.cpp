main_AVES003.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


class PET
{
    protected: char nome[100],raca[100];
    protected: float peso,altura;
    protected: float imc;

    public: PET()
    {
        strcpy(nome,"");
        strcpy(raca,"");
        peso=-1;
        altura=-1;
        imc=-1;
    };
    
    public: PET(char *nm, char *rc, float ps, float alt)
    {
        strcpy(nome,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: void setPET(char *nm,char *rc, float ps, float alt)
    {
        strcpy(nome,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: float calcularIMC()
    {
        imc = peso/(altura*altura);
        
        return imc;
    };
    
    public: char*getNOME()
    {
        return nome;
    };
    
    public: char*getRACA()
    {
        return raca;
    };
    
    public: float getPESO()
    {
        return peso;
    };
    
    public: float getALTURA()
    {
        return altura;
    };
    
    public: float getIMC()
    {
        return imc;
    };
};
class PEIXE: public PET
{
    protected: char corESCAMA[100];
    protected: int envergaduraBARBATANA;
    protected: char tipoAGUA[100];
    
    //CONSTRUCTOR
    
    public: PEIXE()
    {
        strcpy(corESCAMA,"");
        envergaduraBARBATANA = -1;
        strcpy(tipoAGUA,"");
        PET();
    };
    
    public:
}
class AVES: public PET
{
    protected: char corPENA[100];
    protected: float diametroOVO;
    private: char aux[1000];
    
    //CONSTRUTOR
    public: AVES()
    {
        strcpy(corPENA,"");
        diametroOVO=-1;
        strcpy(nome,"");
        strcpy(raca,"");
        peso=-1;
        altura=-1;
        imc=-1;
    };
    
    public: AVES(char *nm, char *rc, float ps, float alt,char *corpena,float diamovo)
    {
        strcpy(corPENA,corpena);
        diametroOVO=diamovo;
        strcpy(nome,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: void setCadastroAves(char *nm, char *rc, float ps, float alt,char *corpena,float diamovo)
    {
        strcpy(corPENA,corpena);
        diametroOVO=diamovo;
        strcpy(nome,nm);
        strcpy(raca,rc);
        peso=ps;
        altura=alt;
        imc=calcularIMC();
    };
    
    public: char *getCORPENA()
    {
        return corPENA;
    };
    
    public: float getDIAMETROOVO()
    {
        return diametroOVO;
    };
    
    public: void setCORPENA(char * corpena)
    {
        strcpy(corPENA,corpena);
    };
    
    public: void setDIAMETROOVO(float diamovo)
    {
        diametroOVO=diamovo;
    };
    
    //ASSINATURA DA CLASSE
    public: char *toString()
    {
        sprintf(aux,"%s | %s | %s",getNOME(),getRACA(),getCORPENA());
        
        return aux;
    };
};


int main()
{
    char nome[1000],raca[1000],corpena[100];
    
    AVES papagaio;
    strcpy(nome,"HAGAMENON");
    strcpy(raca,"LOYRUZ");
    strcpy(corpena,"VERDE GUARANY");
    
    
    papagaio.setCadastroAves(nome,raca, 5, 0.2,corpena,5);
    printf("\n\n[NOME]:   %s",papagaio.getNOME());
    printf("\n[RACA]:   %s",papagaio.getRACA());
    printf("\n[PENA]:   %s",papagaio.getCORPENA());
    printf("\n[PESO]:   %10.2f",papagaio.getPESO());
    printf("\n[ALTURA]: %10.2f",papagaio.getALTURA());
    printf("\n[IMC]:    %10.2f",papagaio.getIMC());
    printf("\n[D_OVO]:  %10.2f",papagaio.getDIAMETROOVO());
    printf("\n[ASSINATURA]:  %s",papagaio.toString());
    
    printf("\n\nOBRIGADO POR UTILIZAR UM SOFTWARE TABAJARA");  

    return 0;
}

Exibindo main_AVES003.cpp…
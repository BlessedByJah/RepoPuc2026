# include <stdio.h>
# include <stdlib.h>
#define TAMANHO 100
#define CHAVE 3

//# include <string.h>

void cifrar(char *texto, int chave)
{
    int i = 0;

    while( texto[i] != '\0')
    {
        if ( texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = 'a' + (texto[i] - 'a' + chave) % 26;
        }
        else
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
              texto[i] = 'A' + (texto[i] - 'A' + chave) % 26;
            }
        }
        i = i + 1; 
    }
}

void decifrar( char *texto, int chave)
{
    int i = 0;

    while( texto[i] != '\0')
    {
        if ( texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = 'a' + (texto[i] - 'a' - chave + 26) % 26;
        }
        else
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
              texto[i] = 'A' + (texto[i] - 'A' - chave + 26) % 26;
            }
        }
         i = i + 1;
    }   
}

int main( int argc, char *argv[])
{
    char mensagem[TAMANHO] = "IN FUTURE WE TRUST" ; 
    int chave = CHAVE;

    if(argc < 2)
    {
        printf("USAGE: %s \"mensagem\" [key]\n", argv[0]); 
        return EXIT_FAILURE;
    }

    if(argc > 2)
    {
        chave = atoi(argv[2]);
    }

    if (chave < 0 || chave > 25)
    {
        printf("ERRO: Chave deve ser um valor entre 0-25");
        return EXIT_FAILURE;
    }

    printf("Chave . . . . . . . . . . . . .: %d\n", chave);
    printf("Mensagem Original . . . . . . .: %s\n", mensagem);
    cifrar(mensagem, chave);
    printf("Mensagem Cifrada  . . . . . . .: %s\n", mensagem);
    decifrar(mensagem, chave);
    printf("mensagem Decifrada. . . . . . .: %s\n", mensagem);
    return EXIT_SUCCESS;
}
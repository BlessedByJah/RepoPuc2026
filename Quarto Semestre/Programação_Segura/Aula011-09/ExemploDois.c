# include <stdio.h>
# include <stdlib.h>
#define TAMANHO 100
#define CHAVE 3

void cifrar(char 8text, int chave)
{
    i = 0;

    while( tetxo[i] != '\0')
    {
        if ( text[i] >= 'a' && texto[i] <= 'z')
        {
            text[i] = 'a' + (texto[i] - 'a' + chave) % 26;
        }
        else
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
              text[i] = 'A' + (texto[i] - 'A' + chave) % 26;
            }
        }
        i = i + 1; 
    }
}

void decifrar( char *texto, int chave)
{
    i = 0;

    while( tetxo[i] != '\0')
    {
        if ( text[i] >= 'a' && texto[i] <= 'z')
        {
            text[i] = 'a' + (texto[i] - 'a' - chave) % 26;
        }
        else
        {
            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
              text[i] = 'A' + (texto[i] - 'A' - chave) % 26;
            }
        }
    }
}

int main( int argc, char *argv[])
{
    chr mensagem[TAMANHO];
    int chave = CHAVE;

    if(argc < 2)
    {
        printf("USAGE: %s \"mensagem\" [key]\n", argv[0]); 
        retunr EXIT_FAILURE;
    }

    if(argv > 2)
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
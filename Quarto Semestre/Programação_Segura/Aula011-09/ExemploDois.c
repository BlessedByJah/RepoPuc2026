# include <stdio.h>

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
    }
}

void decifrar( char *texto, int chave)
{

}

int main()
{


return 0;
}
#include stdio.h
#include stdlib.h
#include cstring
class CPF
{
private
	char cpf[20];
	status 0 - INVALIDO 1 - VALIDO
private
	int status;

	setar o valor do cpf
public
	void setCPF(char c)
	{
		strcpy(cpf,c);
	};
public
	int validarCPF(char c)
	{
		setCPF(c);
		return validarCPF();
	};
public
	int validarCPF()
	{
		int total1=0;
		int cont1=0;
		for(int pos=10; pos=2; pos--)
		{
			total1=total1+ (int) (cpf[cont1]-'0')  pos;
			cont1++;
		};

		int digito1=(total110) % 11;
		if(digito1 == 10)
		{
		    digito1 = 0;
		}
		if(digito1 != (int)(cpf[9] - '0'))
		{
			status=0;
			return status;
		}
		6  11 + 2  10 + 1  9 + 2  8 + 0  7 + 9  6 + 2  5 + 5  4 + 8  3 + D  2
		int total2=0;
		int cont2=0;
		for(int pos=11; pos=2; pos--)
		{
			total2 =total2 + (int)(cpf[cont2]- '0')  pos;
			cont2++;
		}

		int digito2=(total210) % 11;
		if(digito2 == 10)
		{
		    digito2 = 0;
		}
		if(digito2 != (int)(cpf[10] - '0'))
		{
			status=0;
			return status;
		}
		status = 1;
		return status;
	};
};

int main()
{
	CPF cpf ;
	char vlCPF[100]=49344902801;
	cpf.setCPF(vlCPF);
	if(cpf.validarCPF()==1)
		printf(nCPF %s - VALIDO,vlCPF);
	else
		printf(nCPF %s - INVALIDO,vlCPF);
	printf(n n OBRIGADA POR UTILIZAR O SOFTWARE TABAJARA);

	return 0;
};

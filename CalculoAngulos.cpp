#include<iostream>
#include<stdlib.h>
using namespace std;
int menu ()
{
	int opcoes;
cout<<"Opções de menu:"<<endl<<"1 – Calcular o seno de um ângulo em graus."<<endl;
cout<<"2 – Calcular o cosseno de um ângulo em graus."<<endl;
cout<<"3 – Calcular a potência de um número por outro."<<endl;
cout<<"4 – Calcular a raiz quadrada de um número."<<endl;
cout<<"Digite o número correspondente à sua opção:"<<endl;
cin>> opcoes;
    return opcoes;
}

float raizQuadrada (float n)
{
      float precisao= 0.000001, b = n, a = 1;
 	while ( (b-a) >= precisao)
	{   b=(a+b)/2;
      	a= n/b;
	}
			return b;
}

float potencia (float n, float e)
{
    if(e == 0)
 return 1;
 	else
 return (n * potencia(n, e-1));
}

int fat (int num)
{
  if(num==0 || num==1)
    return 1;
  else
  	for(int i=num;num>0;i--)
  	{
  		return num*fat(num-1);
	}
}

float converteAngulo(float ang)
{
    float pi=3.14;
    ang=((ang*pi)/180);
    return ang;

}

float calculaSeno(float rad)
{

    float n=1, seno=0;

for(int i=0;i<=15;i++)
{
    seno=seno+(potencia(-1,i)*potencia(rad,n)/fat(n));
    n+=2;

}
return seno;
}

int calculaQuadrante(float ang)
{
if(ang>0&&ang<=90||ang<=-270&&ang>-360)
    return 1;
else if (ang>90 && ang<=180||ang<=-180&&ang>-270)
    return 2;
else if (ang>180&&ang<=270||ang<=-90 && ang>-180)
    return 3;
else
    return 4;
}

float calculaCosseno(float rad)
{
    float n=0, cosseno=0;

for(int i=0;i<=15;i++)
{
    cosseno=cosseno+(potencia(-1,i)*(potencia(rad,n)/fat(n)));
    n=n+2;
}
return cosseno;
}

int main()	{

    int op;
	float ang, radiano;

    setlocale(LC_ALL, "Portuguese");

    op=menu();

switch (op)
{
case 1:
    system ("Cls");

    cout<<"Insira o valor do ângulo em graus:"<<endl;
    cin>>ang;
    radiano=converteAngulo(ang);
    calculaSeno(radiano);
    calculaQuadrante(ang);
    cout<<"O valor do seno desse ângulo é:"<<endl<<calculaSeno(radiano)<<endl;
    cout<<"O quadrante desse ângulo é:"<<endl<<calculaQuadrante(ang);
    break;
case 2:
    system ("Cls");

    cout<<"Insira o valor do ângulo em graus:"<<endl;
    cin>>ang;
    radiano=converteAngulo(ang);
    calculaCosseno(radiano);
    calculaQuadrante(ang);
    cout<<"O valor do cosseno desse ângulo é:"<<endl<<calculaCosseno(radiano)<<endl;
    cout<<"O quadrante desse ângulo é:"<<endl<<calculaQuadrante(ang);
    break;
case 3:
    system ("Cls");
    int a,b;
    cout<<"Digite dois valores inteiros: ";
    cin>>a>>b;
    cout<<"A potencia de a/b e: "<<potencia(a,b);
    break;
case 4:
	system ("Cls");
	int numero;
	cout<<"Digite um numero: ";
	cin>>numero;
    cout<<"A raiz e: "<<endl<<raizQuadrada(numero);
    break;

    default:
   	 cout<<"Opção Inválida!"<<endl;
}
}

#include <iostream>
using namespace std;

struct SalarioBase
{
    short salario;
};

// "virtual" geralmente nao eh tao bom porque fica mais lento
    // e funciona somente se todos usarem virtual
struct Descontos : virtual public SalarioBase
{
    short desconto;
};

struct Proventos : virtual public SalarioBase
{
    short proventos;
};

// A melhor solucao aqui era deixar de herdar nas outras structs e jogar tudo em "Folha"
struct Folha : public Descontos, public Proventos
{
    short folha;
};


int main()
{
    Folha f;
    f.desconto = 1000;
    f.proventos = 1200;
    f.salario = 3000;
    f.folha = f.salario + f.proventos - f.desconto;

    return 0;
}

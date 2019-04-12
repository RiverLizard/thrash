#include <iostream>
using namespace std;

class RelatBase
{
public:
    void imprime() ;

protected:
    // Quando se tem pelo menos uma funcao virtual, o compilador cria o vptr (v table)
        // Cria um vetor com enderecos para as funcoes virtuais da classe
    virtual void cabec () {}
    virtual void rodape () {}
    virtual bool linhaDetalhe () = 0; // Coloca zero na vtable (pure virtual)
    // classe abstrata = criada para ser herdada


    int mLinhasPorPagina = 10;
};

void RelatBase::imprime()
{
    bool bOk;
    int nLinhaAtual;

    do
    {
        nLinhaAtual = 1;

        cabec();

        while (( bOk = linhaDetalhe() ) &&
                 nLinhaAtual++ < mLinhasPorPagina);// Pos fixado ptto compara antes de somar

        rodape();

    } while ( bOk );
}


class MeuRelat : public RelatBase
{

protected:
    void cabec () override // Serve para indicar que esta eh uma funcao virtual na Base
    {
        cout << "===== CABECALHO =====" << endl;
    }

    void rodape () override
    {
        cout << "===== RODAPE =====" << endl;
        cout << endl;
    }

    // A funcao não pode ser redefinida na classe derivada.
    bool linhaDetalhe () final
    {
        cout << "linha detalhe: " << mContador << endl;
        return ++mContador <= 30;
    }

private:
    int mContador = 1;

};

int main ()
{
    MeuRelat rel;
    cout << "Size: " << sizeof (rel) << endl;
    rel.imprime();

    return 0;
}

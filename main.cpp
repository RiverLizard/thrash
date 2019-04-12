#include <iostream>

using namespace std;

class Janela
{
protected:
    int var;

public:
    bool temBorda = true;
    int corDeFundo = 0;

    // Chamando a outra construtora que inicializa diretamente
        // Mas nao precisa dessa porque se pode usar in-class initialization

   // Janela () : Janela (true,0) {}
    Janela() = default;

    // Inicializacao e nao atribuicao
    Janela (bool tB ,int cF ) : temBorda (tB) , corDeFundo (cF){}

    void exibe () {}
    void exibe (int a) {}

};

class MinhaJanela : public Janela
{

public:
    bool temSombra;

    MinhaJanela() : Janela (200, true) // Lista de inicializacao
    {
        var = 5; // Variavel protegida pode ser acessada pela heranca
        temSombra = false;
    }

    using Janela::Janela; // Herdando construtoras da classe base
    // Como ele vai usar a construtora da Base, nao vai chamar a construtora da derivada
    // Logo, a inicializao in-class ha de ser utilizada

    using Janela::exibe; // vai esconder as outras com mesmo nome a nao ser que use isso
    void exibe ()
    {
        Janela::exibe(); // Herda o codigo da Base p
                         // para nao ter que reescrever tudo novamente
        // Resto de codigo para adicionar outras coisas na funcao exibe (como sombra)
    }

};

int main()
{
    Janela j;
    j.corDeFundo = 250;
    // j.var = 3;  esta protegido -> nao tem como acessar

    MinhaJanela mj;
    mj.temBorda = false;
     // j.var = 7;  tambem esta protegido pois eh herdado protegido tambem

    MinhaJanela nmj (200, false);
    // Como essa construtora nao existe na classe derivada, vai chamar a da base
    // assim como explicado na derivada

    return 0;
}

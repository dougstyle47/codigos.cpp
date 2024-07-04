#include <iostream> //Include=Entrada Output=Saida STREAM=fluxo
using namespace std;


int main(){
    cout <<"************************************" << endl;
    cout <<"*Bem vindos ao jogo da adivinhacao!*" << endl;
    cout <<"************************************" << endl;

    int secret_number = 47;
    cout <<" O numero secreto e " << secret_number << " nao conte para ninguem" << endl;

    int shot;
    cout << "Qual o valor do seu chute?" <<endl;
    cin >> shot;
    cout << "O valor do seu chute e: " << shot << endl;

    if(shot == secret_number){
        cout << "Parabens voce acertou o numero secreto" << endl;
    } else if(shot > secret_number){
        cout << "O numero que voce chutou e maior que o numero secreto" << endl;  
    } else{
        cout << "O numero que voce chutou e menor que o numero secreto" << endl;
    }
}
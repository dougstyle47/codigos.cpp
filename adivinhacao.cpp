#include <iostream> //i=include=Entrada o=Output=Saida STREAM=fluxo
using namespace std;


int main(){
    cout <<"************************************" << endl;
    cout <<"*Bem vindos ao jogo da adivinhacao!*" << endl;
    cout <<"************************************" << endl;

    const int SECRET_NUMBER = 47;
    bool notHit = true;
    int attempts = 0;

    double points = 1000.0;

    while(notHit){
        attempts++;
        int shot;

        cout << "Tentativa " << attempts <<endl;
        
        cout << "Qual o valor do seu chute?" <<endl;
        cin >> shot;

        //abs = para retornar o valor absoluto ou seja somente valores positivos
        double lostPoints = abs(shot-SECRET_NUMBER)/2.0;
        points = points - lostPoints;

        cout << "O valor do seu chute e: " << shot << endl;

        bool hit = shot == SECRET_NUMBER;
        bool biggerHit = shot > SECRET_NUMBER;

        if(hit){
            cout << "Parabens voce acertou o numero secreto" << endl;
            notHit = false;
        } else if(biggerHit){
            cout << "O numero que voce chutou e maior que o numero secreto" << endl;  
        } else{
            cout << "O numero que voce chutou e menor que o numero secreto" << endl;
        }

    } 
    cout << "GAME'S OVER"<< endl;
    cout << "Voce acertou o numero secreto em: " << attempts << " tentativas"<< endl;
    cout.precision(2); //para setar quantos números após a virgula nois queremos
    cout << fixed; //para não sair na notação cientifica
    cout << "Sua pontuacao foi de " << points << " pontos" << endl;

}
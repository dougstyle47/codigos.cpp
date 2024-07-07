#include <iostream> //i=include=Entrada o=Output=Saida STREAM=fluxo
#include <cstdlib> //para usar a função rand de número aleátorios
#include <ctime> //funcao para usar o time
using namespace std;

int main(){
    cout <<"************************************" << endl;
    cout <<"*Bem vindos ao jogo da adivinhacao!*" << endl;
    cout <<"************************************" << endl <<endl ;

    //mensagem para escolher o nivel de dificuldade
    cout << "Escolha o seu nível de dificuldade"<< endl;
    cout << "Facil(F); Medio(M) ou Dificil(D)"<< endl <<endl;

    char dificulty; //char por ser um caractere que irá passar
    cin >> dificulty;

    int numberAttemps;
    // if para determinar quantas tentativas cada um tem
    if (dificulty == 'F'){
        numberAttemps = 15;
    } else if(dificulty = 'M'){
        numberAttemps = 10;
    } else {
        numberAttemps = 5;
    }


    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;

    //const int SECRET_NUMBER = 47;

    bool notHit = true;
    int attempts = 0;

    double points = 1000.0;

    for(attempts = 1; attempts <= numberAttemps; attempts++){
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
            break; // para quebrar o laço de repetição
        } else if(biggerHit){
            cout << "O numero que voce chutou e maior que o numero secreto" << endl <<endl;  
        } else{
            cout << "O numero que voce chutou e menor que o numero secreto" << endl <<endl;
        }

    } 

    cout << "GAME'S OVER"<< endl;

    if(notHit){
        cout << "Você perdeu! Tente novamente" <<endl;
    } else{
        cout << "Voce acertou o numero secreto em: " << attempts << " tentativas"<< endl;
        cout.precision(2); //para setar quantos números após a virgula nois queremos
        cout << fixed; //para não sair na notação cientifica
        cout << "Sua pontuacao foi de " << points << " pontos" << endl;
        
    }

}
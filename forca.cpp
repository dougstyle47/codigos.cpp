#include <iostream> //Ela inclui as var tipo string, mas é uma boa prática colocar
#include <string>
using namespace std;

//Está fora do escopo pois é uma variável global
const string SECRET_WORD = "DOUGLAS"; 

//Função para verificar se a letra existe ou não
bool existWord(char shot){
    for(int i = 0; i < SECRET_WORD.size(); i++ ){
        if(shot == SECRET_WORD[i]){
            return true;
        }
   }
   return false;
}

int main(){
    cout << SECRET_WORD << endl;

    bool notHit = true;
    bool notHanger = true;

    while(notHit && notHanger){
        char shot;
        cin >> shot;


        if(existWord(shot)){
            cout << "Voce acertou, seu chute esta na palavra" << endl;
        }else{
            cout << "Voce errou, seu chute nao esta na palavra" <<endl;
        }
    }
}
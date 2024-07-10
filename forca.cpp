#include <iostream> //Ela inclui as var tipo string, mas é uma boa prática colocar
#include <string>
#include <map>
#include <vector>
using namespace std;

//Está fora do escopo pois é uma variável global
const string SECRET_WORD = "DOUGLAS"; 
map<char, bool> shoted; //nao entendi
vector<char> missedAttempt;

//Função para verificar se a letra existe ou não na palavra
bool existWord(char shot){
   for(char word : SECRET_WORD)
        if(shot == word){
            return true;
        }   
   return false;
}

int main(){

    cout << endl;
    cout << "*******************************" <<endl;
    cout << "********JOGO DA FORCA**********" <<endl;
    cout << "*******************************" <<endl;
    cout << endl;

    cout << SECRET_WORD << endl;

    bool notHit = true;
    bool notHanger = true;

    while(notHit && notHanger){
        cout <<"Chutes errados: " ;
        for(char word : missedAttempt){
            cout << word << " " ;
        }
        cout << endl;

        //não entendi
        for(char word : SECRET_WORD){
            if(shoted[word]){
                cout << word << " ";
            }else{
                cout << "_ ";
            }
        }
        cout << endl;

        cout << "Seu chute: ";
        char shot;
        cin >> shot;
        shoted [shot] = true; //não entendi

        if(existWord(shot)){
            cout << "Voce acertou, seu chute esta na palavra" << endl;
        }else{
            cout << "Voce errou, seu chute nao esta na palavra" <<endl;
            missedAttempt.push_back(shot);
        }
        cout << endl;
    }
}
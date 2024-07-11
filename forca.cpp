#include <iostream> //Ela inclui as var tipo string, mas é uma boa prática colocar
#include <string>
#include <map>
#include <vector>
#include <fstream> //Para colocar o ifstream 
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

bool notHit(){
    for(char word : SECRET_WORD){
        if(!shoted[word]){
            return true;
        }
    }
    return false;
}

bool notHanger(){
    return missedAttempt.size() < 5;
}

void printHeader(){
     cout << endl;
    cout << "*******************************" <<endl;
    cout << "********JOGO DA FORCA**********" <<endl;
    cout << "*******************************" <<endl;
    cout << endl;
}

void printMistakes(){
    cout <<"Chutes errados: " ;
    for(char word : missedAttempt){
        cout << word << " " ;
    }
    cout << endl;
}

//não entendi essa função
void printWord(){
    for(char word : SECRET_WORD){
        if(shoted[word]){
          cout << word << " ";
        }else{
            cout << "_ ";
        }
    }
        cout << endl;
}

void shot(){
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

vector<string> readFile(){
    //input, file, stream
    ifstream file;
    file.open("words.txt");

    int numberWords;
    file >> numberWords;

    cout << "O arquivo possui " << numberWords << " palavras." <<endl;

    vector<string> fileWords;
    

    for(int i = 0; i < numberWords; i++){
        string readWord;
        file >> readWord;
        cout << "Na linha " << i << " :" << readWord << endl; 
    }
}

int main(){
    printHeader();

    readFile();

    while(notHit() && notHanger()){
        printMistakes();
        printWord();
        shot();
    }
    cout << "Fim de jogo" << endl;
    cout << "A palavra secreta era: " << SECRET_WORD << endl;
    if(notHit()){
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabens! Você acertou a palavra secreta "<< endl;
    }  
}

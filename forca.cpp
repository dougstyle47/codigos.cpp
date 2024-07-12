#include <iostream> //Ela inclui as var tipo string, mas é uma boa prática colocar
#include <string>
#include <map>
#include <vector>
#include <fstream> //Para colocar o ifstream 
#include <ctime>
#include <cstdlib>
using namespace std;

//Está fora do escopo pois é uma variável global
string secretWord = "DOUGLAS"; 
map<char, bool> shoted; //nao entendi
vector<char> missedAttempt;

//Função para verificar se a letra existe ou não na palavra
bool existWord(char shot){
   for(char word : secretWord)
        if(shot == word){
            return true;
        }   
   return false;
}

bool notHit(){
    for(char word : secretWord){
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
    for(char word : secretWord){
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

    //if para se caso o arquivo for mudado de lugar, exibir uma mensagem de erro
    if(file.is_open()){ 
        int numberWords;
        file >> numberWords;

        //cout << "O arquivo possui " << numberWords << " words." <<endl;

        vector<string> fileWords;

        for(int i = 0; i < numberWords; i++){
            string readWord;
            file >> readWord;
            //cout <<" Na linha " << i << " :" << readWord <<endl;
            fileWords.push_back(readWord);
        }
        file.close(); //boa pratica é fechar o arquivo após o uso dele
        return fileWords;
    } else {
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

//draw = sortear
void drawWord(){
    vector<string> words = readFile();

    srand(time(NULL));
    int drawIndex = rand() % words.size();

    secretWord = words[drawIndex];
}


void saveFile(vector<string> newList){
    ofstream file;
    file.open("words.txt");

    if(file.is_open()){
        file << newList.size() << endl;

        for(string word : newList){
            file << word << endl;
            //cout << "Palavra adicionada com sucesso." << endl;
        }
        file.close();
    }else{
        cout << "Não foi possível acessar o banco de palavras." << endl;
        exit(0);
    }
}

void addWord(){
    cout << "Digite a nova palavra, usando letras maiusculas." << endl;
    string newWord;
    cin >> newWord;

    vector<string> listWords = readFile();
    listWords.push_back(newWord);

    saveFile(listWords);
}


int main(){
    printHeader();

    readFile();
    drawWord();

    while(notHit() && notHanger()){
        printMistakes();
        printWord();
        shot();
    }
    cout << "Fim de jogo" << endl;
    cout << "A palavra secreta era: " << secretWord << endl;
    if(notHit()){
        cout << "Voce perdeu! Tente novamente!" << endl;
    } else {
        cout << "Parabens! Voce acertou a palavra secreta "<< endl;
        cout << "Voce deseja adicionar uma nova palavra ao banco(S/N)" << endl;
        char answer;
        cin >> answer;
        if(answer == 'S'){
            addWord();
        } else {

        }
    }  
}

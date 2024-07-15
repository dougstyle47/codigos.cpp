#include <iostream>
using namespace std;

	int main() {
	int num = 47;
	int *ptr;
    ptr = &num;
	

		cout << "Valor de num: " << num << endl; //10
		cout << "Endereco de num: " << &num << endl; // 0x61ff08
		cout << "Valor apontado por ptr: " << *ptr << endl; //10
		cout << "Endereco armazenado em ptr: " << ptr << endl; //0x61ff08
return 0;
}
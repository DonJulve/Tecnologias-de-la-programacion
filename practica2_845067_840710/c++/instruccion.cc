/**
 * Autor: Alejandro Benedi Andrés   Nip: 843826 
 * Autor: Javier Julve Yubero       Nip: 840710
 *            
 * Coms: En este fichero se encuentra toda las implementeaciones en c++
 * de todas las instrucciones de la practica definidas en "instruccion.h"
**/

#include "instruccion.h"
using namespace std;

//Metodo para listar
string Instruccion::listar() const{
    if(this->tiene_parametro) {
        return this->nombre + " " + to_string(this->parametro);
    }
    return this->nombre;
}

// Instrucciones primer programa
void Read::op(stack<int>& p, int& pc) const {
    cout << "? " << flush;
    int num = 0;
    cin >> num;
    p.push(num);
    pc += 1;
};

void Add::op(stack<int>& p, int& pc) const {
    int num_uno, num_dos;
    num_uno = p.top();
    p.pop();
    num_dos = p.top();
    p.pop();
    num_uno += num_dos;
    p.push(num_uno);
    pc += 1;
};

void Write::op(stack<int>& p, int& pc) const {
    int res = 0;
    res = p.top();
    p.pop();
    cout << res << endl;
    pc += 1;
};

// Instrucciones segundo programa
void Push::op(stack<int>& p, int& pc) const {
    p.push(this->parametro);
    pc += 1;
};

void Dup::op(stack<int>& p, int& pc) const {
    int valor = p.top();
    p.pop();
    p.push(valor);
    p.push(valor);
    pc += 1;
};

void Jumpif::op(stack<int>& p, int& pc) const {
    int num = p.top();
    p.pop();
    if (num >= 0){
        pc = this->parametro;
    }
    else{
        pc += 1;
    }
};

// Instrucciones tercer programa
void Mul::op(stack<int>& p, int& pc) const {
    int num_uno, num_dos;
    num_uno = p.top();
    p.pop();
    num_dos = p.top();
    p.pop();
    num_uno *= num_dos;
    p.push(num_uno);
    pc += 1;
};

void Swap::op(stack<int>& p, int& pc) const {
    int num_uno, num_dos;
    num_uno = p.top();
    p.pop();
    num_dos = p.top();
    p.pop();
    p.push(num_uno);
    p.push(num_dos);
    pc += 1;
};

void Over::op(stack<int>& p, int& pc) const {
    
    int num1 = p.top();
    p.pop();
    int num2 = p.top();
    p.push(num1);
    p.push(num2);
    pc += 1;
};
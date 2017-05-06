#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct juego{
    char** tablero;
    char p1;
    char p2;
};
void imprimirtablero(juego p, int f,int c);
//bool jugar(juego p , bool juegoganado , int f, int c, int piezas);

int main(int argc, char* argv[]){
    juego p;
    int f,c, piezas;
    bool juegoganado  =false;
    f = 6;
    c = 7;
    piezas = 4;
    p.tablero = new char*[f];
    for(int i = 0; i < f; i ++){
        p.tablero[i] =  new char[c];
    }
    for(int j = 0;j < f;j++){
        for(int k = 0;k<j;k++){
            p.tablero[j][k];
        }
    }
    imprimirtablero(p,f,c);
       // juegoganado = jugar(p, juegoganado, f, c, piezas); 
    return 0;
}

void  imprimirtablero(juego p, int f, int c){
    cout<<endl;
    for(int i = 0; i < f;i++){
        for(int j = 0; j < c; j++){
            cout<<"|"<<p.tablero[i][j];
            cout<<"|";
            cout<<endl;
            for(int k = 0; k < c; k++){
                cout<<"--";
                cout<<endl;
            }
        }
    }
    
}

bool jugar();



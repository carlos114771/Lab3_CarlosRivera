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
bool jugar(juego p , bool juegoganado , int f, int c, int piezas);
bool revisar(int a, int b, juego p, int f, int c, int piezas);
int soltar(int b, char jugador, juego p, int c);


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

bool jugar(juego p, bool juegoganado, int f, int c, int piezas){
    int columna, agarrar = 0; colocar=0;
    char jugador = 'y';
    while(!juegoterminado){
        if(agarrar != -1){
            if(jugador == 'y'){
                cout<<"Jugador 1, Seleccione una columna: "<<endl;
                jugador = 'r';
            }else{
                cout<<"Jugador 2, Seleccione una columna: "<<endl;
                jugador= 'y';
            }
        }
        while(true){
            if(colocar == r*c)break;
            cin>>columna;
            columna--;
            if(columna <= f && columna >= 0)break;
            else cout<<"El valor tiene que ser entre 1 y 7"<<endl;
            if(cin.fail()){
                cin.clear;
                char d;
                cin>>d;
             }
        }
        if(colocar == r*c) break;
        agarrar = 
    }
}
    



#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct juego{
    char **tablero;
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
        for(int k = 0;k<c;k++){
            p.tablero[j][k]= ' ';
        }
    }
    imprimirtablero(p,f,c);
       juegoganado = jugar(p, juegoganado, f, c, piezas); 
    return 0;
}

void  imprimirtablero(juego p, int f, int c){
  //  cout<<endl;
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
    int columna, agarrar = 0, colocar=0;
    char jugador = 'y';
    while(!juegoganado){
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
            if(colocar == f*c)break;
            cin>>columna;
            columna--;
            if(columna <= f && columna >= 0)break;
            else cout<<"El valor tiene que ser entre 1 y 7"<<endl;
            if(cin.fail()){
                cin.clear();
                char d;
                cin>>d;
             }
        }
        if(colocar == f*c) break;
        agarrar = soltar(columna, jugador, p, c);
        if(agarrar == -1){ 
            cout<<"La columna esta llena!\nIngrese otro numero entre 1 y 7: ";
        }else{
            juegoganado = revisar(agarrar,columna, p, f, c, piezas);
            colocar++;  
            imprimirtablero(p,f,c);
        }    
    }
    if(colocar == f*c){
        cout<<"No hay ganado! El juego quedo en empate\n";
        return true;
    }if(jugador == 'y'){
        cout<<"El Jugador 2 es el gandor!\n";
    }else{
        cout<<"El Jugador 1 es el ganador!\n";
    }
    return true;
}

int soltar(int b, char jugador, juego p, int c){
    if(b >= 0 && b<= c){
        if(p.tablero[0][b] == ' '){
            int i;
            for(i = 0; p.tablero[i][b] == ' '; i++){
                if(i==5){
                    p.tablero[i][b] = jugador;
                    return i;
                }
           }
           i--;
           p.tablero[i][b] = jugador;
           return i;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}


bool revisar(int a, int b, juego p, int f, int c, int piezas){
    int vertical = 1, horizontal = 1, diagonal_1=1, diagonal_2=1,i,j;
    cout<<i<<" "<<b<<" "<<a<<endl;
    char jugador = p.tablero[a][b];
    cout<<jugador<<endl;
    for(i = a + 1;p.tablero[i][b] ==jugador &&i<f;i++, vertical++);
    for(i = a - 1;p.tablero[i][b] ==jugador &&i>=0;i--, vertical++);
    if(vertical>=piezas){
        return true;
    }
    for(j=b-1;p.tablero[a][j]==jugador&&j>=0;j--,horizontal++);
    for(j=b+1;p.tablero[a][j]==jugador&&j<c;j++,horizontal++);
    if(horizontal>=piezas){
        return true;
    }
    for(i=a-1,j=b-1;p.tablero[i][j]==jugador&&i>=0&&j>=0;diagonal_1++,i--,j--);
    for(i=a+1,j=b+1;p.tablero[i][j]==jugador&&i<=f&&j<=c;diagonal_1++,i++,j++);
    if(diagonal_1>=piezas){
        return true;
    }
    for(i=a-1,j=b+1;p.tablero[i][j]==jugador&&i>=0&&j<=c;diagonal_2++,i--,j++);
    for(i=a+1,j=b-1;p.tablero[i][j]==jugador&&i<=f&&j>=0;diagonal_2++,i++,j--);
    if(diagonal_2>=piezas){
        return true;
    }
    return false;
}

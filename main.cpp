#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    return 0;
}

void imprimirmatriz(int size,char** matriz){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size; j++){
            cout<<" "<<matriz[i][j];
        }
        cout<<endl;
    }
}

char** crearmatriz(int n){
    char** retval = new char*[n];

    for(int i=0;i<n;i++){
        retval[i]= new char[n];
    }
    return retval;
}

void liberarmatriz(int n,char** matriz){
    for(int i=0;i<n;i++){
        delete[] matriz[i];
    }
    
}

#include "ChessBoard.h"
#include "ChessTile.h"

ChessBoard::ChessBoard(int n, int m):n(n), m(m){
    set_row_homogeneous(true);
    set_column_homogeneous(true);
    arr=new ChessTile**[n];
    for(int i=0;i<n;i++) arr[i]=new ChessTile*[m];
}

ChessBoard::~ChessBoard(){
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++) delete arr[i][j];            
        delete[] arr[i];
    }
    delete[] arr;
}

ChessTile**& ChessBoard::operator[](int n){
    return arr[n];
}

void ChessBoard::fillBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=new ChessTile((i+j)%2==0?ChessTile::WHITE:ChessTile::BLACK);
            attach(*arr[i][j],j,i,1,1);
        }
    }
}

int ChessBoard::getN(){
    return n;
}

int ChessBoard::getM(){
    return m;
}
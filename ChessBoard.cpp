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

void ChessBoard::fillWithTiles(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=new ChessTile((i+j)%2==0?ChessTile::WHITE:ChessTile::BLACK);
            attach(*arr[i][j],j,i,1,1);
        }
    }
}

void ChessBoard::fillBoard(){
    int kingColumn=(int) (m-1)/2;

    //Rooks
    arr[0][0]->setFigure(new Rook(ChessFigure::BLACK));
    arr[0][m-1]->setFigure(new Rook(ChessFigure::BLACK));
    arr[n-1][0]->setFigure(new Rook(ChessFigure::WHITE));
    arr[n-1][m-1]->setFigure(new Rook(ChessFigure::WHITE));

    //Bishops
    arr[0][kingColumn-1]->setFigure(new Bishop(ChessFigure::BLACK));
    arr[0][kingColumn+2]->setFigure(new Bishop(ChessFigure::BLACK));
    arr[n-1][kingColumn-1]->setFigure(new Bishop(ChessFigure::WHITE));
    arr[n-1][kingColumn+2]->setFigure(new Bishop(ChessFigure::WHITE));

    //Kings
    arr[0][kingColumn]->setFigure(new King(ChessFigure::BLACK));
    arr[n-1][kingColumn]->setFigure(new King(ChessFigure::WHITE));

    //Queens
    arr[0][kingColumn+1]->setFigure(new Queen(ChessFigure::BLACK));
    arr[n-1][kingColumn+1]->setFigure(new Queen(ChessFigure::WHITE));
    
    //Knights
    arr[0][kingColumn-2]->setFigure(new Knight(ChessFigure::BLACK));
    arr[0][kingColumn+3]->setFigure(new Knight(ChessFigure::BLACK));
    arr[n-1][kingColumn-2]->setFigure(new Knight(ChessFigure::WHITE));
    arr[n-1][kingColumn+3]->setFigure(new Knight(ChessFigure::WHITE));

    //Pawns
    for(int i=0;i<m;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=0;i<m;i++) arr[n-2][i]->setFigure(new Pawn(ChessFigure::WHITE));
    for(int i=1;i<kingColumn-3;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=1;i<kingColumn-3;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::WHITE));
    for(int i=kingColumn+4;i<m-2;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=kingColumn+4;i<m-2;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::WHITE));
}

int ChessBoard::getN(){
    return n;
}

int ChessBoard::getM(){
    return m;
}
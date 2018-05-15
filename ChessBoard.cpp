#include "ChessBoard.h"
#include "ChessTile.h"
#include "ChessFigures.h"
#include <set>
#include <string>
#include <gtkmm.h>

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
            arr[i][j]=new ChessTile((i+j)%2==0?ChessTile::WHITE:ChessTile::BLACK, i, j);
            attach(*arr[i][j],j,i,1,1);
            arr[i][j]->signal_clicked().connect(sigc::bind<ChessTile*>(sigc::mem_fun(this, &ChessBoard::buttonClicked), arr[i][j]));
        }
    }
}

void ChessBoard::fillBoard(){
    int queenColumn=(int) (m-1)/2;

    //Rooks
    arr[0][0]->setFigure(new Rook(ChessFigure::BLACK));
    arr[0][m-1]->setFigure(new Rook(ChessFigure::BLACK));
    arr[n-1][0]->setFigure(new Rook(ChessFigure::WHITE));
    arr[n-1][m-1]->setFigure(new Rook(ChessFigure::WHITE));

    //Bishops
    arr[0][queenColumn-1]->setFigure(new Bishop(ChessFigure::BLACK));
    arr[0][queenColumn+2]->setFigure(new Bishop(ChessFigure::BLACK));
    arr[n-1][queenColumn-1]->setFigure(new Bishop(ChessFigure::WHITE));
    arr[n-1][queenColumn+2]->setFigure(new Bishop(ChessFigure::WHITE));

    //Kings
    arr[0][queenColumn+1]->setFigure(new King(ChessFigure::BLACK));
    arr[n-1][queenColumn+1]->setFigure(new King(ChessFigure::WHITE));

    //Queens
    arr[0][queenColumn]->setFigure(new Queen(ChessFigure::BLACK));
    arr[n-1][queenColumn]->setFigure(new Queen(ChessFigure::WHITE));
    
    //Knights
    arr[0][queenColumn-2]->setFigure(new Knight(ChessFigure::BLACK));
    arr[0][queenColumn+3]->setFigure(new Knight(ChessFigure::BLACK));
    arr[n-1][queenColumn-2]->setFigure(new Knight(ChessFigure::WHITE));
    arr[n-1][queenColumn+3]->setFigure(new Knight(ChessFigure::WHITE));

    //Pawns
    for(int i=0;i<m;i++) arr[1][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=0;i<m;i++) arr[n-2][i]->setFigure(new Pawn(ChessFigure::WHITE));
    for(int i=1;i<queenColumn-2;i++) arr[0][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=1;i<queenColumn-2;i++) arr[n-1][i]->setFigure(new Pawn(ChessFigure::WHITE));
    for(int i=queenColumn+4;i<m-1;i++) arr[0][i]->setFigure(new Pawn(ChessFigure::BLACK));
    for(int i=queenColumn+4;i<m-1;i++) arr[n-1][i]->setFigure(new Pawn(ChessFigure::WHITE));
}

int ChessBoard::getN(){
    return n;
}

int ChessBoard::getM(){
    return m;
}

void ChessBoard::buttonClicked(ChessTile* tile){
    if(stepOptions.empty()){
        if(tile->getFigure()==nullptr) return;
        if(tile->getFigure()->getTeam()==prevTeam) return;
        lastPressed=tile;
        std::set<ChessTile*> steps=tile->getFigure()->getStepOptions(*this);
        stepOptions.insert(steps.begin(),steps.end());
        for(std::set<ChessTile*>::iterator it=steps.begin();it!=steps.end();it++){
            Gdk::RGBA color;
            color.set("yellow");
            (*it)->override_background_color(color);
        }
    }
    else{
        if(stepOptions.find(tile)!=stepOptions.end()){
            if(dynamic_cast<King*>(tile->getFigure())!=nullptr){
                std::string winner=tile->getFigure()->getTeam()==ChessFigure::BLACK?"white":"black";
                Gtk::MessageDialog dialog((Gtk::Window&)(*this->get_toplevel()), "Winner!");
                std::string text="The ";
                dialog.set_secondary_text(text + winner + " player won the game.");
                dialog.run();
                Gtk::Main::quit();
            }
            tile->setFigure(lastPressed->getFigure());
            lastPressed->removeFigure();
            prevTeam=tile->getFigure()->getTeam();
        }
        for(std::set<ChessTile*>::iterator it=stepOptions.begin();it!=stepOptions.end();it++){
            (*it)->resetColour();
        }
        stepOptions.clear();
    }
}
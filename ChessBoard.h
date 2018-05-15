#ifndef ChessBoard_H
#define ChessBoard_H

#include <gtkmm.h>
#include <set>
#include "ChessFigures.h"

class ChessTile;

class ChessBoard: public Gtk::Grid{
private:
    ChessTile*** arr;
    std::set<ChessTile*> stepOptions;
    ChessTile* lastPressed;
    ChessFigure::Team prevTeam=ChessFigure::BLACK;
    int n,m;
public:
    ChessBoard(int=8,int=8);
    ChessBoard(ChessBoard&)=delete;
    ChessTile**& operator[](int);
    void fillWithTiles();
    void fillBoard();
    void buttonClicked(ChessTile*);
    int getN();
    int getM();
    ~ChessBoard();
};

#endif
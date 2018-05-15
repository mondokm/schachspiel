#ifndef ChessBoard_H
#define ChessBoard_H

#include <gtkmm.h>

class ChessTile;

class ChessBoard: public Gtk::Grid{
private:
    ChessTile*** arr;
    std::set<ChessTile*> stepOptions;
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
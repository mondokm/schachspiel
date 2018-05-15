#ifndef CHESSTILE_H
#define CHESSTILE_H

#include <gtkmm.h>
class ChessFigure;

class ChessTile: public Gtk::Button{
public:
    enum Colour{WHITE, BLACK};
private:
    ChessFigure* figure;
    Colour colour;
    int row, column;
public:
    ChessTile(Colour, int, int);
    ChessTile(ChessTile&)=delete; 
    ChessTile& operator=(ChessFigure*);
    void resetColour();
    Colour getColour();
    void setFigure(ChessFigure*);
    void removeFigure();
    int getRow();
    int getColumn();
    ChessFigure* getFigure(); 
    ~ChessTile();
};

#endif
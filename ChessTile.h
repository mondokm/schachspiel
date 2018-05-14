#ifndef CHESSTILE_H
#define CHESSTILE_H

#include <gtkmm.h>
#include "ChessFigures.h"

class ChessTile: public Gtk::Button{
public:
    enum Colour{WHITE, BLACK};
private:
    ChessFigure* figure;
    Colour colour;
public:
    ChessTile(Colour);
    ChessTile(ChessTile&)=delete; 
    ChessTile& operator=(ChessFigure*);
    Colour getColour();
    void setFigure(ChessFigure*);
    void removeFigure();
    ChessFigure* getFigure(); 
    ~ChessTile();
};

#endif
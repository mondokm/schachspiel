#include "ChessTile.h"
#include "ChessFigures.h"
#include <gtkmm.h>

ChessTile::ChessTile(ChessTile::Colour colour, int row, int column):colour(colour), row(row), column(column), figure(nullptr){
    Gdk::RGBA color;
    color.set(colour==WHITE?"khaki":"saddlebrown");
    override_background_color(color);
}

void ChessTile::setFigure(ChessFigure* fig){
    figure=fig;
    Gtk::Image *im=Gtk::manage(new Gtk::Image());
    im->set(fig->getPath());
    set_image(*im);
}

void ChessTile::removeFigure(){
    figure=nullptr;
    Gtk::Image *im=Gtk::manage(new Gtk::Image());
    set_image(*im);
}

int ChessTile::getRow(){
    return row;
}

int ChessTile::getColumn(){
    return column;
}

ChessFigure* ChessTile::getFigure(){
    return figure;
}

ChessTile& ChessTile::operator=(ChessFigure* fig){
    figure=fig;
    return *this;
}

ChessTile::Colour ChessTile::getColour(){
    return colour;
}

ChessTile::~ChessTile(){
}
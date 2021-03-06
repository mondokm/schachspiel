#include "ChessTile.h"
#include "ChessFigures.h"
#include <gtkmm.h>

ChessTile::ChessTile(ChessTile::Colour colour) : colour(colour), figure(nullptr)
{
    resetColour();
}

void ChessTile::resetColour()
{
    Gdk::RGBA color;
    color.set(colour == WHITE ? "khaki" : "saddlebrown");
    override_background_color(color);
}

void ChessTile::setFigure(ChessFigure *fig)
{
    figure = fig;
    if (fig == nullptr)
        removeFigure();
    else
    {
        Gtk::Image *im = Gtk::manage(new Gtk::Image());
        im->set(fig->getPath());
        set_image(*im);
    }
}

void ChessTile::removeFigure()
{
    figure = nullptr;
    Gtk::Image *im = Gtk::manage(new Gtk::Image());
    set_image(*im);
}

ChessFigure *ChessTile::getFigure()
{
    return figure;
}

ChessTile &ChessTile::operator=(ChessFigure *fig)
{
    setFigure(fig);
    return *this;
}

ChessTile::Colour ChessTile::getColour()
{
    return colour;
}

ChessTile::~ChessTile()
{
}
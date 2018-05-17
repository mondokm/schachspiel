#ifndef CHESSTILE_H
#define CHESSTILE_H

#include <gtkmm.h>
class ChessFigure;

/** \brief A class that represents a tile of the board
*/
class ChessTile : public Gtk::Button
{
public:
  /** \brief An enum that represents the background colour of the tile
  */
  enum Colour
  {
    WHITE,
    BLACK
  };

private:
  /** \brief A pointer to the figure that's placed
  */
  ChessFigure *figure;
  /** \brief The background colour of the tile
  */
  Colour colour;

public:
  /** \brief A constructor expecting a Colour
  */
  ChessTile(Colour);
  ChessTile(ChessTile &) = delete;
  /** \brief The assign operator can be used to set the figure
  */
  ChessTile &operator=(ChessFigure *);
  /** \brief Sets the colour of the tile to the colour found in the colour variable
  */
  void resetColour();
  /** \brief Returns the background colour of the board (BLACK/WHITE)
  */
  Colour getColour();
  /** \brief Sets the figure
  */
  void setFigure(ChessFigure *);
  /** \brief Removes the figure
  */
  void removeFigure();
  /** \brief Returns the figure
  */
  ChessFigure *getFigure();
  ~ChessTile();
};

#endif
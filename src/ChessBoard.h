#ifndef ChessBoard_H
#define ChessBoard_H

#include <gtkmm.h>
#include <set>
#include "ChessFigures.h"

class ChessTile;

/** \brief A class representing a chessboard
*/

class ChessBoard : public Gtk::Grid
{
private:
  /** \brief A 2 dimensional array (n rows, m columns) of chesstile pointers that represent the board 
  */
  ChessTile ***arr;
  /** \brief After clicking a figure its available stepping options get loaded into this set
  */
  std::set<ChessTile *> stepOptions;
  /** \brief A pointer to the tile that contains the selected figure
  */
  ChessTile *lastPressed;
  /** \brief The team of the player that made the last step
  */
  ChessFigure::Team prevTeam = ChessFigure::BLACK;
  /** \brief The number of rows the board has
  */
  int n;
  /** \brief The number of columns the board has
  */
  int m;
  /** \brief The signal handler of the tiles
  */
  void buttonClicked(ChessTile *);

public:
  /** \brief A contructor expecting the number of rows and columns
   * @param rows The number of rows
   * @param columns The number of columns
  */
  ChessBoard(int rows = 8, int columns = 8);
  ChessBoard(ChessBoard &) = delete;
  /** \brief The ChessTiles can be accessed using nameOfChessBoard[row][column]
  */
  ChessTile **&operator[](int);
  /** \brief Instantiates the tiles of the board
  */
  void fillWithTiles();
  /** \brief Fills the board with figures
  */
  void fillBoard();
  /** \brief Returns the number of rows the board has
  */
  int getN();
  /** \brief Returns the number of columns the board has
  */
  int getM();
  /** \brief Destructor
  */
  ~ChessBoard();
};

#endif
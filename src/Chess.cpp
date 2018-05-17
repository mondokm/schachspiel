/** \file
*/

#include <gtkmm.h>
#include <iostream>
#include "ChessBoard.h"
#include "ChessFigures.h"
#include "ChessTile.h"
#include <set>

/// The main function of the program
int main(int argc, char *argv[])
{
  /// Creating a Gtk Application instance
  auto app = Gtk::Application::create(argc, argv, "hu.mondokm.schachspiel");

  /// Creating a window instance
  Gtk::Window window;

  /// Setting the size of the window
  window.set_default_size(200, 200);

  /// Creating a ChessBoard instance
  ChessBoard board(8, 8);

  /// Filling the board with tiles
  board.fillWithTiles();

  /// Filling the board with figures
  board.fillBoard();

  /// Adding the board to the window
  window.add(board);

  /// Asking the window to show all its children
  window.show_all_children();

  /// Running the application
  return app->run(window);
}
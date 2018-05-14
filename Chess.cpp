#include <gtkmm.h>
#include <iostream>
#include "ChessBoard.h"
#include "ChessFigures.h"
#include "ChessTile.h"

int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv,
      "org.gtkmm.examples.base");

  Gtk::Window window;
  window.set_default_size(200, 200);


  ChessBoard board;
  board.fillBoard();
  window.add(board);

  for(int i=0;i<4;i++){
    for(int j=0;j<8;j++){
      board[i][j]->setFigure(new Queen(ChessFigure::WHITE));
    }
  }

  board[0][0]->removeFigure();

  window.show_all_children();


  return app->run(window);
}
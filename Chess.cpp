#include <gtkmm.h>
#include <iostream>
#include "ChessBoard.h"
#include "ChessFigures.h"
#include "ChessTile.h"
#include <set>

int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv,
      "hu.mondokm.schachspiel");

  Gtk::Window window;
  window.set_default_size(200, 200);


  ChessBoard board(8,8);
  board.fillWithTiles();
  window.add(board);

  board.fillBoard();
  // board[3][4]->setFigure(new Knight(ChessFigure::WHITE));
  // std::set<ChessTile*> steps=board[3][4]->getFigure()->getStepOptions(board);
  // for(std::set<ChessTile*>::iterator it=steps.begin();it!=steps.end();it++){
  //   Gdk::RGBA color;
  //   color.set("yellow");
  //   (*it)->override_background_color(color);
    
  // }
  // for(int i=0;i<4;i++){
  //   for(int j=0;j<8;j++){
  //     board[i][j]->setFigure(new Rook(ChessFigure::WHITE));
  //   }
  // }
  // board[0][0]->removeFigure();

  window.show_all_children();


  return app->run(window);
}
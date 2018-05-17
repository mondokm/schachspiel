#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H

#include <string>
#include <set>
#include "ChessTile.h"

class ChessBoard;

///An abstract class that represents the chessfigures
class ChessFigure
{
public:
  /// An enum that can represent the team of the figure (white/black)
  enum Team
  {
    WHITE,
    BLACK
  };

protected:
  /// The figure's team
  Team team;

public:
  /**
  * \brief A contructor that expects the team of the figure
  * @param team the team of the figure
   */
  ChessFigure(Team team);
  /** \brief A getter function for the team variable
   */
  Team getTeam();
  /** \brief A getter function for the value of the figure (an AI can use it for weighting the figures)
   */
  virtual int getValue() = 0;
  /** \brief The path to the image file of the figure
   */
  virtual std::string getPath() = 0;
  /** \brief A function that returns the available stepping options for the figure
   * @param board The ChessBoard that the figure is placed on
   */
  virtual std::set<ChessTile *> getStepOptions(ChessBoard &board) = 0;
};

/** \brief An abstract class that defines methods for stepping horizontally and vertically
 */
class StraightFigure : virtual public ChessFigure
{
public:
  virtual int getValue() = 0;
  /** \brief A function that returns a set containing the horizontal stepping options for the figure
   * @param board The board that the figure is placed on
   * @param distance How far away the figure is allowed to step
   * @param row The row the figure is placed in (starts from 0)
   * @param column The column the figure is placed in (starts from 0)
   */
  std::set<ChessTile *> getHorizontalSteppingOptions(ChessBoard &board, int distance, int row, int column);
  /** \brief A function that returns a set containing the vertical stepping options for the figure
   * @param board The board that the figure is placed on
   * @param distance How far away the figure is allowed to step
   * @param row The row the figure is placed in (starts from 0)
   * @param column The column the figure is placed in (starts from 0)
   */
  std::set<ChessTile *> getVerticalSteppingOptions(ChessBoard &board, int distance, int row, int column);
};

/** \brief An abstract class that defines methods for stepping diagonally
 */
class DiagonalFigure : virtual public ChessFigure
{
public:
  virtual int getValue() = 0;
  /** \brief A function that returns a set containing the diagonal stepping options for the figure
   * @param board The board that the figure is placed on
   * @param distance How far away the figure is allowed to step
   * @param row The row the figure is placed in (starts from 0)
   * @param column The column the figure is placed in (starts from 0)
   */
  std::set<ChessTile *> getDiagonalSteppingOptions(ChessBoard &, int, int, int);
};

/** \brief A class that represents king figures
 */
class King : virtual public StraightFigure, virtual public DiagonalFigure
{
private:
  /** \brief The value of the figure
  */
  static const int KING_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_KING_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_KING_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  King(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

/** \brief A class that represents queen figures
  */
class Queen : virtual public StraightFigure, virtual public DiagonalFigure
{
private:
  /** \brief The value of the figure
  */
  static const int QUEEN_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_QUEEN_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_QUEEN_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  Queen(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

/** \brief A class that represents pawn figures
*/
class Pawn : virtual public ChessFigure
{
private:
  /** \brief The value of the figure
  */
  static const int PAWN_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_PAWN_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_PAWN_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  Pawn(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

/** \brief A class that represents bishop figures
*/
class Bishop : virtual public DiagonalFigure
{
private:
  /** \brief The value of the figure
  */
  static const int BISHOP_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_BISHOP_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_BISHOP_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  Bishop(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

/** \brief A class that represents bishop figures
*/
class Rook : virtual public StraightFigure
{
private:
  /** \brief The value of the figure
  */
  static const int ROOK_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_ROOK_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_ROOK_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  Rook(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

/** \brief A class that represents knight figures
*/
class Knight : virtual public ChessFigure
{
private:
  /** \brief The value of the figure
  */
  static const int KNIGHT_VALUE;
  /** \brief The path to the black image file
  */
  static const std::string BLACK_KNIGHT_PATH;
  /** \brief The path to the white image file
  */
  static const std::string WHITE_KNIGHT_PATH;

public:
  /** \brief A constructor expecting a Team
  */
  Knight(Team team);
  int getValue();
  std::string getPath();
  std::set<ChessTile *> getStepOptions(ChessBoard &);
};

#endif
#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H

#include <string>
#include <set>

class ChessBoard;

class ChessFigure{
public:
    enum Team{WHITE,BLACK};
protected:
    Team team;
public:
    ChessFigure(Team team);
    Team getTeam();
    virtual int getValue()=0;
    virtual std::string getPath()=0;
    virtual std::set<ChessFigure*> getStepOptions(ChessBoard&)=0;    
};

class StraightFigure: virtual public ChessFigure{
public:
    std::set<ChessFigure*> getHorizontalSteppingOptions(ChessBoard&, int);
    std::set<ChessFigure*> getVerticalSteppingOptions(ChessBoard&, int);
};

class DiagonalFigure: virtual public ChessFigure{
public:
    std::set<ChessFigure*> getDiagonalSteppingOptions(ChessBoard&, int);
};
 
class King: virtual public StraightFigure, virtual public DiagonalFigure{
private:
    static const int KING_VALUE;
    static const std::string BLACK_KING_PATH;
    static const std::string WHITE_KING_PATH;
public:
    King(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

class Queen: virtual public StraightFigure, virtual public DiagonalFigure{
private:
    static const int QUEEN_VALUE;
    static const std::string BLACK_QUEEN_PATH;
    static const std::string WHITE_QUEEN_PATH;
public:
    Queen(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

class Pawn: virtual public ChessFigure{
private:
    static const int PAWN_VALUE;
    static const std::string BLACK_PAWN_PATH;
    static const std::string WHITE_PAWN_PATH;
public:
    Pawn(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

class Bishop: virtual public DiagonalFigure{
private:
    static const int BISHOP_VALUE;
    static const std::string BLACK_BISHOP_PATH;
    static const std::string WHITE_BISHOP_PATH;
public:
    Bishop(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

class Rook: virtual public StraightFigure{
private:
    static const int ROOK_VALUE;
    static const std::string BLACK_ROOK_PATH;
    static const std::string WHITE_ROOK_PATH;
public:
    Rook(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

class Knight: virtual public ChessFigure{
private:
    static const int KNIGHT_VALUE;
    static const std::string BLACK_KNIGHT_PATH;
    static const std::string WHITE_KNIGHT_PATH;
public:
    Knight(Team team);
    int getValue();
    std::string getPath();
    std::set<ChessFigure*> getStepOptions(ChessBoard&);
};

#endif
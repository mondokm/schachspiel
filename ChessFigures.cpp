#include "ChessFigures.h"

ChessFigure::ChessFigure(Team team):team(team){}

ChessFigure::Team ChessFigure::getTeam(){return team;}

King::King(Team team):ChessFigure(team){}
Queen::Queen(Team team):ChessFigure(team){}
Pawn::Pawn(Team team):ChessFigure(team){}
Bishop::Bishop(Team team):ChessFigure(team){}
Rook::Rook(Team team):ChessFigure(team){}
Knight::Knight(Team team):ChessFigure(team){}

int King::getValue(){
    return KING_VALUE;
}

std::string King::getPath(){
    return team==WHITE?WHITE_KING_PATH:BLACK_KING_PATH;
}

int Queen::getValue(){
    return QUEEN_VALUE;
}

std::string Queen::getPath(){
    return team==WHITE?WHITE_QUEEN_PATH:BLACK_QUEEN_PATH;
}

int Pawn::getValue(){
    return PAWN_VALUE;
}

std::string Pawn::getPath(){
    return team==WHITE?WHITE_PAWN_PATH:BLACK_PAWN_PATH;
}

int Bishop::getValue(){
    return BISHOP_VALUE;
}

std::string Bishop::getPath(){
    return team==WHITE?WHITE_BISHOP_PATH:BLACK_BISHOP_PATH;
}

int Rook::getValue(){
    return ROOK_VALUE;
}

std::string Rook::getPath(){
    return team==WHITE?WHITE_ROOK_PATH:BLACK_ROOK_PATH;
}

int Knight::getValue(){
    return KNIGHT_VALUE;
}

std::string Knight::getPath(){
    return team==WHITE?WHITE_KNIGHT_PATH:BLACK_KNIGHT_PATH;
}

std::set<ChessFigure*> King::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

std::set<ChessFigure*> Queen::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

std::set<ChessFigure*> Pawn::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

std::set<ChessFigure*> Bishop::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

std::set<ChessFigure*> Rook::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

std::set<ChessFigure*> Knight::getStepOptions(ChessBoard& ref){
    std::set<ChessFigure*> steps;
    return steps;
}

const int King::KING_VALUE=2;
const int Queen::QUEEN_VALUE=1;
const int Pawn::PAWN_VALUE=0;
const int Bishop::BISHOP_VALUE=0;
const int Rook::ROOK_VALUE=0;
const int Knight::KNIGHT_VALUE=0;

const std::string King::BLACK_KING_PATH="res/BlackKing.png";
const std::string Queen::BLACK_QUEEN_PATH="res/BlackQueen.png";
const std::string Pawn::BLACK_PAWN_PATH="res/BlackPawn.png";
const std::string Bishop::BLACK_BISHOP_PATH="res/BlackBishop.png";
const std::string Rook::BLACK_ROOK_PATH="res/BlackRook.png";
const std::string Knight::BLACK_KNIGHT_PATH="res/BlackKnight.png";

const std::string King::WHITE_KING_PATH="res/WhiteKing.png";
const std::string Queen::WHITE_QUEEN_PATH="res/WhiteQueen.png";
const std::string Pawn::WHITE_PAWN_PATH="res/WhitePawn.png";
const std::string Bishop::WHITE_BISHOP_PATH="res/WhiteBishop.png";
const std::string Rook::WHITE_ROOK_PATH="res/WhiteRook.png";
const std::string Knight::WHITE_KNIGHT_PATH="res/WhiteKnight.png";


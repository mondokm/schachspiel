#include "ChessFigures.h"
#include "ChessBoard.h"

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

std::set<ChessTile*> StraightFigure::getHorizontalSteppingOptions(ChessBoard& board, int dist, int row, int column){
    std::set<ChessTile*> steps;
    
    //Left
    int border=0>(column-dist-1)?column-dist:0;
    for(int j=column-1;j>border;j--){
        if(board[row][j]->getFigure()==nullptr){
            steps.insert(board[row][j]);
        }
        else{
            steps.insert(board[row][j]);
            break;
        }
    }

    //Right
    border=(board.getM()-1)<(column+dist+1)?board.getM()-1:column+dist+1;
    for(int j=column+1;j<border;j++){
        if(board[row][j]->getFigure()==nullptr){
            steps.insert(board[row][j]);
        }
        else{
            steps.insert(board[row][j]);
            break;
        }
    }

    return steps;
}

std::set<ChessTile*> StraightFigure::getVerticalSteppingOptions(ChessBoard& board, int dist, int row, int column){
    std::set<ChessTile*> steps;
    
    //Up
    int border=0>(row-dist-1)?row-dist:0;
    for(int i=row-1;i>border;i--){
        if(board[i][column]->getFigure()==nullptr){
            steps.insert(board[i][column]);
        }
        else{
            steps.insert(board[i][column]);
            break;
        }
    }

    //Down
    border=(board.getN()-1)<(row+dist+1)?board.getN()-1:column+dist+1;
    for(int i=row+1;i<border;i++){
        if(board[i][column]->getFigure()==nullptr){
            steps.insert(board[i][column]);
        }
        else{
            steps.insert(board[i][column]);
            break;
        }
    }
    return steps;
}

std::set<ChessTile*> DiagonalFigure::getDiagonalSteppingOptions(ChessBoard& board, int dist, int row, int column){
    std::set<ChessTile*> steps;
    
    //Left-Up
    int border=std::min(dist,std::min(row+1,column+1));
    for(int i=1;i<border;i++){
        if(board[row-i][column-i]->getFigure()==nullptr){
            steps.insert(board[row-i][column-i]);
        }
        else{
            steps.insert(board[row-i][column-i]);
            break;
        }
    }

    //Right-Down
    border=std::min(dist,std::min(board.getN()-row,board.getM()-column));
    for(int i=1;i<border;i++){
        if(board[row+i][column+i]->getFigure()==nullptr){
            steps.insert(board[row+i][column+i]);
        }
        else{
            steps.insert(board[row+i][column+i]);
            break;
        }
    }

    return steps;

}

std::set<ChessTile*> King::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
    int row=-1,column=-1;
    for(int i=0;i<board.getN();i++){
        for(int j=0;j<board.getM();j++){
            if(board[i][j]->getFigure()==this){
                row=i;
                column=j;
            }
        }
    }
    if(row==-1) return steps;

    std::set<ChessTile*> diagonalSteps=getDiagonalSteppingOptions(board,1, row, column);
    steps.insert(diagonalSteps.begin(),diagonalSteps.end());
    std::set<ChessTile*> horizontalSteps=getHorizontalSteppingOptions(board,1, row, column);
    steps.insert(horizontalSteps.begin(),horizontalSteps.end());
    std::set<ChessTile*> verticalSteps=getVerticalSteppingOptions(board,1, row, column);
    steps.insert(verticalSteps.begin(),verticalSteps.end());
    return steps;
}

std::set<ChessTile*> Queen::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
    return steps;
}

std::set<ChessTile*> Pawn::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
    return steps;
}

std::set<ChessTile*> Bishop::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
    return steps;
}

std::set<ChessTile*> Rook::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
    return steps;
}

std::set<ChessTile*> Knight::getStepOptions(ChessBoard& board){
    std::set<ChessTile*> steps;
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


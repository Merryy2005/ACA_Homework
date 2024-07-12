#include "Game.h"

Game::Game() : Board()
{

}

Game::Game(const Game& other) : Board(other)
{

}

bool Game::isCheckmate() const
{
    Figure::Column col = getBlackCol();
    Figure::Row row = getBlackRow();
    bool check = true;
    check &= isAttack(col ,row);
    int colInt = (int)col;
    int rowInt = (int)row;
    if (colInt - 1 >= 0) 
    {
        check &= isAttack((Figure::Column)(colInt - 1), row);
    }
    if (colInt - 1 >= 0 && rowInt - 1 >= 0) 
    {
        check &= isAttack((Figure::Column)(colInt - 1), (Figure::Row)(rowInt - 1));
    }
    if (colInt - 1 >= 0 && rowInt + 1 < 8) 
    {
        check &= isAttack((Figure::Column)(colInt - 1), (Figure::Row)(rowInt + 1));
    }
    if (rowInt - 1 >= 0) 
    {
        check &= isAttack(col, (Figure::Row)(rowInt - 1));
    }
    if (rowInt + 1 < 8) 
    {
        check &= isAttack(col, (Figure::Row)(rowInt + 1));
    }
    if (colInt + 1 < 8 && rowInt - 1 >= 0) 
    {
        check &= isAttack((Figure::Column)(colInt + 1), (Figure::Row)(rowInt - 1));
    }
    if (colInt + 1 < 8) 
    {
        check &= isAttack((Figure::Column)(colInt + 1), row);
    }
    if (colInt + 1 < 8 && rowInt + 1 < 8) 
    {
        check &= isAttack((Figure::Column)(colInt + 1), (Figure::Row)(rowInt + 1));
    }
    return check;
}

bool Game::isCheckmateOneStep(bool print) const
{
    if(isCheckmate()) return false;
    if(isAttack(getBlackCol() , getBlackRow()))
    {
        return false;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == Figure::Color::white)
            {
                while(m_figures[i][j] -> nextMove(*this))
                {
                    Game newGame(*this);
                    newGame.m_figures[i][j] = nullptr;
                    int i1 = (int)m_figures[i][j] -> m_row1;
                    int j1 = (int)m_figures[i][j] -> m_col1;
                    switch(m_figures[i][j]->m_name)
                    {
                        case Figure::Name::king:
                            newGame.m_figures[i1][j1] = new King(*((King*)(m_figures[i][j])));
                            break;
                        case Figure::Name::queen:
                            newGame.m_figures[i1][j1] = new Queen(*((Queen*)(m_figures[i][j])));
                            break;
                        case Figure::Name::bishop:
                            newGame.m_figures[i1][j1] = new Bishop(*((Bishop*)(m_figures[i][j])));
                            break;
                        case Figure::Name::rook:
                            newGame.m_figures[i1][j1] = new Rook(*((Rook*)(m_figures[i][j])));
                            break;
                        case Figure::Name::knight:
                            newGame.m_figures[i1][j1] = new Knight(*((Knight*)(m_figures[i][j])));
                            break;
                        case Figure::Name::pawn:
                            newGame.m_figures[i1][j1] = new Pawn(*((Pawn*)(m_figures[i][j])));
                            break;
                    }
                    newGame.m_figures[i1][j1] -> setCol(m_figures[i][j] -> m_col1);
                    newGame.m_figures[i1][j1] -> setRow(m_figures[i][j] -> m_row1);
                    if(newGame.isCheckmate()) 
                    {
                        if(print)newGame.printBoard();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Game::isCheckmateTwoStep() const
{
    if(isCheckmate() || isCheckmateOneStep(false)) return false;
    if(isAttack(getBlackCol() , getBlackRow()))
    {
        return false;
    }
    Game newGame(*this);
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            if(newGame.m_figures[i][j] && newGame.m_figures[i][j]->getColor() == Figure::Color::white)
            {
                while(newGame.m_figures[i][j] -> nextMove(newGame))
                {
                    Game newGame1(newGame);
                    newGame1.m_figures[i][j] = nullptr;
                    int i1 = (int)newGame.m_figures[i][j] -> m_row1;
                    int j1 = (int)newGame.m_figures[i][j] -> m_col1;
                    switch(newGame.m_figures[i][j]->m_name)
                    {
                        case Figure::Name::king:
                            newGame1.m_figures[i1][j1] = new King(*((King*)(newGame.m_figures[i][j])));
                            break;
                        case Figure::Name::queen:
                            newGame1.m_figures[i1][j1] = new Queen(*((Queen*)(newGame.m_figures[i][j])));
                            break;
                        case Figure::Name::bishop:
                            newGame1.m_figures[i1][j1] = new Bishop(*((Bishop*)(newGame.m_figures[i][j])));
                            break;
                        case Figure::Name::rook:
                            newGame1.m_figures[i1][j1] = new Rook(*((Rook*)(newGame.m_figures[i][j])));
                            break;
                        case Figure::Name::knight:
                            newGame1.m_figures[i1][j1] = new Knight(*((Knight*)(newGame.m_figures[i][j])));
                            break;
                        case Figure::Name::pawn:
                            newGame1.m_figures[i1][j1] = new Pawn(*((Pawn*)(newGame.m_figures[i][j])));
                            break;
                    }
                    newGame1.m_figures[i1][j1] -> setCol(newGame.m_figures[i][j] -> m_col1);
                    newGame1.m_figures[i1][j1] -> setRow(newGame.m_figures[i][j] -> m_row1);
                    int blackCol = (int)newGame1.getBlackCol();
                    int blackRow = (int)newGame1.getBlackRow();
                    bool check = true;
                    int cnt = 0;
                    Game forprint;
                    while(newGame1.m_figures[blackRow][blackCol] -> nextMove(newGame1) && check)
                    {
                        cnt++;
                        Game newGame2(newGame1);
                        int blackRow2 = (int)newGame2.m_figures[blackRow][blackCol] -> m_row1;
                        int blackCol2 = (int)newGame2.m_figures[blackRow][blackCol] -> m_col1;
                        newGame2.m_figures[blackRow][blackCol] = nullptr;
                        newGame2.m_figures[blackRow2][blackCol2] = new King(*((King*)(newGame1.m_figures[blackRow][blackCol])));
                        newGame2.m_figures[blackRow2][blackCol2] -> setCol((Figure::Column)blackCol2);
                        newGame2.m_figures[blackRow2][blackCol2] -> setRow((Figure::Row)blackRow2);
                        if(!newGame2.isCheckmateOneStep(false))
                        {
                            check = false;
                        }
                        else
                        {
                            forprint = newGame2;
                        }
                    }
                    if(check && cnt)
                    {
                        newGame1.printBoard();
                        forprint.printBoard();
                        forprint.isCheckmateOneStep(true);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Game::analizeGame() const
{
    if(isCheckmate())
    {
        std::cout << GREEN "Checkmate" RESET<< std::endl;
    }
    else if(isCheckmateOneStep(true))
    {
        std::cout << GREEN "Checkmate in one step" RESET<< std::endl;
    }
    else if(isCheckmateTwoStep())
    {
        std::cout << GREEN "Checkmate in two steps" RESET<< std::endl;   
    }
    else
    {
        std::cout << RED "Not Checkmate" RESET<< std::endl;
    }
}
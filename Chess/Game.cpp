#include "Game.h"

Game::Game() : Board()
{

}

Game::Game(const Game& other) : Board(other)
{

}

bool Game::isAttack(Figure::Column col , Figure::Row row) const
{
    bool check = false;
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == Figure::Color::black)
            {
                continue;
            }
            else if(m_figures[i][j])
            {
                check |= m_figures[i][j] -> isAttack(col , row , *this);
            }
        }
    }
    return check;
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
                    newGame.printBoard();
                    int blackCol = (int)newGame.getBlackCol();
                    int blackRow = (int)newGame.getBlackRow();
                    bool check = true;
                    Game forPrint;
                    while(m_figures[blackRow][blackCol] -> nextMove(newGame) && check)
                    {
                        Game newGame1(newGame);
                        int blackRow1 = (int)newGame.m_figures[blackRow][blackCol] -> m_row1;
                        int blackCol1 = (int)m_figures[blackRow][blackCol] -> m_col1;
                        newGame1.m_figures[blackRow][blackCol] = nullptr;
                        newGame1.m_figures[blackRow1][blackCol1] = new King(*((King*)(newGame.m_figures[blackRow][blackCol])));
                        newGame1.m_figures[blackRow1][blackCol1] -> setCol((Figure::Column)blackCol1);
                        newGame1.m_figures[blackRow1][blackCol1] -> setRow((Figure::Row)blackRow1);
                        if(!newGame1.isCheckmateOneStep(false))
                        {
                            check = false;
                        }
                        else
                        {
                            forPrint = newGame1;
                        }
                    }
                    if(check)
                    {
                        forPrint.isCheckmateOneStep(true);
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
    // else if(isCheckmateTwoStep())
    // {
    //     std::cout << GREEN "Checkmate in two steps" RESET<< std::endl;   
    // }
    else
    {
        std::cout << RED "Not Checkmate" RESET<< std::endl;
    }
}
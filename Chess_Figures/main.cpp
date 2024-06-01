#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

int main()
{
    Figure** figures = new Figure*[6];
    figures[0] = new King("black" , true , 'A' , 8);
    figures[1] = new Queen("white" , true , 'B' , 2);
    figures[2] = new Rook("black" , false , 'C' , 7);
    figures[3] = new Bishop("white" , true , 'H' , 2);
    figures[4] = new Knight("black" , false , 'F' , 1);
    figures[5] = new Pawn("white" , true , 'G' , 5);
    for(int i = 0 ; i < 6 ; i++)
    {
        figures[i] -> printParameters();
        std::cout << "--------------------" << std::endl;
    }
    for(int i = 0 ; i < 6 ; i++)
    {
        delete figures[i];
        figures[i] = nullptr;
    }
    delete[] figures;
    figures = nullptr;
    return 0;
}
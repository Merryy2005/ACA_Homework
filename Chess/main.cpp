#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Board.h"
#include "Game.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


int main()
{   
    Game game;
    Figure** figures = new Figure*[32];

    figures[0] = new King("black", true, 'F', 6);
    figures[1] = new Rook("white", true, 'B', 5);
    figures[2] = new Queen("white", true, 'G', 4);
    figures[3] = new Pawn("white", true, 'C', 5);
    figures[4] = new Knight("white", true, 'F', 3);
    figures[5] = new King("white", true, 'G', 8);
    figures[6] = new Bishop("white", true, 'H', 4); 

    for (int i = 7; i < 32; ++i) {
        figures[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures[i] != nullptr) {
            if (!game.registerFigure(figures[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }

    game.printBoard();
    std::cout <<(game.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures[i];
        figures[i] = nullptr;
    }
    delete[] figures;
    figures = nullptr;
    std::cout << "----------------" << std::endl;
    std::cout << std::endl;
    Game game1;
    Figure** figures1 = new Figure*[32];
    figures1[0] = new Rook("white", true, 'E', 1);
    figures1[1] = new Rook("white", true, 'D', 1);
    figures1[2] = new Queen("white", true, 'C', 1);
    figures1[3] = new Bishop("white", true, 'B', 1);
    figures1[4] = new Knight("white", true, 'A', 1);
    figures1[5] = new King("black", true, 'E', 8);
      for (int i = 6; i < 32; ++i) {
        figures1[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures1[i] != nullptr) {
            if (!game1.registerFigure(figures1[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game1.printBoard();
    std::cout << (game1.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures1[i];
        figures1[i] = nullptr;
    }
    delete[] figures1;
    figures1 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game2;
    Figure** figures2 = new Figure*[32];
    figures2[0] = new Rook("white", true, 'D', 8);
    figures2[1] = new Queen("white", true, 'A', 6);
    figures2[2] = new King("black", true, 'H', 8);
    for (int i = 3; i < 32; ++i) {
        figures2[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures2[i] != nullptr) {
            if (!game2.registerFigure(figures2[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game2.printBoard();
    std::cout <<(game2.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures2[i];
        figures2[i] = nullptr;
    }
    delete[] figures2;
    figures2 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game3;
    Figure** figures3 = new Figure*[32];
    figures3[0] = new Rook("white", true, 'D', 8);
    figures3[1] = new Queen("white", true, 'H', 6);
    figures3[2] = new King("black", true, 'H', 8);
    for (int i = 3; i < 32; ++i) {
        figures3[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures3[i] != nullptr) {
            if (!game3.registerFigure(figures3[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game3.printBoard();
    std::cout << (game3.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures3[i];
        figures3[i] = nullptr;
    }
    delete[] figures3;
    figures3 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game4;
    Figure** figures4 = new Figure*[32];
    figures4[0] = new Rook("white", true, 'D', 8);
    figures4[1] = new Knight("white", true, 'G', 6);
    figures4[2] = new King("white", true, 'H', 6);
    figures4[3] = new King("black", true, 'H', 8);
    for (int i = 4; i < 32; ++i) {
        figures4[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures4[i] != nullptr) {
            if (!game4.registerFigure(figures4[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game4.printBoard();
    std::cout << (game4.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures4[i];
        figures4[i] = nullptr;
    }
    delete[] figures4;
    figures4 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game5;
    Figure** figures5 = new Figure*[32];
    figures5[0] = new Rook("white", true, 'D', 8);
    figures5[1] = new Knight("white", true, 'G', 6);
    figures5[2] = new King("white", true, 'H', 5);
    figures5[3] = new King("black", true, 'H', 8);
    for (int i = 4; i < 32; ++i) {
        figures5[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures5[i] != nullptr) {
            if (!game5.registerFigure(figures5[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game5.printBoard();
    std::cout << (game5.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures5[i];
        figures5[i] = nullptr;
    }
    delete[] figures5;
    figures5 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game6;
    Figure** figures6 = new Figure*[32];
    figures6[0] = new King("white", true, 'C', 8);
    figures6[1] = new Queen("white", true, 'B', 8);
    figures6[2] = new King("black", true, 'A', 8);
    for (int i = 3; i < 32; ++i) {
        figures6[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures6[i] != nullptr) {
            if (!game6.registerFigure(figures6[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game6.printBoard();
    std::cout << (game6.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures6[i];
        figures6[i] = nullptr;
    }
    delete[] figures6;
    figures6 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game7;
    Figure** figures7 = new Figure*[32];
    figures7[0] = new Rook("white", true, 'D', 8);
    figures7[1] = new Queen("white", true, 'A', 7);
    figures7[2] = new King("black", true, 'H', 8);
    for (int i = 3; i < 32; ++i) {
        figures7[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures7[i] != nullptr) {
            if (!game7.registerFigure(figures7[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game7.printBoard();
    std::cout << (game7.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures7[i];
        figures7[i] = nullptr;
    }
    delete[] figures7;
    figures7 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    Game game8;
    Figure** figures8 = new Figure*[32];
    figures8[0] = new Bishop("white", true, 'H', 8);
    figures8[1] = new Queen("white", true, 'G', 4);
    figures8[2] = new King("black", true, 'F', 6);
    figures8[3] = new King("white", true, 'E', 8);
    for (int i = 4; i < 32; ++i) {
        figures8[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures8[i] != nullptr) {
            if (!game8.registerFigure(figures8[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    game8.printBoard();
    std::cout << (game8.isCheckmate() ? GREEN "Checkmate" : RED "Not Checkmate") << RESET << std::endl;
    for (int i = 0; i < 32; i++) {
        delete figures8[i];
        figures8[i] = nullptr;
    }
    delete[] figures8;
    figures8 = nullptr;
    std::cout << "---------------" << std::endl;
    std::cout << std::endl;
    return 0;
}

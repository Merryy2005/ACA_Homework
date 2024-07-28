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
    // Game game;
    // Figure** figures = new Figure*[32];
    // figures[0] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R6);
    // figures[1] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R5);
    // figures[2] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R4);
    // figures[3] = new Pawn(Figure::Color::white, true, Figure::Column::C, Figure::Row::R5);
    // figures[4] = new Knight(Figure::Color::white, true, Figure::Column::F, Figure::Row::R3);
    // figures[5] = new King(Figure::Color::white, true, Figure::Column::G, Figure::Row::R8);
    // figures[6] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R4); 
    // for (int i = 7; i < 32; ++i) {
    //     figures[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures[i] != nullptr) {
    //         if (!game.registerFigure(figures[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }

    // game.printBoard();
    // game.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures[i];
    //     figures[i] = nullptr;
    // }
    // delete[] figures;
    // figures = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;
    // Game game2;
    // Figure** figures2 = new Figure*[32];
    // figures2[0] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R8);
    // figures2[1] = new Queen(Figure::Color::white, true, Figure::Column::A, Figure::Row::R6);
    // figures2[2] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    // figures2[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures2[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures2[i] != nullptr) {
    //         if (!game2.registerFigure(figures2[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game2.printBoard();
    // game2.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures2[i];
    //     figures2[i] = nullptr;
    // }
    // delete[] figures2;
    // figures2 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game4;
    // Figure** figures4 = new Figure*[32];
    // figures4[0] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R8);
    // figures4[1] = new Knight(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures4[2] = new King(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // figures4[3] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    // for (int i = 4; i < 32; ++i) {
    //     figures4[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures4[i] != nullptr) {
    //         if (!game4.registerFigure(figures4[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game4.printBoard();
    // game4.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures4[i];
    //     figures4[i] = nullptr;
    // }
    // delete[] figures4;
    // figures4 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game5;
    // Figure** figures5 = new Figure*[32];
    // figures5[0] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R8);
    // figures5[1] = new Knight(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures5[2] = new King(Figure::Color::white, true, Figure::Column::H, Figure::Row::R5);
    // figures5[3] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    // for (int i = 4; i < 32; ++i) {
    //     figures5[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures5[i] != nullptr) {
    //         if (!game5.registerFigure(figures5[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game5.printBoard();
    // game5.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures5[i];
    //     figures5[i] = nullptr;
    // }
    // delete[] figures5;
    // figures5 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game6;
    // Figure** figures6 = new Figure*[32];
    // figures6[0] = new King(Figure::Color::white, true, Figure::Column::C, Figure::Row::R8);
    // figures6[1] = new Queen(Figure::Color::white, true, Figure::Column::B, Figure::Row::R8);
    // figures6[2] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // for (int i = 3; i < 32; ++i) {
    //     figures6[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures6[i] != nullptr) {
    //         if (!game6.registerFigure(figures6[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game6.printBoard();
    // game6.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures6[i];
    //     figures6[i] = nullptr;
    // }
    // delete[] figures6;
    // figures6 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game7;
    // Figure** figures7 = new Figure*[32];
    // figures7[0] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R8);
    // figures7[1] = new Queen(Figure::Color::white, true, Figure::Column::A, Figure::Row::R7);
    // figures7[2] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    // figures7[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures7[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures7[i] != nullptr) {
    //         if (!game7.registerFigure(figures7[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game7.printBoard();
    // game7.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures7[i];
    //     figures7[i] = nullptr;
    // }
    // delete[] figures7;
    // figures7 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game8;
    // Figure** figures8 = new Figure*[32];
    // figures8[0] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R8);
    // figures8[1] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R4);
    // figures8[2] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R6);
    // figures8[3] = new King(Figure::Color::white, true, Figure::Column::E, Figure::Row::R8);
    // for (int i = 4; i < 32; ++i) {
    //     figures8[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures8[i] != nullptr) {
    //         if (!game8.registerFigure(figures8[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game8.printBoard();
    // game8.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures8[i];
    //     figures8[i] = nullptr;
    // }
    // delete[] figures8;
    // figures8 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game9;
    // Figure** figures9 = new Figure*[32];
    // figures9[0] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R8);
    // figures9[1] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R7);
    // figures9[2] = new Rook(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures9[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures9[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures9[i] != nullptr) {
    //         if (!game9.registerFigure(figures9[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game9.printBoard();
    // game9.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures9[i];
    //     figures9[i] = nullptr;
    // }
    // delete[] figures9;
    // figures9 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game10;
    // Figure** figures10 = new Figure*[32];
    // figures10[0] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R8);
    // figures10[1] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R7);
    // figures10[2] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures10[3] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R5);
    // figures10[4] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 5; i < 32; ++i) {
    //     figures10[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures10[i] != nullptr) {
    //         if (!game10.registerFigure(figures10[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game10.printBoard();
    // game10.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures10[i];
    //     figures10[i] = nullptr;
    // }
    // delete[] figures10;
    // figures10 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game11;
    // Figure** figures11 = new Figure*[32];
    // figures11[0] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R8);
    // figures11[1] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R7);
    // figures11[2] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures11[3] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R5);
    // figures11[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // figures11[5] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 6; i < 32; ++i) {
    //     figures11[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures11[i] != nullptr) {
    //         if (!game11.registerFigure(figures11[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game11.printBoard();
    // game11.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures11[i];
    //     figures11[i] = nullptr;
    // }
    // delete[] figures11;
    // figures11 = nullptr;
    // std::cout << "---------------" << std::endl;
    //std::cout << std::endl;

    // Game one_game;
    // Figure** figures = new Figure*[32];
    // figures[0] = new King(Figure::Color::black, true, Figure::Column::F, Figure::Row::R8);
    // figures[1] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R5);
    // figures[2] = new Queen(Figure::Color::white, true, Figure::Column::C, Figure::Row::R7);
    // figures[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // figures[5] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 6; i < 32; ++i) {
    //     figures[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures[i] != nullptr) {
    //         if (!one_game.registerFigure(figures[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game.printBoard();
    // one_game.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures[i];
    //     figures[i] = nullptr;
    // }
    // delete[] figures;
    // figures = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R1);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::C, Figure::Row::R1);
    // figures1[2] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R4);
    // // figures1[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // // figures1[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 3; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::C, Figure::Row::R7);
    // figures1[1] = new Queen(Figure::Color::white, true, Figure::Column::B, Figure::Row::R5);
    // figures1[2] = new Bishop(Figure::Color::white, true, Figure::Column::D, Figure::Row::R4);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R8);
    // figures1[4] = new King(Figure::Color::white, true, Figure::Column::H, Figure::Row::R8);
    // for (int i = 5; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::C, Figure::Row::R7);
    // // figures1[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // // figures1[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 3; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::C, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::C, Figure::Row::R7);
    // // figures1[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // // figures1[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 3; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::E, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::C, Figure::Row::R7);
    // // figures1[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // // figures1[4] = new Pawn(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 3; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::D, Figure::Row::R8);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::D, Figure::Row::R6);
    // figures1[2] = new Pawn(Figure::Color::white, true, Figure::Column::F, Figure::Row::R6);
    // figures1[3] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 5; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R1);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::D, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::F, Figure::Row::R6);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // //figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R7);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::D, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::F, Figure::Row::R6);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // //figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R1);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::G, Figure::Row::R3);
    // figures1[2] = new Knight(Figure::Color::white, true, Figure::Column::H, Figure::Row::R3);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::G, Figure::Row::R2);
    // //figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R1);
    // figures1[1] = new Knight(Figure::Color::white, true, Figure::Column::F, Figure::Row::R3);
    // figures1[2] = new King(Figure::Color::white, true, Figure::Column::F, Figure::Row::R7);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R2);
    // //figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R1);
    // figures1[1] = new King(Figure::Color::white, true, Figure::Column::D, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R3);
    // figures1[3] = new Rook(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    // //figures1[4] = new Rook(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new Pawn(Figure::Color::white, true, Figure::Column::A, Figure::Row::R7);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::B, Figure::Row::R8);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::C, Figure::Row::R6);
    // figures1[4] = new Knight(Figure::Color::white, true, Figure::Column::E, Figure::Row::R8);
    // for (int i = 5; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R7);
    // figures1[2] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R2);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::B, Figure::Row::R6);
    // //figures1[4] = new Knight(Figure::Color::white, true, Figure::Column::E, Figure::Row::R8);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R7);
    // figures1[1] = new Queen(Figure::Color::white, true, Figure::Column::B, Figure::Row::R4);
    // figures1[2] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R6);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // // figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;

    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R7);
    // figures1[1] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R4);
    // figures1[2] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R6);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // // figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;
    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::G, Figure::Row::R4);
    // figures1[1] = new Queen(Figure::Color::white, true, Figure::Column::F, Figure::Row::R2);
    // figures1[2] = new King(Figure::Color::white, true, Figure::Column::E, Figure::Row::R4);
    // figures1[3] = new Knight(Figure::Color::white, true, Figure::Column::F, Figure::Row::R5);
    // figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R4);
    // for (int i = 5; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;
    // Game game3;
    // Figure** figures3 = new Figure*[32];
    // figures3[0] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R8);
    // figures3[1] = new Queen(Figure::Color::white, true, Figure::Column::H, Figure::Row::R6);
    // figures3[2] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    // figures3[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // for (int i = 4; i < 32; ++i) {
    //     figures3[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures3[i] != nullptr) {
    //         if (!game3.registerFigure(figures3[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game3.printBoard();
    // game3.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures3[i];
    //     figures3[i] = nullptr;
    // }
    // delete[] figures3;
    // figures3 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new Rook(Figure::Color::white, true, Figure::Column::E, Figure::Row::R1);
    // figures1[1] = new Rook(Figure::Color::white, true, Figure::Column::D, Figure::Row::R1);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::C, Figure::Row::R1);
    // figures1[3] = new Bishop(Figure::Color::white, true, Figure::Column::B, Figure::Row::R1);
    // figures1[4] = new Knight(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // figures1[5] = new King(Figure::Color::black, true, Figure::Column::E, Figure::Row::R8);
    // figures1[6] = new King(Figure::Color::white, true, Figure::Column::F, Figure::Row::R1);
    //   for (int i = 7; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // game1.printBoard();
    // game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "---------------" << std::endl;
    // std::cout << std::endl;
    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::A, Figure::Row::R8);
    // figures1[1] = new Rook(Figure::Color::white, true, Figure::Column::B, Figure::Row::R6);
    // figures1[2] = new Rook(Figure::Color::white, true, Figure::Column::C, Figure::Row::R7);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::C, Figure::Row::R6);
    // figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R1);
    // for (int i = 5; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;
    // Game one_game1;
    // Figure** figures1 = new Figure*[32];
    // figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R6);
    // figures1[1] = new Pawn(Figure::Color::white, true, Figure::Column::F, Figure::Row::R6);
    // figures1[2] = new Queen(Figure::Color::white, true, Figure::Column::G, Figure::Row::R3);
    // figures1[3] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    // // figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::H, Figure::Row::R4);
    // for (int i = 4; i < 32; ++i) {
    //     figures1[i] = nullptr;
    // }
    // for (int i = 0; i < 32; ++i) {
    //     if (figures1[i] != nullptr) {
    //         if (!one_game1.registerFigure(figures1[i])) {
    //             std::cout << "Couldn't create" << std::endl;
    //             return -1;
    //         }
    //     }
    // }
    // one_game1.printBoard();
    // one_game1.analizeGame();
    // for (int i = 0; i < 32; i++) {
    //     delete figures1[i];
    //     figures1[i] = nullptr;
    // }
    // delete[] figures1;
    // figures1 = nullptr;
    // std::cout << "----------------" << std::endl;
    // std::cout << std::endl;
    Game one_game1;
    Figure** figures1 = new Figure*[32];
    figures1[0] = new King(Figure::Color::black, true, Figure::Column::H, Figure::Row::R8);
    figures1[1] = new Pawn(Figure::Color::white, true, Figure::Column::G, Figure::Row::R6);
    figures1[2] = new Knight(Figure::Color::white, true, Figure::Column::E, Figure::Row::R7);
    figures1[3] = new Knight(Figure::Color::white, true, Figure::Column::F, Figure::Row::R5);
    figures1[4] = new Bishop(Figure::Color::white, true, Figure::Column::D, Figure::Row::R5);
    figures1[5] = new King(Figure::Color::white, true, Figure::Column::A, Figure::Row::R1);
    for (int i = 6; i < 32; ++i) {
        figures1[i] = nullptr;
    }
    for (int i = 0; i < 32; ++i) {
        if (figures1[i] != nullptr) {
            if (!one_game1.registerFigure(figures1[i])) {
                std::cout << "Couldn't create" << std::endl;
                return -1;
            }
        }
    }
    one_game1.printBoard();
    one_game1.analizeGame();
    for (int i = 0; i < 32; i++) {
        delete figures1[i];
        figures1[i] = nullptr;
    }
    delete[] figures1;
    figures1 = nullptr;
    std::cout << "----------------" << std::endl;
    std::cout << std::endl;
    return 0;
}
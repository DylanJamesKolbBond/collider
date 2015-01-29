//primer.h
//Holds all the definitions for the file
//Mandatory include file

#ifndef PRIMER_H
#define PRIMER_H

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

using namespace std;


//CONSTANTS

//DEFINITIONS

#define NAME "Collider 0.1"
#define SQNUM 120

#define startFen "rnbqkbnr/pppppppp/8/8/8/8/pppppppp/RNBQKBNR w KQkq - 0 1"

typedef unsigned long long U64;
//Initialization


//ENUMERATION

enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum {  EMPTY,
	wqR, wqN, wqB,  wQ,  wK, wkB, wkN, wkR,
	wPa, wPb, wPc, wPd, wPe, wPf, wPg, wPh,
	bqR, bqN, bqB,  bQ,  bK, bkB, bkN, bkR,
	bPa, bPb, bPc, bPd, bPe, bPf, bPg, bPh  }; 
	

/* Constants for File and Rank */

enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

/* Constants for colors */

enum { NONE, WHITE, BLACK, };

/* Constants for every square */

enum {
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD = -1 };

enum {
	a1 = 0, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8 };
	

enum { FALSE, TRUE };

//DECLARATIONS


struct pieceStruct
{
	int position;
	int position64;
	int color;
	int type;
	int value;
	bool alive;
	U64 bitboard;
	int movelistSize;
} ;

//Bitboards
extern U64 whitePawns;
extern U64 whiteKnights;
extern U64 whiteBishops;
extern U64 whiteRooks;
extern U64 whiteQueen;
extern U64 whiteKing;
extern U64 whitePieces;

extern U64 blackPawns;
extern U64 blackKnights;
extern U64 blackBishops;
extern U64 blackRooks;
extern U64 blackQueen;
extern U64 blackKing;
extern U64 blackPieces;

extern U64 occupiedSquares;
extern U64 emptySquares;

//GLOBALS
extern int board64[64];
extern int side;
extern int fiftymove;
extern int ply;
extern int oppPly;
extern int board120[SQNUM];
extern int board120to64[SQNUM];
extern int board64to120[64];
extern pieceStruct pieceList[33];
extern int toSquare;
extern int fromSquare;
extern bool stop;
//MACROS

/*
	 These two FR2SQ macros are used for finding the index squares
  	 when fed file and rank information.
 */
#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )    //Finds 120 square index
#define FR2SQ64(f,r) ( (f) + ( (r) * 8) )	     //Finds 64 square index

//FUNCTIONS
extern void nl(int lines);
extern void initArray120to64();
extern void stars(int stars);
extern void initializeAll();
extern void displayBoard();
extern void displayAll();
extern void displayHeader();
extern void initialBoard();
extern void initialBitboards();
extern void spaces(int spaces);
extern void userEntry();
extern void makeMove();
extern bool checkLegal();
extern bool checkCheck();
extern void bitboardDebug();
extern void displayBitboard( U64 bbDisplay );
extern void setBit( int sq, U64 &bbAddress );
extern void logSDLError(std::ostream &outputStream, const std::string &message);
extern std::string getResourcePath(const std::string &subDir = "");
#endif

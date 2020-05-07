/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, pieceAtBlank)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, pieceAtIllegalRowUnder)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.pieceAt(-1, 0), Invalid);
}

TEST(PiezasTest, pieceAtIllegalRowOver)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.pieceAt(3, 0), Invalid);
}

TEST(PiezasTest, pieceAtIllegalColumnUnder)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.pieceAt(0, -1), Invalid);
}

TEST(PiezasTest, pieceAtIllegalColumnOver)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest, constructorEmptyBoard)
{
	Piezas testPiezas;
	bool allBlank = true;
	int rows = 3;
	int columns = 4;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (testPiezas.pieceAt(i, j) != Blank) {
				allBlank = false;
				break;
			}
		}
	}
	ASSERT_TRUE(allBlank);
}

TEST(PiezasTest, resetBlankBoard)
{
	Piezas testPiezas;
	testPiezas.reset();
	bool allBlank = true;
	int rows = 3;
	int columns = 4;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (testPiezas.pieceAt(i, j) != Blank) {
				allBlank = false;
				break;
			}
		}
	}
	ASSERT_TRUE(allBlank);
}

TEST(PiezasTest, dropPieceInvalidUnder)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceInvalidOver)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPieceInvalidUnderOTurn)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPieceFirstRowReturn)
{
	Piezas testPiezas;
	ASSERT_EQ(testPiezas.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceFirstRowBoardCheck)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.pieceAt(0, 0), X);
}

TEST(PiezasTest, dropPieceSecondRowReturn)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.dropPiece(0), O);
}

TEST(PiezasTest, dropPieceSecondRowBoardCheck)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.pieceAt(1, 0), O);
}

TEST(PiezasTest, dropPieceThirdRowReturn)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceThirdRowBoardCheck)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.pieceAt(2, 0), X);
}

TEST(PiezasTest, resetBoardWithPieces)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.reset();
	bool allBlank = true;
	int rows = 3;
	int columns = 4;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (testPiezas.pieceAt(i, j) != Blank) {
				allBlank = false;
				break;
			}
		}
	}
	ASSERT_TRUE(allBlank);
}

TEST(PiezasTest, dropPieceOverflow)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPieceOverflowXTurn)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	ASSERT_EQ(testPiezas.dropPiece(0), Blank);
}

TEST(PiezasTest, gameStateGameNotOver)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	ASSERT_EQ(testPiezas.gameState(), Invalid);
}

// Winner vertical X
/*
 * [X] [O] [X] [O]
 * [X] [X] [O] [O]
 * [X] [O] [O] [X]
 */
TEST(PiezasTest, winnerVerticalX)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	ASSERT_EQ(testPiezas.gameState(), X);
}

// Winner vertical O
/*
 * [X] [O] [O] [X]
 * [O] [O] [X] [X]
 * [X] [O] [X] [O]
 */
TEST(PiezasTest, winnerVerticalO)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(2);
	ASSERT_EQ(testPiezas.gameState(), O);
}

// Winner horizontal X
/*
 * [O] [O] [X] [O]
 * [O] [O] [X] [O]
 * [X] [X] [X] [X]
 */
TEST(PiezasTest, winnerHorizontalX)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	ASSERT_EQ(testPiezas.gameState(), X);
}

// Winner horizontal O
/*
 * [X] [O] [X] [X]
 * [O] [O] [O] [O]
 * [X] [X] [X] [O]
 */
TEST(PiezasTest, winnerHorizontalO)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	ASSERT_EQ(testPiezas.gameState(), O);
}

// Tie vertical x vertical
/*
 * [X] [O] [X] [O]
 * [X] [O] [O] [X]
 * [X] [O] [X] [O]
 */
TEST(PiezasTest, tieVerticalVsVertical)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	ASSERT_EQ(testPiezas.gameState(), Blank);
}

// Tie vertical x horizontal
/*
 * [X] [O] [X] [X]
 * [X] [X] [O] [O]
 * [X] [O] [O] [O]
 */
TEST(PiezasTest, tieVerticalVsHorizontal)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	ASSERT_EQ(testPiezas.gameState(), Blank);
}

// Tie horizontal x horizontal
/*
 * [X] [O] [X] [O]
 * [O] [O] [O] [O]
 * [X] [X] [X] [X]
 */
TEST(PiezasTest, tieHorizontalVsHorizontal)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	ASSERT_EQ(testPiezas.gameState(), Blank);
}

// Tie horizontal x vertical
/*
 * [O] [X] [O] [O]
 * [X] [O] [X] [O]
 * [X] [X] [X] [O]
 */
TEST(PiezasTest, tieHorizontalVsVertical)
{
	Piezas testPiezas;
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(0);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(2);
	testPiezas.dropPiece(3);
	testPiezas.dropPiece(1);
	testPiezas.dropPiece(2);
	ASSERT_EQ(testPiezas.gameState(), Blank);
}

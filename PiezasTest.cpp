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
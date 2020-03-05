#include "pch.h"
#include "CppUnitTest.h"
#include "..\Yachtzee\Player.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Player playerForTests("Player One");
			Dice diceForTests;
			Points pointsForTests;

			Assert::IsTrue(playerForTests.GetKeptDiceforPoints() == diceForTests.GetKeptDices());
			Assert::IsTrue(playerForTests.GetRollDices() == diceForTests.GetRolledDices());
			Assert::IsTrue(playerForTests.GetPossiblePlacesForPoints() == pointsForTests.GetPossiblePlaces());
			Assert::IsTrue(playerForTests.GetLowerPoints() == pointsForTests.GetVectorLowerPoints());
			Assert::IsTrue(playerForTests.GetUpperPoints() == pointsForTests.GetVectorUpperPoints());
			Assert::IsTrue(playerForTests.GetNumberOfDices() == diceForTests.GetSizeOfArray());
		}
		TEST_METHOD(PrintName)
		{
			Player playerForTests("Player One");
			std::stringstream stream;
			stream << playerForTests;
			Assert::AreEqual(std::string("Player One"), stream.str(), L"You see this message if the name is not the same.");
		}
		TEST_METHOD(Destructor)
		{
			Player playerForTests("Player One");
			playerForTests.~Player();
			std::stringstream stream;
			stream << playerForTests;
			Assert::IsTrue(stream.str().length() == 0);
			for (auto iterator = playerForTests.GetKeptDiceforPoints().begin(); iterator < playerForTests.GetKeptDiceforPoints().end(); iterator++)
				Assert::IsTrue(*iterator == 0);
			Assert::IsTrue(playerForTests.GetRollDices().size() == 0);
			for (auto iterator1 = playerForTests.GetPossiblePlacesForPoints().begin(); iterator1 < playerForTests.GetPossiblePlacesForPoints().end(); iterator1++)
				Assert::IsTrue(*iterator1 == 0);
			Assert::IsTrue(playerForTests.GetUpperPoints().size() == 0);
			Assert::IsTrue(playerForTests.GetLowerPoints().size() == 0);
			Assert::IsTrue(playerForTests.GetNumberOfDices() == 0);
			Assert::IsTrue(playerForTests.GetIndexOfOption() == 0);
		}

	};
}

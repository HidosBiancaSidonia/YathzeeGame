#include "pch.h"
#include "CppUnitTest.h"
#include "..\Yachtzee\Dice.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YachtzeeTests
{
	TEST_CLASS(DiceTests)
	{
	public:

		TEST_METHOD(Constructor)
		{

			Dice diceForTests;

			std::vector< int8_t >rolledDicesForTests = { 1,2,3,4,5 };
			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,0 };
			Assert::IsTrue(diceForTests.GetRolledDices() == rolledDicesForTests);
			Assert::IsTrue(diceForTests.GetKeptDices() == keptDicesForTests);
			Assert::IsTrue(diceForTests.GetSizeOfArray() == 5);
		}
		TEST_METHOD(Destructor)
		{

			Dice diceForTests;
			diceForTests.~Dice();


			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,0 };
			Assert::IsTrue(diceForTests.GetRolledDices().size() == 0);
			Assert::IsTrue(diceForTests.GetKeptDices() == keptDicesForTests);
			Assert::IsTrue(diceForTests.GetSizeOfArray() == 0);
		}

		TEST_METHOD(RolledDices)
		{

			std::vector<int8_t> rolledDicesForTests = { 1,2,3,4,5 };
			Dice diceForTests;
			for (auto iterator1 = diceForTests.GetRolledDices().begin(), iterator2 = rolledDicesForTests.begin(); iterator1 != diceForTests.GetRolledDices().end(), iterator2 != rolledDicesForTests.end(); ++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);

		}

		TEST_METHOD(KeptDices)
		{

			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,0 };
			Dice diceForTests;
			for (auto iterator1 = diceForTests.GetKeptDices().begin(), iterator2 = keptDicesForTests.begin(); iterator1 != diceForTests.GetKeptDices().end(), iterator2 != keptDicesForTests.end(); ++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);

		}
		TEST_METHOD(SizeOfArray)
		{
			uint8_t sizeOfArrayForTests = 5;
			Dice diceForTests;
			Assert::AreEqual(sizeOfArrayForTests, diceForTests.GetSizeOfArray());
		}

	};
}
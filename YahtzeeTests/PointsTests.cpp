#include "pch.h"
#include "CppUnitTest.h"
#include "..\Yachtzee\Points.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YachtzeeTests
{
	TEST_CLASS(PointsTests)
	{
	public:

		TEST_METHOD(Constructor)
		{

			Points pointsForTests;
			std::vector<int> upperPointsForTest, lowerPointsForTest;
			upperPointsForTest.reserve(6);
			lowerPointsForTest.reserve(7);
			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,0 };

			Assert::IsTrue(pointsForTests.GetVectorUpperPoints().size() == upperPointsForTest.size());
			Assert::IsTrue(pointsForTests.GetVectorLowerPoints().size() == lowerPointsForTest.size());
			Assert::IsTrue(pointsForTests.GetKeptDices() == keptDicesForTests);
		}

		TEST_METHOD(Destructor)
		{
			std::vector<int> upperPointsForTests;
			std::vector<int> lowerPointsForTests;
			upperPointsForTests.clear();
			lowerPointsForTests.clear();

			Points pointsForTests;
			pointsForTests.~Points();

			Assert::IsTrue(pointsForTests.GetVectorUpperPoints() == upperPointsForTests);
			Assert::IsTrue(pointsForTests.GetVectorLowerPoints() == lowerPointsForTests);
		}

		TEST_METHOD(VectorUpperPoints)
		{

			std::vector<int> upperPointsForTests;
			upperPointsForTests.reserve(6);

			Points pointsForTests;
			Assert::IsTrue(upperPointsForTests == pointsForTests.GetVectorUpperPoints());
		}

		TEST_METHOD(VectorLowerPoints)
		{

			std::vector<int> lowerPointsForTests;
			lowerPointsForTests.reserve(8);

			Points pointsForTests;
			Assert::IsTrue(lowerPointsForTests == pointsForTests.GetVectorLowerPoints());
		}

		TEST_METHOD(KeptDices)
		{
			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,0 };
			Points pointsForTests;

			for (auto iterator1 = pointsForTests.GetKeptDices().begin(), iterator2 = keptDicesForTests.begin(); iterator1 != pointsForTests.GetKeptDices().end(), iterator2 != keptDicesForTests.end(); ++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
		}

		TEST_METHOD(Ones)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), false);
			std::array<int8_t, 6> keptDicesForTests = { 2,1,0,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(2);
			Points pointsForTests;

			pointsForTests.Ones(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::One)] == true);
		}

		TEST_METHOD(Twos)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 2,3,0,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(6);
			Points pointsForTests;

			pointsForTests.Twos(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Two)] == true);
		}

		TEST_METHOD(Threes)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 2,3,2,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(6);
			Points pointsForTests;

			pointsForTests.Threes(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Three)] == true);
		}

		TEST_METHOD(Fours)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 2,3,2,1,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(4);
			Points pointsForTests;

			pointsForTests.Fours(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Four)] == true);
		}

		TEST_METHOD(Fives)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 2,3,2,1,5,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(25);
			Points pointsForTests;

			pointsForTests.Fives(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Five)] == true);
		}

		TEST_METHOD(Sixes)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 2,3,2,1,5,4 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(24);
			Points pointsForTests;

			pointsForTests.Sixes(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Six)] == true);
		}

		TEST_METHOD(PartialSum)
		{
			std::vector<int> upperPointsForTests;
			upperPointsForTests.push_back(1);
			upperPointsForTests.push_back(4);
			upperPointsForTests.push_back(6);
			upperPointsForTests.push_back(16);
			upperPointsForTests.push_back(15);
			upperPointsForTests.push_back(12);

			Points pointsForTests;

			Assert::IsTrue(pointsForTests.PartialSum(upperPointsForTests) == 54);
		}

		TEST_METHOD(VerifyBonus)
		{
			std::vector<int> upperPointsForTests;
			upperPointsForTests.push_back(1);
			upperPointsForTests.push_back(4);
			upperPointsForTests.push_back(6);
			upperPointsForTests.push_back(16);
			upperPointsForTests.push_back(15);
			upperPointsForTests.push_back(12);

			std::vector<int> upperPointsForTestsTwo;
			upperPointsForTestsTwo.push_back(3);
			upperPointsForTestsTwo.push_back(6);
			upperPointsForTestsTwo.push_back(9);
			upperPointsForTestsTwo.push_back(12);
			upperPointsForTestsTwo.push_back(15);
			upperPointsForTestsTwo.push_back(18);

			Points pointsForTests;

			Assert::IsTrue(pointsForTests.VerifyBonus(upperPointsForTests) == 0);
			Assert::IsTrue(pointsForTests.VerifyBonus(upperPointsForTestsTwo) == 35);
		}

		TEST_METHOD(TotalScore)
		{
			std::vector<int> upperPointsForTests;
			upperPointsForTests.push_back(1);
			upperPointsForTests.push_back(4);
			upperPointsForTests.push_back(6);
			upperPointsForTests.push_back(16);
			upperPointsForTests.push_back(15);
			upperPointsForTests.push_back(12);
			std::vector<int> lowerPointsForTests;
			lowerPointsForTests.push_back(12);
			lowerPointsForTests.push_back(15);
			lowerPointsForTests.push_back(25);
			lowerPointsForTests.push_back(30);
			lowerPointsForTests.push_back(40);
			lowerPointsForTests.push_back(22);
			lowerPointsForTests.push_back(50);

			Points pointsForTests;

			Assert::IsTrue(pointsForTests.TotalScore(lowerPointsForTests, upperPointsForTests) == 248);
		}

		TEST_METHOD(ThreeOfAKind)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,3,2,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(12);
			Points pointsForTests;

			pointsForTests.ThreeOfAKind(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::ThreeOfKind)] == true);
		}

		TEST_METHOD(WrongThreeOfAKind)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,2,2,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.ThreeOfAKind(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::ThreeOfKind)] == true);
		}

		TEST_METHOD(FourOfAKind)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,0,1,0,4,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(23);
			Points pointsForTests;

			pointsForTests.FourOfAKind(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::FourOfKind)] == true);
		}


		TEST_METHOD(WrongFourOfAKind)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,0,1,2,2,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.FourOfAKind(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::FourOfKind)] == true);
		}

		TEST_METHOD(FullHouse)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,3,2,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(25);
			Points pointsForTests;

			pointsForTests.FullHouse(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Full)] == true);
		}

		TEST_METHOD(WrongFullHouse)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,2,2,0,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.FullHouse(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Full)] == true);
		}

		TEST_METHOD(SmallStraight)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 1,1,1,1,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(30);
			Points pointsForTests;

			pointsForTests.SmallStraight(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Small)] == true);
		}

		TEST_METHOD(WrongSmallStraight)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,1,1,1,0,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.SmallStraight(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Small)] == true);
		}

		TEST_METHOD(LargeStraight)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 1,1,1,1,1,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(40);
			Points pointsForTests;

			pointsForTests.LargeStraight(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Large)] == true);
		}

		TEST_METHOD(WrongLargeStraight)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 1,1,0,1,1,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.LargeStraight(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Large)] == true);
		}

		TEST_METHOD(Chance)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 1,0,0,1,3,0 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(20);
			Points pointsForTests;

			pointsForTests.Chance(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Chance)] == true);
		}

		TEST_METHOD(Yahtzee)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,0,0,5 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(50);
			Points pointsForTests;

			pointsForTests.Yachtzee(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Yahtzee)] == true);
		}

		TEST_METHOD(WrongYahtzee)
		{
			std::array<bool, 16> possiblePlacesForPointsForTests;
			std::fill(std::begin(possiblePlacesForPointsForTests), std::end(possiblePlacesForPointsForTests), 0);
			std::array<int8_t, 6> keptDicesForTests = { 0,0,0,1,0,4 };
			std::vector<int> upperPointsForTests;
			std::vector<int> upperPointsForValidation;
			upperPointsForValidation.push_back(0);
			Points pointsForTests;

			pointsForTests.Yachtzee(upperPointsForTests, keptDicesForTests, possiblePlacesForPointsForTests);

			for (auto iterator1 = upperPointsForTests.begin(), iterator2 = upperPointsForValidation.begin();
				iterator1 != upperPointsForTests.end(), iterator2 != upperPointsForValidation.end();
				++iterator1, ++iterator2)
				Assert::AreEqual(*iterator2, *iterator1);
			Assert::IsTrue(possiblePlacesForPointsForTests[static_cast<int>(Points::TypesOfScore::Yahtzee)] == true);
		}

	};
}
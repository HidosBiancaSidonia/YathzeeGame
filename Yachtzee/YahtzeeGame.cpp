#include "YahtzeeGame.h"
#include "Player.h"

void YahtzeeGame::GeneralRules()
{
	std::cout << '\n' << "The game has 5 dices. Each player in turn rolls out the dices. Each turn consists of a maximum of three rolls." << '\n';
	std::cout << "The first roll must be made with all five dices. If the player chooses to roll a second and, if desired, a third time, he may pick up any or all the dices and roll again." << '\n';
	std::cout << "It is the skillful use of these two optional rolls of the dice that can turn an unlucky first or second roll into a high-scoring turn. A score must be entered after the last roll in the appropriate box or a zero entered in a box of the player's choice." << '\n';
	std::cout << "There are 13 scoring boxes. On each completed turn, the player must score in one of the 13 boxes. The boxes may be filled in any order, according to the player's best judgment." << '\n' << '\n';
}


void YahtzeeGame::UpperSectionRules()
{
	std::cout << "UPPER SECTION RULES" << '\n';
	std::cout << "The upper section contains six boxes labelled 1 to 6" << '\n';
	std::cout << "When a player chooses to score in the Upper Section, he counts and adds only the dice with the same number and enters the total of these dice in the appropriate box." << '\n';
}

void YahtzeeGame::LowerSectionRules()
{
	std::cout << "LOWER SECTION RULES" << '\n';
	std::cout << "3 OF A KIND: " << "The '3 of a kind' box may be filled in only if the dices show at least 3 of the same number. The result from the box will be the sum of all the dices." << '\n';
	std::cout << "4 OF A KIND: " << "The '4 of a kind' box may be filled in only if the dices show at least 4 of the same number. The result from the box will be the sum of all the dices." << '\n';
	std::cout << "FULL HOUSE: " << "You need to roll both a '3 of a kind' and a pair. A 'Full House' scores 25 points." << '\n';
	std::cout << "SMALL STRAIGHT: " << "You need to have 4 consecutive dices. The 'Small Straight' scores 30 points." << '\n';
	std::cout << "LARGE STRAIGHT: " << "You need to have 5 consecutive dices. The 'Small Straight' scores 40 points." << '\n';
	std::cout << "CHOICE: " << "This offers a player the opportunity to score on any turn where he does not choose to score in any of the other open boxes. Mark score by totalling number of points on all dice.This offers a player the opportunity to score on any turn where he does not choose to score in any of the other open boxes. Mark score by totalling number of points on all dice." << '\n';
	std::cout << "YACHTZEE: " << "This is any 'five of a kind'. Score 50 points in the 'Yahtzee' box." << '\n' << '\n';
}

void YahtzeeGame::Bonus()
{
	std::cout << "BONUS POINTS" << '\n';
	std::cout << "Here are some bonus points you can achieve during the game: " << '\n';
	std::cout << "You get a bonus of 35 points if the total number of points you scored in the upper section is 63 or higher." << '\n';
	std::cout << "If you roll a Yahtzee and you already filled in the Yahtzee box with a 50 , you get a 100-point bonus." << '\n';
}

void YahtzeeGame::GameRules()
{
	YahtzeeGame rules;
	rules.GeneralRules();
	rules.UpperSectionRules();
	rules.LowerSectionRules();
	rules.Bonus();
}

void YahtzeeGame::Run()
{
	int option;
	std::cout << "WELCOME TO YACHTZEE!" << '\n';
	std::cout << "Do you want to see the rules before de the game starts? " << '\n';
	std::cout << "If yes, please press 1, else press 0.   ";
	std::cin >> option;

	while (option != 0 && option != 1)
	{
		std::cout << "Invalid option! Please try inserting it again" << '\n';
		std::cin >> option;
	}

	if (option == 1)
	{
		GameRules();
	}

	std::string playerName;
	std::cout << "First player name: ";
	std::cin >> playerName;
	Player player1(playerName);
	std::cout << "Second player name: ";
	std::cin >> playerName;
	Player player2(playerName);

	int playerOption, contorRollDices;

	std::reference_wrapper<Player> firstPlayer = player1;
	std::reference_wrapper<Player> secondPlayer = player2;

	Dice dice;

	for (int indexOfTurn = 0; indexOfTurn < 26; indexOfTurn++)
	{
		system("cls");
		contorRollDices = 0;
		dice.DisplayDices(dice.GetRolledDices());

		while (contorRollDices < 3)
		{
			std::cout << "It's " << firstPlayer << "'s turn." << '\n';
			std::cout << "Please be aware of the fact that you can roll up to 3 times." << '\n';
			firstPlayer.get().SwitchOptions();

			do
			{
				std::cout << "Please write your option" << '\n';
				std::cin >> playerOption;
			} while (playerOption != 1 && playerOption != 2 && playerOption != 3 && playerOption != 4);

			if (playerOption == 1)
				firstPlayer.get().ChooseOption(Player::TypesOfOptionsForPlayer::KeepDices);
			else if (playerOption == 2)
			{
				firstPlayer.get().ChooseOption(Player::TypesOfOptionsForPlayer::RollDices);
				contorRollDices++;
				if (contorRollDices == 3)
					firstPlayer.get().ChooseOption(Player::TypesOfOptionsForPlayer::ChoosePointsOption);
			}
			else if (playerOption == 3)
			{
				firstPlayer.get().ChooseOption(Player::TypesOfOptionsForPlayer::ChoosePointsOption);
				contorRollDices = 3;
			}
			else if (playerOption == 4)
				firstPlayer.get().ChooseOption(Player::TypesOfOptionsForPlayer::ReleaseDices);
		}

		std::swap(firstPlayer, secondPlayer);
	}

	int firstPlayerPoints = 0, secondPlayerPoints = 0;
	firstPlayerPoints = firstPlayer.get().finalPoints();
	secondPlayerPoints = secondPlayer.get().finalPoints();
	std::cout << firstPlayer << " has " << firstPlayerPoints << '\n';
	std::cout << secondPlayer << " has " << secondPlayerPoints << '\n';
	if (firstPlayerPoints > secondPlayerPoints)
		std::cout << firstPlayer << " wons with " << firstPlayerPoints << " points." << '\n';
	else std::cout << secondPlayer << " wons with " << secondPlayerPoints << " points." << '\n';

}
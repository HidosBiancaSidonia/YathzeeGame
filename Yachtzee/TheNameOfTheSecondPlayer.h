#include <string>
using namespace std;
namespace sf
{
	class RenderWindow;
}
class TheNameOfTheSecondPlayer
{
public:
	TheNameOfTheSecondPlayer(sf::RenderWindow& window,string nameOfTheFirstPlayer);

private:
	string nameOfTheSecondPlayer;
	
};


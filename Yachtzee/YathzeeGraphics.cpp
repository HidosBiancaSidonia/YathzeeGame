#include "YathzeeGraphics.h"

void YahtzeeGraphics::InitializeWindow()
{
	std::ifstream fin("window.in");
	std::string title = "None";
	sf::VideoMode windowBounds(0, 0);
	unsigned int frameLimit = 0;
	bool verticalSyncEnable = false;
	if (fin.is_open())
	{
		std::getline(fin, title);
		fin >> windowBounds.width >> windowBounds.height;
		fin >> frameLimit;
		fin >> verticalSyncEnable;
	}
	fin.close();

	this->window = new sf::RenderWindow(windowBounds, title);
	this->window->setFramerateLimit(frameLimit);
	this->window->setVerticalSyncEnabled(verticalSyncEnable);
}

void YahtzeeGraphics::InitKeys()
{
	std::ifstream ifs("x64/Debug/supported_keys.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->suportedKeys[key] = key_value;
		}
	}
	ifs.close();

}

void YahtzeeGraphics::InitializeStates()
{
	//this->states.push(new MainMenuState(this->window, &this->suportedKeys));

}

YahtzeeGraphics::YahtzeeGraphics()
{
	this->InitializeWindow();
	this->InitKeys();
	this->InitializeStates();
}

YahtzeeGraphics::~YahtzeeGraphics()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void YahtzeeGraphics::EndApplication()
{
	std::cout << "Ending application" << '\n';
}

void YahtzeeGraphics::UpdateDeltaTime()
{
	this->deltaTime = this->deltaTimeClock.restart().asSeconds();

	/*system("cls");
	std::cout << this->deltaTime<<'\n';*/
}

void YahtzeeGraphics::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->SFevent))
	{
		if (this->SFevent.type == sf::Event::Closed)
			this->window->close();
	}
}

void YahtzeeGraphics::Update()
{
	this->UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->deltaTime);
		if (this->states.top()->GetQuit())
		{
			this->states.top()->EndState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->EndApplication();
		this->window->close();
	}

}

void YahtzeeGraphics::Render()
{
	this->window->clear();

	if (!this->states.empty())
		this->states.top()->Render(this->window);

	this->window->display();
}

void YahtzeeGraphics::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	}
}



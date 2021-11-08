#include "game.hpp"

Game::Game() : backgroundColor(255, 222, 173, 255)
{
	window.create(sf::VideoMode(512, 512), "Firefighter");
}

sf::Time Game::sleepTime()
{
    if (sf::microseconds(16'666) <= timeExecution.getElapsedTime())
        return sf::microseconds(0);
    else
        return (sf::microseconds(16'666) - timeExecution.getElapsedTime());
}

void Game::play()
{
	while (window.isOpen())
	{
        sf::sleep(sleepTime());
        timeExecution.restart();
        window.clear(backgroundColor);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
	}
}

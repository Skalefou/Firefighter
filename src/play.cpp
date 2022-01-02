#include <SFML/Graphics.hpp>
#include "play.hpp"

void Play::run()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && option.canOpenOption())
		option.setOption(!option.getOption());
	if(option.getOption())

}

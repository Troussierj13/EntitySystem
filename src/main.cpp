#include <iostream>

#include <SFML/Main.hpp>
#include <SFML/Window/Touch.hpp>
#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "PlayState.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "GreedyMonkey", sf::Style::Fullscreen);
	storm::state::StateManager states;

	states.requestPush<PlayState>( window);

	while(window.isOpen()) {
		states.executeRequests();

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
				window.close();

			states.top<State>().handleEvent(event);
		}
		states.update();

		window.clear(sf::Color::White);
		states.render();
		window.display();
	}
	return EXIT_SUCCESS;
}

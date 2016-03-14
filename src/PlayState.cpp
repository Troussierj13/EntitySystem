#include "PlayState.hpp"

#include <Storm/State/StateManager.hpp>

#include "Archetypes.hpp"
#include "RenderSystem.hpp"

PlayState::PlayState(storm::state::StateManager &parent, sf::RenderTarget &target)
	: State(parent, target) {
	rect.setFillColor(sf::Color::Red);
	rect.setPosition({80,150});
	rect.setSize({50,50});

	m_texturesHolder.load(Textures::Banane, "../assets/banane.png");

	m_entityManager.addSystem<RenderSystem>(*m_target);

	makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Banane), 0.f, {300, 300});
}

void PlayState::pause() {

}

void PlayState::resume() {

}

void PlayState::handleEvent(const sf::Event &event) {
	m_entityManager.preUpdateSystems();
}

void PlayState::update(float delta) {
	m_entityManager.updateSystems(delta);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Banane), 0.f, sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
}

void PlayState::render() {
	//m_target->draw(rect);

	m_entityManager.postUpdateSystems();
}

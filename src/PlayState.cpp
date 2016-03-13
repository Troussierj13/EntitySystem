#include "PlayState.hpp"

#include <Storm/State/StateManager.hpp>

#include "Archetypes.hpp"
#include "RenderSystem.hpp"

PlayState::PlayState(storm::state::StateManager &parent, sf::RenderTarget &target)
	: State(parent, target) {
	rect.setFillColor(sf::Color::Red);
	rect.setPosition({80,150});
	rect.setSize({50,50});

	m_texturesHolder.load(Textures::Projectile, "../assets/proj.png");

	m_entityManager.addSystem<RenderSystem>(*m_target);

	makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Projectile), 15, {300, 300});
	makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Projectile), 15, {400, 200});
	makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Projectile), 15, {200, 400});
	makeProjectile(m_entityManager, m_texturesHolder.get(Textures::Projectile), 15, {500, 500});
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
}

void PlayState::render() {
	//m_target->draw(rect);

	//m_entityManager.postUpdateSystems();
}

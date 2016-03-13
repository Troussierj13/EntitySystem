#include "RenderSystem.hpp"

#include "Components.hpp"

#include <memory>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <Storm/Entity/EntityManager.hpp>

RenderSystem::RenderSystem(storm::entity::EntityManager &manager, sf::RenderTarget &target)
	: System(manager, 0, {RenderComponent::TYPE, PositionComponent::TYPE, SizeComponent::TYPE}), m_target(target){

}

RenderSystem::~RenderSystem() {

}

void RenderSystem::preUpdate() {

}

void RenderSystem::update(float delta) {

}

void RenderSystem::postUpdate() {
	for(auto e : m_entities) {
			auto &render = m_manager.getComponent<RenderComponent>(e);
			auto &position = m_manager.getComponent<PositionComponent>(e);

			std::unique_ptr<sf::Sprite> _sprite;

			_sprite->setTexture(*render.texture);
			_sprite->setPosition(position.position);

			m_target.draw(*_sprite);
		}
}

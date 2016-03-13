#include "Archetypes.hpp"
#include "Components.hpp"

#include <Storm/Entity/EntityManager.hpp>

#include <memory>

storm::entity::Entity makeProjectile(storm::entity::EntityManager &manager, const sf::Texture &texture, float power, const sf::Vector2f &pos) {
	auto e = manager.makeEntity();

	auto &_display = manager.addComponent<RenderComponent>(e);
	auto &_power = manager.addComponent<PowerComponent>(e);
	auto &_position = manager.addComponent<PositionComponent>(e);

	_display.texture = std::make_unique<sf::Texture>(texture);
	_power.power = power;
	_position.position = {pos.x - texture.getSize().x/2.f, pos.y - texture.getSize().y/2.f};

	return e;
}

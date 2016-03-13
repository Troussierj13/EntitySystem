_Pragma("once")

#include <Storm/Entity/Entity.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace storm {
	namespace entity {
		class EntityManager;
	}
}

storm::entity::Entity makeProjectile(storm::entity::EntityManager &manager, const sf::Texture &texture, float power, const sf::Vector2f &pos);


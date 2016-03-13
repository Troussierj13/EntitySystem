_Pragma("once")

#include <Storm/Core/HashHelpers.hpp>
#include <Storm/Entity/Component.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>

struct SizeComponent : public storm::entity::Component {
		enum class Primitiv {
			Circle, Rectangle
		} primitiv;

		union {
			float radius;
			struct {
				float w;
				float h;
			} size;
		};

		static constexpr Type TYPE = storm::core::hash::murmur3_32("Size");
};

struct RenderComponent : public storm::entity::Component {
		std::unique_ptr<sf::Texture> texture;

		static constexpr Type TYPE = storm::core::hash::murmur3_32("Render");
};

struct PositionComponent : public storm::entity::Component {
		sf::Vector2f position;
		static constexpr Type TYPE = storm::core::hash::murmur3_32("Position");
};

struct AccelerationComponent : public storm::entity::Component {
		sf::Vector2f acceleration;
		static constexpr Type TYPE = storm::core::hash::murmur3_32("Acceleration");
};

struct VelocityComponent : public storm::entity::Component {
		sf::Vector2f velocity;
		static constexpr Type TYPE = storm::core::hash::murmur3_32("Velocity");
};

struct PowerComponent : public storm::entity::Component {
		float power;
		static constexpr Type TYPE = storm::core::hash::murmur3_32("Power");
};

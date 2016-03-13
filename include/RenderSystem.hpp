_Pragma("once")

#include <Storm/Entity/System.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

class RenderSystem : public storm::entity::System
{
	public:
		explicit RenderSystem(storm::entity::EntityManager &manager, sf::RenderTarget &target);
		virtual ~RenderSystem();

		virtual void preUpdate();
		virtual void update(float delta);
		virtual void postUpdate();
	private:
		sf::RenderTarget &m_target;
};

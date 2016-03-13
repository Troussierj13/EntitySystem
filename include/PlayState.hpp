_Pragma("once")

#include "State.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

#include <Storm/Entity/EntityManager.hpp>

class PlayState : public State {
	public:
		explicit PlayState(storm::state::StateManager &parent, sf::RenderTarget &target);
		PlayState(PlayState &&state) = default;
		PlayState &operator=(PlayState &&state) = default;
		virtual ~PlayState() = default;

		virtual void pause();
		virtual void resume();

		virtual void handleEvent(const sf::Event &event);
		virtual void update(float delta);
		virtual void render();

	private:
		sf::RectangleShape rect;
		storm::entity::EntityManager m_entityManager;
		ResourceHolder<sf::Texture, Textures::ID> m_texturesHolder;
};

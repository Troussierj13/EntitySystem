_Pragma("once")

#include <Storm/State/State.hpp>
#include <Storm/State/StateManager.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace sf {
	class RenderTarget;
	class Event;
}

class State: public storm::state::State {
	public:
		explicit State(storm::state::StateManager &parent, sf::RenderTarget &target) : m_target(&target), storm::state::State(parent) {

		}

		virtual ~State() = default;

		void setRenderTarget(sf::RenderTarget &target) {
			m_target = &target;
		}

		virtual void handleEvent(const sf::Event &event) = 0;

	protected:
		sf::RenderTarget *m_target;
};

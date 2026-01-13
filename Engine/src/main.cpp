#include <SFML/Graphics.hpp>
#include <optional>

class Game
{
public:
	//Initialize game objects
    Game()
    {
        m_shape.setRadius(50.f);
        m_shape.setFillColor(sf::Color::Green);
        m_shape.setPosition({ 375.f, 275.f });
    }

    void update(float deltaTime)
    {
        float speed = 300.f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            m_shape.move({ -speed * deltaTime, 0.f });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            m_shape.move({ speed * deltaTime, 0.f });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            m_shape.move({ 0.f, -speed * deltaTime });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            m_shape.move({ 0.f, speed * deltaTime });
        }
    }

	//Draw the game objects
    void draw(sf::RenderWindow& window)
    {
        window.draw(m_shape);
    }

private:
    sf::CircleShape m_shape;
};

class Engine
{
public:
	//Initialize the engine and create the window
    Engine()
        : m_window(sf::VideoMode({ 800, 600 }), "Mini Engine")
    {
    }

	//Main loop of the engine
    void run()
    {
        sf::Clock clock;

        while (m_window.isOpen())
        {
            float deltaTime = clock.restart().asSeconds();

            handleEvents();
            m_game.update(deltaTime);

            m_window.clear(sf::Color::Black);
            m_game.draw(m_window);
            m_window.display();
        }
    }

private:
	//Handle window events
    void handleEvents()
    {
        while (const std::optional event = m_window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                m_window.close();
        }
    }

private:
    sf::RenderWindow m_window;
    Game m_game;
};

int main()
{
	// Create and run the engine
    Engine engine;
    engine.run();
    return 0;
}

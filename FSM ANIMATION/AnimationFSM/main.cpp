#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{


	sf::Text m_helpText[2];
	sf::Font m_font;

	if (!m_font.loadFromFile("assets\\arial.ttf"))
	{
		DEBUG_MSG("Failed to load font");
		return EXIT_FAILURE;
	}
	for(int i = 0; i < 2; i++)
	{
		m_helpText[i].setFont(m_font);
		m_helpText[i].setCharacterSize(20);
		m_helpText[i].setFillColor(sf::Color::White);
	}
	
	m_helpText[0].setString("1 - CLIMBING\n2 - WALKING\n3 - JUMPING\n4 - SHOVELLING\n5 - SWORDMANSHIP(SWORDING)\n6 - HAMMERING\n7 - IDLING");
	m_helpText[0].setPosition(50, 400);
	m_helpText[1].setPosition(450, 400);

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\grid.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);

	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			animated_sprite.addFrame(sf::IntRect(3 + (j * 85), 3 + (i * 85), 84, 84));
		}
	}




	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
					{
						input.setCurrent(Input::Action::CLIMBING_1);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
					{
						input.setCurrent(Input::Action::WALKING_2);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
					{
						input.setCurrent(Input::Action::JUMPING_3);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
					{
						input.setCurrent(Input::Action::SHOVELLING_4);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
					{
						input.setCurrent(Input::Action::SWORDMANSHIP_5);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
					{
						input.setCurrent(Input::Action::HAMMERING_6);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
					{
						input.setCurrent(Input::Action::IDLING_7);
					}
				break;
			default:
				break;
			}
		}

		// Handle input to Player
		player.handleInput(input);
		
		

		// Update the Player
		player.update(input);

		// Clear screen
		window.clear();

		m_helpText[1].setString("NEXT STATE: " + input.outputCurrent());

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());
		window.draw(m_helpText[0]);
		window.draw(m_helpText[1]);
		

		// Update the window
		window.display();
		



		
	
		
		
	}

	return EXIT_SUCCESS;
};
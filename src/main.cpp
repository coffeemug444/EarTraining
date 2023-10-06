#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void pollEvents(sf::RenderWindow& window)
{
   sf::Event event;
   while (window.pollEvent(event))
   {
      switch (event.type)
      {
      case sf::Event::Closed:
         window.close();
         break;
      case sf::Event::MouseMoved:
         sf::Vector2i{event.mouseMove.x,event.mouseMove.y};
         break;
      case sf::Event::MouseButtonPressed:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         sf::Vector2i{event.mouseMove.x,event.mouseMove.y};
         break;
      case sf::Event::MouseButtonReleased:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         sf::Vector2i{event.mouseMove.x,event.mouseMove.y};
         break;
      default:
         break;
      }
   }
}

int main()
{
   sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
   sf::CircleShape shape(100.f);
   shape.setFillColor(sf::Color::Green);


   sf::SoundBuffer buffer1;
   sf::SoundBuffer buffer2;

   buffer1.loadFromFile("samples/17.wav");
   buffer2.loadFromFile("samples/16.wav");

   sf::Sound sound1;
   sf::Sound sound2;

   sound1.setBuffer(buffer1);
   sound2.setBuffer(buffer2);

   sound1.play();
   sound2.play();

   while (window.isOpen())
   {
      pollEvents(window);

      window.clear();
      window.draw(shape);
      window.display();
   }

   return 0;
}

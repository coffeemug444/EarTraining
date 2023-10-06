#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guessingPage.hpp"
#include "settingsPage.hpp"

enum PageId {
   SETTINGS,
   GUESSING
};

const int WIDTH = 200;
const int HEIGHT = 200;

PageId activePage = SETTINGS;
GuessingPage guessing_page(WIDTH, HEIGHT);
SettingsPage settings_page(WIDTH, HEIGHT);

Page& getActivePage()
{
   if (activePage == SETTINGS) return settings_page;
   return guessing_page;
}

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
         getActivePage().MouseMoved({static_cast<float>(event.mouseMove.x),static_cast<float>(event.mouseMove.y)});
         break;
      case sf::Event::MouseButtonPressed:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         getActivePage().MouseDown({static_cast<float>(event.mouseMove.x),static_cast<float>(event.mouseMove.y)});
         break;
      case sf::Event::MouseButtonReleased:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         getActivePage().MouseUp({static_cast<float>(event.mouseMove.x),static_cast<float>(event.mouseMove.y)});
         break;
      default:
         break;
      }
   }
}

int main()
{
   sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ear Training");
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

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guessingPage.hpp"
#include "settingsPage.hpp"

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

   while (window.isOpen())
   {
      pollEvents(window);

      window.clear();
      window.draw(getActivePage());
      window.display();
   }

   return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guessingPage.hpp"
#include "settingsPage.hpp"


void setActivePage(PageId page_id);
Page& getActivePage();
void pollEvents(sf::RenderWindow& window);

const int WIDTH = 600;
const int HEIGHT = 600;

PageId activePage = SETTINGS;
GuessingPage guessing_page(WIDTH, HEIGHT, setActivePage);
SettingsPage settings_page(WIDTH, HEIGHT, setActivePage);

Page& getActivePage()
{
   if (activePage == SETTINGS) return settings_page;
   return guessing_page;
}

void setActivePage(PageId page_id)
{
   activePage = page_id;
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
         getActivePage().mouseMoved({static_cast<float>(event.mouseMove.x),static_cast<float>(event.mouseMove.y)});
         break;
      case sf::Event::MouseButtonPressed:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         getActivePage().mouseDown({static_cast<float>(event.mouseButton.x),static_cast<float>(event.mouseButton.y)});
         break;
      case sf::Event::MouseButtonReleased:
         if (event.mouseButton.button != sf::Mouse::Button::Left) break;
         getActivePage().mouseUp({static_cast<float>(event.mouseButton.x),static_cast<float>(event.mouseButton.y)});
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

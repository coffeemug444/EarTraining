#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "guessingPage.hpp"
#include "settingsPage.hpp"
#include "resources.hpp"

void setActivePage(PageId page_id);
Page& getActivePage();
void pollEvents(sf::RenderWindow& window, sf::Cursor& cursor);

const int WIDTH = 300;
const int HEIGHT = 300;

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
   if (page_id == GUESSING)
   {
      std::vector<Interval> intervals = settings_page.getSelectedIntervals();
      if (intervals.empty()) return;

      std::vector<Direction> directions = settings_page.getSelectedDirections();
      if (directions.empty()) return;

      guessing_page.setAvailableIntervals(intervals);
      guessing_page.setAvailableDirections(directions);
      guessing_page.selectNewInterval();
   }

   activePage = page_id;
}

void pollEvents(sf::RenderWindow& window, sf::Cursor& cursor)
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
         cursor.loadFromSystem(
            getActivePage().mouseMoved({static_cast<float>(event.mouseMove.x),static_cast<float>(event.mouseMove.y)})
         );
         window.setMouseCursor(cursor);
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
   sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ear Training", sf::Style::Titlebar | sf::Style::Close);
   sf::Cursor cursor;
   cursor.loadFromSystem(sf::Cursor::Arrow);
   window.setMouseCursor(cursor);
   window.setFramerateLimit(60);

   Resources::init();

   while (window.isOpen())
   {
      pollEvents(window, cursor);

      window.clear();
      window.draw(getActivePage());
      window.display();
   }

   return 0;
}

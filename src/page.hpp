#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

enum PageId {
   SETTINGS,
   GUESSING
};

class Page : public sf::Drawable
{
public:
   Page(int widgth, int height, std::function<void(PageId)> switch_page)
      :WIDTH(widgth)
      ,HEIGHT(height)
      ,m_switch_page(switch_page)
   {}

   virtual void MouseMoved(const sf::Vector2f&) {}
   virtual void MouseDown(const sf::Vector2f&) {}
   virtual void MouseUp(const sf::Vector2f&) {}

protected:

   const int WIDTH;
   const int HEIGHT;
   const std::function<void(PageId)> m_switch_page;
};
#pragma once
#include <SFML/Graphics.hpp>

enum PageId {
   SETTINGS,
   GUESSING
};

class Page : public sf::Drawable
{
public:
   Page(int widgth, int height)
      :WIDTH(widgth)
      ,HEIGHT(height)
   {}

   virtual void MouseMoved(const sf::Vector2f&) {}
   virtual void MouseDown(const sf::Vector2f&) {}
   virtual void MouseUp(const sf::Vector2f&) {}

protected:

   const int WIDTH;
   const int HEIGHT;
};
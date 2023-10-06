#pragma once
#include <SFML/Graphics.hpp>


class Button : sf::Drawable
{
public:
   Button(int width, int height)
      :WIDTH(width)
      ,HEIGHT(height)
   {}
   void mouseDown(const sf::Vector2f& pos);
   void mouseUp(const sf::Vector2f& pos);
   bool mouseIsOver(const sf::Vector2f& pos);
   void setPos(const sf::Vector2f& pos) { m_position = pos; }

protected:
   virtual void onClicked() {}

   const int WIDTH;
   const int HEIGHT;

   sf::Vector2f m_position;

private:
   bool m_was_pressed = false;
};
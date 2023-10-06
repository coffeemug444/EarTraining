#include "button.hpp"

void Button::setSize(int width, int height)
{
   WIDTH = width;
   HEIGHT = height;
   setSizeHook(width, height);
}

void Button::mouseDown(const sf::Vector2f &pos)
{
   m_was_pressed = mouseIsOver(pos);
}

void Button::mouseUp(const sf::Vector2f& pos)
{
   if (mouseIsOver(pos) and m_was_pressed) onClicked();
}

bool Button::mouseIsOver(const sf::Vector2f& pos) const
{
   if (pos.x < m_position.x) return false;
   if (pos.x > m_position.x + WIDTH) return false;
   if (pos.y < m_position.y) return false;
   if (pos.y > m_position.y + HEIGHT) return false;
   
   return true;
}

void Button::setSizeHook(int, int) {}

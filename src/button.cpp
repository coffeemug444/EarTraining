#include "button.hpp"

void Button::setSize(int width, int height)
{
   WIDTH = width;
   HEIGHT = height;
   m_background.setSize(sf::Vector2f{static_cast<float>(width), static_cast<float>(height)});
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

void Button::setPos(const sf::Vector2f& pos) 
{ 
   m_position = pos; 
   m_background.setPosition(pos);
   setPosHook(pos); 
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
   target.draw(m_background);
   drawHook(target, states);
}

void Button::drawHook(sf::RenderTarget &, sf::RenderStates ) const {}

void Button::setSizeHook(int, int) {}

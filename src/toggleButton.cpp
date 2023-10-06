#include "toggleButton.hpp"


ToggleButton::ToggleButton()
{
   m_background.setFillColor(sf::Color::Red); // temporary
}

void ToggleButton::setSizeHook(int width, int height)
{
   m_background.setSize(sf::Vector2f{static_cast<float>(width), static_cast<float>(height)});
}

void ToggleButton::setPosHook(const sf::Vector2f &pos)
{
   m_background.setPosition(pos);
}

void ToggleButton::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   // std::cout << "Drawing toggle button\n";
   target.draw(m_background);
}
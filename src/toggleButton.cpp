#include "toggleButton.hpp"


ToggleButton::ToggleButton()
{
   m_background.setFillColor(sf::Color::Red); // temporary
}


void ToggleButton::toggle(bool on)
{
   m_toggled = on;
   m_background.setFillColor(on ? m_fill_color : m_toggled_fill_color);
}
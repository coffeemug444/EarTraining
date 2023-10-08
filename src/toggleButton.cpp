#include "toggleButton.hpp"


ToggleButton::ToggleButton(const std::string& name)
   :Button(name)
{
   m_background.setFillColor(sf::Color::Red); // temporary
}


void ToggleButton::toggle(bool on)
{
   m_toggled = on;
   m_background.setFillColor(on ? m_fill_color : m_toggled_fill_color);
}
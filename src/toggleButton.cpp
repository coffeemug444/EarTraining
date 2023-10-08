#include "toggleButton.hpp"


ToggleButton::ToggleButton(const std::string& name)
   :Button(name)
{
}


void ToggleButton::toggle(bool on)
{
   m_toggled = on;
   m_background.setFillColor(on ? m_toggled_fill_color : m_fill_color);
}
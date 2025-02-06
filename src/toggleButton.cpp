#include "toggleButton.hpp"


ToggleButton::ToggleButton(const std::string& name, const int font_size)
   :Button(name, font_size)
{
}


void ToggleButton::toggle(bool on)
{
   m_toggled = on;
   m_background.setFillColor(on ? m_toggled_fill_color : m_fill_color);
}
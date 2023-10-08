#pragma once
#include "button.hpp"

#include <iostream>

class ToggleButton : public Button
{
public:
   ToggleButton(const std::string& name);
   void setToggledFillColor(const sf::Color& color) { m_toggled_fill_color = color; }
   bool isToggled() const { return m_toggled; }
   void onClicked() override { toggle(!m_toggled); }
   void reset() { toggle(false); }

   
private:
   void toggle(bool on);

   bool m_toggled = false;
   sf::Color m_toggled_fill_color;
};
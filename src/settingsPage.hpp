#pragma once
#include "page.hpp"
#include "toggleButton.hpp"

class SettingsPage : public Page
{
public:
   SettingsPage(int widgth, int height)
      :Page(widgth, height)
   {
   }
   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
};
#pragma once
#include "page.hpp"
#include "toggleButton.hpp"

class SettingsPage : public Page
{
public:
   SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page)
      :Page(widgth, height, switch_page)
   {
   }
   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
};
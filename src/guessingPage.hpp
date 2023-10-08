#pragma once
#include "page.hpp"

class GuessingPage : public Page
{
public:
   GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page)
      :Page(widgth, height, switch_page)
   {}
   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
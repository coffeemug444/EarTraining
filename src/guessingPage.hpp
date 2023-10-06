#pragma once
#include "page.hpp"

class GuessingPage : public Page
{
public:
   GuessingPage(int widgth, int height)
      :Page(widgth, height)
   {}
   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
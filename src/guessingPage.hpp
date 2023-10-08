#pragma once
#include "page.hpp"
#include "standardButton.hpp"

class GuessingPage : public Page
{
public:
   GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page);

   virtual void mouseMoved(const sf::Vector2f&) override;
   virtual void mouseDown(const sf::Vector2f&) override;
   virtual void mouseUp(const sf::Vector2f&) override;

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
   StandardButton m_button_next;
};
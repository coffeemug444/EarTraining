#pragma once
#include "page.hpp"
#include "toggleButton.hpp"
#include "standardButton.hpp"

class SettingsPage : public Page
{
public:
   SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page);

   virtual void mouseMoved(const sf::Vector2f&) override;
   virtual void mouseDown(const sf::Vector2f&) override;
   virtual void mouseUp(const sf::Vector2f&) override;

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
   StandardButton m_button_next;
   ToggleButton m_a_button;
};
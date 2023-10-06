#pragma once
#include "button.hpp"


class ToggleButton : public Button
{
public:
   ToggleButton();
   
   void setSizeHook(int width, int height) override;
   void setPosHook(const sf::Vector2f& pos) override;
   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
   sf::RectangleShape m_background;
};
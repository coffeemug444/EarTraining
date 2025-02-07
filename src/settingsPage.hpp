#pragma once
#include "page.hpp"
#include "toggleButton.hpp"
#include "standardButton.hpp"
#include "enums.hpp"
#include <array>

class SettingsPage : public Page
{
public:
   SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page);

   virtual sf::Cursor::Type mouseMoved(const sf::Vector2f&) override;
   virtual void mouseDown(const sf::Vector2f&) override;
   virtual void mouseUp(const sf::Vector2f&) override;

   std::vector<Interval> getSelectedIntervals() const;
   std::vector<Direction> getSelectedDirections() const;

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
   StandardButton m_button_next;
   ToggleButton m_1;
   ToggleButton m_2;
   ToggleButton m_3;
   ToggleButton m_4;
   ToggleButton m_5;
   ToggleButton m_6;
   ToggleButton m_7;
   ToggleButton m_8;
   ToggleButton m_9;
   ToggleButton m_10;
   ToggleButton m_11;

   ToggleButton m_ascending;
   ToggleButton m_descending;
   ToggleButton m_simultaneous;

   std::array<std::reference_wrapper<ToggleButton>, 14> m_toggle_buttons;
};
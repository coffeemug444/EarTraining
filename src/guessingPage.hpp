#pragma once
#include "page.hpp"
#include "standardButton.hpp"
#include "enums.hpp"
#include <SFML/Audio.hpp>

class GuessingPage : public Page
{
public:
   GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page);

   sf::Cursor::Type mouseMoved(const sf::Vector2f&) override;
   void mouseDown(const sf::Vector2f&) override;
   void mouseUp(const sf::Vector2f&) override;

   void setAvailableIntervals(const std::vector<Interval>& intervals);
   void selectNewInterval();
   void revealIntervalDescription();

   void playInterval();
   void stopInterval();

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
   StandardButton m_button_back;
   StandardButton m_button_next;
   StandardButton m_button_reveal;
   StandardButton m_button_repeat;
   sf::Text m_interval_description;
   Interval m_current_interval;
   std::vector<Interval> m_intervals;

   sf::SoundBuffer m_buffer1;
   sf::SoundBuffer m_buffer2;

   sf::Sound m_sound1;
   sf::Sound m_sound2;
};
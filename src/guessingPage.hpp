#pragma once
#include "page.hpp"
#include "standardButton.hpp"
#include "tones.hpp"

class GuessingPage : public Page
{
public:
   GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page);

   virtual void mouseMoved(const sf::Vector2f&) override;
   virtual void mouseDown(const sf::Vector2f&) override;
   virtual void mouseUp(const sf::Vector2f&) override;

   void setAvailableTones(const std::vector<Tone>& tones);
   void selectNewTone();
   void revealToneDescription();

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
   StandardButton m_button_back;
   StandardButton m_button_next;
   StandardButton m_button_reveal;
   sf::Text m_tone_description;
   Tone m_current_tone;
   std::vector<Tone> m_tones;

   int m_tone1 = 0;
   int m_tone2 = 0;
};
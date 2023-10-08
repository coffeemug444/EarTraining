#pragma once
#include "page.hpp"
#include "standardButton.hpp"
#include "tones.hpp"
#include <SFML/Audio.hpp>

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

   void playTones();
   void stopTones();

   void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
   StandardButton m_button_back;
   StandardButton m_button_next;
   StandardButton m_button_reveal;
   StandardButton m_button_repeat;
   sf::Text m_tone_description;
   Tone m_current_tone;
   std::vector<Tone> m_tones;

   sf::SoundBuffer m_buffer1;
   sf::SoundBuffer m_buffer2;

   sf::Sound m_sound1;
   sf::Sound m_sound2;
};
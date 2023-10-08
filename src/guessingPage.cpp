#include "guessingPage.hpp"

GuessingPage::GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page)
   :Page(widgth, height, switch_page)
   ,m_button_next("Back", [this](){ this->m_switch_page(SETTINGS); })
{
   m_button_next.setFillColor(sf::Color::Green);
   m_button_next.setSize(widgth/2.f, height/2.f);
   m_button_next.setPos({widgth/4.f, height/4.f});
}

void GuessingPage::mouseMoved(const sf::Vector2f&)
{
   
}

void GuessingPage::mouseDown(const sf::Vector2f &pos)
{
   m_button_next.mouseDown(pos);
}

void GuessingPage::mouseUp(const sf::Vector2f &pos)
{
   m_button_next.mouseUp(pos);
}

void GuessingPage::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   target.draw(m_button_next);
}
#include "settingsPage.hpp"

SettingsPage::SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page)
   :Page(widgth, height, switch_page)
   ,m_button_next("Next", [this](){ this->m_switch_page(GUESSING); })
   ,m_a_button("Test")
{
   m_button_next.setFillColor(sf::Color::Red);
   m_button_next.setSize(widgth/2.f, height/2.f);
   m_button_next.setPos({widgth/4.f, height/4.f});


   m_a_button.setSize(widgth/4, height/4);
   m_a_button.setFillColor(sf::Color::Blue);
   m_a_button.setToggledFillColor(sf::Color::Cyan);
}

void SettingsPage::mouseMoved(const sf::Vector2f&)
{
   
}

void SettingsPage::mouseDown(const sf::Vector2f &pos)
{
   m_button_next.mouseDown(pos);
   m_a_button.mouseDown(pos);
}

void SettingsPage::mouseUp(const sf::Vector2f &pos)
{
   m_button_next.mouseUp(pos);
   m_a_button.mouseUp(pos);
}

void SettingsPage::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   target.draw(m_button_next);
   target.draw(m_a_button);
}
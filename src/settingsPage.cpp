#include "settingsPage.hpp"

SettingsPage::SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page)
   :Page(widgth, height, switch_page)
   ,m_button_next([this](){ this->m_switch_page(GUESSING); })
{
   m_button_next.setFillColor(sf::Color::Red);
   m_button_next.setSize(widgth/2, height/2);
   m_button_next.setPos({widgth/4, height/4});
}

void SettingsPage::mouseMoved(const sf::Vector2f&)
{
   
}

void SettingsPage::mouseDown(const sf::Vector2f &pos)
{
   m_button_next.mouseDown(pos);
}

void SettingsPage::mouseUp(const sf::Vector2f &pos)
{
   m_button_next.mouseUp(pos);
}

void SettingsPage::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   target.draw(m_button_next);
}
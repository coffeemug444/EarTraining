#include "settingsPage.hpp"
#include "resources.hpp"
#include <algorithm>

SettingsPage::SettingsPage(int widgth, int height, std::function<void(PageId)> switch_page)
   :Page(widgth, height, switch_page)
   ,m_button_next("Next", [this](){ this->m_switch_page(GUESSING); }, height * Resources::TEXT_RATIO)
   ,m_1("Minor second",   height * Resources::TEXT_RATIO)
   ,m_2("Major second",   height * Resources::TEXT_RATIO)
   ,m_3("Minor third",    height * Resources::TEXT_RATIO)
   ,m_4("Major third",    height * Resources::TEXT_RATIO)
   ,m_5("Perfect fourth", height * Resources::TEXT_RATIO)
   ,m_6("Tritone",        height * Resources::TEXT_RATIO)
   ,m_7("Perfect fifth",  height * Resources::TEXT_RATIO)
   ,m_8("Minor sixth",    height * Resources::TEXT_RATIO)
   ,m_9("Major sixth",    height * Resources::TEXT_RATIO)
   ,m_10("Minor seventh", height * Resources::TEXT_RATIO)
   ,m_11("Major seventh", height * Resources::TEXT_RATIO)
   ,m_toggle_buttons{m_1,m_2,m_3,m_4,m_5,m_6,m_7,m_8,m_9,m_10,m_11}
{

   float button_w = widgth/3.f;
   float button_h = height/8.f;
   float w_padding = ((widgth - 2*button_w)/2.f)/2.f; // 2 columns
   float h_padding = ((height - 6*button_h)/6.f)/2.f; // 6 rows

   float button_total_w = button_w + 2*w_padding;
   float button_total_h = button_h + 2*h_padding;

   for (int i = 0; i < 6; i++)
   {
      ToggleButton& button = m_toggle_buttons.at(i);
      button.setSize(button_w, button_h);
      button.setFillColor(sf::Color::Blue);
      button.setToggledFillColor(sf::Color::Cyan);
      button.setPos({w_padding, i*button_total_h + h_padding});
   }
   for (int i = 6; i < 11; i++)
   {
      ToggleButton& button = m_toggle_buttons.at(i);
      button.setSize(button_w, button_h);
      button.setFillColor(sf::Color::Blue);
      button.setToggledFillColor(sf::Color::Cyan);
      button.setPos({button_total_w+w_padding, (i-6)*button_total_h + h_padding});
   }

   m_button_next.setFillColor(sf::Color::Red);
   m_button_next.setSize(button_w, button_h);
   m_button_next.setPos({button_total_w+w_padding,5*button_total_h + h_padding});
}

sf::Cursor::Type SettingsPage::mouseMoved(const sf::Vector2f& pos)
{
   auto fn = std::bind(std::mem_fn(&Button::mouseIsOver), std::placeholders::_1, pos);
   if (m_button_next.mouseIsOver(pos) or std::ranges::any_of(m_toggle_buttons, fn))
   {
      return sf::Cursor::Hand;
   }
   
   return sf::Cursor::Arrow;
}

void SettingsPage::mouseDown(const sf::Vector2f &pos)
{
   m_button_next.mouseDown(pos);
   for (ToggleButton& button : m_toggle_buttons) button.mouseDown(pos);
}

void SettingsPage::mouseUp(const sf::Vector2f &pos)
{
   m_button_next.mouseUp(pos);
   for (ToggleButton& button : m_toggle_buttons) button.mouseUp(pos);
}

std::vector<Interval> SettingsPage::getSelectedIntervals() const
{
   std::vector<Interval> selected_intervals;
   using enum Interval;
   if (m_1.isToggled())  selected_intervals.push_back(MINOR_SECOND);
   if (m_2.isToggled())  selected_intervals.push_back(MAJOR_SECOND);
   if (m_3.isToggled())  selected_intervals.push_back(MINOR_THIRD);
   if (m_4.isToggled())  selected_intervals.push_back(MAJOR_THIRD);
   if (m_5.isToggled())  selected_intervals.push_back(PERFECT_FOURTH);
   if (m_6.isToggled())  selected_intervals.push_back(TRITONE);
   if (m_7.isToggled())  selected_intervals.push_back(PERFECT_FIFTH);
   if (m_8.isToggled())  selected_intervals.push_back(MINOR_SIXTH);
   if (m_9.isToggled())  selected_intervals.push_back(MAJOR_SIXTH);
   if (m_10.isToggled()) selected_intervals.push_back(MINOR_SEVENTH);
   if (m_11.isToggled()) selected_intervals.push_back(MAJOR_SEVENTH);

   return selected_intervals;
}

void SettingsPage::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   target.draw(m_button_next);
   for (ToggleButton& button : m_toggle_buttons) target.draw(button);
}
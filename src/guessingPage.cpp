#include "guessingPage.hpp"
#include "resources.hpp"
#include <random>
#include <sstream>

GuessingPage::GuessingPage(int widgth, int height, std::function<void(PageId)> switch_page)
   :Page(widgth, height, switch_page)
   ,m_button_back("Back", [this](){ this->stopInterval(); this->m_switch_page(SETTINGS); }, height * Resources::TEXT_RATIO)
   ,m_button_next("Next", [this](){ this->selectNewInterval(); }, height * Resources::TEXT_RATIO)
   ,m_button_reveal("Reveal", [this](){ this->revealIntervalDescription(); }, height * Resources::TEXT_RATIO)
   ,m_button_repeat("Repeat", [this](){ this->playInterval(); }, height * Resources::TEXT_RATIO)
   ,m_interval_description("", Resources::font, height * Resources::TEXT_RATIO)
{
   m_sound1.setBuffer(m_buffer1);
   m_sound2.setBuffer(m_buffer2);

   float button_w = widgth/3.f;
   float button_h = height/8.f;
   float w_padding = ((widgth - 2*button_w)/2.f)/2.f; // 2 columns
   float h_padding = ((height - 6*button_h)/6.f)/2.f; // 6 rows

   m_button_back.setFillColor(sf::Color::Red);
   m_button_back.setSize(button_w, button_h);
   m_button_back.setPos({w_padding, h_padding});

   m_button_next.setFillColor(sf::Color::Green);
   m_button_next.setSize(button_w, button_h);
   m_button_next.setPos({WIDTH - button_w - w_padding, HEIGHT - button_h - h_padding});

   m_button_reveal.setFillColor(sf::Color::Blue);
   m_button_reveal.setSize(button_w, button_h);
   m_button_reveal.setPos({w_padding, (HEIGHT -button_h)/2.f});

   m_button_repeat.setFillColor(sf::Color::Blue);
   m_button_repeat.setSize(button_w, button_h);
   m_button_repeat.setPos({w_padding, HEIGHT - button_h - h_padding});

   m_interval_description.setPosition({WIDTH/2.F + w_padding, (HEIGHT - button_h)/2.f});
}

sf::Cursor::Type GuessingPage::mouseMoved(const sf::Vector2f& pos)
{
   if (m_button_back.mouseIsOver(pos)) return sf::Cursor::Hand;
   if (m_button_next.mouseIsOver(pos)) return sf::Cursor::Hand;
   if (m_button_reveal.mouseIsOver(pos)) return sf::Cursor::Hand;
   if (m_button_repeat.mouseIsOver(pos)) return sf::Cursor::Hand;
   return sf::Cursor::Arrow;
}

void GuessingPage::mouseDown(const sf::Vector2f &pos)
{
   m_button_back.mouseDown(pos);
   m_button_next.mouseDown(pos);
   m_button_reveal.mouseDown(pos);
   m_button_repeat.mouseDown(pos);
}

void GuessingPage::mouseUp(const sf::Vector2f &pos)
{
   m_button_back.mouseUp(pos);
   m_button_next.mouseUp(pos);
   m_button_reveal.mouseUp(pos);
   m_button_repeat.mouseUp(pos);
}

void GuessingPage::setAvailableIntervals(const std::vector<Interval>& intervals)
{
   m_intervals = intervals;
}

void GuessingPage::setAvailableDirections(const std::vector<Direction>& directions)
{
   m_directions = directions;
}

void GuessingPage::selectNewInterval()
{
   static std::random_device dev;
   static std::mt19937 rng(dev());

   m_interval_description.setString("");

   std::uniform_int_distribution<std::mt19937::result_type> intervals_dist(0,m_intervals.size()-1);

   m_current_interval = m_intervals.at(intervals_dist(rng));
   std::uniform_int_distribution<std::mt19937::result_type> samples_dist(1,28 - (int)m_current_interval);

   int tone1 = samples_dist(rng);
   int tone2 = tone1 + (int)m_current_interval;

   std::stringstream filepath_ss;

   filepath_ss << "resources/samples/" << std::to_string(tone1) << ".wav";
   m_buffer1.loadFromFile(filepath_ss.str());

   filepath_ss.str(std::string());
   filepath_ss << "resources/samples/" << std::to_string(tone2) << ".wav";
   m_buffer2.loadFromFile(filepath_ss.str());

   std::uniform_int_distribution<std::mt19937::result_type> directions_dist(0,m_directions.size()-1);
   Direction direction = m_directions.at(directions_dist(rng));

   switch (direction) {
   case Direction::ASCENDING:
      insertSilence(m_buffer2, sf::seconds(1));
      break;
   case Direction::DESCENDING:
      insertSilence(m_buffer1, sf::seconds(1));
      break;
   case Direction::SIMULTANEOUS:
   default:
      break;
   }

   playInterval();
}

void GuessingPage::revealIntervalDescription()
{
   m_interval_description.setString([this]() -> std::string {
   switch (m_current_interval)
   {
   using enum Interval;
   case MINOR_SECOND:   return "Minor second";
   case MAJOR_SECOND:   return "Major second";
   case MINOR_THIRD:    return "Minor third";
   case MAJOR_THIRD:    return "Major third";
   case PERFECT_FOURTH: return "Perfect fourth";
   case TRITONE:        return "Tritone";
   case PERFECT_FIFTH:  return "Perfect fifth";
   case MINOR_SIXTH:    return "Minor sixth";
   case MAJOR_SIXTH:    return "Major sixth";
   case MINOR_SEVENTH:  return "Minor seventh";
   case MAJOR_SEVENTH:  return "Major seventh";
   default: return "";
   }}());
}

void GuessingPage::stopInterval()
{
   m_sound1.stop();
   m_sound2.stop();
}

void GuessingPage::playInterval()
{
   stopInterval();

   m_sound1.play();
   m_sound2.play();
}

void GuessingPage::draw(sf::RenderTarget &target, sf::RenderStates ) const
{
   target.draw(m_button_back);
   target.draw(m_button_next);
   target.draw(m_button_reveal);
   target.draw(m_button_repeat);
   target.draw(m_interval_description);
}


void GuessingPage::insertSilence(sf::SoundBuffer& buffer, sf::Time duration)
{
   std::vector<sf::Int16> samples(buffer.getSamples(), std::next(buffer.getSamples(), buffer.getSampleCount()));
   size_t silent_sample_count = (1000.f / duration.asMilliseconds()) * buffer.getSampleRate() * buffer.getChannelCount();
   std::vector<sf::Int16> silent_samples(silent_sample_count, 0);
   
   samples.insert(std::begin(samples), std::begin(silent_samples), std::end(silent_samples));

   buffer.loadFromSamples(samples.data(), samples.size(), buffer.getChannelCount(), buffer.getSampleRate());
}
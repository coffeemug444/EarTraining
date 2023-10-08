#pragma once
#include <SFML/Graphics.hpp>


class Button : public sf::Drawable
{
public:
   Button(const std::string& name);
   void setSize(int width, int height);
   void mouseDown(const sf::Vector2f& pos);
   void mouseUp(const sf::Vector2f& pos);
   bool mouseIsOver(const sf::Vector2f& pos) const;
   void setPos(const sf::Vector2f& pos);
   virtual void setFillColor(const sf::Color& color);
   void draw(sf::RenderTarget &target, sf::RenderStates ) const override;

protected:
   virtual void onClicked() {}
   virtual void setPosHook(const sf::Vector2f&) {};
   virtual void setSizeHook(int width, int height);
   virtual void drawHook(sf::RenderTarget &target, sf::RenderStates ) const;
   sf::Font& getFont();


   sf::Text m_name;
   sf::Vector2f m_position;
   sf::RectangleShape m_background;
   sf::Color m_fill_color;

   static inline bool FONT_AVAILABLE = false;
   static inline sf::Font FONT;


private:
   int WIDTH = 0;
   int HEIGHT = 0;
   bool m_was_pressed = false;
};
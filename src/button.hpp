#pragma once
#include <SFML/Graphics.hpp>


class Button : public sf::Drawable
{
public:
   Button(){}
   void setSize(int width, int height);
   void mouseDown(const sf::Vector2f& pos);
   void mouseUp(const sf::Vector2f& pos);
   bool mouseIsOver(const sf::Vector2f& pos) const;
   void setPos(const sf::Vector2f& pos) { m_position = pos; setPosHook(pos); }

protected:
   virtual void onClicked() {}
   virtual void setPosHook(const sf::Vector2f&) {};
   virtual void setSizeHook(int width, int height);



   sf::Vector2f m_position;

private:
   int WIDTH = 0;
   int HEIGHT = 0;
   bool m_was_pressed = false;
};
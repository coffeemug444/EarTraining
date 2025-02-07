#pragma once
#include <SFML/Graphics.hpp>

class Resources
{
public:
   static void init()
   {
      font.loadFromFile("resources/Rubik-VariableFont_wght.ttf");
   }

   inline static sf::Font font;
   inline static const float TEXT_RATIO = 1/20.f;
};

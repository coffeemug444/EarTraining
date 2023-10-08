#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>


class Resources
{
public:
   static void init()
   {
      font.loadFromFile("Rubik-VariableFont_wght.ttf");
   }

   inline static sf::Font font;
};

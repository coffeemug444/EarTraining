#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;

    buffer1.loadFromFile("samples/17.wav");
    buffer2.loadFromFile("samples/16.wav");

    sf::Sound sound1;
    sf::Sound sound2;

    sound1.setBuffer(buffer1);
    sound2.setBuffer(buffer2);

    sound1.play();
    sound2.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

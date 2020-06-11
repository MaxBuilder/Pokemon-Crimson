#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!", sf::Style::Close);
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Red);

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

    std::cout << "Coucou" << std::endl;
    return 1;
}


/*
#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Hello World!\n";

    std::ifstream test("data/Text.txt");
    if (test)
        std::cout << "oui!" << std::endl;
    else return -1;

    return 0;
}
*/
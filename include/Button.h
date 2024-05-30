#include "Widgets.h"

class Button {
    sf::Text text;
    sf::RectangleShape button;
public:
    Button() {}

    Button(std::string s, sf::Vector2f size, int char_size, sf::Color bg_color, sf::Color text_color, const sf::Font &font);

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    void setColor(sf::Color color);

    void setSize(sf::Vector2f size);

    void drawTo(sf::RenderWindow &window);

    void update(sf::RenderWindow &window);

    bool isMouseOver(sf::RenderWindow &window);
};

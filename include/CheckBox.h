#include "Widgets.h"

class CheckBox {
    sf::Texture image;
    sf::RectangleShape checkbox;
    bool is_enabled = false;
public:
    CheckBox() {}

    CheckBox(sf::Vector2f size, sf::Color bg_color);

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    void setColor(sf::Color color);

    void setSize(sf::Vector2f size);

    bool toggle();

    bool isEnabled();

    void drawTo(sf::RenderWindow &window);

    void update(sf::RenderWindow &window);

    bool isMouseOver(sf::RenderWindow &window);
};

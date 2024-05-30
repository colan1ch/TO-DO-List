#include "Widgets.h"

#define ESCAPE_KEY 36
#define DELETE_KEY 8
#define ENTER_KEY 58

class TextBox{
    std::string text;
    bool is_selected;
    int limit;
    sf::Text textbox;
public:
    TextBox() : text(""), is_selected(false), limit(100) {}

    TextBox(int size, sf::Color color, bool _is_selected, const sf::Font &font);

    void inputText(sf::Event event);

    void deleteLastChar();

    void setPosition(sf::Vector2f pos);

    void setColor(sf::Color color);

    void setString(std::string str);

    std::string getString();

    sf::Vector2f getPosition();

    void drawTo(sf::RenderWindow &window);

    bool isMouseOver(sf::RenderWindow &window);

    void setActive();

    void setInactive();

    bool getActive();

    sf::Color getColor();
};

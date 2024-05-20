#include "Widgets.h"


class Button {
    sf::Text text;
    sf::RectangleShape button;
public:
    Button() {}

    Button(std::string s, sf::Vector2f size, int char_size, sf::Color bg_color, sf::Color text_color, const sf::Font &font) {
        text.setString(s);
        text.setColor(text_color);
        text.setCharacterSize(char_size);
        text.setFont(font);
        button.setSize(size);
        button.setFillColor(bg_color);
    }

    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);
        text.setPosition(pos.x + 4, pos.y + 7);
    }

    sf::Vector2f getPosition() {
        return button.getPosition();
    }

    void setColor(sf::Color color) {
        button.setFillColor(color);
    }

    void setSize(sf::Vector2f size) {
        button.setSize(size);
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }

    void update(sf::RenderWindow &window) {
        if (isMouseOver(window)) {
            if (button.getFillColor() == sf::Color::White) return;
            setColor(sf::Color::White);
            sf::Vector2f size = button.getSize();
            setSize({size.x - 2, size.y - 2});
            sf::Vector2f cur_pos = button.getPosition();
            setPosition({cur_pos.x + 1, cur_pos.y + 1});
        }
        else {
            if (button.getFillColor() == sf::Color::Green) return;
            setColor(sf::Color::Green);
            sf::Vector2f size = button.getSize();
            button.setSize({size.x + 2, size.y + 2});
            sf::Vector2f cur_pos = button.getPosition();
            button.setPosition({cur_pos.x - 1, cur_pos.y - 1});
        }
    }

    bool isMouseOver(sf::RenderWindow &window) {
        double mouseX = sf::Mouse::getPosition(window).x;
        double mouseY = sf::Mouse::getPosition(window).y;
        double btnPosX = button.getPosition().x;
        double btnPosY = button.getPosition().y;
        double btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        double btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;
        return (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY);
    }
};

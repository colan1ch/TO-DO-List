#include "Widgets.h"

class CheckBox {
    sf::Texture image;
    sf::RectangleShape checkbox;
    bool is_enabled = false;
public:
    CheckBox() {}

    CheckBox(sf::Vector2f size, sf::Color bg_color) {
        checkbox.setSize(size);
        checkbox.setFillColor(bg_color);
        image.create(size.x, size.y);
        image.loadFromFile("../files/empty.png");
        checkbox.setTexture(&image, true);
    }

    void setPosition(sf::Vector2f pos) {
        checkbox.setPosition(pos);
    }

    sf::Vector2f getPosition() {
        return checkbox.getPosition();
    }

    void setColor(sf::Color color) {
        checkbox.setFillColor(color);
    }

    void setSize(sf::Vector2f size) {
        checkbox.setSize(size);
    }

    bool toggle() {
        is_enabled = !is_enabled;
        if (is_enabled) {
            image.loadFromFile("../files/check_mark.png");
        }
        else {
            image.loadFromFile("../files/empty.png");
        }
        return is_enabled;
    }

    void drawTo(sf::RenderWindow &window) {
        checkbox.setTexture(&image, true);
        window.draw(checkbox);
    }

    void update(sf::RenderWindow &window) {
        if (isMouseOver(window)) {
            if (checkbox.getFillColor() == sf::Color::White) return;
            setColor(sf::Color::White);
            sf::Vector2f size = checkbox.getSize();
            setSize({size.x - 2, size.y - 2});
            sf::Vector2f cur_pos = checkbox.getPosition();
            setPosition({cur_pos.x + 1, cur_pos.y + 1});
        }
        else {
            if (checkbox.getFillColor() == sf::Color::Green) return;
            setColor(sf::Color::Green);
            sf::Vector2f size = checkbox.getSize();
            checkbox.setSize({size.x + 2, size.y + 2});
            sf::Vector2f cur_pos = checkbox.getPosition();
            checkbox.setPosition({cur_pos.x - 1, cur_pos.y - 1});
        }
    }

    bool isMouseOver(sf::RenderWindow &window) {
        double mouseX = sf::Mouse::getPosition(window).x;
        double mouseY = sf::Mouse::getPosition(window).y;
        double btnPosX = checkbox.getPosition().x;
        double btnPosY = checkbox.getPosition().y;
        double btnxPosWidth = checkbox.getPosition().x + checkbox.getLocalBounds().width;
        double btnyPosHeight = checkbox.getPosition().y + checkbox.getLocalBounds().height;
        return (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY);
    }
};

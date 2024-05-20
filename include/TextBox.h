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

    TextBox(int size, sf::Color color, bool _is_selected, const sf::Font &font) {
        textbox.setFont(font);
        textbox.setCharacterSize(size);
        textbox.setColor(color);
        textbox.setString('_');
        is_selected = _is_selected;
        limit = 100;
    }

    void inputText(sf::Event event) {
        char chr = static_cast<char>(event.text.unicode);
        if (chr < 128) {
            if (chr != DELETE_KEY && chr != ESCAPE_KEY && chr != ENTER_KEY) {
                text += chr;
            }
            else if (chr == DELETE_KEY) {
                if (text.size() > 0) {
                    deleteLastChar();
                }
            }
            textbox.setString(text + '_');
        }
    }

    void deleteLastChar() {
        text.pop_back();
        textbox.setString(text);
    }

    void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
    }

    void setColor(sf::Color color) {
        textbox.setColor(color);
    }

    sf::Vector2f getPosition() {
        return textbox.getPosition();
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(textbox);
    }

    bool isMouseOver(sf::RenderWindow &window) {
        double mouseX = sf::Mouse::getPosition(window).x;
        double mouseY = sf::Mouse::getPosition(window).y;
        double btnPosX = textbox.getPosition().x;
        double btnPosY = textbox.getPosition().y;
        double btnxPosWidth = textbox.getPosition().x + textbox.getLocalBounds().width;
        double btnyPosHeight = textbox.getPosition().y + textbox.getLocalBounds().height;
        return (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY);
    }

    void setActive() {
        is_selected = true;
        textbox.setString(text + '_');
    }

    void setInactive() {
        is_selected = false;
        textbox.setString(text);
    }

    bool getActive() {
        return is_selected;
    }

    sf::Color getColor() {
        return textbox.getColor();
    }
};

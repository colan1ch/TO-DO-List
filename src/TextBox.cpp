#include "Widgets.h"

TextBox::TextBox(int size, sf::Color color, bool _is_selected, const sf::Font &font) {
    textbox.setFont(font);
    textbox.setCharacterSize(size);
    textbox.setColor(color);
    textbox.setString('_');
    is_selected = _is_selected;
    limit = 100;
}

void TextBox::inputText(sf::Event event) {
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

void TextBox::deleteLastChar() {
    text.pop_back();
    textbox.setString(text);
}

void TextBox::setPosition(sf::Vector2f pos) {
    textbox.setPosition(pos);
}

void TextBox::setColor(sf::Color color){
    textbox.setColor(color);
}

sf::Vector2f TextBox::getPosition() {
    return textbox.getPosition();
}

void TextBox::drawTo(sf::RenderWindow &window) {
    window.draw(textbox);
}

bool TextBox::isMouseOver(sf::RenderWindow &window) {
    double mouseX = sf::Mouse::getPosition(window).x;
    double mouseY = sf::Mouse::getPosition(window).y;
    double btnPosX = textbox.getPosition().x;
    double btnPosY = textbox.getPosition().y;
    double btnxPosWidth = textbox.getPosition().x + textbox.getLocalBounds().width;
    double btnyPosHeight = textbox.getPosition().y + textbox.getLocalBounds().height;
    return (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY);
}

void TextBox::setActive() {
    is_selected = true;
    textbox.setString(text + '_');
}

void TextBox::setInactive() {
    is_selected = false;
    textbox.setString(text);
}

void TextBox::setString(std::string str) {
    text = str;
    textbox.setString(text);
}

std::string TextBox::getString() {
    return text;
}


bool TextBox::getActive(){
    return is_selected;
}

sf::Color TextBox::getColor()  {
    return textbox.getColor();
}

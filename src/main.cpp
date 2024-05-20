#include "Widgets.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "TO-DO List");
    sf::Font font;
    font.loadFromFile("../files/Comfortaa-Regular.ttf");

    sf::Text welcome_text("Enter your tasks:\n", font);
    welcome_text.setCharacterSize(20);
    welcome_text.setPosition({0, 10});

    Button add_task_btn("Add new task:", {100, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
    add_task_btn.setPosition({250, 10});

    CheckBox check_box1({30, 30}, sf::Color::Green);
    check_box1.setPosition({10, 40});
    std::vector<CheckBox> checkboxes;
    checkboxes.push_back(check_box1);

    TextBox task1(20, sf::Color::Yellow, true, font);
    task1.setPosition({120, 40});
    std::vector<TextBox> textboxes;
    int cur_tbox = 0;
    textboxes.push_back(task1);

    Button ok_btn1("OK", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
    ok_btn1.setPosition({90, 40});
    std::vector<Button> ok_buttons;
    ok_buttons.push_back(ok_btn1);

    Button del_btn1("Del", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
    del_btn1.setPosition({50, 40});
    std::vector<Button> del_buttons;
    del_buttons.push_back(del_btn1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (textboxes[cur_tbox].getActive()) {
                    textboxes[cur_tbox].inputText(event);
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.text.unicode == ESCAPE_KEY) {
                    window.close();
                }
                if (event.text.unicode == ENTER_KEY) {
                    textboxes[cur_tbox].setInactive();
                    cur_tbox = -1;
                }
            }

            if (event.type == sf::Event::MouseMoved) {
                for (auto &button : ok_buttons) {
                    button.update(window);
                }
                for (auto &button : del_buttons) {
                    button.update(window);
                }
                for (auto &checkbox : checkboxes) {
                    checkbox.update(window);
                }
                add_task_btn.update(window);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (cur_tbox == -1) {
                    for (int i = 0; i < textboxes.size(); i++) {
                        if (textboxes[i].isMouseOver(window)) {
                            textboxes[i].setActive();
                            cur_tbox = i;
                            break;
                        }
                    }
                }
                for (int i = 0; i < del_buttons.size(); i++) {
                    if (del_buttons[i].isMouseOver(window)) {
                        for (int j = del_buttons.size() - 1; j > i; j--) {
                            del_buttons[j].setPosition(del_buttons[j - 1].getPosition());
                            ok_buttons[j].setPosition(ok_buttons[j - 1].getPosition());
                            textboxes[j].setPosition(textboxes[j - 1].getPosition());
                            checkboxes[j].setPosition(checkboxes[j - 1].getPosition());
                        }
                        del_buttons.erase(del_buttons.begin() + i, del_buttons.begin() + i + 1);
                        ok_buttons.erase(ok_buttons.begin() + i, ok_buttons.begin() + i + 1);
                        textboxes.erase(textboxes.begin() + i, textboxes.begin() + i + 1);
                        checkboxes.erase(checkboxes.begin() + i, checkboxes.begin() + i + 1);
                        if (cur_tbox == i) {
                            cur_tbox = -1;
                        }
                        else if (cur_tbox > i) {
                            cur_tbox--;
                        }
                    }
                }
                if (ok_buttons[cur_tbox].isMouseOver(window)) {
                    textboxes[cur_tbox].setInactive();
                    cur_tbox = -1;
                }
                for (int i = 0; i < checkboxes.size(); i++) {
                    if (checkboxes[i].isMouseOver(window)) {
                        if (checkboxes[i].toggle()) {
                            textboxes[i].setColor(sf::Color::Green);
                        }
                        else {
                            textboxes[i].setColor(sf::Color::White);
                        }
                        textboxes[i].setInactive();
                        cur_tbox = -1;
                    }
                }
                if (add_task_btn.isMouseOver(window) && cur_tbox == -1) {
                    CheckBox check_box({30, 30}, sf::Color::Green);
                    sf::Vector2f prev_cb_pos(10, -10);
                    if (checkboxes.size() > 0) {
                        prev_cb_pos = checkboxes[checkboxes.size() - 1].getPosition();
                    }
                    check_box.setPosition({prev_cb_pos.x, prev_cb_pos.y + 50});
                    checkboxes.push_back(check_box);

                    Button btn("OK", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
                    sf::Vector2f prev_btn_pos(90, -10);
                    if (ok_buttons.size() > 0) {
                        prev_btn_pos = ok_buttons[ok_buttons.size() - 1].getPosition();
                    }
                    btn.setPosition({prev_btn_pos.x, prev_btn_pos.y + 50});
                    ok_buttons.push_back(btn);

                    Button del_btn("Del", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
                    sf::Vector2f prev_del_btn_pos(50, -10);
                    if (del_buttons.size() > 0) {
                        prev_del_btn_pos = del_buttons[del_buttons.size() - 1].getPosition();
                    }
                    del_btn.setPosition({prev_del_btn_pos.x, prev_del_btn_pos.y + 50});
                    del_buttons.push_back(del_btn);

                    TextBox tbox(20, sf::Color::Yellow, true, font);
                    sf::Vector2f prev_tbox_pos(120, -10);
                    if (textboxes.size() > 0) {
                        prev_tbox_pos = textboxes[textboxes.size() - 1].getPosition();
                    }
                    tbox.setPosition({prev_tbox_pos.x, prev_tbox_pos.y + 50});
                    textboxes.push_back(tbox);
                    cur_tbox = textboxes.size() - 1;
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(welcome_text);
        for (auto &textbox : textboxes) {
            if (textbox.getColor() != sf::Color::Green) {
                if (textbox.getActive()) {
                    textbox.setColor(sf::Color::Yellow);
                }
                else {
                    textbox.setColor(sf::Color::White);
                }
            }
            textbox.drawTo(window);
        }
        for (auto &button : ok_buttons) {
            button.drawTo(window);
        }
        for (auto &button : del_buttons) {
            button.drawTo(window);
        }
        for (auto &checkbox : checkboxes) {
            checkbox.drawTo(window);
        }
        add_task_btn.drawTo(window);
        window.display();
    }
    return 0;
}

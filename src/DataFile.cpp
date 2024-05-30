#include "Widgets.h"


void DataFile::readDB(std::vector<CheckBox> &checkboxes, std::vector<TextBox> &textboxes, int &cur_tbox, std::vector<Button> &ok_buttons, std::vector<Button> &del_buttons, const sf::Font &font) {
    std::ifstream fin(data->filename);
    CheckBox check_box1({30, 30}, sf::Color::Green);
    check_box1.setPosition({10, 40});
    checkboxes.push_back(check_box1);

    TextBox task1(20, sf::Color::Yellow, true, font);
    task1.setPosition({120, 40});
    cur_tbox = 0;
    textboxes.push_back(task1);

    Button ok_btn1("OK", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
    ok_btn1.setPosition({90, 40});
    ok_buttons.push_back(ok_btn1);

    Button del_btn1("Del", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
    del_btn1.setPosition({50, 40});
    del_buttons.push_back(del_btn1);
    if (fin.peek() == EOF) {
        fin.close();
        return;
    }

    int tasks_count;
    fin >> tasks_count;
    char status;
    std::string s;
    fin >> status;
    fin.ignore(1);
    getline(fin, s);
    if (status == 'y') {
        checkboxes[0].toggle();
        textboxes[0].setColor(sf::Color::Green);
    }
    textboxes[0].setString(s);
    for (int i = 1; i < tasks_count; i++) {
        fin >> status;
        fin.ignore(1);
        getline(fin, s);
        CheckBox check_box({30, 30}, sf::Color::Green);
        sf::Vector2f prev_cb_pos = checkboxes[checkboxes.size() - 1].getPosition();
        check_box.setPosition({prev_cb_pos.x, prev_cb_pos.y + 50});
        if (status == 'y') check_box.toggle();
        checkboxes.push_back(check_box);

        Button btn("OK", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
        sf::Vector2f prev_btn_pos = ok_buttons[ok_buttons.size() - 1].getPosition();
        btn.setPosition({prev_btn_pos.x, prev_btn_pos.y + 50});
        ok_buttons.push_back(btn);

        Button del_btn("Del", {30, 30}, 12, sf::Color::Green, sf::Color::Blue, font);
        sf::Vector2f prev_del_btn_pos = del_buttons[del_buttons.size() - 1].getPosition();
        del_btn.setPosition({prev_del_btn_pos.x, prev_del_btn_pos.y + 50});
        del_buttons.push_back(del_btn);

        TextBox tbox(20, sf::Color::White, false, font);
        tbox.setString(s);
        if (status == 'y') tbox.setColor(sf::Color::Green);
        sf::Vector2f prev_tbox_pos = textboxes[textboxes.size() - 1].getPosition();
        tbox.setPosition({prev_tbox_pos.x, prev_tbox_pos.y + 50});
        textboxes.push_back(tbox);
    }
    cur_tbox = -1;
    fin.close();
}


void DataFile::writeDB(std::vector<CheckBox> checkboxes, std::vector<TextBox> textboxes) {
    std::ofstream fout(data->filename);
    fout << checkboxes.size() << '\n';
    for (int i = 0; i < checkboxes.size(); i++) {
        if (checkboxes[i].isEnabled()) {
            fout << "y ";
        }
        else {
            fout << "n ";
        }
        fout << textboxes[i].getString() << '\n';
    }
    fout.close();
}

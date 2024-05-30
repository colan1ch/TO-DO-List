#include "Widgets.h"

class DataFile {
    std::string filename;
    static DataFile *data;

    DataFile() {}

    DataFile(std::string _filename) : filename(_filename) {}
public:
    static DataFile *init(std::string _filename) {
        if (!data) {
            data = new DataFile(_filename);
        }
        return data;
    }

    static void readDB(std::vector<CheckBox> &checkboxes, std::vector<TextBox> &textboxes, int &cur_tbox, std::vector<Button> &ok_buttons, std::vector<Button> &del_buttons, const sf::Font &font);

    static void writeDB(std::vector<CheckBox> checkboxes, std::vector<TextBox> textboxes);
};

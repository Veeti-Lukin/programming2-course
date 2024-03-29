#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onFindPress();

    bool find_substr(std::string str, std::string substr, bool match_case);
    bool read_file(const std::string &file_name, std::string &str_holder);
private:
    Ui::MainWindow *ui;

    // used for holding the the file in string format after reading the file
    std::string file_as_str = "";

    // convert given string *str* to lower case in place
    void to_lower(std::string &str);
};
#endif // MAINWINDOW_HH

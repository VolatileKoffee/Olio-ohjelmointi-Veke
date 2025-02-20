#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString number1, number2; // QString can be printed to QLineEdit
    int calcState = 0;      // state variable is needed to know which number is being given
    float calcResult;   // result is calculated when user presses enter
    short calcOperator;  // calcCalculator is stored when user presses +,-,*,/

private slots:
    void numberClickHandler(); // numbers 0-9
    void enterClickHandler(); // enter
    void clearClickHandler(); // clear
    void operatorClickHandler(); // operators +, -, * and /
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

public slots:
    void timeout(); // public slots is not necessary but increases readability. Included in QTimer

private:
    Ui::MainWindow *ui;
    short player1Time = 0;
    short player2Time = 0;
    short currentPlayer = 0;
    short gameTime = 0;
    QTimer * pQTimer; // pQTimer points to QTimer

    /* updateProgressBar method updates each progress bar according
     * to player1time-,player2Time- and gameTime-variables */
    void updateProgressBar();

    void setGameInfoText(QString, short); // prints game information to labelGame (short is font size)

private slots:
    void switchPlayerHandler();
    void timeHandler();
    void game1Handler();
    void game2Handler();
    void startHandler();
    void stopHandler();
};
#endif // MAINWINDOW_H

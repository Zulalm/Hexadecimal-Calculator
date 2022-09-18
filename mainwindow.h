#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    int number; // to store and display the given input
    int term1; // to store the first input and the result of the previous operation
    int term2; // to store the second input
    bool op; // it is true if an operator button was clicked
    bool add; // it is true if "+" button was clicked
    bool sub; // it is true if "-" button was clicked
public slots:
    void mydisplay(); // displays the stored number
    void shiftnum(const int &num); // updates the number
    void clear(); // resets the calculator
    void result(); // does arithmetic operations and displays the result
    void operation(const int &type); // updates the first term with the input and resets the number
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

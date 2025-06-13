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

    void addBook();
    void viewBooks();
    void searchBook();
    void filterBook();

    void addArticle();
    void viewArticles();       // ✅ ADDED
    void addThesis();
    void viewTheses();         // ✅ ADDED
    void addDigital();
    void registerUser();

    void borrowResource();
    void returnResource();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

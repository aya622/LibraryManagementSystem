#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 📘 Books
    connect(ui->pushButton_addBook, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(ui->pushButton_filterBook, &QPushButton::clicked, this, &MainWindow::viewBooks);
    connect(ui->pushButton_searchBook, &QPushButton::clicked, this, &MainWindow::searchBook);
    connect(ui->pushButton_filterBook, &QPushButton::clicked, this, &MainWindow::filterBook);

    // 📄 Articles
    connect(ui->pushButton_addArticle, &QPushButton::clicked, this, &MainWindow::addArticle);
    connect(ui->pushButton_viewArticles, &QPushButton::clicked, this, &MainWindow::viewArticles);

    // 🎓 Theses
    connect(ui->pushButton_addThesis, &QPushButton::clicked, this, &MainWindow::addThesis);
    connect(ui->pushButton_viewTheses, &QPushButton::clicked, this, &MainWindow::viewTheses);

    // 💾 Digital
    connect(ui->pushButton_addDigital, &QPushButton::clicked, this, &MainWindow::addDigital);

    // 👤 Users
    connect(ui->pushButton_registerUser, &QPushButton::clicked, this, &MainWindow::registerUser);

    // 🔁 Loans
    connect(ui->pushButton_borrow, &QPushButton::clicked, this, &MainWindow::borrowResource);
    connect(ui->pushButton_return, &QPushButton::clicked, this, &MainWindow::returnResource);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// =================== BOOKS ===================

void MainWindow::addBook() {
    QFile file("books.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->lineEdit_bookID->text() << "," << ui->lineEdit_title->text() << "," << ui->lineEdit_author->text() << "," << ui->lineEdit_year->text() << "," << ui->lineEdit_category->text() << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "Book added.");
    }
}

void MainWindow::viewBooks() {
    QFile file("books.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString content;
    while (!in.atEnd()) content += in.readLine() + "\n";
    file.close();
    QMessageBox::information(this, "All Books", content);
}

void MainWindow::searchBook() {
    QString keyword = ui->lineEdit_searchBook->text();
    QFile file("books.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString result;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains(keyword, Qt::CaseInsensitive))
            result += line + "\n";
    }
    QMessageBox::information(this, "Search Result", result.isEmpty() ? "No matches" : result);
}

void MainWindow::filterBook() {
    QString category = ui->lineEdit_filterBook->text();
    QFile file("books.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString result;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains(category, Qt::CaseInsensitive))
            result += line + "\n";
    }
    QMessageBox::information(this, "Filtered Books", result.isEmpty() ? "No matches" : result);
}

// =================== ARTICLES ===================

void MainWindow::addArticle() {
    QFile file("articles.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->lineEdit_articleID->text() << "," << ui->lineEdit_articleTitle->text() << "," << ui->lineEdit_articleAuthor->text() << "," << ui->lineEdit_articleYear->text() << "," << ui->lineEdit_doi->text() << "," << ui->lineEdit_journal->text() << "," << ui->lineEdit_articleCategory->text() << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "Article added.");
    }
}

void MainWindow::viewArticles() {
    QFile file("articles.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString content;
    while (!in.atEnd()) content += in.readLine() + "\n";
    file.close();
    QMessageBox::information(this, "All Articles", content);
}

// =================== THESES ===================

void MainWindow::addThesis() {
    QFile file("theses.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->lineEdit_thesisID->text() << "," << ui->lineEdit_thesisTitle->text() << "," << ui->lineEdit_thesisAuthor->text() << "," << ui->lineEdit_thesisYear->text() << "," << ui->lineEdit_university->text() << "," << ui->lineEdit_degree->text() << "," << ui->lineEdit_advisor->text() << "," << ui->lineEdit_thesisCategory->text() << "," << ui->lineEdit_thesisCategory->text() << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "Thesis added.");
    }
}

void MainWindow::viewTheses() {
    QFile file("theses.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString content;
    while (!in.atEnd()) content += in.readLine() + "\n";
    file.close();
    QMessageBox::information(this, "All Theses", content);
}

// =================== DIGITAL ===================

void MainWindow::addDigital() {
    QFile file("digital.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->lineEdit_digitalID->text() << "," << ui->lineEdit_digitalTitle->text() << "," << ui->lineEdit_digitalAuthor->text() << "," << ui->lineEdit_digitalYear->text() << "," << ui->lineEdit_format->text() << "," << ui->lineEdit_url->text() << "," << ui->lineEdit_fileSize->text() << "," << ui->lineEdit_digitalCategory->text() << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "Digital content added.");
    }
}

// =================== USERS ===================

void MainWindow::registerUser() {
    QFile file("users.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->lineEdit_userID->text() << "," << ui->lineEdit_userName->text() << "," << ui->lineEdit_email->text() << "," << ui->lineEdit_limit->text() << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "User registered.");
    }
}

// =================== LOANS ===================

void MainWindow::borrowResource() {
    QString userID = ui->lineEdit_loanUserID->text();
    QString resID = ui->lineEdit_loanResID->text();
    QFile file("loans.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << userID << "," << resID << "\n";
        file.close();
        QMessageBox::information(this, "Saved", "Resource borrowed.");
    }
}

void MainWindow::returnResource() {
    QString userID = ui->lineEdit_loanUserID->text();
    QString resID = ui->lineEdit_loanResID->text();

    QFile file("loans.csv");
    QFile temp("loans_temp.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text) &&
        temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream in(&file), out(&temp);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (!line.contains(userID + "," + resID))
                out << line << "\n";
        }
        file.close(); temp.close();
        file.remove(); temp.rename("loans.csv");
        QMessageBox::information(this, "Returned", "Resource returned.");
    }
}

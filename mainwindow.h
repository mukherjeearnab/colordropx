#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QColor tempColor;
    bool focus;
    void func();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_3_released();

    void on_pushButton_3_clicked();

    void on_pushButton_4_released();

    void on_lineEdit_textChanged(const QString &arg1);
    void RGBchanged();

    void on_lineEdit_R_textChanged(const QString &arg1);

    void on_lineEdit_G_textChanged(const QString &arg1);

    void on_lineEdit_B_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // MAINWINDOW_H

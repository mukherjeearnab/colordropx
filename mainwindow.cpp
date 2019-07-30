#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

#include <QColorDialog>
//#include <qDebug>
#include <QMessageBox>
#include <QScreen>
#include <QScreen>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    focus = true;
    tempColor.setRgb(255, 255, 255);
    ui->setupUi(this);
    setMouseTracking(true);
    qApp->installEventFilter(this);
    QPixmap pix(":/logo.png");
    ui->label_3->setPixmap(pix.scaled(98, 98));
    QPixmap pix2(":/binarytek.png");
    ui->pushButton_3->setIcon(pix2.scaled(64, 64, Qt::AspectRatioMode::KeepAspectRatio));
    //ui->lineEdit_2->stackUnder(ui->pushButton_4);
    connect(ui->lineEdit_R, SIGNAL(textEdited(QString)), this, SLOT(RGBchanged()));
    connect(ui->lineEdit_G, SIGNAL(textEdited(QString)), this, SLOT(RGBchanged()));
    connect(ui->lineEdit_B, SIGNAL(textEdited(QString)), this, SLOT(RGBchanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
        QPoint globalCursorPos = QCursor::pos();
        //qDebug() << globalCursorPos.x() << "-" << globalCursorPos.y();
        //if(!checked)
            //ui->pushButton->setStyleSheet("background-color: #cdcdcd; border: none; padding: 3px;");
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QRect r = geometry();
    QPoint globalCursorPos = QCursor::pos();
    int xx = globalCursorPos.x(), yy = globalCursorPos.y();

  if (event->type() == QEvent::MouseMove && ((xx < r.x() || xx > r.x() + 559)||(yy < r.y() || yy > r.y() + 252)) && focus) // && MainWindow::hasFocus()
  {
      QPoint globalCursorPos = QCursor::pos();
      int x = globalCursorPos.x(), y = globalCursorPos.y();
      QScreen *screen = QGuiApplication::primaryScreen();
          if (const QWindow *window = windowHandle())
              screen = window->screen();
      QPixmap pix = screen->grabWindow(0);
      QPixmap qPix = screen->grabWindow(0, x-7, y-7, 14, 14);
      ui->label_3->setPixmap(qPix.scaled(98, 98));//.scaled(11, 11));
      QImage image(pix.toImage());
      QColor color(image.pixel(x, y));
      //ui->pushButton->setStyleSheet("background-color: #75DA81; border: none; padding: 3px;");

      ui->pushButton_2->setStyleSheet("QPushButton { border: 1px solid #cdcdcd;   background-color: " + color.name() + "; }");
      ui->lineEdit->setText(color.name().toUpper());
      ui->lineEdit_R->setText(QString::number(tempColor.red()));
      ui->lineEdit_G->setText(QString::number(tempColor.green()));
      ui->lineEdit_B->setText(QString::number(tempColor.blue()));
      tempColor = color;
  }
  else {

  }
  return false;
}

void MainWindow::on_pushButton_3_released()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    about a;
    a.setModal(true);
    a.setWindowFlags(a.windowFlags() & ~Qt::WindowContextHelpButtonHint);
    a.exec();
}

void MainWindow::on_pushButton_4_released()
{
    focus = false;
    QColor color = QColorDialog::getColor(tempColor, this, "Edit Color", QColorDialog::DontUseNativeDialog);
        if( color.isValid() )
        {
          //qDebug() << "Color Choosen L: " << color.name();

          tempColor = color;

          //qDebug() << "Color Given L: " << tempColor.name();
          ui->pushButton_2->setStyleSheet("QPushButton { border: 1px solid #cdcdcd;   background-color: " + tempColor.name() + "; }");
          ui->lineEdit->setText(tempColor.name().toUpper());
          /*ui->lineEdit_R->setText(QString::number(tempColor.red()));
          ui->lineEdit_G->setText(QString::number(tempColor.green()));
          ui->lineEdit_B->setText(QString::number(tempColor.blue()));
          */focus = true;
        }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    //qDebug() << "HexChanged();";

    tempColor.setNamedColor(ui->lineEdit->text());

    //qDebug() << "Color Given H : " << tempColor.name();
    ui->pushButton_2->setStyleSheet("QPushButton { border: 1px solid #cdcdcd;   background-color: " + tempColor.name() + "; }");
    ui->lineEdit->setText(ui->lineEdit->text().toUpper());
    ui->lineEdit_R->setText(QString::number(tempColor.red()));
    ui->lineEdit_G->setText(QString::number(tempColor.green()));
    ui->lineEdit_B->setText(QString::number(tempColor.blue()));
}

void MainWindow::RGBchanged() {
    //qDebug() << "RGBchanged();";
    if(!ui->lineEdit->hasFocus()) {
        int R = ui->lineEdit_R->text().toInt(), G = ui->lineEdit_G->text().toInt(), B = ui->lineEdit_B->text().toInt();
        tempColor.setRgb(R, G, B);
        //qDebug() << "Color Given R: " << tempColor.name();
        ui->pushButton_2->setStyleSheet("QPushButton { border: 1px solid #cdcdcd;   background-color: " + tempColor.name() + "; }");
        ui->lineEdit->setText(tempColor.name().toUpper());
        ui->lineEdit_R->setText(QString::number(tempColor.red()));
        ui->lineEdit_G->setText(QString::number(tempColor.green()));
        ui->lineEdit_B->setText(QString::number(tempColor.blue()));
    }
}

void MainWindow::on_lineEdit_R_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_G_textChanged(const QString &arg1)
{

}

void MainWindow::on_lineEdit_B_textChanged(const QString &arg1)
{

}

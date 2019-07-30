#include "about.h"
#include "ui_about.h"

#include <QMessageBox>

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_3_clicked()
{
    QMessageBox::aboutQt(nullptr);
}

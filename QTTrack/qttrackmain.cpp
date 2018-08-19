#include "qttrackmain.h"
#include "ui_qttrackmain.h"
#include <QMessageBox>

QTTrackMain::QTTrackMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTTrackMain)
{
    ui->setupUi(this);
    QTTrackSetup();
}

QTTrackMain::~QTTrackMain()
{
    QTTrackTeardown();
    delete ui;
}

void QTTrackMain::QTTrackSetup(void)
{
    ui->WdgCalendar->setFocus();
    TimeTracker = std::make_unique<CTimeTrack>();
}

void QTTrackMain::QTTrackTeardown(void)
{
}

void QTTrackMain::on_MnuFileExit_triggered()
{
    QApplication::quit();
}

void QTTrackMain::on_MnuAboutAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("© 2018 Jochen Paul");
    msgBox.exec();
}

void QTTrackMain::on_MnuFileActionNew_triggered()
{
    // Start a new action
}

void QTTrackMain::on_BtnToday_clicked()
{
    // Select current day in calendar widget
    QDate dateToday = QDateTime::currentDateTime().date();
    ui->WdgCalendar->setSelectedDate(dateToday);
    ui->WdgCalendar->setFocus();
}

void QTTrackMain::on_BtnActionNew_clicked()
{
    // Start a new action
}

void QTTrackMain::on_BtnActionContinue_clicked()
{
    // Continue selected action
}

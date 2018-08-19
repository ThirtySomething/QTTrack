#ifndef QTTRACKMAIN_H
#define QTTRACKMAIN_H

#include <QMainWindow>
#include <memory>
#include "ctimetrack.h"

namespace Ui {
class QTTrackMain;
}

class QTTrackMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTTrackMain(QWidget *parent = nullptr);
    ~QTTrackMain();

private slots:
    void on_MnuFileExit_triggered();

    void on_MnuAboutAbout_triggered();

    void on_MnuFileActionNew_triggered();

    void on_BtnToday_clicked();

    void on_BtnActionNew_clicked();

    void on_BtnActionContinue_clicked();

private:
    Ui::QTTrackMain *ui;

    void QTTrackSetup(void);

    void QTTrackTeardown(void);

    std::unique_ptr<CTimeTrack> TimeTracker;
};

#endif // QTTRACKMAIN_H

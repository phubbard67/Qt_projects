#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

#define LINUX_PATH "/VaVaVaVideo"
#define WIND_PATH  "C:\\VaVaVaVideo\\"
#define INI_FILE   "video.ini"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString m_strMovieDir;
    QString m_strTVDir;
    QString m_iniFile;

private slots:
    void on_actionChange_Movie_Directory_triggered();
};
#endif // MAINWINDOW_H

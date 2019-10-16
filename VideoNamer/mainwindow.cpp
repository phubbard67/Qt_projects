#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "qdebug.h"
#include "qmessagebox.h"
#include "qfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_strMovieDir("N/A"),
      m_strTVDir("N/A")
{
    ui->setupUi(this);
    QDir iniDir("C:");
    if(iniDir.exists())
    {
        iniDir.setPath(WIND_PATH);
        if(iniDir.exists())
        {

        }
        else
        {
            iniDir.mkpath(WIND_PATH);
            m_iniFile = WIND_PATH;
            m_iniFile.append(INI_FILE);
            QFile file(m_iniFile);
            if(!file.exists())
            {
                if(file.open(QFile::WriteOnly))
                {
                    file.close();
                }
                else
                {
                    QMessageBox::warning(nullptr, "Could Not Create Settings", "There was an issue creating your settings. This is bad. Contact support.");
                    return;
                }

            }
        }
    }
    else
    {
        iniDir.setPath("/");
        if(iniDir.exists())
        {

        }
        else
        {
            QString path = "";
            while(path == "")
            {
                QMessageBox::warning(nullptr, "No Valid Root", "There is no valid root directory. Please select a directory in which you wish your settings to be stored.");
                path = QFileDialog::getExistingDirectory(this, "Select Root Directory", "");
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionChange_Movie_Directory_triggered()
{
    QFileDialog newFolder(this);
    newFolder.setFileMode(QFileDialog::DirectoryOnly);
    QUrl dir("/");
    m_strMovieDir = newFolder.getExistingDirectory(this, tr("Select Movie Folder"), "/");
    qDebug() << m_strMovieDir;
    ui->labelMovieDir->setText(m_strMovieDir);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include "chessboard.h"

class ToolBar;
QT_FORWARD_DECLARE_CLASS(QMenu)

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    chessboard m_chessboard;

public:
    MainWindow(QWidget *parent = nullptr);
    QHBoxLayout *H_layout;

};


#endif // MAINWINDOW_H

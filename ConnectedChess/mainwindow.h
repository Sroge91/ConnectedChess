#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QMessageBox>
#include "chessboard.h"
#include "fenetreloadfen.h"


class ToolBar;
QT_FORWARD_DECLARE_CLASS(QMenu)

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT
    QHBoxLayout *H_layout;
    chessboard* m_chessboard;
    QStandardItemModel *model;
    QLabel *m_trait;
    QHBoxLayout *Hboxlayout;
    QVBoxLayout *VRightBoxlayout;
public:
    MainWindow(QWidget *parent = nullptr);
    void setupChessboard();
    void pieceMove(int startSquare, int endSquare);
    void loadFEN(QString fen);
    void updateTrait();

public slots:
    void ouvrirFenetreLoadFEN();

};


#endif // MAINWINDOW_H

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include "piece.h"

class chessboard : public QWidget
{
    QLabel **m_square; //cases
    QLabel ***m_square2; //pieces
    QGridLayout* m_board;
    piece *m_piece[32];
    QString m_trait;
public:
    chessboard(QWidget *parent = nullptr);
    ~chessboard();

    void resetchessboard();
    void loadFEN(QString fen);
    QString getTrait();
};

#endif // CHESSBOARD_H

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

class chessboard : public QWidget
{
private:
    QGridLayout *m_chessboardLayout;
    QLabel **m_square;
public:
    chessboard(QWidget* parent = nullptr);
    ~chessboard();
};

#endif // CHESSBOARD_H

#ifndef PIECE_H
#define PIECE_H

#include <QLabel>

class piece
{
private:
    //QLabel* m_nomPiece;
    //int valeur;

    QString* m_name;
    QLabel* m_icone;
    int m_x;
    int m_y;

public:
    piece();
    piece(QString icone);
    piece(QString *name, QString icone, int x=-1, int y=-1);

    QLabel* getIcon();
    QString* getname();
    QPixmap getPixmap();
    void move(int x, int y);
};

#endif // PIECE_H

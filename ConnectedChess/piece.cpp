#include "piece.h"

piece::piece()
{
    m_name = nullptr;
    m_icone = nullptr;
    m_x= -1;
    m_y= -1;
}

piece::piece(QString icone){
    QString path = "/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/";
    m_icone = new QLabel;
    m_icone->setPixmap(QPixmap(path + icone + ".svg").scaled(45,45));
}

piece::piece(QString *name, QString icone, int x, int y){
    QString path = "/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/";

    m_name = new QString;
    m_name = name;
    m_icone = new QLabel;
    m_icone->setPixmap(QPixmap(path + icone + ".svg"));
    m_x = x;
    m_y = y;

}

QLabel* piece::getIcon(){
    return this->m_icone;
}

QString* piece::getname(){
    return m_name;
}

QPixmap piece::getPixmap(){
    QString path = "/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/";
    QString format = ".svg";
    return QPixmap(this->getname() + format);
}

void piece::move(int x, int y){
    m_x = x;
    m_y = y;
}

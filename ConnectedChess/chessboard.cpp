#include "chessboard.h"

chessboard::chessboard(QWidget *parent) : QWidget(parent)
{
    m_chessboardLayout = new QGridLayout;
    m_square = new QLabel*[72];

    int widthSquare = 60, lenghtSquare = 60;
    for (int i =0; i<72;i++){
        if ((i+1)%2 == 1){
            m_square[i]=new QLabel();
            QPixmap caseBlanche = QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/case_blanche.png");
            m_square[i]->setPixmap(caseBlanche.scaled(widthSquare,lenghtSquare));
        }
        else{
            m_square[i]=new QLabel();
            QPixmap caseNoire = QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/case_noire.png");
            m_square[i]->setPixmap(caseNoire.scaled(widthSquare,lenghtSquare));
        }
    }

    int indice=0;
    for(int i=0;i<8;i++){
        for (int j=0; j<8;j++){
            m_chessboardLayout->addWidget(m_square[indice],i,j);
            indice++;
        }
        indice++;
    }
    m_chessboardLayout->setSpacing(0);

    //pions noirs
    QLabel** black_pawn = new QLabel*[8];
    for (int i=0; i<8;i++){
        black_pawn[i]=new QLabel();
        black_pawn[i]->setPixmap(QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/black_pawn.png").scaled(40,40));
        m_chessboardLayout->addWidget(black_pawn[i], 1,i,Qt::AlignHCenter);
    }

    //pions blancs
}


chessboard::~chessboard(){

};



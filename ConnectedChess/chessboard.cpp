#include "chessboard.h"


chessboard::chessboard(QWidget *parent) : QWidget(parent)
{
    m_board = new QGridLayout();
    m_square = new QLabel*[72];
    int widthSquare = 60, lenghtSquare = 60;

    //Génération des cases noires et blanches

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

    // Affichage de l'échiquier
    int indice=0;
    for(int i=0;i<8;i++){
        for (int j=0; j<8;j++){
            m_board->addWidget(m_square[indice],i,j);
            indice++;
        }
        indice++;
    }

    //Initialisation de m_square2 qui gère l'affichage des pieces

    m_board->setSpacing(0);
    m_square2 = new QLabel**[8];
    for(int i=0;i<8;i++){
        m_square2[i] = new QLabel*[8];
        for(int j=0; j<8;j++){
            m_square2[i][j] = new QLabel();
            m_board->addWidget(m_square2[i][j], j,i, Qt::AlignHCenter);
        }

    }

    this->setLayout(m_board);

}


void chessboard::loadFEN(QString fen) {
    QStringList F = fen.split(' ');

    fen =            F[0]; // ex : rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR
    QString trait =  F[1]; // b ou w (black,white)
    QString roque =  F[2]; // KQkq
    QString ep =     F[3]; // e3
    QString rule50 = F[4]; // 0 (half-moves since start of game for 50 moves rule)
    QString num =    F[5]; // move number


    QString path = "/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/";

    resetchessboard();

    int i=0; int j=0;
        for (int k=0; k < fen.length(); k++){
                if(fen[k] == 'K')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_king.svg"));
                else if (fen[k] == 'k')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_king.svg"));
                else if (fen[k] == 'N')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_knight.svg"));
                else if (fen[k] == 'n')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_knight.svg"));
                else if (fen[k] == 'B')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_bishop.svg"));
                else if (fen[k] == 'b')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_bishop.svg"));
                else if (fen[k] == 'Q')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_queen.svg"));
                else if (fen[k] == 'q')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_queen.svg"));
                else if (fen[k] == 'R')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_rook.svg"));
                else if (fen[k] == 'r')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_rook.svg").scaled(45,45));
                else if (fen[k] == 'P')
                    m_square2[i][j]->setPixmap(QPixmap(path + "white_pawn.svg"));
                else if (fen[k] == 'p')
                    m_square2[i][j]->setPixmap(QPixmap(path + "black_pawn.svg"));
                else if (fen[k] == '/'){
                    j++;
                    i=-1;
                }
                else {
                    try {
                        int nb = fen[k].digitValue();
                        i += nb-1;
                    }
                    catch(QString err) {

                    }
                }
                i++;
        }

    m_trait = trait;
}

QString chessboard::getTrait(){
    return m_trait;
}

chessboard::~chessboard(){
    delete m_board;
    for (int i =0; i< 72 ;i++){
        delete m_square[i];
    }
    delete[] m_square;
}

void chessboard::resetchessboard(){
    if (m_square2 != nullptr){
        for (int i=0; i<8;i++){
            for (int j =0; j<8;j++){
                delete m_square2[i][j];
            }
            delete[] m_square2[i];
        }
        delete m_square2;
    }

    m_square2 = new QLabel**[8];
    for(int i=0;i<8;i++){
        m_square2[i] = new QLabel*[8];
        for(int j=0; j<8;j++){
            m_square2[i][j] = new QLabel();
            m_board->addWidget(m_square2[i][j], j,i, Qt::AlignHCenter);
        }
    }
}

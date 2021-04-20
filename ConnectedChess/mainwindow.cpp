#include "mainwindow.h"
#include "chessboard.h"

#include <QLabel>
#include <QStringListModel>
#include <QListView>
#include <QToolBar>
#include <QApplication>
#include <QMenuBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("ConnectedChess");
    QWidget *zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = menuFichier->addAction("&Quitter");
    actionQuitter->setIcon(QIcon("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/quitter.png"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));


    QHBoxLayout *Hboxlayout = new QHBoxLayout;

    // Echiquier
    QGridLayout *chessboard = new QGridLayout;
    QLabel **square = new QLabel*[72];
    int widthSquare = 60, lenghtSquare = 60;
    for (int i =0; i<72;i++){
        if ((i+1)%2 == 1){
            square[i]=new QLabel();
            QPixmap caseBlanche = QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/case_blanche.png");
            square[i]->setPixmap(caseBlanche.scaled(widthSquare,lenghtSquare));
        }
        else{
            square[i]=new QLabel();
            QPixmap caseNoire = QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/case_noire.png");
            square[i]->setPixmap(caseNoire.scaled(widthSquare,lenghtSquare));
        }
    }
    int indice=0;
    for(int i=0;i<8;i++){
        for (int j=0; j<8;j++){
            chessboard->addWidget(square[indice],i,j);
            indice++;
        }
        indice++;
    }
    chessboard->setSpacing(0);

    //pions noirs
    QLabel** black_pawn = new QLabel*[8];
    for (int i=0; i<8;i++){
        black_pawn[i]=new QLabel();
        black_pawn[i]->setPixmap(QPixmap("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/chess_pieces/black_pawn.png").scaled(40,40));
        chessboard->addWidget(black_pawn[i], 1,i,Qt::AlignHCenter);
    }

    //pions blancs






    QVBoxLayout *VRightBoxlayout = new QVBoxLayout;
    Hboxlayout->addLayout(VRightBoxlayout);


    QStringListModel *modele;
    QStringList move_history;
    QListView *view;

    modele = new QStringListModel(move_history);

    view = new QListView;
    view->setModel(modele);


    Hboxlayout->addLayout(chessboard);
    Hboxlayout->addWidget(view);


    zoneCentrale->setLayout(Hboxlayout);


    // Création de la barre d'outils
    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionQuitter);


}


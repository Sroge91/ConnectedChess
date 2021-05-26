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

    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionLoadFEN = menuFichier->addAction("&Charger FEN");
    actionLoadFEN->setIcon(QIcon("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/import_icon.svg"));
    QAction *actionQuitter = menuFichier->addAction("&Quitter");
    actionQuitter->setIcon(QIcon("/Users/simonroge/Documents/Polytech/4A/Projet S8/ConnectedChess_app/ConnectedChess/icon/quitter.png"));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    // // ECHIQUIER
    m_chessboard = new chessboard(this);
    setupChessboard();

    Hboxlayout = new QHBoxLayout;
    Hboxlayout->addWidget(m_chessboard);

    VRightBoxlayout = new QVBoxLayout;


    // // TRAIT
    m_trait = new QLabel(this);
    m_trait->setMargin(50);
    m_trait->setFixedSize(300,50);
    VRightBoxlayout->addWidget(m_trait);
    updateTrait();

    // // MOVE HISTORY
    model = new QStandardItemModel(1,2,this);
    QStringList side;
    side << "Blancs" << "Noirs";
    model->setHorizontalHeaderLabels(side);
    QTableView* move_history = new QTableView;
    move_history->setModel(model);
    VRightBoxlayout->addWidget(move_history);


    Hboxlayout->addLayout(VRightBoxlayout, Qt::AlignCenter);


    // Création de la barre d'outils
    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionLoadFEN);
    toolBarFichier->addAction(actionQuitter);

    QObject::connect(actionLoadFEN, SIGNAL(triggered()), this, SLOT(ouvrirFenetreLoadFEN()));

    zoneCentrale->setLayout(Hboxlayout);
    setCentralWidget(zoneCentrale);
}

void MainWindow::setupChessboard(){
    m_chessboard->loadFEN("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void MainWindow::ouvrirFenetreLoadFEN()
{
    FenetreLoadFEN fenetre;
    fenetre.exec();

    if (fenetre.get_fen() != nullptr){
        m_chessboard->loadFEN(fenetre.get_fen());
        updateTrait();
    }
}

void MainWindow::updateTrait(){
    if (m_chessboard->getTrait() == 'w'){
        m_trait->setText("Trait aux Blancs");
    }
    else if (m_chessboard->getTrait()== 'b'){
        m_trait->setText("Trait aux noirs");
    }
    else
        m_trait->setText("Trait aux ???");
}

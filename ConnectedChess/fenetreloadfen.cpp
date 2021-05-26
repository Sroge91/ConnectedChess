#include "fenetreloadfen.h"

FenetreLoadFEN::FenetreLoadFEN(QDialog *parent) : QDialog(parent)
{
    m_FEN = nullptr;

    LineEdit_FEN = new QLineEdit(this);

    button_load = new QPushButton("Charger", this);
    QObject::connect(button_load, &QPushButton::clicked, this, &FenetreLoadFEN::set_FEN);
    QObject::connect(button_load, &QPushButton::clicked, this, &FenetreLoadFEN::close);

    button_cancel = new QPushButton("Annuler",this);
    QObject::connect(button_cancel, &QPushButton::clicked, this, &FenetreLoadFEN::close);

    layout = new QFormLayout;
    layout->addRow("FEN", LineEdit_FEN);

    layout_button = new QHBoxLayout;
    layout_button->addWidget(button_load);
    layout_button->addWidget(button_cancel);

    layout_vertical = new QVBoxLayout;
    layout_vertical->addLayout(layout);
    layout_vertical->addLayout(layout_button);

    this->setLayout(layout_vertical);
}

void FenetreLoadFEN::set_FEN(){
    m_FEN = LineEdit_FEN->text();
}

QString FenetreLoadFEN::get_fen(){
    return m_FEN;
}

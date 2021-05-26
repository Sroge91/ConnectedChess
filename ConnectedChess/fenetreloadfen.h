#ifndef FENETRELOADFEN_H
#define FENETRELOADFEN_H

#include <QWidget>
#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>


class FenetreLoadFEN : public QDialog
{
private:
    Q_OBJECT
    QString m_FEN;
    QVBoxLayout *layout_vertical;
    QHBoxLayout *layout_button;
    QFormLayout *layout;
    QLineEdit *LineEdit_FEN;
    QPushButton *button_load;
    QPushButton *button_cancel;

public:
    explicit FenetreLoadFEN(QDialog *parent = nullptr);
public slots:
    void set_FEN();
    QString get_fen();
signals:

};

#endif // FENETRELOADFEN_H

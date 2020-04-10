#ifndef CREATE_GAME_H
#define CREATE_GAME_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class CreateGame:public QWidget{
    Q_OBJECT
public:
    explicit CreateGame(QWidget *parent = 0);
private:
    QPushButton *but0_0;
    QPushButton *but0_1;
    QPushButton *but0_2;
    QPushButton *but1_0;
    QPushButton *but1_1;
    QPushButton *but1_2;
    QPushButton *but2_0;
    QPushButton *but2_1;
    QPushButton *but2_2;
    QGridLayout *g_layout;
    void createButton();
    QHBoxLayout *h_layout;
    QLabel *pers_1_lbl;
    QLabel *pers_2_lbl;
    int count_pers1;
    int count_pers2;
    void createLabel();
    QVBoxLayout *v_layout;
    QPushButton *but_clear;
    enum step_state {CROSS, ZERO};
    step_state state;
    char mass[3][3];
    void fill_mass();
    void clear_pole();
    void checked_mass();
    void checked_winner();

signals:
    void game_over();

private slots:
     void gameStep0_0();
     void gameStep0_1();
     void gameStep0_2();
     void gameStep1_0();
     void gameStep1_1();
     void gameStep1_2();
     void gameStep2_0();
     void gameStep2_1();
     void gameStep2_2();
     void end_round();
     void final_round();


};

#endif // CREATE_GAME_H

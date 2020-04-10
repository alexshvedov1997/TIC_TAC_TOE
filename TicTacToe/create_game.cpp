#include "create_game.h"
#include <QSizePolicy>
#include <QString>
#include <QMessageBox>
#include <QApplication>

CreateGame::CreateGame(QWidget *parent):QWidget(parent){
    resize(500,500);
    setWindowTitle("Tic tac toe");
    createButton();
    createLabel();
    but_clear = new QPushButton("Clear");
    v_layout = new QVBoxLayout();
   // v_layout->addLayout(h_layout);
    v_layout->addLayout(g_layout);
    v_layout->addWidget(but_clear);
    setLayout(v_layout);
    state = CROSS;
    connect(but0_0, SIGNAL(clicked()), this, SLOT(gameStep0_0()));
    connect(but0_1, SIGNAL(clicked()), this, SLOT(gameStep0_1()));
    connect(but0_2, SIGNAL(clicked()), this, SLOT(gameStep0_2()));
    connect(but1_0, SIGNAL(clicked()), this, SLOT(gameStep1_0()));
    connect(but1_1, SIGNAL(clicked()), this, SLOT(gameStep1_1()));
    connect(but1_2, SIGNAL(clicked()), this, SLOT(gameStep1_2()));
    connect(but2_0, SIGNAL(clicked()), this, SLOT(gameStep2_0()));
    connect(but2_1, SIGNAL(clicked()), this, SLOT(gameStep2_1()));
    connect(but2_2, SIGNAL(clicked()), this, SLOT(gameStep2_2()));
    connect(but_clear, SIGNAL(clicked()), this, SLOT(end_round()));
    fill_mass();
}

void CreateGame::createButton(){
    but0_0= new QPushButton(" ");
    but0_1= new QPushButton(" ");
    but0_2= new QPushButton(" ");
    but1_0= new QPushButton(" ");
    but1_1= new QPushButton(" ");
    but1_2= new QPushButton(" ");
    but2_0= new QPushButton(" ");
    but2_1= new QPushButton(" ");
    but2_2= new QPushButton(" ");
    but0_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but0_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but0_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but1_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but1_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but1_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but2_0->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but2_1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    but2_2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    g_layout = new QGridLayout();
    g_layout->addWidget(but0_0, 0, 0);
    g_layout->addWidget(but0_1, 0, 1);
    g_layout->addWidget(but0_2, 0 ,2);
    g_layout->addWidget(but1_0, 1, 0);
    g_layout->addWidget(but1_1, 1, 1);
    g_layout->addWidget(but1_2, 1, 2);
    g_layout->addWidget(but2_0, 2, 0);
    g_layout->addWidget(but2_1, 2, 1);
    g_layout->addWidget(but2_2, 2, 2);
}

void CreateGame::createLabel(){
    pers_1_lbl= new QLabel();
    pers_2_lbl= new QLabel();
    h_layout = new QHBoxLayout();
    h_layout->addWidget(pers_1_lbl);
    h_layout->addWidget(pers_2_lbl);
    count_pers1 = 0;
    pers_1_lbl->setText("Person1 score: " + QString::number(count_pers1));
    count_pers2 = 0;
    pers_2_lbl->setText("Person2 score: " + QString::number(count_pers2));
}

void CreateGame::gameStep0_0(){
    if(state == CROSS){
        but0_0->setText("X");
        state = ZERO;
        but0_0->setEnabled(false);
        mass[0][0] = 'X';
    }
    else if(state == ZERO){
        but0_0->setText("O");
        state = CROSS;
         but0_0->setEnabled(false);
         mass[0][0] = 'O';
    }
    checked_winner();
}

void CreateGame::gameStep0_1(){
    if(state == CROSS){
        but0_1->setText("X");
        state = ZERO;
        but0_1->setEnabled(false);
        mass[0][1] = 'X';
    }
    else if(state == ZERO){
        but0_1->setText("O");
        state = CROSS;
         but0_1->setEnabled(false);
         mass[0][1] = 'O';
    }
    checked_winner();
}

void CreateGame::gameStep0_2(){
    if(state == CROSS){
        but0_2->setText("X");
        state = ZERO;
        but0_2->setEnabled(false);
        mass[0][2] = 'X';
    }
    else if(state == ZERO){
        but0_2->setText("O");
        state = CROSS;
         but0_2->setEnabled(false);
         mass[0][2] = 'O';

    }
    checked_winner();
}

void CreateGame::gameStep1_0(){
    if(state == CROSS){
        but1_0->setText("X");
        state = ZERO;
        but1_0->setEnabled(false);
        mass[1][0] = 'X';
    }
    else if(state == ZERO){
        but1_0->setText("O");
        state = CROSS;
         but1_0->setEnabled(false);
         mass[1][0] = 'O';
    }
    checked_winner();
}

void CreateGame::gameStep1_1(){
    if(state == CROSS){
        but1_1->setText("X");
        state = ZERO;
        but1_1->setEnabled(false);
        mass[1][1] = 'X';

    }
    else if(state == ZERO){
        but1_1->setText("O");
        state = CROSS;
         but1_1->setEnabled(false);
          mass[1][1] = 'O';

    }
    checked_winner();
}

void CreateGame::gameStep1_2(){
    if(state == CROSS){
        but1_2->setText("X");
        state = ZERO;
        but1_2->setEnabled(false);
        mass[1][2] = 'X';
    }
    else if(state == ZERO){
        but1_2->setText("O");
        state = CROSS;
         but1_2->setEnabled(false);
         mass[1][2] = 'O';
    }
    checked_winner();
}

void CreateGame::gameStep2_0(){
    if(state == CROSS){
        but2_0->setText("X");
        state = ZERO;
        but2_0->setEnabled(false);
        mass[2][0] = 'X';

    }
    else if(state == ZERO){
        but2_0->setText("O");
        state = CROSS;
         but2_0->setEnabled(false);
         mass[2][0] = 'O';

    }
    checked_winner();
}

void CreateGame::gameStep2_1(){
    if(state == CROSS){
        but2_1->setText("X");
        state = ZERO;
        but2_1->setEnabled(false);
        mass[2][1] = 'X';
    }

    else if(state == ZERO){
        but2_1->setText("O");
        state = CROSS;
         but2_1->setEnabled(false);
         mass[2][1] = 'O';
    }
    checked_winner();
}

void CreateGame::gameStep2_2(){
    if(state == CROSS){
        but2_2->setText("X");
        state = ZERO;
        but2_2->setEnabled(false);
        mass[2][2] = 'X';
    }
    else if(state == ZERO){
        but2_2->setText("O");
        state = CROSS;
         but2_2->setEnabled(false);
         mass[2][2] = 'O';
    }
    checked_winner();
}

void CreateGame::fill_mass(){
    for( int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            mass[i][j] = '*';
}

void CreateGame::clear_pole(){
    but0_0->setText(" ");
    but0_0->setEnabled(true);
    but0_1->setText(" ");
    but0_1->setEnabled(true);
    but0_2->setText(" ");
    but0_2->setEnabled(true);
    but1_0->setText(" ");
    but1_0->setEnabled(true);
    but1_1->setText(" ");
    but1_1->setEnabled(true);
    but1_2->setText(" ");
    but1_2->setEnabled(true);
    but2_0->setText(" ");
    but2_0->setEnabled(true);
    but2_1->setText(" ");
    but2_1->setEnabled(true);
    but2_2->setText(" ");
    but2_2->setEnabled(true);
    fill_mass();
}

void CreateGame::checked_mass(){
    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mass[i][j] == '*')
               return;
        }
    }
    clear_pole();
}

void CreateGame::end_round(){
     QMessageBox::StandardButton reply =
    QMessageBox::information(this, "End round", "Are you really want to end round?",
                             QMessageBox::Yes | QMessageBox::No);
     if(reply == QMessageBox::Yes)
         clear_pole();
}

void CreateGame::checked_winner(){
    int count = 0;
    for( int i =0 ; i < 3; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            if(state== CROSS){
                if(mass[i][j] == 'X')
                    count++;
            }
            else if(state== ZERO){
                if(mass[i][j] == 'O')
                    count++;
            }
        }
        if( count == 3)
            final_round();
    }
}

void CreateGame::final_round(){
if(state == CROSS){
     QMessageBox::StandardButton relay=
    QMessageBox::information(this,"Winner", "Cross won \n. If you want to constinue enter Yes",
                             QMessageBox::Yes | QMessageBox::No);
     if(relay == QMessageBox::Yes)
         clear_pole();
     else if(relay == QMessageBox::No)
         QApplication::quit();

}
else if(state == ZERO){
    QMessageBox::StandardButton relay=
   QMessageBox::information(this,"Winner", "Zero won \n. If you want to continue enter Yes",
                            QMessageBox::Yes | QMessageBox::No);
    if(relay == QMessageBox::Yes)
        clear_pole();
    else if(relay == QMessageBox::No)
        QApplication::quit();

}
}





























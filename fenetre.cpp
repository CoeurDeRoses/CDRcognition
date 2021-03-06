#include "fenetre.h"
#include "ui_fenetre.h"
#include <QLCDNumber>
#include  <QTimer>
#include <string>
#include <cstdlib>
#include <QValidator>






Fenetre::Fenetre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fenetre)
{
    ui->setupUi(this);
    QValidator *uniquementChiffre = new QIntValidator(0,1000,this);

    ui->txtReponse1->setValidator(uniquementChiffre);
    ui->txtReponse2->setValidator(uniquementChiffre);
    ui->txtReponse3->setValidator(uniquementChiffre);
    ui->txtReponse4->setValidator(uniquementChiffre);

    //Connexion des boutons aux méthodes
    connect(ui->btCommencer,SIGNAL(clicked()),this, SLOT(Commencer()));
    connect(ui->btArreter,SIGNAL(clicked()),this, SLOT(Arreter()));

    connect(ui->btValider1,SIGNAL(clicked()),this, SLOT(Verif1()));
    connect(ui->btValider2,SIGNAL(clicked()),this, SLOT(Verif2()));
    connect(ui->btValider3,SIGNAL(clicked()),this, SLOT(Verif3()));
    connect(ui->btValider4,SIGNAL(clicked()),this, SLOT(Verif4()));




}



//Initialisation des délais
//Génération des nombres aléatoires
void Fenetre::Commencer()
{
    ui->lbTotal->setText("");
    this->nbTotal =0;

    ui->btArreter->setEnabled(true);
    ui->btCommencer->setDisabled(true);
    //Activation des composants d'interaction avec l'utilisateur
    ui->btValider1->setEnabled(true);
    ui->btValider2->setEnabled(true);
    ui->btValider3->setEnabled(true);
    ui->btValider4->setEnabled(true);

    ui->txtReponse1->setEnabled(true);
    ui->txtReponse2->setEnabled(true);
    ui->txtReponse3->setEnabled(true);
    ui->txtReponse4->setEnabled(true);

    //Mise à 60 des nombres de secondes
    this->secondes_restantes1 = 60;
    this->secondes_restantes2 = 60;
    this->secondes_restantes3 = 60;
    this->secondes_restantes4 = 60;

    //Excepté pour l'endurance qui commence à 0
    this->secondes_endurance = 0;

    //Création des compteurs QTimer
    this->compteur1 = new QTimer(this);
    this->compteur2 = new QTimer(this);
    this->compteur3 = new QTimer(this);
    this->compteur4 = new QTimer(this);
    this->compteur_endurance = new QTimer(this);

    //Intervalle de 1000 ms pour chaque compteur
    this->compteur1->setInterval(1000);
    this->compteur2->setInterval(1000);
    this->compteur3->setInterval(1000);
    this->compteur4->setInterval(1000);

    this->compteur_endurance->setInterval(1000);
    //Execution de la méthode de mise à jour des secondes à chaque fin d'intervalle
    connect(this->compteur1, SIGNAL(timeout()), this, SLOT(SecondesActuelles()));
    //appeler un seul compteur est suffisant sinon, il y'aura 4 décrémentations
    // sur chaque compteur par secondes au lieu d'une seule

    this->compteur1->start(); this->compteur2->start();
    this->compteur3->start(); this->compteur4->start();

    this->compteur_endurance->start();


    srand(time(NULL));// Pour garantir qu'on aura pas tout le temps les mêmes opérandes
    this->Initial1();
    this->Initial2();
    this->Initial3();
    this->Initial4();






}

void Fenetre::Initial1()
{
    //Préparation calcul 1
    ui->txtReponse1->setText("");// Vider la fenêtre après la réponse trouvé
                //ou la réinitialisation de l'exercice
    this->operande1A = rand() % 16; // Dernier nombre exclusif, 15 ext le maximum
    this->operande1B = rand() % 16;

    this->resultat1 = this->operande1A * this->operande1B;

    //Affichage dans le label
    auto op1 =std::to_string(operande1A)+" x "+std::to_string(operande1B);
    ui->lbCalcul1->setText(op1.c_str());
}
void Fenetre::Initial2()
{
    ui->txtReponse2->setText("");
    //Préparation calcul 2
    this->operande2A = rand() % 16;
    this->operande2B = rand() % 16;

    this->resultat2 = this->operande2A * this->operande2B;

    auto op2 =std::to_string(operande2A)+" x "+std::to_string(operande2B);
    ui->lbCalcul2->setText(op2.c_str());
}
void Fenetre::Initial3()
{
    ui->txtReponse3->setText("");
    //Préparation calcul 3
    this->operande3A = rand() % 16;
    this->operande4B = rand() % 16;

    this->resultat3 = this->operande3A * this->operande3B;

    auto op3 =std::to_string(operande3A)+" x "+std::to_string(operande3B);
    ui->lbCalcul3->setText(op3.c_str());

}
void Fenetre::Initial4()
{
    ui->txtReponse4->setText("");
    //Préparation calcul 4
    this->operande4A = rand() % 16;
    this->operande4B = rand() % 16;

    this->resultat4 = this->operande4A * this->operande4B;

    auto op4 =std::to_string(operande4A)+" x "+std::to_string(operande4B);
    ui->lbCalcul4->setText(op4.c_str());
}

void Fenetre::Arreter()
{
    this->Effacer();
    ui->btArreter->setDisabled(true);
    ui->btCommencer->setEnabled(true);
}

void Fenetre::SecondesActuelles()
{
    //this->Effacer();// Toujours à appeler au début pour une remise à zero
    //en cas de nouvelles partie

    secondes_restantes1--;
     secondes_restantes2--;
      secondes_restantes3--;
       secondes_restantes4--;
        secondes_endurance++;

        ui->lcdNumber->display(secondes_endurance);

    auto delais1 = std::to_string(secondes_restantes1);
    auto delais2 = std::to_string(secondes_restantes2);
    auto delais3 = std::to_string(secondes_restantes3);
    auto delais4 = std::to_string(secondes_restantes4);

    if(secondes_restantes1==0 ||
            secondes_restantes2==0 ||
            secondes_restantes3==0 ||
            secondes_restantes4==0)
        //Si un délais de 60 secondes est passé
        //L'exercice est terminé
    {
        this->compteur1->stop();
        this->compteur2->stop();
        this->compteur3->stop();
        this->compteur4->stop();
        this->compteur_endurance->stop();

        this->Effacer();

        ui->btArreter->setEnabled(false);//Le desactivé
        //car inutile d'arrêter une partie déja terminé :)

        ui->btCommencer->setEnabled(true);

        ui->lbFin->setText("C'est terminé.");
    }

    ui->lbDelais1->setText(delais1.c_str());
    ui->lbDelais2->setText(delais2.c_str());
    ui->lbDelais3->setText(delais3.c_str());
    ui->lbDelais4->setText(delais4.c_str());
}

void Fenetre:: Verif1()
{

        auto compar1= std::to_string(this->resultat1);
        if(compar1.c_str() == ui->txtReponse1->text())
        {
            this->nb1++;
            ui->lbInfo1->setText("Bonne réponse");
            this->secondes_restantes1 = 60-this->nb1;

            this->nbTotal++;
            auto leTotal= std::to_string(this->nbTotal);
            ui->lbTotal->setText( leTotal.c_str());



            Initial1();


        }

        else
        {
            ui->lbInfo1->setText("Mauvaise réponse");
        }


}

void Fenetre:: Verif2()
{
    auto compar2= std::to_string(this->resultat2);
    if(compar2.c_str() == ui->txtReponse2->text())
    {
        this->nb2++;
        ui->lbInfo2->setText("Bonne réponse");
        this->secondes_restantes2 = 60-this->nb2;
        Initial2();
        this->nbTotal++;
        auto leTotal= std::to_string(this->nbTotal);
        ui->lbTotal->setText( leTotal.c_str());
    }

    else
    {
        ui->lbInfo2->setText("Mauvaise réponse");
    }
}

void Fenetre:: Verif3()
{
    auto compar3= std::to_string(this->resultat3);
    if(compar3.c_str() == ui->txtReponse3->text())
    {
        this->nb3++;
        ui->lbInfo3->setText("Bonne réponse");
        this->secondes_restantes3 = 60-this->nb3;
        Initial3();

        this->nbTotal++;
        auto leTotal= std::to_string(this->nbTotal);
        ui->lbTotal->setText( leTotal.c_str());
    }

    else
    {
        ui->lbInfo3->setText("Mauvaise réponse");
    }

}

void Fenetre:: Verif4()
{
    auto compar4= std::to_string(this->resultat4);
    if(compar4.c_str() == ui->txtReponse4->text())
    {
        this->nb4++;
        ui->lbInfo4->setText("Bonne réponse");
        this->secondes_restantes4 = 60-this->nb4;
        Initial4();

        this->nbTotal++;
        auto leTotal= std::to_string(this->nbTotal);
        ui->lbTotal->setText( leTotal.c_str());
    }

    else
    {
        ui->lbInfo4->setText("Mauvaise réponse");
    }
}


void Fenetre:: Effacer()
{


    this->compteur1->stop();
    this->compteur2->stop();
    this->compteur3->stop();
    this->compteur4->stop();

        ui->txtReponse1->setText("");
        ui->txtReponse2->setText("");
        ui->txtReponse3->setText("");
        ui->txtReponse4->setText("");

     ui->btValider1->setEnabled(false);
     ui->btValider2->setEnabled(false);
     ui->btValider3->setEnabled(false);
     ui->btValider4->setEnabled(false);

     ui->txtReponse1->setEnabled(false);
     ui->txtReponse2->setEnabled(false);
     ui->txtReponse3->setEnabled(false);
     ui->txtReponse4->setEnabled(false);


    ui->lbDelais1->setText("");
    ui->lbCalcul1->setText("");
    ui->lbInfo1->setText("");

    ui->lbDelais2->setText("");
    ui->lbCalcul2->setText("");
    ui->lbInfo2->setText("");

    ui->lbDelais3->setText("");
    ui->lbCalcul3->setText("");
    ui->lbInfo3->setText("");

    ui->lbDelais4->setText("");
    ui->lbCalcul4->setText("");
    ui->lbInfo4->setText("");






}

Fenetre::~Fenetre()
{

    delete ui;

}

#ifndef FENETRE_H
#define FENETRE_H
#include <QTime>
#include <QKeyEvent>


#include <QDialog>

namespace Ui {
class Fenetre;
}

class Fenetre : public QDialog
{
    Q_OBJECT

public:
    explicit Fenetre(QWidget *parent = 0);
    ~Fenetre();

public slots:
        //Méthode pour démarrer les compter à rebour
      void Commencer();
      //Arreter l'exercice
      void Arreter();
      //Méthode pour mettre à jour le nombre de secondes
      void SecondesActuelles();

      //Méthodes de verification pour chaque calcul
      void Verif1();
      void Verif2();
      void Verif3();
      void Verif4();
      void Effacer();//Pour une remise à 0 après un nouvelle partie ou un arrêt

      //méthodes servant à réinitialiser les calculs
      void Initial1();
      void Initial2();
      void Initial3();
      void Initial4();



private:
      //Variable pour les 4 compteurs
     int secondes_restantes1;



    QTimer* compteur1;

    int secondes_restantes2;
    QTimer* compteur2;

    int secondes_restantes3;
    QTimer* compteur3;

    int secondes_restantes4;
    QTimer* compteur4;

        //Compter l'endurance mentale
    int secondes_endurance;
    QTimer* compteur_endurance;


    // pour connaître le nombre de calcul trouvé.
    int nbTotal =0;
    //Opérandes calcul 1 et variable résultat

    int operande1A = 0;

    int operande1B = 0;
    int resultat1 = 0;
    int nb1 = 0;//Les variables commencant par nb
    // seront nécessaires pour accroitre la difficulté
    // en baissant le temps pour chaque calcul d'une seconde
    // chaque fois qu'une réponse est trouvé

    //Opérandes calcul 2 et variable résultat

    int operande2A = 0;
    int operande2B = 0;
    int resultat2 = 0;
    int nb2=0;

    //Opérandes calcul 3 et variable résultat

    int operande3A = 0;
    int operande3B = 0;
    int resultat3 = 0;
    int nb3 = 0;

    //Opérandes calcul 4 et variable résultat

    int operande4A = 0;
    int operande4B = 0;
    int resultat4 =0;
    int nb4 = 0;

    Ui::Fenetre *ui;
};

#endif // FENETRE_H

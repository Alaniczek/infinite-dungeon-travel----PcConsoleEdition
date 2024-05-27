#include <iostream>
#include <string>

#include <chrono> //spanie
#include <thread> //spanie

using namespace std;

void wait(int X)
{  this_thread::sleep_for(chrono::seconds(X));   }

int zyciePoWalce;
int CoinyPoWalce;

class potworek{

private:
	string nazwa;
	int hp;
	int armor;
	int DMG;
	int coin;

public:
	potworek();
	potworek(string, int , int , int , int);

	int getHP() {return hp;}
	int getArmor() {return armor;}
	int getDMG() {return DMG;}
	string getName() {return nazwa;}

	int getCOIN() {return coin;}

    void setHP(int newHP) { hp = newHP; } // Method to update hit points
    void setCoin(int newCoin) {coin = newCoin;}

	void obrazenia(int ilosc);
	void dodajHP(int hpe);
	void dodajDMG(int demage);
	void dodajARMOR(int armorek);

	void dodajCOINY(int coinPP);


};

potworek::potworek() {}


void potworek::dodajHP(int hpe)
{
    hp += hpe;
}

void potworek::dodajDMG(int demage)
{
    DMG += demage;
}

void potworek::dodajARMOR(int armorek)
{
    armor += armorek;
}

void potworek::dodajCOINY(int coinPP)
{
    coin += coinPP;
}


potworek::potworek(string n, int h , int a , int d , int c)
{
	nazwa = n;
	armor = a;
	DMG = d;
	coin = c;
	if(h >= 0)
	{
    	hp = h;
	} else
	{
    	hp = 0;
    	cout << "USTAWIONO HP NA 0 \n";
	}
}


void target(potworek &attacker, potworek &target)
{
    int damage = attacker.getDMG() - target.getArmor();

    if (damage <= 5){
        damage = 5;
    }
    target.obrazenia(damage);

    cout << endl << target.getName() <<" otrzymuje " << damage << " obrażeń!" << endl;
}

void strongTarget(potworek &attacker, potworek &target)
{
    int damage = (attacker.getDMG() * 2) - target.getArmor();

    if (damage <= 5){
        damage = 5;
    }
    target.obrazenia(damage);

    cout << endl << target.getName() <<" otrzymuje " << damage << " obrażeń!" << endl;
}




void potworek::obrazenia(int ilosc) {
    //Obrazenia ALPHA, uzywane w losowym momencie gry mog¹ byæ

	int Demage = ilosc - armor;

	if (Demage <= 5) {
    	Demage = 5;
	}

	hp -= Demage;

	if (hp < 0) {
    	hp = 0;
    	cout << "Ktos dead";
	}
}

void staty(potworek &kogo)
{
    cout << endl;
    cout << "Nazwa: " << kogo.getName() << endl;
	cout << "HP : " << kogo.getHP() << endl;
	cout << "Armor :" << kogo.getArmor() << endl;
	cout << "Dmg :" << kogo.getDMG() << endl;
	cout << "\nCoiny/Wartość :" << kogo.getCOIN() << endl;
	cout << endl;
}

void addHP(potworek $OsobaDoLeczenia)
{
    $OsobaDoLeczenia.dodajHP(35);
    wait(1);
     //Dodaj dodawanie HP
}

/*
while (gracz.getHP() > 0 && przeciwnik.getHP() > 0)
    {
        cout << "\n TEST \n " << endl << gracz.getHP() << endl << przeciwnik.getHP();
        gracz.obrazenia(10);
        przeciwnik.obrazenia(60);
        cout << "\n TEST 2 \n " << endl << gracz.getHP() << endl << przeciwnik.getHP() << endl;

        this_thread::sleep_for(chrono::seconds(5));
    }
*/

//ATTACK SYSTEM

void fight(potworek &gracz , potworek &przeciwnik)
{
    wait(2);
    int wyborGracza;
    int punktyAkcjiGracza = 4;
    int punktyAkcjiPrzeciwnika = 7;
    while (gracz.getHP() > 0 && przeciwnik.getHP() > 0)
    {
        wait(2);
        cout<< "\n\n WYBIERZ AKCJE \n"
            << "1. Atak \n"
            << "2. Heal (4pkt Akcji) \n"
            << "3. strongAttack x2 (3pkt Akcji) \n"
            << "4. Podwójny atak (4pkt Akcji) \n \n";


        cout << "TWOJE PUNKTY AKCJI :" << punktyAkcjiGracza << endl;
        cout << "PUNKTY PRZECIWNIKA :" << punktyAkcjiPrzeciwnika << endl << endl;
        cin >> wyborGracza;

        switch(wyborGracza)
        {
            case 1:
            target(gracz , przeciwnik);
            cout << "ATAK!";
            break;

            case 2:
            if(punktyAkcjiGracza >= 4)
            {
                addHP(gracz);
                cout << "Leczenie";
                punktyAkcjiGracza = punktyAkcjiGracza - 4;
            }else  target(gracz, przeciwnik);

            break;

            case 3:
            if(punktyAkcjiGracza >= 3)
            {
                strongTarget(gracz , przeciwnik);
                cout << "\n WYKONANO Podwójny ATAK! \n";
                punktyAkcjiGracza = punktyAkcjiGracza - 3;
            } else target(gracz, przeciwnik);

            break;

            case 4:
            if(punktyAkcjiGracza >= 4)
            {
                target(gracz, przeciwnik);
                target(gracz, przeciwnik);
                cout << "\n WYKONANO PODWÓJNY ATAK! \n";

                punktyAkcjiGracza = punktyAkcjiGracza - 4;
            }else target(gracz, przeciwnik);
            break;


            default:
            target(gracz , przeciwnik);
            cout << "ATAK!";

            break;
        }

        this_thread::sleep_for(chrono::seconds(2));

        cout << "wróg akcja";

        this_thread::sleep_for(chrono::seconds(1));

        if(przeciwnik.getHP() <= 25 && punktyAkcjiPrzeciwnika >= 4)
        {
            addHP(przeciwnik);
            cout << "\n \n ODLECZY£ SIÊ!! \n\n";
            punktyAkcjiPrzeciwnika -= 4;
        }
        else if(przeciwnik.getHP() >= 26 && punktyAkcjiPrzeciwnika >= 4)
        {
            strongTarget(przeciwnik, gracz);
            cout << "\n \nPOTÊ¯NY ATAK \n\n";
            punktyAkcjiPrzeciwnika -=4;
        }
        else
        {
            target(przeciwnik , gracz);
            cout << "\n \nZWYK£Y ATAK \n\n";
        }

        this_thread::sleep_for(chrono::seconds(2));

        cout << "\n Twoje HP: " << gracz.getHP();
        cout << "\n Wroga HP: " << przeciwnik.getHP() << endl;

        this_thread::sleep_for(chrono::seconds(1));

        punktyAkcjiGracza++;
        punktyAkcjiPrzeciwnika++;
            if(gracz.getHP() <= 0)
            {
                    cout << " \n Twoja wêdrówka zosta³a skoñczona {*} UMAR£EŒ";
                    break;
            }
    }
    zyciePoWalce = gracz.getHP();
    gracz.setCoin(gracz.getCOIN() + przeciwnik.getCOIN() );
    cout << "\n\n Suma monet po walce: " << gracz.getCOIN() << endl;


}

// void coinyDodawanie(int coinyPP)
// {
//     coin += coinyPP;
// }

// SHOP SYSTEM

void Shop(potworek &gracz)
{
    int coin = gracz.getCOIN();
    cout << "\n\n\n WITAMY W SKLEPIE \n";
    cout << "WYBIERZ \n 1. +3 obrazenia   100coin \n 2. +15 hp   100coin    \n 3. +2 armor 100coin \n";

    bool wyjscieZSklepu = false;

    while(1)
    {
        cout << "\n Wybierz coś jeszcze \n";
        int wyborSKLEP;
        cin >> wyborSKLEP;
        switch(wyborSKLEP)
        {
            case 1:
            if(coin >= 100)
            {
                cout << "wybrano 1 ";
                gracz.dodajDMG(3);
                coin -= 100;

            }else {cout << "BRAK PINIĘDZY";}
            break;


            case 2:
            if(coin >= 100)
            {
                cout << "wybrano 2 ";
                gracz.dodajHP(15);
                coin -= 100;

            }else{ cout << "BRAK PINIĘDZY";}
            break;

            case 3:
            if(coin >= 100)
            {
                cout << "wybrano 3 ";
                gracz.dodajARMOR(2);
                coin -= 100;

            }else{ cout << "BRAK PINIĘDZY";}
            break;

            default:
                cout << "wychodze z sklepu!";

                wyjscieZSklepu = true;
                break;
        }
        if(wyjscieZSklepu)
        {
            break;
        }
        cout << "OBECNE COINY: " << coin ;

    }
        gracz.setCoin(coin);

}

void Opowiesc()
{
    cout << "Witaj podróżniku \n"
        << "Miło cię widzieć w tej krainie w której wszystko ginie \n"
        << "Jesteś kolejnym z setek wojowników próbujących uratować Mroczny las Ellie \n"
        << "Jeżeli ci się uda to gratulację zdobędziesz jakąś ziemię Aelorin, jeżeli nie to no cóż... Chyba się domyślasz"
        << "A więc zacznijmy... \n Wchodzisz do lasu... \n";
}

int main()
{

    Opowiesc();
    wait(3);

	potworek p("Joel", 100 , 5 ,30 , 250);

	staty(p);


// 	p.dodajHP(20);
// 	p.dodajARMOR(30);
// 	p.dodajDMG(10);
// 	staty(p);
    Shop(p);
    wait(1);
    staty(p);
    wait(1);

	potworek pot1("Stwor1" , 75 , 8 , 10 , 80);

	staty(pot1);


    //target(p , s);
    fight(p , pot1);

     Shop(p);
     wait(1);

    potworek pot2("Stwor2" , 80 , 12 , 23 , 100);

    p.setHP(zyciePoWalce);
    cout << "-----TWOJE STATY-----";
    staty(p);
    cout << "------NOWY WRÓG------";
	staty(pot2);

    fight(p , pot2);


    Shop(p);
    wait(1);

    potworek pot3("Stwor3" , 180 , 17 , 7 , 150);


    p.setHP(zyciePoWalce);
    cout << "-----TWOJE STATY-----";
    staty(p);
    cout << "------NOWY WRÓG------";
	staty(pot3);

    fight(p , pot3);

    cout << "OSTATNIA WALKA";

    Shop(p);
    wait(1);

    potworek pot4("Stwor4" , 180 , 17 , 7 , 150);


    p.setHP(zyciePoWalce);
    cout << "-----TWOJE STATY-----";
    staty(p);
    cout << "------NOWY WRÓG------";
	staty(pot4);

    fight(p , pot4);




    cout<< "Dzięki tobie Mroczny las Ellie jest bezpieczny \n"
        << "Wygrałeś, tą krótką prostą grę, kiedyś może wyjdzie aktualizacja fabularna lub z menu \n"
        << "Kto wie...";

	return 0;
}

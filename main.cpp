#include <iostream>
#include <string>

#include <chrono> //spanie
#include <thread> //spanie

using namespace std;

class potworek{

private:
	string nazwa;
	int hp;
	int armor;
	int DMG;

public:
	potworek();
	potworek(string, int , int , int);

	int getHP() {return hp;}
	int getArmor() {return armor;}
	int getDMG() {return DMG;}
	string getName() {return nazwa;}


	void obrazenia(int ilosc);
	void dodajHP(int hp);
};

potworek::potworek() {}

void potworek::dodajHP(int hp)
{
    hp += hp;
}

potworek::potworek(string n, int h , int a , int d)
{
	nazwa = n;
	armor = a;
	DMG = d;
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

    cout << endl << target.getName() <<" otrzymuje " << damage << " obra¿eñ!" << endl;
}

void strongTarget(potworek &attacker, potworek &target)
{
    int damage = ( attacker.getDMG() * 2) - target.getArmor();

    if (damage <= 5){
        damage = 5;
    }
    target.obrazenia(damage);

    cout << endl << target.getName() <<" otrzymuje " << damage << " obra¿eñ!" << endl;
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

void staty(potworek kogo)
{
    cout << endl;
    cout << "Nazwa: " << kogo.getName() << endl;
	cout << "HP : " << kogo.getHP() << endl;
	cout << "Armor :" << kogo.getArmor() << endl;
	cout << "Dmg :" << kogo.getDMG() << endl;
	cout << endl;
}

void addHP(potworek $OsobaDoLeczenia)
{
    $OsobaDoLeczenia.dodajHP(35);
    this_thread::sleep_for(chrono::seconds(3));
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
void fight(potworek gracz , potworek przeciwnik)
{
    int wyborGracza;
    int punktyAkcjiGracza = 4;
    int punktyAkcjiPrzeciwnika = 7;
    while (gracz.getHP() > 0 && przeciwnik.getHP() > 0)
    {
        this_thread::sleep_for(chrono::seconds(3));

        cout<< "\n\n WYBIERZ AKCJE \n"
            << "1. Atak \n"
            << "2. Heal (4pkt Akcji) \n"
            << "3. strongAttack x2 (3pkt Akcji) \n"
            << "4. Podwójny atak (4pkt Akcji) \n \n";
        cout << "TWOJE PUNKTY AKCJI :" << punktyAkcjiGracza << endl;
        cout << "PUNKTY PRZECIWNIKA " << punktyAkcjiPrzeciwnika << endl << endl;
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
                punktyAkcjiGracza = punktyAkcjiGracza - -4;
            }else  target(gracz, przeciwnik);

            break;

            case 3:
            if(punktyAkcjiGracza >= 3)
            {
                strongTarget(gracz , przeciwnik);
                cout << "\n WYKONANO PODWÓJNY ATAK! \n";
                punktyAkcjiGracza = punktyAkcjiGracza - 5;
            } else target(gracz, przeciwnik);

            break;

            case 4:
            if(punktyAkcjiGracza >= 4)
            {
                target(gracz, przeciwnik);
                target(gracz, przeciwnik);
            }else target(gracz, przeciwnik);
            break;


            default:
            target(gracz , przeciwnik);
            cout << "ATAK!";

            break;
        }


        cout << "wróg akcja";

        if(przeciwnik.getHP() <= 25 && punktyAkcjiPrzeciwnika >= 4)
        {
            addHP(przeciwnik);
            cout << "\n ODLECZY£ SIÊ!! \n";
            punktyAkcjiPrzeciwnika -= 4;
        }else if(przeciwnik.getHP() >= 26 && punktyAkcjiPrzeciwnika >= 6)
        {
            target(przeciwnik, gracz);
            target(przeciwnik, gracz);
        }else if(przeciwnik.getHP() >= 26 && punktyAkcjiPrzeciwnika >= 4)
        {
            strongTarget(przeciwnik, gracz);
            cout << "\n POTÊ¯NY ATAK \n";
            punktyAkcjiPrzeciwnika -=4;
        }else
        {
            target(przeciwnik , gracz);
            cout << "\n ZWYK£Y ATAK \n";
        }


        cout << "\n Twoje HP: " << gracz.getHP();
        cout << "\n Wroga HP: " << przeciwnik.getHP() << endl;

        punktyAkcjiGracza++;
        punktyAkcjiPrzeciwnika++;
            if(gracz.getHP() <= 0)
            {
                    cout << " \n Twoja wêdrówka zosta³a skoñczona {*} UMAR£EŒ";
                    break;
            }
    }

    cout << " \n Walka zakoñczona! \n " << endl;
}


int main()
{
	potworek p("Andrzej", 100 , 15 ,30);

	staty(p);


	potworek pot1("Stwor1" , 130 , 8 , 10);

	staty(pot1);


    //target(p , s);
    fight(p , pot1);


    addHP(p);

    potworek pot2("Stwor2" , 80 , 12 , 23);

    cout << "-----TWOJE STATY-----";
    staty(p);
    cout << "------NOWY WRÓG------";
	staty(pot2);


    fight(p , pot2);

    cout << "Wygra³eœ... pogratulowaæ tylko mo¿na";

	return 0;
}








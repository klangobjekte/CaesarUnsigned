/*##############################################

Ein "Kodeknacker"

##############################################*/



#include <iostream>
#include "utf8.h"

using namespace std;



//die Prototypen f¸r die Funktionen

void dreherKnacken(string);

void caesarKnacken(string);

void gartenzaunKnacken(string);



//die Funktion zum Umdrehen

void dreherKnacken(string kette)
{
	//die L‰nge der urspr¸nglichen Zeichenkette ermitteln
	int laenge;
	laenge = kette.length();
	//length liefert die "echte" L‰nge

	//Daher muss 1 abgezogen werden
	laenge = laenge - 1;
    cout << "Das Umdrehen ergibt: " << endl;

	//die Zeichen von hinten nach vorne ausgeben
	for (int zaehler = laenge; zaehler >= 0; zaehler--)
        cout << kette[zaehler];
    cout << endl << endl;
}



//die Funktion zum Knacken der C‰sar-Verschl¸sselung

void caesarKnacken(string kette)
{
	int laenge, verschiebung;
	//die L‰nge der urspr¸nglichen Zeichenkette ermitteln
	laenge = kette.length();
    cout << "Durchprobieren der Caesar-Verschluesselungen" << endl;
    //alle Verschiebewerte von 1 bis 255 durchgehen
    for (verschiebung = 1; verschiebung <= 255; verschiebung++)
    {
        cout << "Mit der Verschiebezahl " << verschiebung << " ist das Ergebnis : ";

        //jedes Zeichen um den angegebenen Wert verschieben, diesmal aber nach links
        for (int zaehler = 0; zaehler < laenge; zaehler++)
            cout << static_cast<char>(kette[zaehler] - verschiebung);
        cout << endl;

        //alle 10 Ausgaben auf eine Eingabe warten
        if (verschiebung % 10 == 0)
            getchar();
    }
    cout << endl << endl;
}



void gartenzaunKnacken(string kette)

{
	string dekodiert, teil1, teil2;
	int laenge;
	int mitte;
	//die L‰nge der urspr¸nglichen Zeichenkette ermitteln
	laenge = kette.length();

	//die Mitte finden
	mitte = laenge / 2;

	//wenn es eine ungerade Anzahl ist, noch 1 addieren
	if (laenge % 2 != 0)
        mitte++;

    //die Zeichenkette zerlegen
    teil1 = kette.substr(0, mitte);
    teil2 = kette.substr(mitte, laenge);

	for (int zaehler = 0; zaehler < laenge; zaehler++)
	{
		//Zeichen mit einem geraden Index kommen in die erste Zeichenkette
		if (zaehler % 2 == 0)
			dekodiert.push_back(teil1[zaehler / 2]);
		//Zeichen mit einem ungeraden Index kommen in die zweite Zeichenkette
		else
			dekodiert.push_back(teil2[zaehler / 2]);
	}

    cout << "Der Versuch mit der Gartenzaunverschluesselung ergibt: " << endl;
	cout << dekodiert << endl;

}



void caesarKnacken(unsigned  int kette[],int laenge)
{
	int verschiebung;
	/*
	cout << "Eingabe war: " << endl;
	for(int i=0; i<laenge; i++){
        cout << static_cast<int>(kette[i]) << " ";
	}
	cout << endl;
    */
	////die L‰nge der urspr¸nglichen Zeichenkette ermitteln
	//laenge = kette.length();
    cout << "Durchprobieren der Caesar-Verschluesselungen " << laenge << endl;
    //alle Verschiebewerte von 1 bis 255 durchgehen
    for (verschiebung = 0; verschiebung <= 255; verschiebung++)
    {
        cout << "Mit der Verschiebezahl            " << verschiebung << " ist das Ergebnis                  : ";
        unsigned char test =0;
        unsigned char *p = 0;
        //jedes Zeichen um den angegebenen Wert verschieben, diesmal aber nach links
        for (int zaehler = 0; zaehler < laenge; zaehler++){
            test =  static_cast<unsigned char>(kette[zaehler]) - verschiebung;
            p= toUtf8(&test,1);
            cout << p;
        }
        cout << endl;
        cout << "";
        for (int zaehler = 0; zaehler < laenge; zaehler++){
            test =  static_cast<unsigned char>(kette[zaehler]) - verschiebung;
            cout << static_cast<unsigned int>(test) << " ";
        }
        cout << endl << endl;

            //alle 10 Ausgaben auf eine Eingabe warten
            if (verschiebung % 50 == 0)
                getchar();
    }
    cout << endl << endl;
}



unsigned int *asciiKode(unsigned char kette[],int len) {
    //string isoconvert;
    unsigned int *p;
    unsigned int isconvert[256];
    for(int i=0; i<256;i++){
        isconvert[i]=0;
    }

    cout << "Eingabe unsigend int:" << endl;
    for (int i =0,y=0;i<len;i++){
        cout << " : " << static_cast<unsigned int> (kette[i]) << endl;
    }
    cout << endl;
    //int laenge; laenge = kette.length();
    //die Länge der ursprünglichen Zeichenkette ermitteln int laenge; laenge = kette.length();
    cout << "Entfernen des Startbytes:" << endl;
    //für jedes Zeichen den ASCII-Wert ausgeben for (int zaehler = 0; zaehler < laenge; zaehler++)
    //for (int zaehler = 0;zaehler < laenge;zaehler++){
    //    cout << static_cast<int>(kette[zaehler]) << ' '; cout << endl << endl;
    for (int i =0,y=0;i<len;i++){
        //cout << static_cast<unsigned int>(kette[i]) << endl;
        if(isStartByte(&kette[i])){
            cout << "remove byte---: " << static_cast<unsigned int> (kette[i]) << endl;
        }
        else{
            cout << "kepp byte     : "<< static_cast<unsigned int>(kette[i]) << endl;
            isconvert[y] = kette[i];
            y++;
        }
    }
    p = &isconvert[0];
    return p;
}


int main()
{
    cout << "Bitte geben Sie eine Zeichenkette ein (ohne Leerzeichen): ";
/*
	string stringeingabe;
	cin >> stringeingabe;
*/
    unsigned char eingabe[256];
    for(int i= 0;i<256;i++){
        eingabe[i]=0;
    }

    //Die urspr¸ngliche Zeichenkette einlesen
    //eingabe = getchar();
	//cout << "Die urspruengliche Zeichenkette ist: " << eingabe << endl << endl;
    int i=0;
    unsigned char in =0;
    do {
        in = getchar();
        if(in >31)
         eingabe[i] = in;

        //putchar (eingabe[i]);
        i++;
    } while (in != 10);


    unsigned int *isochars = asciiKode(eingabe,i-1);
    //cout << "Eingabe: ";
    int len = 0;
    for(int y=0; y<i; y++){
        //cout  << (isochars[y]) << " ";
        len = y;
        if(isochars[y] == 0){
            y = i;
        }
    }
    cout << endl;

    caesarKnacken(isochars,len);
    //die verschiedenen Ans‰tze ausprobieren

	//dreherKnacken(eingabe);

	//caesarKnacken(stringeingabe);

	//gartenzaunKnacken(eingabe);



    return 0;

}








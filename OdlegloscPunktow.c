#include <stdio.h>
#include <math.h>

/*funkcja do obliczenia odleglosci*/
float obliczOdlegloscDwochPunktow(int aX, int aY, int bX, int bY){
    float wynik = sqrt(pow((bX - aX), 2) + (pow((bY - aY), 2)));
    return wynik;
}// koniec funkcji obliczOdl

/*funkcja liczaca silnie*/
int silnia(int num){
	int i;
	int wynik = 1;
	       
	for(i = 1; i <= num; i++){
             wynik = wynik * i;
	}//koniec for i
	       
	return wynik; 
}//koniec funkcji silnia


int main(){   
    /*deklaracje zmiennych */   
    int a, i, j, iloscKombinacji;    
    
    /*Nag³ówek*/
    printf("Program, ktory wczyta n punktow na plaszczyznie w dowolnej kolejnosci \n"); 
    printf("i znajdzie dwa punkty najbardziej i dwa najmniej odlegle od siebie...\n\n");
    printf("Podaj liczbe badanych punktow (wieksza od 1 ale mniejsza od 13)  ->  ");  
    scanf("%d",&a);
    
   /*warunek minimum dwa punkty*/
   if(a <= 1 || a > 12){
        do{
           printf(" -----> Podales zla liczbe, sprobuj ponownie.\n"); printf("Podaj liczbe badanych punktow (wieksza od 1 ale mniejsza od 13):");
           scanf("%d",&a);
        }while(a <= 1 || a > 12);
   }//koniec if
    
    /*tablica naszych punktow */     
    int punkty[a][2];
    
    for(i = 0; i < a ; i++)
    {
        printf("Wpisz wspolrzedne punktu ");printf("%d", i + 1);printf("\nDla x: ");scanf("%d", &punkty[i][0]);
        printf("\nDla y: ");
        scanf("%d", &punkty[i][1]);
    }//koniec for    
   
    /*niech przeliczy ile kombinacji*/    
    iloscKombinacji = ((silnia(a))/(silnia(a - 2)))/2; //wariacja bez powtorzen dzielona przez dwa
    printf("\nIlosc badan bedzie rowna %d\n", iloscKombinacji);        
    
    
    /*nasze dwie tablice zestawiajace numery punktow i wyniki miedzy nimi*/
    float wyniki[iloscKombinacji];
    char badanePunkty[iloscKombinacji][7];     
    
    /*zmienna bedaca indeksem dla obu powyzszych tablic*/
    int k = 0;    
    
    /*petla oblicza odleglosc pomiedzy danymi punktami oraz rownolegle zapisuje o ktore punkty chodzilo w danym ruchu*/    
    for(i = 0; i < a; i ++){
          for(j = i + 1; j <= a; j++){
                //licz odleglosc
                wyniki[k] = obliczOdlegloscDwochPunktow(punkty[i][0], punkty[i][1], punkty[j][0], punkty[j][1]);
                
                //wypisz o ktore punkty chodzilo
                if(i < 9){
                     if(j < 9){
                          sprintf(badanePunkty[k], "0%d->0%d", i, j);
                     }
                     else{
                          sprintf(badanePunkty[k], "0%d->%d", i, j);
                     }
                }//if(i < 10)
                else{
                     if(j < 9){
                          sprintf(badanePunkty[k], "%d->0%d", i, j);
                     }
                     else{
                          sprintf(badanePunkty[k], "%d->%d", i, j);
                     }
                } //else
                
                k++;
          }//for         
    }//for    
    
    /*wypiszmy badane punkty */   
    for(i = 0; i < iloscKombinacji; i++){
        printf("\nBadane punkty: %s maja odleglosc rowna: %.3f", badanePunkty[i], wyniki[i]); 
    }//koniec for
    printf("\n");    
    
    /*zmienne najwiekszy wynik*/
    float tmpMax = wyniki[0];
    int tmpIndexMax = 0;

    /*najwieksza odleglosc*/
    for(i = 1; i < iloscKombinacji; i++){
          if(tmpMax < wyniki[i]){
                    tmpMax = wyniki[i];
                    tmpIndexMax = i;
          }//koniec if
    }//koniec najwiekszy wynik
    printf("\nNajwieksza odleglosc to odleglosc pomiedzy punktami %s rowna: %.3f\n", badanePunkty[tmpIndexMax], tmpMax);
    for(i = tmpIndexMax + 1; i <= iloscKombinacji; i++){
          if(tmpMax == wyniki[i]){
                    printf("\tOraz odleglosc pomiedzy punktami %s rowna: %.3f\n", 
                    badanePunkty[i], tmpMax);
          }//koniec if
    }//koniec for

    /*zmienne najmniejszy wynik*/
    float tmpMin = wyniki[0];
    int tmpIndexMin = 0;

    /*najmniejsza odleglosc*/
    for(i = 1; i < iloscKombinacji; i++){
          if(tmpMin > wyniki[i]){
                    tmpMin = wyniki[i];
                    tmpIndexMin = i;
          }//koniec if
    }//koniec najwiekszy wynik
    if(tmpMin == tmpMax)
              goto koniec;
    printf("\nNajmniejsza odleglosc to odleglosc pomiedzy punktami %s rowna: %.3f\n", badanePunkty[tmpIndexMin], tmpMin);
    for(i = tmpIndexMin + 1; i <= iloscKombinacji; i++){
          if(tmpMin == wyniki[i]){
                    printf("\tOraz odleglosc pomiedzy punktami %s rowna: %.3f\n", badanePunkty[i], tmpMin);
          }//koniec if
    }// koniec for
    koniec:;



    system("PAUSE");
    return 0;

}// int main()


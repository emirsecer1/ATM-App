#include <stdio.h>
#include <string.h>
#include<conio.h>

struct User {
    char name[50];
    char password[50];
};

struct User users[] = {
    {"emir", "1234"},
    {"omer", "1029"},
    {"asli", "9293"},
};

void Anaislem(int bakiye, int tutar);
void durum(int bakiye, int tutar, int borc, int durumne);

int main() {
    int bakiye = 10000;
    int tutar;
    char isim[50], sifre[50];

    printf("Kullanici adi: ");
    scanf("%s", isim);

    struct User *user = NULL;
    for (int i = 0; i < sizeof(users) / sizeof(struct User); ++i) {
        if (strcmp(users[i].name, isim) == 0) {
            user = &users[i];
            break;
        }
    }

    if (user == NULL) {
        printf("Kullanici bulunamadi. Yeni kullanici eklemek ister misiniz? (E/H): ");
        char cevap;
        scanf(" %c", &cevap);

        if (cevap == 'E' || cevap == 'e') {
            printf("Yeni kullanici adi: ");
            scanf("%s", isim);
            printf("Yeni sifre: ");
            scanf("%s", sifre);

            strcpy(users[sizeof(users) / sizeof(struct User)].name, isim);
            strcpy(users[sizeof(users) / sizeof(struct User)].password, sifre);

            printf("Yeni kullanici eklendi. Lutfen giris yapin.\n");
        } else {
            printf("Kartinizi iade alin.\n");
        }
    } else {
        printf("Sifre: ");
        scanf("%s", sifre);

        if (strcmp(user->password, sifre) == 0) {
            printf("Giris basarili!\n");
            Anaislem(bakiye, tutar);
        } else {
            printf("Hatali sifre. Kartinizi iade alin.\n");
        }
    }

    return 0;
}

void Anaislem(int bakiye, int tutar) {
    printf("Lutfen yapmak istediginiz islemi seciniz:\n 1 - Para cekme \n 2 - Para yatirma \n 3 - Bakiye goruntuleme \n ");
    int islem;
    scanf("%d", &islem);

    switch (islem) {
        case 1:
            printf("Bakiyeniz %d TL. Lutfen bu tutardan daha fazla para cekmeyeceginizi unutmayin\n", bakiye);
            printf("Cekmek istediginiz tutari giriniz: ");
            scanf("%d", &tutar);

            if (tutar <= bakiye) {
                printf("Islem gerceklestiriliyor.\n");
                bakiye -= tutar;
                printf("Islem basarili. Yeni bakiyeniz %d TL.\n", bakiye);
                durum(bakiye, tutar, 0, 0);
            } else {
                printf("Yetersiz bakiye. Islem iptal edildi.\n");
                durum(bakiye, tutar, 0, 0);
            }
            break;
        case 2:
            printf("Lutfen yatirmak istediginiz tutari giriniz: ");
            scanf("%d", &tutar);
            printf("Islem gerceklestiriliyor.\n");
            bakiye += tutar;
            printf("Islem basarili. Yeni bakiyeniz %d TL.\n", bakiye);
            durum(bakiye, tutar, 0, 0);
            break;
        case 3:
            printf("Bakiyeniz %d TL.\n", bakiye);
            durum(bakiye, tutar, 0, 0);
            break;
        default:
            printf("Hatali tuslama. Lutfen kartinizi iade alin.\n");
    }
}

void durum(int bakiye, int tutar, int borc, int durumne) {
    printf("Simdi ne yapmak istiyorsunuz: \n 1 - Baska islem \n 2 - Kart iade\n");
    scanf("%d", &durumne);

    switch (durumne) {
        case 1:
            Anaislem(bakiye, tutar);
            break;
        case 2:
            printf("Lutfen kartinizi aliniz.\n");
            break;
        default:
            printf("Hatali tuslama. Lutfen kartinizi iade alin.\n");
    }
    
}
    
    
    
    
    
    
    /*
    NOT:
    fonksiyonlar programlarda aşağıdaki şemadaki gibi kullanılır.
    
    
    
    #include<>
    #include<>
    fonksiyon öngösterimleri...
    
    main()
    {
    
    
    program kodları
    +
	fonksiyonun çağrılması
return 0

	}

	fonksiyonun tanımlanması

*/



	
     

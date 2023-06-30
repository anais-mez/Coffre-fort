// initialisation des variables des broches utilisées par les leds rouges
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;
const int led5 = 7;

// initialistion de la variable de la broche utilise par la led verte
const int led_verte = 13;
const int ledv2 = 12;

// initialisation des variables des broches utilisées par les boutons
const int bouton1 = 3;
const int bouton2 = 4;
const int bouton3 = 5;
const int bouton4 = 6;

// initialisation des variables des états des boutons
int etat_btn1, etat_btn2, etat_btn3, etat_btn4;

// initialisation des variables des états des leds
int etat_led1, etat_led2, etat_led3, etat_led4;

// initialisation des tableaux des noms d'agent et de clé publique associée
char nom_agent[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q'};
int cle_public[16] = {601, 619, 631, 641, 647, 653, 661, 673, 691, 701, 733, 739, 751, 797, 809, 811};
int NS_model[8][2] = { {1, 1}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {6, 3}, {7, 4}, {8, 5} };

// initialisation de la variable indice et de reçu des entrées
int ind, model, Ns, R1, R2, R3, R4, R5;
float tension;
char input_v, x;
char card_id[16][5] = {
    {'0', '0', '0', '0', 'A'},
    {'0', '0', '0', '1', 'B'},
    {'0', '0', '1', '0', 'C'},
    {'0', '0', '1', '1', 'D'},
    {'0', '1', '0', '0', 'E'},
    {'0', '1', '0', '1', 'F'},
    {'0', '1', '1', '0', 'H'},
    {'0', '1', '1', '1', 'I'},
    {'1', '0', '0', '0', 'J'},
    {'1', '0', '0', '1', 'K'},
    {'1', '0', '1', '0', 'L'},
    {'1', '0', '1', '1', 'M'},
    {'1', '1', '0', '0', 'N'},
    {'1', '1', '0', '1', 'O'},
    {'1', '1', '1', '0', 'P'},
    {'1', '1', '1', '1', 'Q'},
}

// fonction void setup
void setup() {
    Serial.begin(9600);

    // initialisation des leds rouges comme sorties
    pinMode(led1, OUTPUT);
    pinMode(ledé, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);

    // initialisation de la led verte comme sortie
    pinMode(led_verte, OUTPUT);
    pinMode(ledv2, OUTPUT);

    // initialisation des boutons comme entrées
    pinMode(bouton1, INPUT);
    pinMode(bouton2, INPUT);
    pinMode(bouton3, INPUT);
    pinMode(bouton4, INPUT);

    // initialisation des boutons en position haute
    digitalWrite(bouton1, HIGH);
    digitalWrite(bouton2, HIGH);
    digitalWrite(bouton3, HIGH);
    digitalWrite(bouton4, HIGH);
}

// fonction void loop
void loop() {
    while (digitalRead(led1) == LOW) {
        int etat_btn1 = digitalRead(bouton1);
        int etat_btn2 = digitalRead(bouton2);
        int etat_btn3 = digitalRead(bouton3);
        int etat_btn4 = digitalRead(bouton4);

        if (etat_btn1 == HIGH) {
            digitalWrite(led1, HIGH);
            etat_led1 = HIGH;
        }
        else if ((etat_btn2 == HIGH) || (etat_btn3 == HIGH) || (etat_btn4 == HIGH)) {
            blink();
            etat_led1 = LOW;
            etat_led2 = LOW;
            etat_led3 = LOW;
            etat_led4 = LOW;
        }
    }
    delay(200);
    if (etat_led1 == HIGH) {
        while (digitalRead(led2) == LOW) {
            int etat_btn1 = digitalRead(bouton1);
            int etat_btn2 = digitalRead(bouton2);
            int etat_btn3 = digitalRead(bouton3);
            int etat_btn4 = digitalRead(bouton4);

        if (etat_btn2 == HIGH) {
            digitalWrite(led2, HIGH);
            etat_led2 = HIGH;
        }
        else if ((etat_btn1 == HIGH) || (etat_btn3 == HIGH) || (etat_btn4 == HIGH)) {
            blink();
            etat_led1 = LOW;
            etat_led2 = LOW;
            etat_led3 = LOW;
            etat_led4 = LOW;
        }
        }
    }
    delay(200);
    if (etat_led2 == HIGH) {
        while (digitalRead(led3) == LOW) {
            int etat_btn1 = digitalRead(bouton1);
            int etat_btn2 = digitalRead(bouton2);
            int etat_btn3 = digitalRead(bouton3);
            int etat_btn4 = digitalRead(bouton4);

        if (etat_btn3 == HIGH) {
            digitalWrite(led3, HIGH);
            etat_led3 = HIGH;
        }
        else if ((etat_btn1 == HIGH) || (etat_btn2 == HIGH) || (etat_btn4 == HIGH)) {
            blink();
            etat_led1 = LOW;
            etat_led2 = LOW;
            etat_led3 = LOW;
            etat_led4 = LOW;
        }
        }
    }
    delay(200);
    if (etat_led3 == HIGH) {
        while (digitalRead(led2) == LOW) {
            int etat_btn1 = digitalRead(bouton1);
            int etat_btn2 = digitalRead(bouton2);
            int etat_btn3 = digitalRead(bouton3);
            int etat_btn4 = digitalRead(bouton4);

        if (etat_btn4 == HIGH) {
            digitalWrite(led4, HIGH);
            etat_led4 = HIGH;
        }
        else if ((etat_btn1 == HIGH) || (etat_btn3 == HIGH) || (etat_btn2 == HIGH)) {
            blink();
            etat_led1 = LOW;
            etat_led2 = LOW;
            etat_led3 = LOW;
            etat_led4 = LOW;
        }
        }
    }

    if (digitalRead(led_verte) == HIGH) {
        tension = tension_entrer();
        model = Model();
        Ns = NS(model);

        switch (Ns) {
            case 1 :
                Serial.println("##################################");
                Serial.println("Modèle d'authentification numéro 1");
                Serial.println("##################################");
                Serial.println("");
                R1 = MA1();

                if ( R1 == 1) {
                    Serial.println("##################################");
                    Serial.println("Modèle d'authentification numéro 3");
                    Serial.println("##################################");
                    Serial.println("");
                    R3 = MA3();
                    if ( R1 == 1) {
                        Serial.println("Authentification valide ! Bonjour Agent");
                        Serial.println("");
                        digitalWrite(ledv2, HIGH);
                    }
                    else {
                        Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                        Serial.println("");
                        digitalWrite(led5, HIGH);
                    }
                    // break; 
                }
                else {
                    Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                    Serial.println("");
                    digitalWrite(led5, HIGH);
                }
            case 2 :
                Serial.println("##################################");
                Serial.println("Modèle d'authentification numéro 1");
                Serial.println("##################################");
                Serial.println("");
                R1 = MA1();

                if ( R1 == 1) {
                    Serial.println("##################################");
                    Serial.println("Modèle d'authentification numéro 4");
                    Serial.println("##################################");
                    Serial.println("");
                    R4 = MA4();
                    if ( R4 == 1) {
                        Serial.println("Authentification valide ! Bonjour Agent");
                        Serial.println("");
                        digitalWrite(ledv2, HIGH);
                    }
                    else {
                        Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                        Serial.println("");
                        digitalWrite(led5, HIGH);
                    }
                    // break; 
                }
                else {
                    Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                    Serial.println("");
                    digitalWrite(led5, HIGH);
                }
            case 3 :
                Serial.println("##################################");
                Serial.println("Modèle d'authentification numéro 2");
                Serial.println("##################################");
                Serial.println("");
                R2 = MA2(x);

                if ( R2 == 1) {
                    Serial.println("##################################");
                    Serial.println("Modèle d'authentification numéro 5");
                    Serial.println("##################################");
                    Serial.println("");
                    R5 = MA5(x);
                    if ( R5 == 1) {
                        Serial.println("Authentification valide ! Bonjour Agent");
                        Serial.println("");
                        digitalWrite(ledv2, HIGH);
                    }
                    else {
                        Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                        Serial.println("");
                        digitalWrite(led5, HIGH);
                    }
                    // break; 
                }
                else {
                    Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                    Serial.println("");
                    digitalWrite(led5, HIGH);
                }
            case 4 :
                Serial.println("##################################");
                Serial.println("Modèle d'authentification numéro 2");
                Serial.println("##################################");
                Serial.println("");
                R2 = MA2(x);

                if ( R2 == 1) {
                    Serial.println("##################################");
                    Serial.println("Modèle d'authentification numéro 3");
                    Serial.println("##################################");
                    Serial.println("");
                    R3 = MA3();
                    if ( R3 == 1) {
                        Serial.println("##################################");
                        Serial.println("Modèle d'authentification numéro 4");
                        Serial.println("##################################");
                        Serial.println("");
                        R4 = MA4();
                        if ( R4 == 1) {
                            Serial.println("Authentification valide ! Bonjour Agent");
                            Serial.println("");
                            digitalWrite(ledv2, HIGH);
                        }
                    }
                    else {
                        Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                        Serial.println("");
                        digitalWrite(led5, HIGH);
                    }
                    break; 
                }
                else {
                    Serial.println("Intrusion détectée, le système de sécurité va se déclancher !");
                    Serial.println("");
                    digitalWrite(led5, HIGH);
                }
            default :
                Serial.println("Votre carte n'est pas reconnue par l'agence, le système de sécurité va se déclancher !");
                Serial.println("");
                digitalWrite(led5, HIGH);
        }
    }
    delay(5000);
    digitalWrite(led5, LOW);
    digitalWrite(ledv2, LOW);
}

// fonction MA1
int MA1() {
    int r1, r2, r3, r4, R;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    r4 = 0;
    Serial.println("##################################################");
    Serial.println("Bienvenue au centre de question d'authentification");
    Serial.println("##################################################");
    Serial.println("");
    r1 = Q1();

    if (r1 == 1) {
        r2 = Q2();
        if (r2 == 1) {
            r3 = Q3();
            if (r3 == 1) {
                r4 = Q4();
                if (r4 == 1) {
                    Serial.println("Authentification validé");
                    Serial.println("");
                    R = 1;
                }
                else {
                    Serial.println("Intrusion détectée !!");
                    Serial.println("");
                    R = 0;
                }
            }
            else {
                Serial.println("Intrusion détectée !!");
                Serial.println("");
                R = 0;
            }
        }
        else {
            Serial.println("Intrusion détectée !!");
            Serial.println("");
            R = ;
        }
    }
    else {
        Serial.println("Intrusion détectée !!");
        Serial.println("");
        R = 0;
    }
    return R;
}

// fonction Q1
int Q1() {
    int r, rep1;
    Serial.println("Quel est la capitale de la France ?");
    Serial.println("###################################");
    Serial.println("A - Marseille");
    Serial.println("B - Lille");
    Serial.println("C - Paris");
    Serial.println("D - Versaille");
    Serial.println("###################################");
    
    while ( r != 'A' && r != 'B' && r != 'C' && r != 'D') {
        r = input();
    }
    if ( r == 'C') {
        rep1 = 1;
    }
    else {
        rep1 = 0;
    }

    return rep1;
}

// fonction Q2
int Q2() {
    int r, rep2;
    Serial.println("Où se situe notre agence ?");
    Serial.println("###################################");
    Serial.println("A - En France");
    Serial.println("B - En Angleterre");
    Serial.println("C - En Amérique du nord");
    Serial.println("D - Cette information est confidentielle");
    Serial.println("###################################");
    
    while ( r != 'A' && r != 'B' && r != 'C' && r != 'D') {
        r = input();
    }
    if ( r == 'D') {
        rep2 = 1;
    }
    else {
        rep2 = 0;
    }

    return rep2;
}

// fonction Q3
int Q3() {
    int r, rep3;
    Serial.println("Quel est le nom d'agent du directeur de l'agence ?");
    Serial.println("###################################");
    Serial.println("A - L'agent X");
    Serial.println("B - L'agent R");
    Serial.println("C - L'agent W");
    Serial.println("D - L'agent T");
    Serial.println("###################################");
    
    while ( r != 'A' && r != 'B' && r != 'C' && r != 'D') {
        r = input();
    }
    if ( r == 'A') {
        rep3 = 1;
    }
    else {
        rep3 = 0;
    }

    return rep3;
}

// fonction Q4
int Q4() {
    int r, rep4;
    Serial.println("La divulgation d'information classé secrète est répréhnsible d'une peine de ?");
    Serial.println("###################################");
    Serial.println("A - 2 ans d'emprisonnement");
    Serial.println("B - 5 ans de banissement du territoire");
    Serial.println("C - 10 ans d'affectation au maintient de l'ordre");
    Serial.println("D - La mort");
    Serial.println("###################################");
    
    while ( r != 'A' && r != 'B' && r != 'C' && r != 'D') {
        r = input();
    }
    if ( r == 'D') {
        rep4 = 1;
    }
    else {
        rep4 = 0;
    }

    return rep4;
}

// fonction MA2
int MA2() {
    int M, e, C, R;
    long int Mp;
    Serial.println("#################################");
    Serial.println("Veuillez entrer votre nom d'agent");
    Serial.println("#################################");
    Serial.println("");
    x = input();
    M = random(1, 2882);
    e = CleAgent();
    C = Chiffrer(M, e);
    Serial.println("Message à déchiffrer : ");
    Serial.print(C);
    Serial.println("");

    while (Serial.available() == 0) {
        Mp = Serial.readStringUntil('\n');
    }
    if (M == Mp) {
        Serial.println("Vous êtes authentifié ! Bienvenue Agent");
        Serial.print(x);
        R = 1;
    }
    else {
        Serial.println("Erreur d'authentification, le système se déclanchera dans 5 secondes");
        R = 0;
        delay(5000);
    }
    return R;
}

// fonction Chiffrer()
int Chiffrer(int M, int e) {
    int n;
    int C;
    n = 43*67;
    C = Modexp(M, e, n);
    return C;
}

// fonction Modexp()
int Modexp(int a, int e, int n) {
    int r;
    if (e < 0) {
        Serial.println("unhandled case");
        exit(-1);
    }
    if ((a == 0) || (n == 1)) {
        r = 0;
    }
    else {
        r = 1;
        while ( e > 0) {
            r = (r * (a % n)) % n;
            e = e - 1;
        }
    }
    return r;
}

// fonction CleAgent()
int CleAgent(int x) {
    for (int i = 0; i !=15; i++) {
        if (nom_agent[i] == nom_agent[x]) {
            int ind = i;
            break;
        }
    }
    return cle_public[ind];
}

// fonction MA3()
int MA3() {
    int R, retine;
    Serial.println("############################################################");
    Serial.println("Scan rétinien - Veuillez approchez votre oeil");
    Serial.println("(Dans ce cas, l'entrée d'une lettre dans la console suffira)");
    Serial.println("############################################################");
    Serial.println("");
    Serial.println("############################################################");
    Serial.println("##      A      #       B      #      C      #      D      ##");
    Serial.println("##   Oeil 1    #    Oeil 2    #   Oeil 3    #    Oeil 4   ##");
    Serial.println("############################################################");

    while ( retine != 'A' && retine != 'B' && retine != 'C' && retine !='D') {
        retine = input();
    }
    if (retine == 'C') {
        Serial.println("Authentification validée");
        R = 1;
    }
    else {
        Serial.println("Intrusion détectée !!");
        R = 0:
    }
    return R;
}

// fonction MA4()
int MA4() {
    int R, finger;
    Serial.println("############################################################");
    Serial.println("Lecteur d'empreinte - Veuillez approchez votre doigt");
    Serial.println("(Dans ce cas, l'entrée d'une lettre dans la console suffira)");
    Serial.println("############################################################");
    Serial.println("");
    Serial.println("############################################################");
    Serial.println("##      A      #       B      #      C      #      D      ##");
    Serial.println("##   Doigt 1   #    Doigt 2   #   Doigt 3   #   Doigt 4   ##");
    Serial.println("############################################################");

    while ( finger != 'A' && finger != 'B' && finger != 'C' && finger !='D') {
        finger = input();
    }
    if (finger == 'B') {
        Serial.println("Authentification validée");
        R = 1;
    }
    else {
        Serial.println("Intrusion détectée !!");
        R = 0:
    }
    return R;
}

// fonction MA5()
int MA5(char x) {
    char y1, y2, Y3, Y4;
    int R, ind;
    for (int i = 0; i < 15; i++) {
        if (x == card_id[i][4]) {
            ind = i;
        }
    }
    while (y1 != '1' && y1 != '0') {
        y1 = input();
    }
    while (y2 != '1' && y2 != '0') {
        y2 = input();
    }
    while (y3 != '1' && y3 != '0') {
        y3 = input();
    }
    while (y4 != '1' && y4 != '0') {
        y4 = input();
    }
    if (y1 == card_id[ind][0]) {
        if (y2 == card_id[ind][1]) {
            if (y3 == card_id[ind][2]) {
                if (y4 == card_id[ind][3]) {
                    Serial.println("Authentification valide");
                    Serial.println("");
                    R = 1;
                }
                else {
                    Serial.println("Authentification invalide");
                    Serial.println("");
                    R = 0;
                }
            }
            else {
                Serial.println("Authentification invalide");
                Serial.println("");
                R = 0;
            }
        }
        else {
            Serial.println("Authentification invalide");
            Serial.println("");
            R = 0;
            
    }
    else {
        Serial.println("Authentification invalide");
        Serial.println("");
        R = 0;
    }
}

// fonction blink
void blink() {
    int i = 0;
    while( i < 3) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);

        delay(250);

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);

        delay(250);

        i += 1;
    }
}

// fonction input
char input() {
    while(Serial.available() == 0) {
        input_v = Serial.read();
        delay(500);
        return input_v;
    }
}

// fonction NS
int NS(int model) {
    int Ns, ind1;
    for (int i = 0; i != 7; i++) {
        if (NS_model[i][0] == model) {
            ind1 = i;
        }
    }
    NS = NS_model[ind1][1];
    return Ns;
}

// fonction Model()
int Model() {
    int M;
    if (tension <= 1.42) {
        M = 1;
    }
    if (tension <= 2.3) {
        M = 2;
    }
    if (tension <= 2.78) {
        M = 3;
    }
    if (tension <= 3.26) {
        M = 4;
    }
    if (tension <= 3.47) {
        M = 5;
    }
    if (tension <= 3.66) {
        M = 6;
    }
    if (tension <= 4) {
        M = 7;
    }
    if (tension <= 4.27) {
        M = 8;
    }
    else {
        M = 9;
    }
    return M;
}

// fonction tension_entrer()
float tension_entrer() {
    float tension = analogRead(Ao);
    return tension;
}
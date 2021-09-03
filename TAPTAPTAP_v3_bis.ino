/*
 * La version V3 bis a été crée à Milan le 3/7/21 par Flo de SIGMASIX
 * Un des module 4 relay est deffectueux, la sortie NO du relay 3 ne fonctionne plus par contre le NC oui.
 * Du coup cette version du firmware intervertit la logique du relay 3. Une fois le relay board remplacé, le firmware v3 devra etre reuploader
 * 
 */
//int nbmots;
//int randSole;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  randomSeed(analogRead(0));
}

unsigned long newrandom(unsigned long howsmall, unsigned long howbig){
  return howsmall + random() % (howbig-howsmall);
  }

// the loop function runs over and over again forever
void loop() {
  int nbmots = random(5, 30);


  for (int i = 0 ; i < nbmots ; i++)
  {
    int randSole = newrandom(2, 5);
    if (randSole == 3){
      digitalWrite(randSole, HIGH);   
      delay(100);                    
      digitalWrite(randSole, LOW);  
      delay(500);
    } else {
      digitalWrite(randSole, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(100);                      // wait for a second
      digitalWrite(randSole, HIGH);    // turn the LED off by making the voltage LOW
      delay(500);          // fonction à répéter
    }
  }
  delay(500);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(5, HIGH);
  delay(10000);
}

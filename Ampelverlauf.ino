//Inizialisierung für den roten Knopf
int buttonState = LOW;

void setup() {
  //outputs, weil sie etwas von sich geben, in diesem Fall Licht. 
  //grünes Licht
  pinMode(7, OUTPUT);
  gelbes Licht
  pinMode(5, OUTPUT);
  //rotes Licht
  pinMode(3, OUTPUT);
  //input, weil es ein Knopf ist der gedrückt wird
  //ist für den roten Knopf
  pinMode(10, INPUT);
  //dient für die Ausgabe in der Konsole
  Serial.begin(9800);
}

void loop() {
//der Status des Knopfs wird eingelesen.
buttonState = digitalRead(10);
//hier wird ein Test mit dem Wert des Knopfs ausgegeben. 
Serial.print("erster println ");
Serial.println(buttonState);

  //falls der Knopf nicht gedrückt wurde geht es in den folgenden Code
  if(buttonState == LOW){
    /*Ampel wird hier implementiert */
    //rotes Signal
    digitalWrite(3, HIGH);
    delay(500);
    //aufläuchten des gelben Signals
    digitalWrite(5, HIGH);
    delay(1000);
    //Ausstellen des roten und gelben Signals
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delay(100);

    //grünes Signal geht auf, welches im Alltag ebenso vorhanden ist
    digitalWrite(7, HIGH);
    delay(5000);

    /* wieder auf rot */
    //grünes Signal ausgehen lassen
    digitalWrite(7, LOW);
    delay(700);
    // gelbes Signal aufleuchten lassen
    digitalWrite(5, HIGH);
    delay(500);
    //gelbes Signal ausstellen
    digitalWrite(5, LOW);
    //nur noch rotes Signal leuchtet. 
    digitalWrite(3, HIGH);  
    delay(5000);
  //falls roter Knopf gedrückt wurde
  if(buttonState == HIGH){
      //ausschalten von grün und rot
      digitalWrite(3, LOW);
      digitalWrite(7, LOW);
      //einlesen des Knopfs ob er gedrückt wurde oder nicht.
      buttonState = digitalRead(10);
      //solange der Knopf kein zweites Mal gedrückt wird. 
  while(buttonState == LOW){ 
      //blinkendes Licht
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      delay(500);
      //einlesen des Knopfs, ob er gedrückt wurde oder nicht.
      buttonState = digitalRead(10);
    }
  }
  
}

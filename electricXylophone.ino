int sharpSwitchPin = 13;
int buzzerPin = 12;
int noteButtonPins [] = {8, 7, 6, 5, 4, 3, 2};
int sustainPotentiometerPin = A3;
int octaveControlPotentiometerPin = A4;
int redPin = 9;
int bluePin = 10;
int greenPin = 11;
int numNoteButtons = 7;
double octaveControlValue;
int notes [7];
int buttonValues [] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int sustainTime;
  
void setup()
{
  // Setting the pin for the switch to input
  pinMode(sharpSwitchPin, INPUT);
  // Setting the pin for the buzzer to output
  pinMode(buzzerPin, OUTPUT);
  // Setting all of the pins for the buttons to input
  for (int i = 0; i < numNoteButtons; i++)
  {
   	pinMode(noteButtonPins[i], INPUT);
  }
  // Setting all of the pins for the RGB LED to output
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{  
  analogWrite(greenPin, 255); // Tells the RGB LED to change its colour to green
  octaveControlValue = (analogRead(octaveControlPotentiometerPin)) / 3.79259;  // Determines the angle that the arrow on the potentiometer is at
  // Checks if the user wants to use natural notes
  if (digitalRead(sharpSwitchPin) == HIGH)
  {
    // Checks which octave the user wants and stores the notes in that octave
    if(octaveControlValue < 45 && octaveControlValue >= 0)
    {
      notes[0] = 1760;
      notes[1] = 1976;
      notes[2] = 2093;
      notes[3] = 2349;
      notes[4] = 2637;
      notes[5] = 2794;
      notes[6] = 3136;
    }
    else if (octaveControlValue < 90 && octaveControlValue >= 45)
    {
      notes[0] = 880;
      notes[1] = 988;
      notes[2] = 1047;
      notes[3] = 1175;
      notes[4] = 1319;
      notes[5] = 1397;
      notes[6] = 1568;
    }
    else if (octaveControlValue < 135 && octaveControlValue >= 90)
    {
      notes[0] = 440;
      notes[1] = 494;
      notes[2] = 523;
      notes[3] = 587;
      notes[4] = 659;
      notes[5] = 698;
      notes[6] = 784;
    }
    else if (octaveControlValue < 180 && octaveControlValue >= 135)
    {
      notes[0] = 220;
      notes[1] = 247;
      notes[2] = 262;
      notes[3] = 294;
      notes[4] = 330;
      notes[5] = 349;
      notes[6] = 392;
    }
    else if (octaveControlValue < 225 && octaveControlValue >= 180)
    {
      notes[0] = 110;
      notes[1] = 123;
      notes[2] = 131;
      notes[3] = 147;
      notes[4] = 165;
      notes[5] = 175;
      notes[6] = 196;
    }
    else
    {
      notes[0] = 55;
      notes[1] = 62;
      notes[2] = 65;
      notes[3] = 73;
      notes[4] = 82;
      notes[5] = 87;
      notes[6] = 98;
    }
  }
  // Checks if the user wants to use sharp notes
  else
  {
    // Checks which octave the user wants and stores the notes in that octave
    if (octaveControlValue < 45 && octaveControlValue >= 0)
    {
      notes[0] = 1865;
      notes[1] = 2093;
      notes[2] = 2217;
      notes[3] = 2489;
      notes[4] = 2794;
      notes[5] = 2960;
      notes[6] = 3322;
    }
    else if (octaveControlValue < 90 && octaveControlValue >= 45)
    {
      notes[0] = 932;
      notes[1] = 1047;
      notes[2] = 1109;
      notes[3] = 1245;
      notes[4] = 1397;
      notes[5] = 1480;
      notes[6] = 1661;
    }
    else if (octaveControlValue < 135 && octaveControlValue >= 90)
    {
      notes[0] = 466;
      notes[1] = 523;
      notes[2] = 554;
      notes[3] = 622;
      notes[4] = 698;
      notes[5] = 740;
      notes[6] = 831; 
    }
    else if (octaveControlValue < 180 && octaveControlValue >= 135)
    {
      notes[0] = 233;
      notes[1] = 262;
      notes[2] = 277;
      notes[3] = 311;
      notes[4] = 349;
      notes[5] = 370;
      notes[6] = 415;
    }
    else if (octaveControlValue < 225 && octaveControlValue >= 180)
    {
      notes[0] = 117;
      notes[1] = 131;
      notes[2] = 139;
      notes[3] = 156;
      notes[4] = 175;
      notes[5] = 185;
      notes[6] = 208;
    }
	else
    {
      notes[0] = 58;
      notes[1] = 65;
      notes[2] = 69;
      notes[3] = 78;
      notes[4] = 87;
      notes[5] = 93;
      notes[6] = 104;
    }
  }
  
  sustainTime = (analogRead(sustainPotentiometerPin))*5 + 500; // Determines how long the user wants notes to sustain for
  
  // Checks the state of each button. If a button is newly pressed the program will change the colour of the LED and play a note
  for (int i = 0; i < numNoteButtons; i++)
  {
    // Checks if a button has been newly pressed. If it has, the program will change the colour of the LED and play a note
    if (digitalRead(noteButtonPins[i]) == LOW && buttonValues[i] == HIGH)
    { 
      analogWrite(greenPin, 0);
      analogWrite(redPin, 255);
      tone(buzzerPin, notes[i]);
      delay(sustainTime);
      noTone(buzzerPin);
      analogWrite(redPin, 0);
    }
  }
  // Stores the current button states
  for (int i = 0; i < numNoteButtons; i++)
  {
   	buttonValues [i] = digitalRead(noteButtonPins[i]); 
  } 
}



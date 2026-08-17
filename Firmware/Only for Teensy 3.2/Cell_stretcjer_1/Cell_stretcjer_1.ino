#include "TeensyStep.h"
#include <Encoder.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Bounce.h>

Encoder freq_knob(5, 6);
Encoder stretch_knob(8, 9);


const int encoder_SW = 7;
const int encoder_SW_2 = 10;

// Instantiate a Bounce object with a 5 millisecond debounce time
Bounce pushbutton = Bounce( encoder_SW,20 ); 
Bounce pushbutton2 = Bounce( encoder_SW_2,20 ); 

const int Enable = 2;
const int DIR = 4;
const int STEP = 3;

Stepper M1(STEP, DIR);  

const int SW1 = 23; // Photo_switch
//const int SW2 = 17;
//const int SW3 = 21;
//const int SW4 = 23;

StepControl step_controller;    // The StepControl class is used to synchronously move up to 10 motors to their target positions.

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int MS1 = 20;
const int MS2 = 21;
const int MS3 = 22;

float um_per_step = 1.6; //400 steps/revolution
const int steps_per_mm = 100;
int steps = 0;
const int initial_pos_mm = 1;
const int initial_steps = initial_pos_mm*steps_per_mm;
const int compression_steps = 3000;

int mode = 0;

float freq = 0;
float freq_factor = 0.05;
float stretch = 0;
float T;
const float initial_stretch_length = 20;
float p_stretch;
unsigned long t = 0;
bool state = 0;
float vel;
int steps_s;
float accel;
int steps_s2;

void setup()
{
  pinMode(MS1, OUTPUT);    // set the MS1, MS2, MS3 and Enable as an outputs
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);

  pinMode(Enable, OUTPUT);

  digitalWrite(MS1, LOW); 
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);

  digitalWrite(Enable, LOW); // set the enables to LOW

  // Set the motor max acceleration
  M1.setMaxSpeed(1000)
  .setAcceleration(5000)   // stp/s^2
  .setInverseRotation(false);

  pinMode(SW1, INPUT_PULLUP);
  
  pinMode(encoder_SW, INPUT_PULLUP);
  pinMode(encoder_SW_2, INPUT_PULLUP);
  
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  delay(1000);
  display.clearDisplay(); 

  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println(F("HOMING"));
  
  Homing_routine();
  
  Serial.println("Homing completed");

  //delay(1000);
  // Go to initial position
  M1.setTargetAbs(initial_steps);
  step_controller.move(M1);

  
  digitalWrite(Enable, HIGH); // Remove power from the motor to decrease heat


  
}

void loop()
{

//steps = 300; // 3 mm 
//simultaneous();

 
//Serial.println(digitalRead(SW1));
  freq = abs(freq_knob.read())/4*freq_factor; // Select the frequency in Hz
  stretch = abs(stretch_knob.read())/4*0.05; // select the stretch in mm 

  //Constrained frequancy and stretch
  freq = constrain(freq, 0, 1);
  stretch = constrain(stretch, 0, 3);
  
  
  p_stretch = stretch/(initial_stretch_length)*100; // Calculate percentage of stretch, period and motor speed based on the previous user selection
  T = 1/freq; // Calculate the period

  vel = 1.5*(stretch/(T/2)); // 1.5 = 3/2 Because 1/3 of the time is used for accelerating, 1/3 is used for constant velocity, and 1/3 is used for decelerating.
  accel = vel/(T/6);
  
  t = T*1000; // Convert the period in milliseconds

  // Get steps from mm selected by the user using the stretch knob
  steps = mm_to_step(stretch); // Divided by two beacuse it is what will move each arm

  // Get steps/s from the selected velocity
  steps_s = mm_to_step(vel);

  // Get steps/s^2 from the acceleration calculated based on displacement and frequency
  steps_s2 = mm_to_step(accel);
  
  //Set the selected motor speed
  set_velocity(steps_s);

  //Set the acceleration
  set_acceleration(steps_s2);

  OLED_display(); // Display selection

  read_pushbutton();
  read_pushbutton2();

  
  if (state == 1)
  {
    read_pushbutton();
    simultaneous();  
  }

//  if (state == 1 && mode == 0)
//  {
//    read_pushbutton();
//    simultaneous();  
//  }
//
//  if (state == 1 && mode == 1)
//  {
//    read_pushbutton();
//    alternate();  
//  }
//  if (state == 1 && mode == 2)
//  {
//    read_pushbutton();
//    one_by_one();
//  };
//  if (state == 1 && mode == 3)
//  {
//    read_pushbutton();
//    x_axis();
//  };
//  if (state == 1 && mode == 4)
//  {
//    read_pushbutton();
//    y_axis();
//  };
//  if (state == 1 && mode == 5)
//  {
//    read_pushbutton();
//    compression();
//  };
}

// Function to get the steps from the mm
int mm_to_step (float mm)
{
  int steps;
  steps = mm * 100; // 100 steps per mm
  return steps;
}

// Function to get the mm from the steps
float step_to_mm (int steps)
{
  float mm;
  mm = steps * 0.01; // 0.01 mm per step
  return mm;
}

//Function to rotate the left motor CW
void TurnClockwise_M1 (int pd)
{
  digitalWrite(DIR, 0);
  digitalWrite(STEP, HIGH);
  digitalWrite(STEP, LOW);
  delayMicroseconds(pd);
}

void read_pushbutton()
{
  if (pushbutton.update())
  {
    if (pushbutton.fallingEdge())
    {
      state = !state;
    }
  }
}

void read_pushbutton2()
{
  if (pushbutton2.update())
  {
    if (pushbutton2.fallingEdge())
    {
      mode = mode +1;
      mode = constrain(mode, 0, 5);
    }
  }
}

void Homing_routine()
{
  
  while (digitalRead(SW1) == LOW)
  {
    TurnClockwise_M1 (5000);
    Serial.println(digitalRead(SW1));
  }
}

void set_velocity(int v)
{  
  // Set the motor max speed
  M1.setMaxSpeed(v);
}

void set_acceleration(int a)
{  
  // Set the motor max speed
  M1.setAcceleration(a);
}
void OLED_display()
{
  display.clearDisplay();
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println(F("Cell stretcher"));
  display.println();
  display.print(F("Frequency:"));
  display.print(freq);
  display.println(F(" Hz"));
  //display.println();
  display.print(F("Stretch:"));
  display.print(stretch);
  display.println(F(" mm"));
  //display.println();
  display.print(F("%Stretch:"));
  display.print(p_stretch);
  display.println(F(" %"));
//  display.print(F("Steps stretch:"));
//  display.println(steps);
  //display.println();
  display.print(F("Period:"));
  display.print(T);
  display.println(F(" s"));
  //display.println();
  display.print(F("State:"));
  //display.print(state);
  if (state == 0){display.println(F("Inactive"));}
  if (state == 1){display.println(F("Active"));}
  display.print(F("Mode:"));
  display.println(F("Simult"));
//  if (mode == 0){display.println(F("Simult"));}
//  if (mode == 1){display.println(F("Alternate"));}
//  if (mode == 2){display.println(F("Separete"));}
//  if (mode == 3){display.println(F("X axis"));}
//  if (mode == 4){display.println(F("Y axis"));}
//  if (mode == 5){display.println(F("Compress"));}
//  display.print(mode);
  display.display();
}

void simultaneous()
{
   digitalWrite(Enable, LOW); // Enable the motor again
    
    // Set the target for each motor and move to the target
    M1.setTargetAbs(initial_steps+steps);
    step_controller.move(M1);

    digitalWrite(Enable, HIGH); // Remove power from the motor to decrease heat

    //delay(t);

    digitalWrite(Enable, LOW); // Enable the motor again

    // Com back to the origin
    M1.setTargetAbs(initial_steps);
    step_controller.move(M1);

    digitalWrite(Enable, HIGH); // Remove power from the motor to decrease heat  
}

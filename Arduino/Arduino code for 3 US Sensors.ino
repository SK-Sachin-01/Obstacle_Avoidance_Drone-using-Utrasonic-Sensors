#include <SoftwareSerial.h>

#define MAX_DISTANCE 100

#define trig_F 1                      // F -> FRONT
#define echo_F 2                      // B -> BACK
#define trig_R 3                      // R -> RIGHT
#define echo_R 4                      // L -> LEFT
#define trig_L 5                     
#define echo_L 6
#define motor_FR 7
#define motor_FL 8
#define motor_BR 9
#define motor_BL 10

int FSD, RSD, LSD;       // FSD -> FRONT_SENSOR_DISTANCE,    RSD -> RIGHT_SENSOR_DISTANCE,      LSD -> LEFT_SENSOR_DISTANCE

void setup() {
  Serial.begin(9600);
  pinMode(trig_F, OUTPUT);
  pinMode(echo_F, INPUT);
  pinMode(trig_R, OUTPUT);
  pinMode(echo_R, INPUT);
  pinMode(trig_L, OUTPUT);
  pinMode(echo_L, INPUT);
  pinMode(motor_FR, OUTPUT);
  pinMode(motor_FL, OUTPUT);
  pinMode(motor_BR, OUTPUT);
  pinMode(motor_BL, OUTPUT);
}

void loop() {
  FSD = CALCULATE_DISTANCE(trig_F, echo_F);
  RSD = CALCULATE_DISTANCE(trig_R, echo_R);
  LSD = CALCULATE_DISTANCE(trig_L, echo_L);


  if( FSD < MAX_DISTANCE ){
      if( RSD < MAX_DISTANCE ){
        if(LSD < MAX_DISTANCE) ROTATE();
        else MOVE_LEFT();
      }
          
      else
          MOVE_RIGHT();
  }
  else
    MOVE_FORWARD();  
}

int CALCULATE_DISTANCE(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration / 58;

  return distance;
}



void MOVE_FORWARD() {
  analogWrite(motor_FR, 50);
  analogWrite(motor_FL, 50);
  analogWrite(motor_BR, 150);
  analogWrite(motor_BL, 150);
}

void MOVE_RIGHT() {
  analogWrite(motor_FR, 50);
  analogWrite(motor_FL, 150);
  analogWrite(motor_BR, 50);
  analogWrite(motor_BL, 150);
}

void MOVE_LEFT() {
  analogWrite(motor_FR, 150);
  analogWrite(motor_FL, 50);
  analogWrite(motor_BR, 150);
  analogWrite(motor_BL, 50);
}

void ROTATE() {
  analogWrite(motor_FR, 150);
  analogWrite(motor_FL, 50);
  analogWrite(motor_BR, 50);
  analogWrite(motor_BL, 150);
}

void STOP_MOTORS() {
  analogWrite(motor_FR, 0);
  analogWrite(motor_FL, 0);
  analogWrite(motor_BR, 0);
  analogWrite(motor_BL, 0);
}







// void CALCULATE_PITCH() {
//   if (FSD < MAX_DISTANCE)
//     PITCH = 1500 + (MAX_DISTANCE - FSD)*5;                     // Min Pitch = 1000, Mid Pitch = 1500, Max Pitch = 2000
//   else
//     PITCH = 1500;
// }

// void CALCULATE_ROLL(int SENSOR_DISTANCE) {
//   if ((SENSOR_DISTANCE==RSD) && (RSD < MAX_DISTANCE))
//     ROLL = 1050 + 5*RSD ;                                       // Min ROLL = 1000, Mid ROLL = 1500, Max ROLL = 2000

//   else if((SENSOR_DISTANCE==LSD) && (LSD < MAX_DISTANCE))
//     ROLL = 1500 + (MAX_DISTANCE - LSD)*5;

//   else
//     ROLL = 1500;
// }



// void SELECT_SENSOR(){

        
//   if(FSD!=0 && RSD==LSD==0)
//     CALCULATE_PITCH();

//   else if(RSD!=0 && FSD==LSD==0 )
//     CALCULATE_ROLL(RSD);

//   else if(LSD!=0 && RSD==FSD==0 )
//     CALCULATE_ROLL(LSD);

//   else if(FSD!=0 && RSD!=0 && LSD==0){ 
//       if( (FSD) < (RSD) )
//         CALCULATE_PITCH();
//       else
//         CALCULATE_ROLL(RSD);  
//   }

//   else if(FSD!=0 && LSD!=0 && RSD==0){ 
//       if( (FSD) < (LSD) )
//         CALCULATE_PITCH();
//       else
//         CALCULATE_ROLL(LSD);  
//   }

//   else if(RSD!=0 && LSD!=0 && FSD==0){ 
//       if( (RSD) < (LSD) )
//         CALCULATE_ROLL(RSD);
//       else
//         CALCULATE_ROLL(LSD);  
//   }

// }


  // if(FSD==0){
  //   if(RSD==0 && LSD!=0)
  //     CALCULATE_ROLL(LSD);
  //   else if(LSD==0 && RSD!=0)
  //     CALCULATE_ROLL(RSD);
  //   else if(LSD!=0 && RSD!=0){
  //     if(RSD<LSD)
  //       CALCULATE_ROLL(RSD);
  //     else
  //       CALCULATE_ROLL(LSD);
  //   }      
  // }
    
  // else if(RSD==0){
  //   if(LSD==0 && FSD!=0)
  //     CALCULATE_PITCH(FSD);
  //   else if(LSD!=0 && FSD!=0){
  //     if(FSD<LSD)
  //       CALCULATE_PITCH(FSD);
  //     else
  //       CALCULATE_ROLL(LSD);
  //   }      
  // }

  // else if(LSD==0){ 
  //   if( FSD<RSD)
  //     CALCULATE_PITCH(FSD);
  //   else
  //     CALCULATE_ROLL(RSD);  
  // }

  // else{
  //   if(FSD<RSD){
  //     if(FSD<LSD)
  //       CALCULATE_PITCH(FSD);
  //     else
  //       CALCULATE_ROLL(LSD);
  //   }
  //   else
  //     CALCULATE_ROLL(RSD);    
  // }



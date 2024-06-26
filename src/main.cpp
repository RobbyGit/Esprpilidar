#include <Arduino.h>
#include <RPLidar.h>

// // You need to create an driver instance 
RPLidar lidar;

// #define RPLIDAR_MOTOR 3 // The PWM pin for control the speed of RPLIDAR's motor.
//                         // This pin should connected with the RPLIDAR's MOTOCTRL signal 
                       
                        
// void setup() {
//   // bind the RPLIDAR driver to the arduino hardware serial
//   lidar.begin(Serial);
  
//   // set pin modes
//   pinMode(RPLIDAR_MOTOR, OUTPUT);
// }

// void loop() {
//   if (IS_OK(lidar.waitPoint())) {
//     float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
//     float angle    = lidar.getCurrentPoint().angle; //anglue value in degree
//     bool  startBit = lidar.getCurrentPoint().startBit; //whether this point is belong to a new scan
//     byte  quality  = lidar.getCurrentPoint().quality; //quality of the current measurement
    
     
    
//   } else {
//     analogWrite(RPLIDAR_MOTOR, 0); //stop the rplidar motor
    
//     // try to detect RPLIDAR... 
//     rplidar_response_device_info_t info;
//     if (IS_OK(lidar.getDeviceInfo(info, 100))) {
//        // detected...
//        lidar.startScan();
       
//        // start motor rotating at max allowed speed
//        analogWrite(RPLIDAR_MOTOR, 255);
//        delay(1000);
//     }
//   }
// }

HardwareSerial mySerial2(0);

void setup() {
  USBSerial.begin(115200);
  lidar.begin(mySerial2);
}


void loop() {
  if (IS_OK(lidar.waitPoint())) {
    float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
    float angle    = lidar.getCurrentPoint().angle; //anglue value in degree
    bool  startBit = lidar.getCurrentPoint().startBit; //whether this point is belong to a new scan
    byte  quality  = lidar.getCurrentPoint().quality; //quality of the current measurement
    
    USBSerial.print(int(distance)); // Print distance as an integer
    USBSerial.print(","); // Separate distance and angle with a comma
    USBSerial.print(int(angle)); // Print angle as an integer
    USBSerial.println("|"); // Separate distance and angle with a pipe
    
  } else {
    //analogWrite(RPLIDAR_MOTOR, 0); //stop the rplidar motor     
    // try to detect RPLIDAR... 
    rplidar_response_device_info_t info;
    if (IS_OK(lidar.getDeviceInfo(info, 100))) {
       // detected...
       lidar.startScan();
       
       // start motor rotating at max allowed speed
       //analogWrite(RPLIDAR_MOTOR, 255);
       delay(1000);
    }
  }
}


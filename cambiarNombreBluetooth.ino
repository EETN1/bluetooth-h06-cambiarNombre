//Utilizar para renombrar los modulos H06 Bluetooth
//Tener en cuenta Cambiar en la consola Nueva Linea, la frecuencia en 9600 baudios

#include <SoftwareSerial.h>
SoftwareSerial BT1(10,11); // RX, TX recorder que se cruzan

void setup()
   {
       Serial.begin(9600);
       Serial.println("Ingresar comando AT:");
         //Para cambiar el nombre deben escribir lo siguiente en la consola:
         //AT+NAME=nombreDeMiBluetooth    
         //Para cambiar la frecuencia ponemos el indice correspondiente en lugar de la x  AT+BAUDx
         //  1 – 1200bps
         // 2 – 2400bps
         // 3 – 4800bps
         // 4 – 9600bps (Default)
         // 5 – 19200bps
         // 6 – 38400bps
         // 7 – 57600bps
         // 8 – 115200bps   
         //como por ejemplo AT+BAUD4 para fijarlo en 9600
   
       BT1.begin(9600);
   }

void loop()
   {
       if (BT1.available())
           Serial.write(BT1.read());
       
       if (Serial.available())
          {  String S = GetLine();
             BT1.print(S);
             Serial.println("---> " + S);
          }
}

String GetLine()
   {   String S = "" ;
       if (Serial.available())
          {    char c = Serial.read(); ;
                while ( c != '\n')            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = Serial.read();
                  }
                return( S + '\n') ;
          }
   }

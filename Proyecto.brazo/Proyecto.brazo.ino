
#include <Servo.h>
Servo adat; //adelante y atras.
Servo arab;//arriba y abajo.
Servo gar;//garra.


void setup() {
  
Serial.begin(9600);

pinMode(11, OUTPUT); // Pin 11 se conecta a al pin IN4 de la placa del motor paso a paso.
pinMode(10, OUTPUT); // Pin 10 se conecta a al pin IN3 de la placa del motor paso a paso.
pinMode(9, OUTPUT); // Pin 9 se conecta a al pin IN2 de la placa del motor paso a paso.
pinMode(8, OUTPUT); // Pin 8 se conecta a al pin IN1 de la placa del motor paso a paso.

adat.attach(6);//el servo adat se ubica en el pin digital(pwm)9.
arab.attach(5);//el servo arab se ubica en el pin digital(pwm)10.
gar.attach(3);//el servo gar se ubica en el pin digital(pwm)11.

adat.write(24);
arab.write(77);
gar.write(0);

Serial.println("    -SERVO 1, MUEVE LA GARRA ADELANTE Y ATRAS");
Serial.println("    -SERVO 2, MUEVE LA GARRA ARRIBA Y ABAJO");
Serial.println("    -SERVO 2, ABRE Y CIERRA LA GARRA");
Serial.println("    -ROTACION, HACE ROTAR EL BRAZO SOBRE SU PROPIO EJE 360°");
Serial.println("-----------------------------------------------------------------------");
Serial.println("..............PUEDE ESCOGER ENTRE 3 POSICIONES DEL BRAZO..............");
Serial.println("  POSICION a, SERVO 1: 24°, SERVO 2: 77°, SERVO 3: 0°, ROTACION: 0°");
Serial.println("  POSICION b, SERVO 1: 24°, SERVO 2: 112°, SERVO 3: 0°, ROTACION: 90°");
Serial.println("  POSICION c, SERVO 1: 76°, SERVO 2: 112°, SERVO 3: 0°, ROTACION: 180°");
Serial.println("  POSICION d, SERVO 1: 63°, SERVO 2: 68°, SERVO 3: 0°, ROTACION: 270°");
Serial.println("  POSICION e, EL BRAZO SE MUEVE SEGUN EL JOYSTICK");
Serial.println("  -----------------POR DEFECTO SE INICIA EN LA POSICION A--------------");




}

void loop() {

  
if(Serial.available()>=1)
   {
    
   char cmd;//varible char para guardar un caracter
   cmd = Serial.read();//lee un caracter, que es el comando para saber en que poscicion se ubica el brazo
   Serial.print("ud indico posicion:");
   Serial.println(cmd);
     
 if(cmd == 'a'|| cmd == 'A')
 {
  adat.write(27);
  arab.write(77);
  gar.write(0);


 }else if(cmd == 'b'|| cmd == 'B') 
{
  adat.write(76);
  arab.write(77);
  gar.write(0);
  
}
 }

  



  

}

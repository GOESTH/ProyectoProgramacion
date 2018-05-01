
#include <Servo.h>
Servo adat; //adelante y atras.
Servo arab;//arriba y abajo.
Servo gar;//garra.


void setup() {
  
Serial.begin(9600);
adat.attach(9);//el servo adat se ubica en el pin digital(pwm)9.
arab.attach(10);//el servo arab se ubica en el pin digital(pwm)10.
gar.attach(11);//el servo gar se ubica en el pin digital(pwm)11.

char cmd;//lee un caracter, que es el comando para saber en que poscicion se ubica el brazo

}


void loop() {

  //El brazo de mueve en dos ejes X y Y


  

}

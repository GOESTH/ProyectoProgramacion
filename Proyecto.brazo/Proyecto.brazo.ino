
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

adat.write(24);
arab.write(77);
gar.write(0);
Serial.println("   SERVO 1, MUEVE LA GARRA ADELANTE Y ATRAS");
Serial.println("   SERVO 2, MUEVE LA GARRA ARRIBA Y ABAJO");
Serial.println("   SERVO 2, ABRE Y CIERRA LA GARRA");
Serial.println("   ROTACION, HACE ROTAR EL BRAZO SOBRE SU PROPIO EJE 360°");
Serial.println("-------------------------------------------------------");
Serial.println("PUEDE ESCOGER ENTRE 3 POSICIONES DEL BRAZO");
Serial.println("POSICION A, SERVO 1: 24°, SERVO 2: 77°, SERVO 3: 0°");
Serial.println("SERVO 2, MUEVE LA GARRA ARRIBA Y ABAJO");


Serial.println("POSICION 1, DEFINA ");


}

void loop() {

  
if(Serial.available()>=1)
   {
    char cmd;//lee un caracter, que es el comando para saber en que poscicion se ubica el brazo
        cmd = Serial.read();
      Serial.print("ud indico posicion:");
     Serial.println(posicion);
     
 if(posicion == 'a')
 {
adat.write(grad1);
arab.write(grad2);
gar.write(grad3);



Serial.println(posicion);
Serial.println("posicion");


 }else if(posicion == 'b') 
{
adat.write(24);
arab.write(112);
gar.write(0);
}
 
      
   }

  



  

}

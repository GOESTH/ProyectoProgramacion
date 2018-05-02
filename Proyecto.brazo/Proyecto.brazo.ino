
#include <Servo.h>
Servo adat; //adelante y atras.
Servo arab;//arriba y abajo.
Servo gar;//garra.
int velmo = 5;// Tiempo (milisegundos)que tarda en dar un paso el motor paso a paso.
int anges = 0;// Angulo escogido por el caracter seleccionado.
int posicion_motor = 0;// grado en el que esta el motor paso a paso


void setup() {
  
Serial.begin(9600);

pinMode(11, OUTPUT); // Pin 11 se conecta a al pin IN4 de la placa del motor paso a paso.
pinMode(10, OUTPUT); // Pin 10 se conecta a al pin IN3 de la placa del motor paso a paso.
pinMode(9, OUTPUT); // Pin 9 se conecta a al pin IN2 de la placa del motor paso a paso.
pinMode(8, OUTPUT); // Pin 8 se conecta a al pin IN1 de la placa del motor paso a paso.

adat.attach(6);//el servo 1, llamado "adat" se ubica en el pin digital(pwm)9.
arab.attach(5);//el servo 2, llamado "arab" se ubica en el pin digital(pwm)10.
gar.attach(3);//el servo  3, llamdo "gar" se ubica en el pin digital(pwm)11.

adat.write(24);
arab.write(85);
gar.write(0);

Serial.println("    -SERVO 1, MUEVE LA GARRA ADELANTE Y ATRAS");
Serial.println("    -SERVO 2, MUEVE LA GARRA ARRIBA Y ABAJO");
Serial.println("    -SERVO 2, ABRE Y CIERRA LA GARRA");
Serial.println("    -ROTACION, HACE ROTAR EL BRAZO SOBRE SU PROPIO EJE 360°");
Serial.println("-----------------------------------------------------------------------");
Serial.println("..............PUEDE ESCOGER ENTRE 3 POSICIONES DEL BRAZO..............");
Serial.println("  POSICION a, SERVO 1: 27°, SERVO 2: 77°, SERVO 3: 0°, ROTACION: 0°");
Serial.println("  POSICION b, SERVO 1: 50°, SERVO 2: 90°, SERVO 3: 0°, ROTACION: 90°");
Serial.println("  POSICION c, SERVO 1: 70°, SERVO 2: 110°, SERVO 3: 0°, ROTACION: 180°");
Serial.println("  POSICION d, SERVO 1: 90°, SERVO 2: 77°, SERVO 3: 0°, ROTACION: 270°");
Serial.println("  POSICION e, EL BRAZO SE MUEVE SEGUN EL JOYSTICK");
Serial.println("  POR DEFECTO SE INICIA EN LA POSICION, SERVO 1: 24°, SERVO 2: 85°, SERVO 3: 0°, ROTACION: 0° !!! ");


}

void loop() {

  
if(Serial.available()>=1)
   {
    
   char cmd;//variable char para guardar un caracter
   cmd = Serial.read();//lee un caracter, que es el comando para saber en que pocision se ubica el brazo
  
     
 if(cmd == 'a'|| cmd == 'A'){
  
   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
  arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
  gar.write(0);//se escribe el numero de grados que se va a mover el servo 3.
  anges =0;
  anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }


 }else if(cmd == 'b'|| cmd == 'B'){

   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(50);
  arab.write(90);
  gar.write(0);

    anges =90;
  anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Girohacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }
  
}else if(cmd == 'c'|| cmd == 'C'){

   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(70);
  arab.write(110);
  gar.write(0);

    anges =180;
  anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Girohacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }
  
}else if(cmd == 'd'|| cmd == 'D'){

   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(90);
  arab.write(77);
  gar.write(0);

    anges = 270;
  anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Girohacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }
  
}else{

 Serial.println("Ingresaste una letra que no representa ninguna pocision disponible ");
}
}
 }
  

void paso_der(){         // funcion_movimiento hacia la derecha del motor paso a paso.
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
   delay(velmo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
   delay(velmo); 
   digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
     delay(velmo);   
}

void paso_izq() {        //funcion_movimiento hacia la izquierda del motor paso a paso.
 digitalWrite(11, HIGH); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
     delay(velmo);  
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, HIGH);  
     delay(velmo);  
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
     delay(velmo); 
}
        
void apagado() {         // funcion_apagado del motor paso a paso.
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }

  

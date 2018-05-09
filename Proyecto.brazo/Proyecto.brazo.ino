
#include <Servo.h>
Servo adat; //adelante y atras.
Servo arab;//arriba y abajo.
Servo gar;//garra.
int velmo = 5;// Tiempo (milisegundos)que tarda en dar un paso el motor paso a paso.
int anges = 0;// Angulo escogido por el caracter seleccionado.
int posicion_motor = 0;// grado en el que esta el motor paso a paso


void setup() {
  
Serial.begin(9600);

pinMode(12, INPUT);
pinMode(2, OUTPUT);
pinMode(11, OUTPUT); // Pin 11 se conecta a al pin IN4 de la placa del motor paso a paso.
pinMode(10, OUTPUT); // Pin 10 se conecta a al pin IN3 de la placa del motor paso a paso.
pinMode(9, OUTPUT); // Pin 9 se conecta a al pin IN2 de la placa del motor paso a paso.
pinMode(8, OUTPUT); // Pin 8 se conecta a al pin IN1 de la placa del motor paso a paso.

digitalWrite(2, LOW); 

adat.attach(6);//el servo 1, llamado "adat" se ubica en el pin digital(pwm)9.
arab.attach(5);//el servo 2, llamado "arab" se ubica en el pin digital(pwm)10.
gar.attach(3);//el servo  3, llamdo "gar" se ubica en el pin digital(pwm)11.

adat.write(24);
arab.write(85);
//gar.write(110);

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
  
  digitalWrite(2, HIGH); //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION
  
   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
  arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
  gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.
  
  delay(1000);
  digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE
  
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

   digitalWrite(2, HIGH);  //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION

   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(50);
  arab.write(90);
  gar.write(120);

 delay(1000);
 digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE

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

  digitalWrite(2, HIGH);  //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION


   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(70);
  arab.write(110);
  gar.write(145);
  
  delay(1000);
  digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE
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

   digitalWrite(2, HIGH);  //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION


   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(90);
  arab.write(77);
  gar.write(120);

  delay(1000);
  digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE

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
  
}else if(cmd == 'e'|| cmd == 'E'){
 
   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   Serial.print("PASO A MODO MANUAL, USE EL JOYSTICK.");

 while(cmd == 'e'|| cmd == 'E'){
    
    int pot1 = analogRead(0);// Lee el valor del potenciometro 1 del joystick, este valor entra por el pin analogico 0 (valor desde 0 a 1023)
    pot1 = map(pot1, 0, 1023, 0, 180);// Se mapea el valor del potenciometro en una escala de 0 a 180 grados, rango de giro de cada servo motor.
    int pot2 = analogRead(1);// Lee el valor del potenciometro 1 del joystick, este valor entra por el pin analogico 1 (valor desde 0 a 1023)
    pot2 = map(pot2, 0, 1023, 0, 180);// Se mapea el valor del potenciometro en una escala de 0 a 180 grados, rango de giro de cada servo motor.
    int pot3  = analogRead(2);
    int botgar = digitalRead(12);
    /*
    int pot3 = analogRead(2);// Lee el valor del potenciometro 1 del joystick, este valor entra por el pin analogico 0 (valor desde 0 a 1023)
    pot3 = map(pot3, 0, 1023, 0, 359);// Se mapea el valor del potenciometro en una escala de 0 a 180 grados, rango de giro del motor paso a paso.
    */
    int pulsador = digitalRead(12);//lee el valor binario del pin digital 2, para asi salir del bucle cambiando el caracter de la variable cmd.
    
  adat.write(pot1);//se manda la orden al servo motor 1 para que se mueva segun el joystick.
  arab.write(pot2);//se manda la orden al servo motor 2 para que se mueva segun el joystick.
  
   if (botgar == HIGH){

  digitalWrite(2, HIGH);  //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION

  gar.write(110);//se manda la orden al servo motor 3 para que se mueva segun un boton.
  
  delay(1000);
  digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE
  
  
}else if (botgar == LOW){
  
    digitalWrite(2, HIGH);  //SE ACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR RECIBA ENERGIA 5V Y CAMBIE DE POSICION

  gar.write(140);//se manda la orden al servo motor 3 para que se mueva segun un boton.
  
  delay(1000);
  digitalWrite(2, LOW);  //SE DESACTIVA EL PUERTO DIGITAL 2 PARA QUE EL MOTOR NO RECIBA ENERGIA 5V Y NO SE CALIENTE
  
  }
  
    anges = pot3;
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Girohacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }
   
   if (pulsador == HIGH){
    cmd = 'a';
   }

   delay(15);
   
   }
   }else
  }

  
   }
  

void paso_der(){// funcion_movimiento hacia la derecha del motor paso a paso.
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

void paso_izq() {//funcion_movimiento hacia la izquierda del motor paso a paso.
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
        
void apagado() {// funcion_apagado del motor paso a paso.
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }

  

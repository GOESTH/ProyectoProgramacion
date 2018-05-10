


#include <Servo.h>

Servo adat; //nombre de la variable que actua sobre el servo que mueve la garra adelante y atras.
Servo arab;//nombre de la variable que actua sobre el servo que mueve la garra  servoarriba y abajo.
Servo gar;//nombre de la variable que actua sobre el servo que abre y cierra la garra.

int velmo = 5;// Tiempo (milisegundos)que tarda en dar un paso el motor paso a paso.
int anges = 0;// Angulo escogido por el caracter seleccionado.
int posicion_motor = 0;// grado en el que esta el motor paso a paso..
int frequencia = 0;// frecuencia de incio = 0.
int numColor = 0;// codigo de color registrado, inicializado en 0

void setup() {
  
Serial.begin(9600);

  pinMode(4, OUTPUT);//pin S0 conectado al pin 4 del arduino
  pinMode(7, OUTPUT);//pin S1 conectado al pin 7 del arduino
  pinMode(2, OUTPUT);//pin S2 conectado al pin 2 del arduino
  pinMode(12, OUTPUT);//pin S3 conectado al pin 12 del arduino
  pinMode(13, INPUT);//pin S4 conectado al pin 13 del arduino

  //se crea un estado base, poniendo el pín 4 HIGH y el pin 7 LOW para leer el los milisegundos que toma en cambiar e inicar la lectura de las frecuecnias por colores.
  digitalWrite(4, HIGH);
  digitalWrite(7, LOW);

  pinMode(11, OUTPUT); // Pin 11 se conecta a al pin IN4 de la placa del motor paso a paso.
  pinMode(10, OUTPUT); // Pin 10 se conecta a al pin IN3 de la placa del motor paso a paso.
  pinMode(9, OUTPUT); // Pin 9 se conecta a al pin IN2 de la placa del motor paso a paso.
  pinMode(8, OUTPUT); // Pin 8 se conecta a al pin IN1 de la placa del motor paso a paso.

digitalWrite(2, LOW); 

adat.attach(6);//el servo 1, llamado "adat" se ubica en el pin digital(pwm)9.
arab.attach(5);//el servo 2, llamado "arab" se ubica en el pin digital(pwm)10.
gar.attach(3);//el servo  3, llamdo "gar" se ubica en el pin digital(pwm)11.

// se envia el angulo al que se quiere que se mueve el servo motor, para dar una posicion de inicio.
adat.write(24);
arab.write(85);
gar.write(110);

/*
Serial.println("    -SERVO 1, MUEVE LA GARRA ADELANTE Y ATRAS");
Serial.println("    -SERVO 2, MUEVE LA GARRA ARRIBA Y ABAJO");
Serial.println("    -SERVO 2, ABRE Y CIERRA LA GARRA");
Serial.println("    -ROTACION, HACE ROTAR EL BRAZO SOBRE SU PROPIO EJE 360°");
Serial.println("-----------------------------------------------------------------------");
Serial.println("..............PUEDE ESCOGER ENTRE 3 POSICIONES DEL BRAZO..............");
Serial.println("  POSICION a, SERVO 1: 27°, SERVO 2: 77°, garra: abierta, ROTACION: 0°");
Serial.println("  POSICION b, SERVO 1: 50°, SERVO 2: 90°, garra: cerrada, ROTACION: 90°");
Serial.println("  POSICION c, SERVO 1: 70°, SERVO 2: 110°, garra: abierta, ROTACION: 180°");
Serial.println("  POSICION d, SERVO 1: 90°, SERVO 2: 77°, garra: cerrar, ROTACION: 270°");
Serial.println("  POSICION e, EL BRAZO SE MUEVE SEGUN EL JOYSTICK");
Serial.println("  POR DEFECTO SE INICIA EN LA POSICION, SERVO 1: 24°, SERVO 2: 85°, garra: cerrada, ROTACION: 0° !!! ");
*/

}

void loop() {
   
  numColor = readColor(); //guarda en la variable numColor el valor que arroja 
  delay(10); 
   
  switch (numColor) {
    
    case 1:    
    adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
    arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
    gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.
    
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

    adat.write(50);
    arab.write(90);
    gar.write(120);
    
    break;
    case 2:    
    adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
    arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
    gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.

    
    anges =90;
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }

    adat.write(50);
    arab.write(90);
    gar.write(120);
    
    break;
    case 3:    
    adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
    arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
    gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.

    
    anges =180;
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }

    adat.write(50);
    arab.write(90);
    gar.write(120);
    
    break;
    case 4:
  
    adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
    arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
    gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.

    
    anges =270;
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }

    adat.write(50);
    arab.write(90);
    gar.write(120);
    
    break;
    case 5:
    adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
    arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
    gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.

    
    anges =360;
    anges = (anges * 1.4222222222);

  while (anges>posicion_motor){   // Giro hacia la izquierda en grados
       paso_izq();
       posicion_motor = posicion_motor + 1;
   }
   
  while (anges<posicion_motor){   // Giro hacia la derecha en grados
        paso_der();
        posicion_motor = posicion_motor -1;
   }

    adat.write(50);
    arab.write(90);
    gar.write(120);
    
    break;
    
    case 0:
    break;
  }

  /*
if(Serial.available()>=1)
   {
    
   char cmd;//variable char para guardar un caracter
   cmd = Serial.read();//lee un caracter, que es el comando para saber en que pocision se ubica el brazo
  
     
 if(cmd == 'a'|| cmd == 'A'){
  
   Serial.print("ud indico posicion:");
   Serial.println(cmd);
   
  adat.write(27);//se escribe el numero de grados que se va a mover el servo 1.
  arab.write(77);//se escribe el numero de grados que se va a mover el servo 2.
  gar.write(145);//se escribe el numero de grados que se va a mover el servo 3.

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
  gar.write(120);


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
  gar.write(145);
  
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
  gar.write(120);


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
 
    int botonera = analogRead(2);//lee el valor de la resistencia que genera un boton u otro que estan en el mismo pin analogo, para asi salir del bucle cambiando el caracter de la variable cmd y cerrar y abrir la garra.
    
  adat.write(pot1);//se manda la orden al servo motor 1 para que se mueva segun el joystick.
  arab.write(pot2);//se manda la orden al servo motor 2 para que se mueva segun el joystick.
  
  if (botonera < x && botonera > x){  

    gar.write(110);//se manda la orden al servo motor 3 para que se mueva segun un boton.
  
  }else if (botonera < x && botonera > x){

  gar.write(140);//se manda la orden al servo motor 3 para que se mueva segun un boton.  
 
  }else if (botonera < x && botonera > x){

     cmd = 'a';
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
    }
     }
     */
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


  int reconocerColor() {
    /*
     * Para reconocer que combinacion de RGB (red, green, blue) o RVA(rojo, verde, azul), 
     * se encienden y se apagan los pines 4 y 5 a los que estan conectados S2 y S3 del sensor de color, 
     * para asi medir en milisegundos la frecuencia de cada color y ver segun esa combinacion que color es.
     */
    
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
 
  frecuencia = pulseIn(6, LOW); // se lee la frecuencia que son el valor de los micrasegundos en los que el puerto 6 pasa de ser HIGH a ser LOW, cada color tiene su propia frecuencia.
  
  int R = frequencia;//El sensor lee RGB (Rojo, Verde, Azul), aca se busca la frecuencia del rojo, su intensidad en el color al que esta expuesto el sensor.


  Serial.print("Rojo: ");
  Serial.print(frequencia);
  Serial.print("  ");
  delay(50);
  

  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);


  frequency = pulseIn(6, LOW);// se lee la frecuencia que son el valor de los micrasegundos en los que el puerto 6 pasa de ser HIGH a ser LOW, cada color tiene su propia frecuencia.
  
  int V = frequencia;//El sensor lee RGB (Rojo, Verde, Azul), aca se busca la frecuencia del Rojo, su intensidad en el color al que esta expuesto el sensor

 
  Serial.print("Verde: ");
  Serial.print(frequencia);// se lee la frecuencia que son el m¿valor de los micrasegundos en los que el puerto 6 pasa de ser HIGH a ser LOW, cada color tiene su propia frecuencia.
  Serial.print("  ");
  delay(50);


  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);

  frequencia = pulseIn(6, LOW);// se lee la frecuencia que son el valor de los micrasegundos en los que el puerto 6 pasa de ser HIGH a ser LOW, cada color tiene su propia frecuencia.
  int A = frequencia;//El sensor lee RGB (Rojo, Verde, Azul), aca se busca la frecuencia del azul, su intensidad en el color al que esta expuesto el sensor.
  
  Serial.print("Azul: ");
  Serial.print(frequencia);// se lee la frecuencia que son el m¿valor de los micrasegundos en los que el puerto 6 pasa de ser HIGH a ser LOW, cada color tiene su propia frecuencia.
  Serial.println("  ");
  delay(50);

  
  if(R<45 & R>32 & V<65 & V>55){// se comprueba que segun la combinacion de frecuencias del rojo y verde, el sensor este analizando un color rojo.
    numColor = 1; 
  }
  if(V<55 & V>43 & A<47 &A>35){// se comprueba que segun la combinacion de frecuencias del verde y azul, el sensor este analizando un color naranja.
    numColor = 2; 
  }
  if(R<53 & R>40 & V<53 & V>40){// se comprueba que segun la combinacion de frecuencias del rojo y verde, el sensor este analizando un color verde.
    numColor = 3; 
  }
  if(R<38 & R>24 & V<44 & V>30){// se comprueba que segun la combinacion de frecuencias del rojo y verde, el sensor este analizando un color amrillo.
    numColor = 4;
  }
  if(R<56 & R>46 & V<65 & V>55){// se comprueba que segun la combinacion de frecuencias del rojo y verde, el sensor este analizando un color cafe.
    numColor = 5; 
  }
  if (V<58 & V>45 & A<40 &A>26){// se comprueba que segun la combinacion de frecuencias del verde y azul, el sensor este analizando un color azul.
    numColor = 6; 
  }
  return numColor;  //devuelve el numero que tiene la variable numColor para asi ser evaluado en el switch.
}

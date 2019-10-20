
/*
  vecto para indicar que pines seran de entrada
  channel 1= pin 2 asi es como se visualizara en el codigo (channel[0]), 
  channel 2= pin 3                                         (channel[1]), 
  channel 3= pin 4                                         (channel[2]), 
  channel 4= pin 5                                         (channel[3]), 
  channel 5= pin 6                                         (channel[4]),
  channel 6= pin 7                                         (channel[5])
 */
int channel[]={2,3,4,5,6,7};//channel del receptor pines de entrada
/*
vector para almacenar los valores traen los pines de entrada
valor[0] = pin 2
valor[1] = pin 3
valor[2] = pin 4
valor[3] = pin 5
valor[4] = pin 6
valor[5] = pin 7
*/
int valor[]={0,0,0,0,0,0};//valores donde guarda los voltajes del receptor

int movimiento[]={8,9,10,11,12,13};//movimientos adelante, atras 

void setup(){
  //activa los pines de entrada para los channel
  for(int i;i<7;i++)
 {
    pinMode(channel[i],INPUT); 
 }
 
 //activa los pines de salida para el movimiento del robot
 for(int i;i<4;i++)
 {
    pinMode(movimiento[i],OUTPUT);    
 }
 Serial.begin(9600); 
}

void loop() {
  //escuchando el valor que envia el control en channel 1 en el pin 2 (derecha,izquierda)
  valor[0] = pulseIn(channel[0],HIGH,25000); 
  
  // activa derecha  
  if ((valor[0]>=1139)&&(valor[0]<=1146)){
    
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
     Serial.println("izquierda pin 8");//mostrar en pantalla
     delay(300);
  }
  //activa derecha
  if ((valor[0]>1900)&&(valor[0]<1985)){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    Serial.println("derecha pin 9 ");//mostrar en pantalla
    delay(300);
  }

  digitalWrite(movimiento[0],HIGH);  // pin 8 apago
    digitalWrite(movimiento[1],HIGH);  // pin 9 activo
    digitalWrite(movimiento[2],HIGH); // pin 10 apago
    digitalWrite(movimiento[3],HIGH);

  //Serial.println(pulseIn(channel[5],HIGH,25000));//mostrar en pantalla
   //escuchando el valor que envia el control en channel 2 en el pin 3 (adelante,atras)
   valor[1]=     pulseIn(channel[1],HIGH,25000);

   // activa adelante  
  if ((valor[1]>=1600)&&(valor[1]<=2500)){
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(300);
     Serial.println("ADELANTE pin 8 y 10");//mostrar en pantalla
  }
  // activa atras
  if ((valor[1]>0)&&(valor[1]<1400)){
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    delay(300);
    Serial.println("ATRAS pin 9 y 11");//mostrar en pantalla 
  }

 

  Serial.println(valor[0]);
/* valor[0]
//  Bandeja de descarga basura

   //escuchando el valor que envia el control en channel 3 en el pin 4 (push , pull)
   valor[1]=     pulseIn(channel[3],HIGH,25000);

   // activa push  
  if ((valor[1]>=1600)&&(valor[1]<=2500)){
    digitalWrite(movimiento[4],HIGH);  // pin 12 enciendo
    Serial.println("descarga pin 12");//mostrar en pantalla
  }
  //activa pull
  if ((valor[1]>0)&&(valor[1]<1400)){
    digitalWrite(movimiento[5],HIGH);  // pin 13 apago
    Serial.println("posicion pin 12");//mostrar en pantalla 
  }

//  Banda Transportadora

   //escuchando el valor que envia el control en channel 4 en el pin 5 
   valor[1]=     pulseIn(channel[2],HIGH,25000);

   // activa recolector  
  if ((valor[1]>=1600)&&(valor[1]<=2500)){
    digitalWrite(movimiento[6],HIGH);  // pin 14 enciendo
    Serial.println("Banda Recolectora ON pin 14");  //mostrar en pantalla
  }
  
  //  Polea Submarino

   //escuchando el valor que envia el control en channel 6 en el pin 7 ( botton )
   valor[1] = pulseIn(channel[5],HIGH,25000);

   // activa arriba  
  if ((valor[1]>=1600)&&(valor[1]<=2500)){
    digitalWrite(movimiento[8],HIGH);  // pin 15 enciendo
    Serial.println("polea abajo");//mostrar en pantalla
  }
  //activa abajo
  if ((valor[1]>0)&&(valor[1]<1200)){
    digitalWrite(movimiento[9],HIGH);  // pin 16 apago
    Serial.println("polea arriba");//mostrar en pantalla 
  }
*/
  //activa pull
//  if ((valor[1]>0)&&(valor[1]<1400)){
//    digitalWrite(movimiento[5],LOW);  // pin 13 apago
//    Serial.println("Banda Recolectora OFF "); //mostrar en pantalla 
 // }

  // se apagando los motores cuando la palanquita este justamente en medio del channel 1 y 2
 //   if (((valor[0]>1400)&&(valor[0]<1600))&&((valor[1]>1400)&&(valor[1]<1600))){
 //   digitalWrite(movimiento[0],LOW);  // pin 8 apago
 //   digitalWrite(movimiento[1],LOW);  // pin 9 apago
 //   digitalWrite(movimiento[2],LOW);  // pin 10 apago
 //   digitalWrite(movimiento[3],LOW);  // pin 11 apago
 //   Serial.println("apago pin 8,9,10,11 palanca al centro channel 1 y 2"); //mostrar en pantalla
//    } 
  // delay(5); 
}

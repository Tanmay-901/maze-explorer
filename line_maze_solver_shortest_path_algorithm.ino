/*
 I'm using 5 sensors 
 lmsv=left most sensor
 lsv=left sensor
 csv=centre sensor
 rsv=right sensor
 rmsv=right mot sensor
 I am going to use a two way switch connected to pins 1 and 2
 for trial mode and shortest path mode
 */
int p=0; 
char* path[500]; 
int trial;
int real;
//line array sensor
int rmsv;
int rsv;
int csv;
int lsv;
int lmsv;
void setup() { 
  //two way switch
  pinMode(2,INPUT);
  pinMode(1,INPUT);
  //line array sensor(INPUT)
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  //Motor terminals(OUTPUT)
  pinMode(11,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  trial==digitalRead(2);
  real=digitalRead(1);
  if(trial==HIGH && real==LOW) {
  //Read sensor values
  rmsv=digitalRead(A0);
  rsv=digitalRead(A1);
  csv=digitalRead(A2);
  lsv=digitalRead(A3);
  lmsv=digitalRead(A4);
  //conditions
  if(rmsv==0 && lmsv==0) {
    if (lsv==0 && csv==0 && rsv==1) {
      stpr();
    }
    else if( lsv==0 && csv==1 && rsv==0) {
      fwd();  
    }
    else if(lsv==0 && csv==1 && rsv==1)  {
      slor();  
    }
    else if(lsv==1 && csv==0 && rsv==0) {
      stpl();  
    }
    else if(lsv==1 && csv==1 && rsv==0) {
      slol();  
    }
    else if(lsv==1 && csv==1 && rsv==1) {
      path[p]="L";
      p++;
      left();
      delay(200);
      stp();
    }
    else if(lsv==0 && csv==0 && rsv==0) {
     path[p]="U";
     p++; 
     left();
    }
  }
  else if(rmsv==0 && lmsv==1) {
   left();  
  }
 else if(rmsv==1 && lmsv==0) {
   right();
  }
 else  if(csv==1 && rmsv==1) {
fwd();
path[p]="S";
p++;
 } 
  else if(rmsv== 1 && lmsv==1) {
      path[p]="L";
      p++;
      left();
      delay(200);
      stp();
      left(); 
      delay(200);
      stp(); 
  }
}
else if(real==HIGH && trial==LOW) {
//i dont know
}
}
void stpl() {
  analogWrite(6,0);  
  digitalWrite(11,LOW);  
  analogWrite(5,150);  
  digitalWrite(3,LOW);      
}
void stpr() {
  analogWrite(11,150);  
  digitalWrite(6,LOW);  
  analogWrite(5,0);  
  digitalWrite(3,LOW);      
}
void stp() {
  digitalWrite(11,LOW);  
  digitalWrite(6,LOW);  
  digitalWrite(5,LOW);  
  digitalWrite(3,LOW);      
}
void fwd()
{
  analogWrite(11,150);  
  digitalWrite(6,LOW);  
  analogWrite(5,150);  
  digitalWrite(3,LOW);  
}
void left() {
  analogWrite(6,150);  
  digitalWrite(11,LOW);  
  analogWrite(5,150);  
  digitalWrite(3,LOW);    
}
void right() {
  analogWrite(11,150);  
  digitalWrite(6,LOW);  
  analogWrite(3,150);  
  digitalWrite(5,LOW);  
}
void slol() {
  analogWrite(11,75);  
  digitalWrite(6,LOW);  
  analogWrite(5,150);  
  digitalWrite(3,LOW);    
}
void slor() {
  analogWrite(11,150);  
  digitalWrite(6,LOW);  
  analogWrite(5,7575);  
  digitalWrite(3,LOW);    
}





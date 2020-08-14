//Default left code

int s1=12;
int s2=13;
// sensors
int sll=2; 
int sl=3; 
int smid=4;
int sr=5;
int srr=6;
int scenter=7;

//  motors declaration
int mlf=8; //left forward
int mlb=9; //left backward
int mrf=10; //right forward
int mrb=11; //right backward

int i=0;
int n=1;
int dir_arr[100];
int dir_arr_b[100];

//north=1
//west=2
//south=3
//east=4

vo
id setup() {
  // put your setup code here, to run once:
  
  pinMode(sl, INPUT);   // treat the I/O pin as an input
  pinMode(sr, INPUT);   // treat the I/O pin as an input
  pinMode(sll, INPUT);   // treat the I/O pin as an input
  pinMode(srr, INPUT);   // treat the I/O pin as an input
  pinMode(smid, INPUT);   // treat the I/O pin as an input
  pinMode(scenter, INPUT);   // treat the I/O pin as an input
  
  pinMode(mlf, OUTPUT);    // treat the I/O pin as an output
  pinMode(mlb, OUTPUT);    // treat the I/O pin as an output
  pinMode(mrf, OUTPUT);    // treat the I/O pin as an output
  pinMode(mrb, OUTPUT);    // treat the I/O pin as an output
  
  Serial.begin(9600);  // begin your Serial monitor and communication
}

void loop() {
  if(s1==HIGH){
  // put your main code here, to run repeatedly:

 int a= digitalRead(sll);   // taking the input value from ir sensor 1
 int b= digitalRead(sl);   // taking the input value from ir sensor 2
 int c= digitalRead(smid);   // taking the input value from ir sensor 3
 int d= digitalRead(sr);   // taking the input value from ir sensor 4
 int e= digitalRead(srr);   // taking the input value from ir sensor 5
 int f= digitalRead(scenter);   // taking the input value from ir sensor 6
 
  if(a==HIGH && b==HIGH && c==LOW && d==HIGH && e==HIGH)  //straight line
  {
   digitalWrite(mlf,HIGH);   // enables motor 1 in forward direction
   digitalWrite(mlb,LOW);
    digitalWrite(mrf,HIGH);   // enables motor 2 in forward direction
     digitalWrite(mrb,LOW);
     Serial.println("move forward");   // print the sentence as it is in serial monitor
  }
  else if(b==LOW && c==LOW && d==HIGH)  //simple Left turn
  {
   digitalWrite(mlf,LOW);
   digitalWrite(mlb,HIGH);
    digitalWrite(mrf,HIGH);
     digitalWrite(mrb,LOW);
  Serial.println("turn left");
  }
  else if(b==HIGH && c==LOW && d==LOW)  //simple Right turn
  {
   digitalWrite(mlf,HIGH);
   digitalWrite(mlb,LOW);
    digitalWrite(mrf,LOW);
     digitalWrite(mrb,HIGH);
     Serial.println("Right side turn");
  }
  else if(a==HIGH && b==HIGH && c==LOW && d==HIGH && e==LOW)  //Right junction, move forward
  {
   digitalWrite(mlf,HIGH);
   digitalWrite(mlb,LOW);
   digitalWrite(mrf,HIGH);
   digitalWrite(mrb,LOW);
   Serial.println("forward");
      dir_arr[i]=n;
      i++;
     }
  else if(a==LOW && c==LOW && e==HIGH)  //Left junction, turn left
  {
   digitalWrite(mlf,LOW);
   digitalWrite(mlb,HIGH);
    digitalWrite(mrf,HIGH);
     digitalWrite(mrb,LOW);
     Serial.println("left");
     if(n>1){
      dir_arr[i]=n-1;
      i++;
     }
     else if(n==1){
      n=4;
      dir_arr[i]=n;
      i++;
     }
  }
  else if(a==HIGH && b==HIGH && c==HIGH && d==HIGH)  //plus point, turn left
  {
   digitalWrite(mlf,LOW);
   digitalWrite(mlb,HIGH);
    digitalWrite(mrf,HIGH);
     digitalWrite(mrb,LOW);
     Serial.println("left");
     if(n>1){
      dir_arr[i]=n-1;
      i++;
     }
     else if(n==1){
      n=4;
      dir_arr[i]=n;
      i++;
     }
  }
  else if(a==LOW && b==LOW && c==LOW && d==HIGH)  //T-point Default left
  {
   digitalWrite(mlf,LOW);
   digitalWrite(mlb,HIGH);
    digitalWrite(mrf,HIGH);
    dig italWrite(mrb,LOW);
     Serial.println("turn left");
     if(n>1){
      dir_arr[i]=n-1;
      i++;
     }
     else if(n==1){
      n=4;
      dir_arr[i]=n;
      i++;
     }
  }
  
  else if(a==HIGH && b==HIGH && c==HIGH && d==HIGH)  //End point, turn about from right side
  {
   digitalWrite(mlf,HIGH);
   digitalWrite(mlb,LOW);
    digitalWrite(mrf,LOW);
    digitalWrite(mrb,HIGH);
     Serial.println("turn about from right");
     if(n>2){
      dir_arr[i]=n-2;
      i++;
     }
     else if(n<=2){
      n=2+n;
      dir_arr[i]=n;
      i++;
     }
  }
}
  if(s2==HIGH){
   abc(i);
  }
}
void abc(int a)
{
   int k=0;
    for(int j=0;j<a;j++){
      if(((dir_arr[j+1]-dir_arr[j])==2)||((dir_arr[j+1]-dir_arr[j])== -2))
      {
        //dir_arr[k] = dir_arr[j];
        k++;
        for(int l=0;l<k;l++)
        {
          dir_arr[j]=dir_arr[j+2];
          }
      }
    }
}

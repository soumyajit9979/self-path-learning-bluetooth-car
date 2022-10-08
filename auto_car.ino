int rst=7;
int bt=2;
int count=0;
char mov[400];
int num[400];
int scount=0;
int bcount=0;
int lcount=0;
int rcount=0;
int fcount=0;
#define ls A0
#define rs A1
int L1=11;
int L2=12;
int R1=9;
int R2=10;
//int led=13;
char val;
int flag=0;
void setup() {
  // put your setup code here, to run once:
pinMode(ls,OUTPUT);
pinMode(rs,OUTPUT);
analogWrite(ls,255);
analogWrite(rs,255);
digitalWrite(rst,HIGH);
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(R1,OUTPUT);
pinMode(R2,OUTPUT);
delay(200);
pinMode(bt,OUTPUT);
pinMode(rst,OUTPUT);
digitalWrite(bt,HIGH);
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,LOW);
digitalWrite(L1,LOW);
pinMode(L2,LOW);
pinMode(R1,LOW);
pinMode(R2,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(bt,HIGH);
  while(Serial.available()>0){
    val = Serial.read();
    if(val=='B'){
      bcount++;
      Serial.println(bcount);
      if(scount>0)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
      else if(fcount>0)
      {
        num[flag]=fcount;
        mov[flag]='F';
        flag++;
        fcount=0;
      }
      else if(rcount>0)
      {
        num[flag]=rcount;
        mov[flag]='R';
        flag++;
        rcount=0;
      }
      else if(lcount>0)
      {
        num[flag]=lcount;
        mov[flag]='L';
        flag++;
        lcount=0;
      }
      

    }

     else if(val=='S'){
      scount++;

      Serial.println(scount);
       
      if(bcount>0)
      {
        num[flag]=bcount;
        mov[flag]='B';
        flag++;
        bcount=0;
      }
      else if(fcount>0)
      {
        num[flag]=fcount;
        mov[flag]='F';
        flag++;
        fcount=0;
      }
      else if(rcount>0)
      {
        num[flag]=rcount;
        mov[flag]='R';
        flag++;
        rcount=0;
      }
      else if(lcount>0)
      {
        num[flag]=lcount;
        mov[flag]='L';
        flag++;
        lcount=0;
      }
}


     else if(val=='F'){
      fcount++;

      Serial.println(fcount);
       
      if(bcount>0)
      {
        num[flag]=bcount;
        mov[flag]='B';
        flag++;
        scount=0;
      }
      else if(scount>0)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
      else if(rcount>0)
      {
        num[flag]=rcount;
        mov[flag]='R';
        flag++;
        scount=0;
      }
      else if(lcount>0)
      {
        num[flag]=lcount;
        mov[flag]='L';
        flag++;
        lcount=0;
      }
}



     else if(val=='L'){
      lcount++;

      Serial.println(lcount);
       
      if(bcount>0)
      {
        num[flag]=bcount;
        mov[flag]='B';
        flag++;
        bcount=0;
      }
      else if(fcount>0)
      {
        num[flag]=fcount;
        mov[flag]='F';
        flag++;
        fcount=0;
      }
      else if(rcount>0)
      {
        num[flag]=rcount;
        mov[flag]='R';
        flag++;
        rcount=0;
      }
      else if(scount>0)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
}


     else if(val=='R'){
      rcount++;

      Serial.println(rcount);
       
      if(bcount>0)
      {
        num[flag]=bcount;
        mov[flag]='B';
        flag++;
        bcount=0;
      }
      else if(fcount>0)
      {
        num[flag]=fcount;
        mov[flag]='F';
        flag++;
        fcount=0;
      }
      else if(scount>0)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
      else if(lcount>0)
      {
        num[flag]=lcount;
        mov[flag]='L';
        flag++;
        lcount=0;
      }
}

      if((val=='w')||(val=='W')){
      if(bcount>0){
          num[flag]=bcount;
          mov[flag]='B';
          bcount=0;
        }
       
      else if(scount>0)
      {
        num[flag]=scount;
        mov[flag]='S';
        flag++;
        scount=0;
      }
      else if(fcount>0)
      {
        num[flag]=fcount;
        mov[flag]='F';
        flag++;
        fcount=0;
      }
      else if(rcount>0)
      {
        num[flag]=rcount;
        mov[flag]='R';
        flag++;
        rcount=0;
      }
      else if(lcount>0)
      {
        num[flag]=lcount;
        mov[flag]='L';
        flag++;
        lcount=0;
      }
      
    }

    Serial.println(val);
    }

    
    if((val=='w')||(val=='W')){
      digitalWrite(bt,LOW);
      
      delay(1000);
      arr(mov,num);
      exit(0);
    }
    else if(val=='L'){
      left();
      
      
    }
    
    else if(val=='F'){
      forward();
      
      
    }
    
    else if(val=='B'){
      backward();
      
      
    }
    
    else if(val=='R'){
      right();
      
      
    }
    

    else if(val=='S'){
       Stop();
      }

}


void arr(char b[],int c[]){
  int x=flag; 
  for(int i=0;i<x;i++){
    Serial.println(b[i]);
    Serial.println(c[i]);
    if(b[i]=='L'){
      for(int j=0;j<c[i];j++){
        delay(27);
        left();
      } 
      }
    else if(b[i]=='F'){
      for(int j=0;j<c[i];j++){
        delay(27);
        forward();
      } 
      }
      
    else if(b[i]=='B'){
      for(int j=0;j<c[i];j++){
        delay(27);
        backward();
      } 
      }
    else if(b[i]=='R'){
      for(int j=0;j<c[i];j++){
        delay(27);
        right();
      } 
      }
    else if(b[i]=='S'){
      for(int j=0;j<c[i];j++){
        delay(27);
        Stop();
      } 
      }
    }
digitalWrite(rst,LOW);
  }

  void forward(){
    digitalWrite(L1,LOW);
    digitalWrite( L2 ,HIGH);
    digitalWrite( R1 ,HIGH);
    digitalWrite(R2 ,LOW);
    
    }
  void backward(){
    digitalWrite(L1,HIGH);
    digitalWrite( L2 ,LOW);
    digitalWrite( R1 ,LOW);
    digitalWrite(R2 ,HIGH
    );
    }

   void right(){
    digitalWrite(L1,HIGH);
    digitalWrite( L2 ,LOW);
    digitalWrite( R1 ,LOW);
    digitalWrite(R2 ,LOW);
    }

   void left(){
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);
    }

   void Stop(){
    digitalWrite(L1,LOW);
    digitalWrite(L2,LOW);
    digitalWrite(R1,LOW);
    digitalWrite(R2,LOW);
    } 

int rst=7;
int bt=12;
int count=0;
char mov[400];
int num[400];
int scount=0;
int bcount=0;
int lcount=0;
int rcount=0;
int fcount=0;
int led1=9;
int led2=6;
int led3=5;
int led4=4;
//int led=13;
char val;
int flag=0;
void setup() {
  // put your setup code here, to run once:
digitalWrite(rst,HIGH);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
delay(200);
pinMode(bt,OUTPUT);
pinMode(rst,OUTPUT);
digitalWrite(bt,HIGH);
pinMode(LED_BUILTIN,OUTPUT);
digitalWrite(LED_BUILTIN,LOW);
digitalWrite(led1,LOW);
pinMode(led2,LOW);
pinMode(led3,LOW);
pinMode(led4,LOW);
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
      digitalWrite(led1,HIGH);
      
      
    }
    
    else if(val=='F'){
      digitalWrite(led2,HIGH);
      
      
    }
    
    else if(val=='B'){
      digitalWrite(led3,HIGH);
      
      
    }
    
    else if(val=='R'){
      digitalWrite(led4,HIGH);
      
      
    }
    

    else if(val=='S'){
       digitalWrite(led1,LOW);
       
       digitalWrite(led2,LOW);
       digitalWrite(led3,LOW);
       digitalWrite(led4,LOW);
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
        digitalWrite(led1,HIGH);
      } 
      }
    else if(b[i]=='F'){
      for(int j=0;j<c[i];j++){
        delay(27);
        digitalWrite(led2,HIGH);
      } 
      }
      
    else if(b[i]=='B'){
      for(int j=0;j<c[i];j++){
        delay(27);
        digitalWrite(led3,HIGH);
      } 
      }
    else if(b[i]=='R'){
      for(int j=0;j<c[i];j++){
        delay(27);
        digitalWrite(led4,HIGH);
      } 
      }
    else if(b[i]=='S'){
      for(int j=0;j<c[i];j++){
        delay(27);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
      } 
      }
    }
digitalWrite(rst,LOW);
  }

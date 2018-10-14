#include "src/gyro_class/gyro_class.h"
volatile int16_t FIFO_CNT_INT=0;
__gyro__ mpu;
double fsa,fsg;
void setup() {
//  pinMode(CS_PIN,OUTPUT);
  Serial.begin(2000000);
  while(!Serial){}
  Serial.println("START");
  
  mpu.init(CS_PIN);
  mpu.FIFO_enable(1,0,0);
  mpu.FIFO_enable(1);
  mpu.FIFO_reset();
  fsg = mpu.FSG(1); //250*/s - 500*/s - 1000*/s - 2000*/s
  fsa = mpu.FSA(); //2g - 4g - 8g - 16g

  
}
uint8_t buf[1024*2];
int16_t *buf16 = (int16_t*)buf;
uint32_t t1,t2,t3,t0;

bool hs = 0;
#define sps(val) Serial.print((val),BIN); Serial.print(" ");
uint32_t t1_next=0;
double px,py,pz,x,y,z;

double a,b,c;
float ii = 0;

void loop() {

//  return;
//      SerialWriteFloat(ii++);
//      ii = ii>1000?0:ii;
//      return;
  int16_t FIFO_CNT = mpu.FIFO_cnt()/2;
//  Serial.println(FIFO_CNT);
  int kkk = 16;
  if(FIFO_CNT>=kkk*3){
//    SPI.setClockDivider(SPI_CLOCK_DIV4);
    mpu.FIFO_read(buf16,kkk*3);
    
    for(int i=0;i<kkk*3;i+=3){
//      Serial.print(i); Serial.print(" ");
a = buf16[i+0]/fsg;
b = buf16[i+1]/fsg;
c = buf16[i+2]/fsg;
//      x = px-a;
//      y = py-b;
//      z = pz-c;
//      px = a;
//      py = b;
//      pz = c;
//      Serial.write(0xaa);
//      SerialWriteFloat(a);
//      SerialWriteFloat(b);
//      SerialWriteFloat(c);
//      Serial.write(i);
      Serial.print(a,8); Serial.print(",");
      Serial.print(b,8); Serial.print(",");
      Serial.print(c,8); Serial.print("");
      Serial.println();
    }
//    SPI.setClockDivider(SPI_CLOCK_DIV128);
  }
}

void MPU_Interrupt(){
FIFO_CNT_INT+=1;
  
}


void SerialWriteFloat(const float &val) {
  uint8_t *wsk = (uint8_t*)&val;
//  Serial.write(0xaa);
  Serial.write(*wsk++);
  Serial.write(*wsk++);
  Serial.write(*wsk++);
  Serial.write(*wsk++);
}

double gensin2(double f,double fs,int n,double amp){
  double v,k;
  k = (2.0d*PI*f)/fs;
  for(int i=0;i<n;i++)
  {
    v = sin(k*i)*amp;
    Serial.println((double)v,18);
  }
  return a;
}

#include "gyro_class.h"
int __hs__ = 0;
void __gyro__::init(uint8_t cs){
  _cs = cs;
  pinMode(_cs,OUTPUT);
  SPI_init();
  MPU_default(); // przywraca wartosci domyslne wszystkich rejestrow
  if(MPU__WHO_AM_I())
    MPU__I2C_IF_DIS(1); // wymusza wylaczenie interfejsu I2C
  MPU__CLKSEL(0); // xgyro
  
  MPU__SMPLR_DIV(7); // 1kHz sampling
  MPU__DLPF_CFG(0);  // DLPF off
  // __hs__ = 1;
}

void __gyro__::SPI_init(){
  SPI.begin();
  // SPI.setBitOrder(MSBFIRST);
  // SPI.setDataMode(SPI_MODE3);
  // SPI.setClockDivider(SPI_CLOCK_DIV128);
  // delay(100);
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
}
void __gyro__::hs(bool hs){
  if(hs==_hs) return;
  _hs=hs;
  SPI.setClockDivider(hs?SPI_CLOCK_DIV4:SPI_CLOCK_DIV128);
}

void __gyro__::MPU_default(){ // przywraca domyślne wartości wszystkich rejestrów
  MPU__DEVICE_RESET(1);
  delay(100);
  MPU__SLEEP(0);
  delay(100);
  MPU__SIG_COND_RESET(1);
  delay(100);
}

void __gyro__::FIFO_enable(bool gyro, bool accel, bool temp){
	MPU__TEMP_FIFO_EN(temp);
	MPU__XG_FIFO_EN(gyro);
	MPU__YG_FIFO_EN(gyro);
	MPU__ZG_FIFO_EN(gyro);
	MPU__ACCEL_FIFO_EN(accel);
}

void __gyro__::FIFO_enable(bool enable){
	MPU__FIFO_EN(enable);
}

void __gyro__::FIFO_read(int16_t* buf,int cnt){
	readRegisters_i16(0x74, buf, cnt);
}

uint16_t __gyro__::FIFO_cnt(){
	return readRegister_i16(0x72);
}

void __gyro__::FIFO_reset(){ // zeruje zawartosc bufora FIFO w MPU
   bool pen = MPU__FIFO_EN();
   MPU__FIFO_EN(0);
   MPU__FIFO_RESET(1);
   // FIFO_CNT_INT = 0;
   MPU__FIFO_EN(pen);
}

void __gyro__::Interrupt_enable(bool en){
  if(en){
//      pinMode(PA3, INPUT);
//      attachInterrupt(PA3, MPU_Interrupt, RISING);
//      MPU__INT_LEVEL(0);    // 0=active high / 1=active low
//      MPU__INT_OPEN(0);     // 0=push-pull / 1=open drain
//      MPU__LATCH_INT_EN(0); // 0=50us pulse / 1=manual register clear
//      MPU__DATA_RDY_EN(1);
  }
  else{
//      pinMode(PA3, INPUT);
//      MPU__DATA_RDY_EN(0);
  }
}

double __gyro__::FSG(void){
	double fs[4] = {131,65.5,32.8,16.4};
	return fs[MPU__FS_SEL()];
}

double __gyro__::FSA(void){
	double fs[4] = {16384,8192,4096,2048};
	return fs[MPU__AFS_SEL()];
}

double __gyro__::FSG(int fs){
	MPU__FS_SEL(fs);
	return FSG();
}

double __gyro__::FSA(int fs){
	MPU__AFS_SEL(fs);
	return FSA();
}

void writeRegister(uint8_t regAddr, uint8_t data){
// SPI.setClockDivider(SPI_CLOCK_DIV128); // <---------- if I do not call this then communication gonna crash
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3)); // <---------- if I do not call this then communication gonna crash
  CS_ON();
  SPI.transfer(regAddr);
  SPI.transfer(data);
  CS_OFF();
}

void readRegisters_u8(uint8_t regAddr, uint8_t* buf, int cnt){
// SPI.setClockDivider(SPI_CLOCK_DIV128); // <---------- if I do not call this then communication gonna crash
SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3)); // <---------- if I do not call this then communication gonna crash
  CS_ON();
  SPI.transfer(SPI_READ | regAddr);
  for(int i=0;i<cnt;i++){
    buf[i] = SPI.transfer(0);
  }
  CS_OFF();
}

void readRegisters_i16(uint8_t regAddr, int16_t* buf, int cnt){
  readRegisters_u8(regAddr,(uint8_t*)buf,cnt*2);
   arrayEndianSwap_16(buf,cnt);
}


uint8_t readRegister_u8(uint8_t regAddr){
  uint8_t buf[1];
  readRegisters_u8(regAddr,buf,1);
  return buf[0];
}
//
int16_t readRegister_i16(uint8_t regAddr){
  uint8_t buf[2];
  readRegisters_u8(regAddr,buf,2);
  return (((int16_t)buf[0]) << 8) | buf[1];
}
uint8_t setBits(uint8_t val, uint8_t POS, uint8_t LEN, uint8_t src){
  // I2Cdev.cpp - writeBits()
  uint8_t mask = ((1 << LEN) - 1) << (POS - LEN + 1);
  val <<= (POS - LEN + 1); // shift data into correct position
  val &= mask; // zero all non-important bits in data
  src &= ~(mask); // zero all important bits in existing byte
  src |= val; // combine data with existing byte
  return src;
}


void MPU_rw(uint8_t regAddr, uint8_t POS, uint8_t LEN, uint8_t val){ // write
  uint8_t oldReg = readRegister_u8(regAddr);
  uint8_t newReg = setBits(val,POS,LEN,oldReg);
  writeRegister(regAddr,newReg);
}

uint8_t MPU_rw(uint8_t regAddr, uint8_t POS, uint8_t LEN){ // read
  uint8_t oldReg = readRegister_u8(regAddr);
  oldReg >>= POS-LEN+1;
  oldReg &= ( (uint8_t)1 << LEN ) - 1;
  return oldReg;
}

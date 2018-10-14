


#ifndef _gyro_class_H_
#define _gyro_class_H_

#include "Arduino.h"
#include "endianSwap.h"
#include "MPU6000.h"
#include "SPI.h"     // SPI library
#define CS_PIN PA4
#define CS_ON()  digitalWrite(CS_PIN,LOW)
#define CS_OFF() digitalWrite(CS_PIN,HIGH)

const uint8_t SPI_READ = 0b10000000;

class __gyro__
{
  public:
  uint8_t _cs;
  bool _hs = 0;
  void init(uint8_t cs);
  void SPI_init(void);
  void hs(bool hs);
  void MPU_default(void);
  void FIFO_enable(bool gyro, bool accel, bool temp);
  void FIFO_enable(bool enable);
  void FIFO_read(int16_t* buf,int cnt);
  uint16_t FIFO_cnt(void);
  void FIFO_reset(void);
  void Interrupt_enable(bool en);
  
  double FSG(void);
  double FSA(void);
  double FSG(int fs);
  double FSA(int fs);
  
};


void writeRegister(uint8_t regAddr, uint8_t data);
void readRegisters_u8(uint8_t regAddr, uint8_t* buf, int cnt);
void readRegisters_i16(uint8_t regAddr, int16_t* buf, int cnt);
uint8_t readRegister_u8(uint8_t regAddr);
int16_t readRegister_i16(uint8_t regAddr);
uint8_t setBits(uint8_t val, uint8_t POS, uint8_t LEN, uint8_t src);
void MPU_rw(uint8_t regAddr, uint8_t POS, uint8_t LEN, uint8_t val);
uint8_t MPU_rw(uint8_t regAddr, uint8_t POS, uint8_t LEN);

#endif

#ifndef _MPU6000_H_
#define _MPU6000_H_

#define SPIrw_helper(...) MPU_rw(__VA_ARGS__)

#define MPU__XA_TEST_H(...)        SPIrw_helper(0x0D,7,3,##__VA_ARGS__)
#define MPU__XG_TEST_H(...)        SPIrw_helper(0x0D,4,5,##__VA_ARGS__)
#define MPU__YA_TEST_H(...)        SPIrw_helper(0x0E,7,3,##__VA_ARGS__)
#define MPU__YG_TEST_H(...)        SPIrw_helper(0x0E,4,5,##__VA_ARGS__)
#define MPU__ZA_TEST_H(...)        SPIrw_helper(0x0F,7,3,##__VA_ARGS__)
#define MPU__ZG_TEST_H(...)        SPIrw_helper(0x0F,4,5,##__VA_ARGS__)
#define MPU__XA_TEST_L(...)        SPIrw_helper(0x10,5,2,##__VA_ARGS__)
#define MPU__YA_TEST_L(...)        SPIrw_helper(0x10,3,2,##__VA_ARGS__)
#define MPU__ZA_TEST_L(...)        SPIrw_helper(0x10,1,2,##__VA_ARGS__)
#define MPU__SMPLR_DIV(...)        SPIrw_helper(0x19,7,8,##__VA_ARGS__)
#define MPU__EXT_SYNC_SET(...)     SPIrw_helper(0x1A,5,3,##__VA_ARGS__)
#define MPU__DLPF_CFG(...)         SPIrw_helper(0x1A,2,3,##__VA_ARGS__)
#define MPU__FS_SEL(...)           SPIrw_helper(0x1B,4,2,##__VA_ARGS__)
#define MPU__XA_ST(...)            SPIrw_helper(0x1C,7,1,##__VA_ARGS__)
#define MPU__YA_ST(...)            SPIrw_helper(0x1C,6,1,##__VA_ARGS__)
#define MPU__ZA_ST(...)            SPIrw_helper(0x1C,5,1,##__VA_ARGS__)
#define MPU__AFS_SEL(...)          SPIrw_helper(0x1C,4,2,##__VA_ARGS__)
#define MPU__TEMP_FIFO_EN(...)     SPIrw_helper(0x23,7,1,##__VA_ARGS__)
#define MPU__XG_FIFO_EN(...)       SPIrw_helper(0x23,6,1,##__VA_ARGS__)
#define MPU__YG_FIFO_EN(...)       SPIrw_helper(0x23,5,1,##__VA_ARGS__)
#define MPU__ZG_FIFO_EN(...)       SPIrw_helper(0x23,4,1,##__VA_ARGS__)
#define MPU__ACCEL_FIFO_EN(...)    SPIrw_helper(0x23,3,1,##__VA_ARGS__)
#define MPU__SLV2_FIFO_EN(...)     SPIrw_helper(0x23,2,1,##__VA_ARGS__)
#define MPU__SLV1_FIFO_EN(...)     SPIrw_helper(0x23,1,1,##__VA_ARGS__)
#define MPU__SLV0_FIFO_EN(...)     SPIrw_helper(0x23,0,1,##__VA_ARGS__)
#define MPU__MULT_MST_EN(...)      SPIrw_helper(0x24,7,1,##__VA_ARGS__)
#define MPU__WAIT_FOR_ES(...)      SPIrw_helper(0x24,6,1,##__VA_ARGS__)
#define MPU__SLV3_FIFO_EN(...)     SPIrw_helper(0x24,5,1,##__VA_ARGS__)
#define MPU__I2C_MST_P_NSR(...)    SPIrw_helper(0x24,4,1,##__VA_ARGS__)
#define MPU__I2C_MST_CLK(...)      SPIrw_helper(0x24,3,4,##__VA_ARGS__)
#define MPU__I2C_SLV0_RW(...)      SPIrw_helper(0x25,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_ADDR(...)    SPIrw_helper(0x25,6,7,##__VA_ARGS__)
#define MPU__I2C_SLV0_REG(...)     SPIrw_helper(0x26,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV0_EN(...)      SPIrw_helper(0x27,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_BYTE_SW(...) SPIrw_helper(0x27,6,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_REG_DIS(...) SPIrw_helper(0x27,5,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_GRP(...)     SPIrw_helper(0x27,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_LEN(...)     SPIrw_helper(0x27,3,4,##__VA_ARGS__)
#define MPU__I2C_SLV1_RW(...)      SPIrw_helper(0x28,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_ADDR(...)    SPIrw_helper(0x28,6,7,##__VA_ARGS__)
#define MPU__I2C_SLV1_REG(...)     SPIrw_helper(0x29,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV1_EN(...)      SPIrw_helper(0x2A,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_BYTE_SW(...) SPIrw_helper(0x2A,6,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_REG_DIS(...) SPIrw_helper(0x2A,5,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_GRP(...)     SPIrw_helper(0x2A,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_LEN(...)     SPIrw_helper(0x2A,3,4,##__VA_ARGS__)
#define MPU__I2C_SLV2_RW(...)      SPIrw_helper(0x2B,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_ADDR(...)    SPIrw_helper(0x2B,6,7,##__VA_ARGS__)
#define MPU__I2C_SLV2_REG(...)     SPIrw_helper(0x2C,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV2_EN(...)      SPIrw_helper(0x2D,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_BYTE_SW(...) SPIrw_helper(0x2D,6,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_REG_DIS(...) SPIrw_helper(0x2D,5,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_GRP(...)     SPIrw_helper(0x2D,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_LEN(...)     SPIrw_helper(0x2D,3,4,##__VA_ARGS__)
#define MPU__I2C_SLV3_RW(...)      SPIrw_helper(0x2E,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_ADDR(...)    SPIrw_helper(0x2E,6,7,##__VA_ARGS__)
#define MPU__I2C_SLV3_REG(...)     SPIrw_helper(0x2F,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV3_EN(...)      SPIrw_helper(0x30,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_BYTE_SW(...) SPIrw_helper(0x30,6,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_REG_DIS(...) SPIrw_helper(0x30,5,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_GRP(...)     SPIrw_helper(0x30,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_LEN(...)     SPIrw_helper(0x30,3,4,##__VA_ARGS__)
#define MPU__I2C_SLV4_RW(...)      SPIrw_helper(0x31,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_ADDR(...)    SPIrw_helper(0x31,6,7,##__VA_ARGS__)
#define MPU__I2C_SLV4_REG(...)     SPIrw_helper(0x32,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV4_DO(...)      SPIrw_helper(0x33,7,8,##__VA_ARGS__)
#define MPU__I2C_SLV4_EN(...)      SPIrw_helper(0x34,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_INT_EN(...)  SPIrw_helper(0x34,6,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_REG_DIS(...) SPIrw_helper(0x34,5,1,##__VA_ARGS__)
#define MPU__I2C_MST_DLY(...)      SPIrw_helper(0x34,4,5,##__VA_ARGS__)
#define MPU__I2C_SLV4_DI(...)      SPIrw_helper(0x35,7,8,##__VA_ARGS__)
#define MPU__PASS_THROUGH(...)     SPIrw_helper(0x36,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_DONE(...)    SPIrw_helper(0x36,6,1,##__VA_ARGS__)
#define MPU__I2C_LOST_ARB(...)     SPIrw_helper(0x36,5,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_NACK(...)    SPIrw_helper(0x36,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_NACK(...)    SPIrw_helper(0x36,3,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_NACK(...)    SPIrw_helper(0x36,2,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_NACK(...)    SPIrw_helper(0x36,1,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_NACK(...)    SPIrw_helper(0x36,0,1,##__VA_ARGS__)
#define MPU__INT_LEVEL(...)        SPIrw_helper(0x37,7,1,##__VA_ARGS__)
#define MPU__INT_OPEN(...)         SPIrw_helper(0x37,6,1,##__VA_ARGS__)
#define MPU__LATCH_INT_EN(...)     SPIrw_helper(0x37,5,1,##__VA_ARGS__)
#define MPU__INT_RD_CLEAR(...)     SPIrw_helper(0x37,4,1,##__VA_ARGS__)
#define MPU__FSYNC_INT_LEVEL(...)  SPIrw_helper(0x37,3,1,##__VA_ARGS__)
#define MPU__FSYNC_INT_EN(...)     SPIrw_helper(0x37,2,1,##__VA_ARGS__)
#define MPU__I2C_BYPASS_EN(...)    SPIrw_helper(0x37,1,1,##__VA_ARGS__)
#define MPU__FIFO_OFLOW_EN(...)    SPIrw_helper(0x38,4,1,##__VA_ARGS__)
#define MPU__I2C_MST_INT_EN(...)   SPIrw_helper(0x38,3,1,##__VA_ARGS__)
#define MPU__DATA_RDY_EN(...)      SPIrw_helper(0x38,0,1,##__VA_ARGS__)
#define MPU__FIFO_OFLOW_INT(...)   SPIrw_helper(0x3A,4,1,##__VA_ARGS__)
#define MPU__I2C_MST_INT(...)      SPIrw_helper(0x3A,3,1,##__VA_ARGS__)
#define MPU__DATA_RDY_INT(...)     SPIrw_helper(0x3A,0,1,##__VA_ARGS__)
#define MPU__DELAY_ES_SHADOW(...)  SPIrw_helper(0x67,7,1,##__VA_ARGS__)
#define MPU__I2C_SLV4_DLY_EN(...)  SPIrw_helper(0x67,4,1,##__VA_ARGS__)
#define MPU__I2C_SLV3_DLY_EN(...)  SPIrw_helper(0x67,3,1,##__VA_ARGS__)
#define MPU__I2C_SLV2_DLY_EN(...)  SPIrw_helper(0x67,2,1,##__VA_ARGS__)
#define MPU__I2C_SLV1_DLY_EN(...)  SPIrw_helper(0x67,1,1,##__VA_ARGS__)
#define MPU__I2C_SLV0_DLY_EN(...)  SPIrw_helper(0x67,0,1,##__VA_ARGS__)
#define MPU__GYRO_RESET(...)       SPIrw_helper(0x68,2,1,##__VA_ARGS__)
#define MPU__ACCEL_RESET(...)      SPIrw_helper(0x68,1,1,##__VA_ARGS__)
#define MPU__TEMP_RESET(...)       SPIrw_helper(0x68,0,1,##__VA_ARGS__)
#define MPU__FIFO_EN(...)          SPIrw_helper(0x6A,6,1,##__VA_ARGS__)
#define MPU__I2C_MST_EN(...)       SPIrw_helper(0x6A,5,1,##__VA_ARGS__)
#define MPU__I2C_IF_DIS(...)       SPIrw_helper(0x6A,4,1,##__VA_ARGS__)
#define MPU__FIFO_RESET(...)       SPIrw_helper(0x6A,2,1,##__VA_ARGS__)
#define MPU__I2C_MST_RESET(...)    SPIrw_helper(0x6A,1,1,##__VA_ARGS__)
#define MPU__SIG_COND_RESET(...)   SPIrw_helper(0x6A,0,1,##__VA_ARGS__)
#define MPU__DEVICE_RESET(...)     SPIrw_helper(0x6B,7,1,##__VA_ARGS__)
#define MPU__SLEEP(...)            SPIrw_helper(0x6B,6,1,##__VA_ARGS__)
#define MPU__CYCLE(...)            SPIrw_helper(0x6B,5,1,##__VA_ARGS__)
#define MPU__TEMP_DIS(...)         SPIrw_helper(0x6B,3,1,##__VA_ARGS__)
#define MPU__CLKSEL(...)           SPIrw_helper(0x6B,2,3,##__VA_ARGS__)
#define MPU__LP_WAKE_CTRL(...)     SPIrw_helper(0x6C,7,2,##__VA_ARGS__)
#define MPU__STBY_XA(...)          SPIrw_helper(0x6C,5,1,##__VA_ARGS__)
#define MPU__STBY_YA(...)          SPIrw_helper(0x6C,4,1,##__VA_ARGS__)
#define MPU__STBY_ZA(...)          SPIrw_helper(0x6C,3,1,##__VA_ARGS__)
#define MPU__STBY_XG(...)          SPIrw_helper(0x6C,2,1,##__VA_ARGS__)
#define MPU__STBY_YG(...)          SPIrw_helper(0x6C,1,1,##__VA_ARGS__)
#define MPU__STBY_ZG(...)          SPIrw_helper(0x6C,0,1,##__VA_ARGS__)
#define MPU__FIFO_CNT_H(...)       SPIrw_helper(0x72,7,8,##__VA_ARGS__)
#define MPU__FIFO_CNT_L(...)       SPIrw_helper(0x73,7,8,##__VA_ARGS__)
#define MPU__FIFO_DATA(...)        SPIrw_helper(0x74,7,8,##__VA_ARGS__)
#define MPU__WHO_AM_I(...)         SPIrw_helper(0x75,6,6,##__VA_ARGS__)
#define MPU__ACCEL_XOUT_H(...)     SPIrw_helper(0x3B,7,8,##__VA_ARGS__)
#define MPU__ACCEL_XOUT_L(...)     SPIrw_helper(0x3C,7,8,##__VA_ARGS__)
#define MPU__ACCEL_YOUT_H(...)     SPIrw_helper(0x3D,7,8,##__VA_ARGS__)
#define MPU__ACCEL_YOUT_L(...)     SPIrw_helper(0x3E,7,8,##__VA_ARGS__)
#define MPU__ACCEL_ZOUT_H(...)     SPIrw_helper(0x3F,7,8,##__VA_ARGS__)
#define MPU__ACCEL_ZOUT_L(...)     SPIrw_helper(0x40,7,8,##__VA_ARGS__)
#define MPU__TEMP_OUT_H(...)       SPIrw_helper(0x41,7,8,##__VA_ARGS__)
#define MPU__TEMP_OUT_L(...)       SPIrw_helper(0x42,7,8,##__VA_ARGS__)
#define MPU__GYRO_XOUT_H(...)      SPIrw_helper(0x43,7,8,##__VA_ARGS__)
#define MPU__GYRO_XOUT_L(...)      SPIrw_helper(0x44,7,8,##__VA_ARGS__)
#define MPU__GYRO_YOUT_H(...)      SPIrw_helper(0x45,7,8,##__VA_ARGS__)
#define MPU__GYRO_YOUT_L(...)      SPIrw_helper(0x46,7,8,##__VA_ARGS__)
#define MPU__GYRO_ZOUT_H(...)      SPIrw_helper(0x47,7,8,##__VA_ARGS__)
#define MPU__GYRO_ZOUT_L(...)      SPIrw_helper(0x48,7,8,##__VA_ARGS__)

#endif
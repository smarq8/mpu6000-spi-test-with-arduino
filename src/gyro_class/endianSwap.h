// MOJE
#ifndef _endianswap_h_
#define _endianswap_h_
#define swap16(val) (uint16_t)((uint16_t)(val) << 8) | ((uint16_t)((uint16_t)(val) >> 8) & (uint16_t)0x00FF)

inline void arrayEndianSwap_16(void* buf,int cnt){
  uint16_t* buf16 = (uint16_t*)buf;
  for(int i=0;i<cnt;i++){
    buf16[i] = swap16(buf16[i]);
  }
}

//https://stackoverflow.com/questions/2182002/convert-big-endian-to-little-endian-in-c-without-using-provided-func
//! Byte swap short

//#define SWAP_INT16(x) *(x) = (((uint16_t)0x00ff & (uint16_t)(*(x))>>8) | ((uint16_t)0xff00 & (uint16_t)(*(x))<<8))
//
//uint16_t swap_uint16( uint16_t val )
//{
//    return (val << 8) | (val >> 8 );
//}
//int16_t swap_int16( int16_t val ) 
//{
//    return (uint16_t)(val << 8) | (uint16_t)((val >> 8) & (uint16_t)0xFF);
//}
//
////! Byte swap unsigned int
//uint32_t swap_uint32( uint32_t val )
//{
//    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF ); 
//    return (val << 16) | (val >> 16);
//}
//
////! Byte swap int
//int32_t swap_int32( int32_t val )
//{
//    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
//    return (val << 16) | ((val >> 16) & 0xFFFF);
//}
//
//int64_t swap_int64( int64_t val )
//{
//    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
//    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
//    return (val << 32) | ((val >> 32) & 0xFFFFFFFFULL);
//}
//
//uint64_t swap_uint64( uint64_t val )
//{
//    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
//    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
//    return (val << 32) | (val >> 32);
//}

#endif

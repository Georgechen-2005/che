#ifndef __ENCODER_H
#define __ENCODER_H

void Encoder1_Init(void);
void Encoder2_Init(void);
void Encoder3_Init(void);
float CalculateSpeed(uint16_t pulse_count, float delta_time);
float GetTime(void);
uint16_t GetEncoderCount1(void);
uint16_t GetEncoderCount2(void);
uint16_t GetEncoderCount3(void);
float  GETEncoderspeed1(void);
float  GETEncoderspeed2(void);
float  GETEncoderspeed3(void);
#endif

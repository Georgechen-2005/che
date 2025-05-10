#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "pid.h"
#include "Motor.h"
#include "OLED.h"
#include "Key.h"
#include "Encoder.h"
#include "PWM.h"
#include "math.h"

uint8_t KeyNum;
int8_t Speed;

PID_t wheel1;
PID_t wheel2;
PID_t wheel3;

static PID_t wheel1 = {
	.Target = 0,
  .Kp = 0.8,
	.Ki =0.1,
	.Kd = 0.08,
  .OutMax = 200,
  .OutMin = -200,
};

static PID_t wheel2 = {
	.Target = 0,
  .Kp = 0.94,
	.Ki = 0.502,
	.Kd = 0.388,
  .OutMax = 200,
  .OutMin = -200,
};

static PID_t wheel3 = {
	.Target = 0,
  .Kp = 0.81,
	.Ki = 0.1,
	.Kd = 0.08,
  .OutMax = 200,
  .OutMin = -200,
};

int main(void)
{
	
	extern void pid_update(PID_t wheel);
	float wheel1speed,wheel2speed,wheel3speed;
		
	int side =1;

	OLED_Init();
	PWM_Init();
	Motor_Init();
	  float w=1;
    float l=0.2;
	float p =0;
	float v;
	float pi =3.14159;
	float v1,v2,v3;

	while (1)
	{
		float vx;  
    float vy;
		Encoder1_Init();
		wheel1.Actual  = GETEncoderspeed1();
		Encoder2_Init();
		wheel2.Actual  = GETEncoderspeed2();
		Encoder3_Init(); 
		wheel3.Actual  = GETEncoderspeed3();


		
			if(side ==1){
				vx=0;
				vy=-130;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
		Encoder1_Init();
		wheel1.Actual  = GETEncoderspeed1();
		Encoder2_Init();
		wheel2.Actual  = GETEncoderspeed2();
		Encoder3_Init(); 
		wheel3.Actual  = GETEncoderspeed3();
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);

							Delay_s(2);
				side++;
			}
			if (side==2){
				vx=48.5;
				vy=0;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);	
					Delay_s(2);
				side++;
			}
				if (side==3){
				vx=0;
				vy=150;
					w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx-7;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);

						Delay_s(2);
				side++;
			}
				if(side==4) {
				vx=-58.8;
				vy=0;
					w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);
						Delay_s(2);
			side++;
				}
			if(side == 5)
			{
			Motor_SetSpeed1(0);
			Motor_SetSpeed2(0);
			Motor_SetSpeed3(0);
				Delay_s(2);
				side++;
			}


//		
	//三角形
			if(side ==6)
			{
				vx=0;
				vy=100;
				w=0;
  wheel2.Kp = 0.8,
	wheel2.Ki =0.1,
	wheel2.Kd = 0.08;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;

      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);
				Delay_s(2);
				side++;
			}
			if(side==7)
			{
				vx=-60/sqrt(3);
				vy=-49;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)-20;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);
				Delay_s(2);
				side++;
			}
			if(side==8)
			{
				vx=60/sqrt(3);
				vy=-50;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+20;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;

      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(-wheel1.Out);
			Motor_SetSpeed2(-wheel2.Out);
			Motor_SetSpeed3(-wheel3.Out);
				Delay_s (2);
				side++;				
			}
		if(side == 9)
			{

			Motor_SetSpeed1(0);
			Motor_SetSpeed2(0);
			Motor_SetSpeed3(0);
				Delay_s(1);
				side++;
			}

			if(side < 210 && side>9)
			{
				v=150;
      w=0;
			vx = v*cos(p);
			vy= v*sin(p);
				 v1=vx*(-0.5)+vy*sqrt(3)*0.5+w*l;
				 v2=vx+w*l;
				 v3=vx*(-0.5)+vy*sqrt(3)*(-0.5)+w*l;
			wheel1speed =v1;
			wheel2speed =v2;
			wheel3speed =v3;
			wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(wheel2.Out*5);
			Motor_SetSpeed3(wheel3.Out);
				p=p+(pi/100);
				Delay_ms(10);
				side++;
  }

						if(side < 390 && side>209)
			{
				v=140;
      w=0;
			vx = -v*cos(p);
			vy= -v*sin(p);
				 v1=vx*(-0.5)+vy*sqrt(3)*0.5+w*l;
				 v2=vx+w*l;
				 v3=vx*(-0.5)+vy*sqrt(3)*(-0.5)+w*l;
			wheel1speed =v1;
			wheel2speed =v2;
			wheel3speed =v3;
			wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(wheel2.Out*5);
			Motor_SetSpeed3(wheel3.Out);
				p=p+(pi/100);
				Delay_ms(10);
				side++;
  }
						if(side==390)
			{
			Motor_SetSpeed1(0);
			Motor_SetSpeed2(0);
			Motor_SetSpeed3(0);
			}
    }
	}

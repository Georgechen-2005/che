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
  .Kp = 18,
	.Ki = 3,
	.Kd = 3,
  .OutMax = 1000,
  .OutMin = -1000,
};

static PID_t wheel2 = {
	.Target = 0,
  .Kp = 18,
	.Ki = 3,
	.Kd = 3,
  .OutMax = 1000,
  .OutMin = -1000,
};

static PID_t wheel3 = {
	.Target = 0,
  .Kp = 18,
	.Ki = 3,
	.Kd = 3,
  .OutMax = 1000,
  .OutMin = -1000,
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

	while (1)
	{
		float vx;  
    float vy;
		w=0;
		Encoder1_Init();
		wheel1.Actual  = GETEncoderspeed1();
		Encoder2_Init();
		wheel2.Actual  = GETEncoderspeed2();
		Encoder3_Init(); 
		wheel3.Actual  = GETEncoderspeed3();


		
			if(side ==1){
				vx=0;
				vy=-1000;
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
//				wheel1speed=500;
//				wheel2speed=0;
//				wheel3speed=-500;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(wheel3.Out);

							Delay_s(2);
				side++;
			}
			if (side==2){
				vx=500;
				vy=0;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
//				wheel2speed=500;
			wheel2.Target =wheel2speed ;
			PID_Update(&wheel2);
			Motor_SetSpeed1(-50);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(-50);		
					Delay_s(2);
				side++;
			}
				if (side==3){
				vx=0;
				vy=1000;
					w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
//				wheel1speed=-500;
//				wheel2speed=0;
//				wheel3speed=500;
      wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(wheel3.Out);

						Delay_s(2);
				side++;
			}
				if(side==4) {
				vx=-500;
				vy=0;
					w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
//				wheel2speed=-500;
			wheel2.Target =wheel2speed ;
			PID_Update(&wheel2);
			Motor_SetSpeed1(50);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(50);
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


		
	//三角形
			if(side ==6)
			{
				vx=0;
				vy=500;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
//				wheel1speed=-50;
//				wheel2speed=500;
//				wheel3speed=-50;
			wheel2.Target =wheel2speed ;
			PID_Update(&wheel2);
			Motor_SetSpeed1(-50);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(-50);
				Delay_s(2);
				side++;
			}
			if(side==7)
			{
				vx=-500/sqrt(3);
				vy=-500;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
//				wheel1speed =500;
				wheel1.Target =wheel1speed ;
			PID_Update(&wheel1);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(-50);
			Motor_SetSpeed3(-50);
				Delay_s(2);
				side++;
			}
			if(side==8)
			{
				vx=-500/sqrt(3);
				vy=500;
				w=0;
	  wheel1speed = -vx*0.5*sqrt(3)-vy*0.5+w*l;
	  wheel2speed =vx+w*l;
		wheel3speed = vy*0.5-vx*0.5*sqrt(3)+w*l;
				wheel3speed=500;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel3);
			Motor_SetSpeed1(-50);
			Motor_SetSpeed2(-50);
			Motor_SetSpeed3(wheel3.Out);
				Delay_s(2);
				side++;				
			}
		if(side == 9)
			{
			Motor_SetSpeed1(0);
			Motor_SetSpeed2(0);
			Motor_SetSpeed3(0);
									Delay_s(2);
				side++;
			}

			if(side == 10)
			{
//			float vx;  //圆
//    float vy;
      w=1;
      float p=0;
			float v=30;
				double pi=3.1415926;
//			float vx,vy;
			vx = v*cos(p);
			vy=v*sin(p);
			wheel1speed = -vx*0.5-vy*sqrt(3)*0.5+w*l;
			wheel2speed =vx+w*l;
			wheel3speed = vy*sqrt(3)*0.5-vx*0.5+w*l;
		  if(p<2*pi)
		  {
			p+=0.01;
		  }
		  Delay_ms(10);
			wheel1.Target =wheel1speed ;
			wheel2.Target =wheel2speed ;
			wheel3.Target =wheel3speed ;
			PID_Update(&wheel1);
			PID_Update(&wheel2);
			PID_Update(&wheel3);
			Motor_SetSpeed1(wheel1.Out);
			Motor_SetSpeed2(wheel2.Out);
			Motor_SetSpeed3(wheel3.Out);
		}
//						if(side == 1)
//			{
//      w=0.01;
//      float p=0;
//			float v=30;
//				double pi =3.14159265358979323846;
////			vx = v*cos(p);
////			vy=v*sin(p);
////			wheel1speed =-vy/sqrt(3)-w*l;
////			wheel2speed =vx+w*l;
////			wheel3speed =+vy/sqrt(3)+w*l;
//		  if(p<(pi/2))
//		  {
//			vx = v*cos(p);
//			vy=v*sin(p);
//			wheel1speed =-vy/sqrt(3)-w*l;
//			wheel2speed =vx+w*l;
//			wheel3speed =vy/sqrt(3)+w*l;
////						  Delay_ms(10);
//			wheel1.Target =wheel1speed ;
//			wheel2.Target =wheel2speed ;
//			wheel3.Target =wheel3speed ;
//			PID_Update(&wheel1);
//			PID_Update(&wheel2);
//			PID_Update(&wheel3);
//			Motor_SetSpeed1(wheel1.Out);
//			Motor_SetSpeed2(wheel2.Out);
//			Motor_SetSpeed3(wheel3.Out);
//			p+=(pi/100);
//			Delay_ms(1000);
//		  }
//			
//					  if((pi/2)<p<pi)
//		  {
//			vx = v*cos(p);
//			vy=v*sin(p);
//			wheel1speed =-vy/sqrt(3)-w*l;
//			wheel2speed =-vx-w*l;
//			wheel3speed =+vy/sqrt(3)+w*l;
//						  
//			wheel1.Target =wheel1speed ;
//			wheel2.Target =wheel2speed ;
//			wheel3.Target =wheel3speed ;
//			PID_Update(&wheel1);
//			PID_Update(&wheel2);
//			PID_Update(&wheel3);
//			Motor_SetSpeed1(wheel1.Out);
//			Motor_SetSpeed2(wheel2.Out);
//			Motor_SetSpeed3(wheel3.Out);
//			p+=(pi/100);
//				Delay_ms(1000);
//		  }
//					  if(pi<p<(pi*3/2))
//		  {
//			vx = v*cos(p);
//			vy=v*sin(p);
//			wheel1speed =vy/sqrt(3)+w*l;
//			wheel2speed =-vx-w*l;
//			wheel3speed =-vy/sqrt(3)-w*l;
//			wheel1.Target =wheel1speed ;
//			wheel2.Target =wheel2speed ;
//			wheel3.Target =wheel3speed ;
//			PID_Update(&wheel1);
//			PID_Update(&wheel2);
//			PID_Update(&wheel3);
//			Motor_SetSpeed1(wheel1.Out);
//			Motor_SetSpeed2(wheel2.Out);
//			Motor_SetSpeed3(wheel3.Out);
//			p+=(pi/100);
//				Delay_ms(1000);
//		  }
//		  
//					  if((pi*3/2)<p<2*pi)
//		  {
//			vx = v*cos(p);
//			vy=v*sin(p);
//			wheel1speed =vy/sqrt(3)+w*l;
//			wheel2speed =vx+w*l;
//			wheel3speed =-vy/sqrt(3)-w*l;
//			wheel1.Target =wheel1speed ;
//			wheel2.Target =wheel2speed ;
//			wheel3.Target =wheel3speed ;
//			PID_Update(&wheel1);
//			PID_Update(&wheel2);
//			PID_Update(&wheel3);
//			Motor_SetSpeed1(wheel1.Out);
//			Motor_SetSpeed2(wheel2.Out);
//			Motor_SetSpeed3(wheel3.Out);
//			p+=(pi/100);
//						  Delay_ms(1000);
//		  }
//			if(p==2*pi)
//			{
//			Motor_SetSpeed1(0);
//			Motor_SetSpeed2(0);
//			Motor_SetSpeed3(0);
//			}

//			wheel1.Target =wheel1speed ;
//			wheel2.Target =wheel2speed ;
//			wheel3.Target =wheel3speed ;
//			PID_Update(&wheel1);
//			PID_Update(&wheel2);
//			PID_Update(&wheel3);
//			Motor_SetSpeed1(wheel1.Out);
//			Motor_SetSpeed2(wheel2.Out);
//			Motor_SetSpeed3(wheel3.Out);
		}
  }

//}

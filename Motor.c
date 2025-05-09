#include "stm32f10x.h"                  // Device header
#include "PWM.h"

// 第一个电机 PWMA:PA0   PA3,6
// 第二个电机 PWMA:PA1   PA7,5
// 第三个电机 PWMA:PA2   PB14,8


void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_5;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);
	// PA3,6第一个 PA7,5第二个
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure2);
	// PB14,8第三个
	
	PWM_Init();
}

void Motor_SetSpeed1(int16_t Duty)
{
		if (Duty >= 0)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_3);
			GPIO_SetBits(GPIOA, GPIO_Pin_6);
			PWM_SetCompare1(Duty);
		}
		else
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_3);
			GPIO_ResetBits(GPIOA, GPIO_Pin_6);
			PWM_SetCompare1(-Duty);
		}
}

void Motor_SetSpeed2(int16_t Duty)
{
		if (Duty >= 0)
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_7);
			GPIO_SetBits(GPIOA, GPIO_Pin_5);
			PWM_SetCompare2(Duty);
		}
		else
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_7);
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);
			PWM_SetCompare2(-Duty);
		}
}

void Motor_SetSpeed3(int16_t Duty)
{
		if (Duty >= 0)
		{
			GPIO_ResetBits(GPIOB, GPIO_Pin_14);
			GPIO_SetBits(GPIOB, GPIO_Pin_15);
			PWM_SetCompare3(Duty);
		}
		else
		{
			GPIO_SetBits(GPIOB, GPIO_Pin_14);
			GPIO_ResetBits(GPIOB, GPIO_Pin_15);
			PWM_SetCompare3(-Duty);
		}
}

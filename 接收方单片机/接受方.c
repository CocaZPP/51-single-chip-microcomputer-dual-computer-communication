#include<reg52.h>         //52ϵ�е�Ƭ��ͷ�ļ�
typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
//sbit led=P2^0;

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//��ʾ0~F��ֵ
u8 a;
void display(num)
{
   P0=smgduan[num];
}
void main()
{
  TMOD=0x20;
  TH1=0xfd;
  TL1=0xfd;
  TR1=1;
  REN=1;
  SM0=0;
  SM1=1;
  EA=1;
  ES=1;
  LSA=0;
  LSB=0;
  LSC=0;
  while(1);				   //�ȴ������жϲ�����Ȼ�������ʾ
  { 
//	  if(a=='1')
//	   {
//	     led=0;
//		}
  }

}
void ser()interrupt 4
{
//  u8 a;
  RI=0;
  a=SBUF;
  display(a);
}
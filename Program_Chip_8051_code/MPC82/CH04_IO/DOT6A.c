/***** DOT6A.c ****�I�x�}��ܾ�������r��********
*�ʧ@�G��ܥ�����|�Ӧr
*���u�GScan�C�q�챽�y��X�A��Data�C�q���X���
*�w��GSW1-2(LED8X8)ON
//**********************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
#include "font4.h"  //�r��ABCD�����
main() 
{ 
  unsigned char i;     //�w�q�}�C��ƭp��
  unsigned char repeat;//�w�q���б��y����	
  unsigned char start; //�w�q������r���}�lŪ���p�� 
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  Scan=0x7F; //��com1�}�l����  
 while(1)
 {
   for(start=0;start<8*4;start++) //�}�l�p�ƭ��w4�Ӧr��
   {
   	for(repeat=0;repeat<200;repeat++)  //���б��˦���
     {
       for(i=0;i<8;i++)   //Ū��8����Ʊ���8��
       {
         Data=font4[(start+i)%32];//Ū���}�l�p�Ƥ��᪺�}�C��ƿ�X
		 Delay_ms(1);       //����
		 Data=0xff;       //���t
         Scan=RR8(Scan); //�����ˤU�@��
       }
     } 
   }
 } 
}
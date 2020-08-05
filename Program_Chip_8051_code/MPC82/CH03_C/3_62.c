/********* 3_62.c ***旋轉函數範例***************
*動作：令LED左旋轉 
*硬體：SW1-3(P0LED)ON
*************************************************/
#include "..\MPC82.H"  //暫存器及組態設定
main()
{
    unsigned char i=0x01; //定義8-bit變數
    P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  loop:
    LED=~i;	//變數輸出
    Delay_ms(100); //延時
    i=RR8(i);	//8-bit變數左旋轉
   goto loop;
}

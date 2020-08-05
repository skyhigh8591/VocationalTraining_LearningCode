/************** QLCD1.C **********************************
*動作：由LCD顯示兩行文字
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void main(void)
{
   unsigned char i;        //資料計數
   LCD_init();    //重置及清除LCD    
   LCD_Cmd(0x85); //游標由第一行第5個字開始顯示  
   LCD_Data('1');
   while(1);  
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(char dat)  //傳送資料到LCD
{
    Data=dat; //資料送到BUS
    RS=1;RW=0;EN=1;//資料寫入到LCD內
    Delay_ms(1);   //LCD等待寫入完成
    EN=0;          //禁能LCD 
	Delay_ms(1);   //LCD等待寫入完成   
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //傳送命令到LCD
{
    Data=Cmd;  //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    Delay_ms(1);    //LCD等待寫入完成     
    EN=0;           //禁能LCD
	Delay_ms(1);   //LCD等待寫入完成
}
/***************************************************************
*函數名稱: LCD_init
*功能描述: 啟始化文字型LCD
*****************************************************************/
void LCD_init(void)    //LCD的啟始程式  
{
   	Delay_ms(10);	 //初始化SETUP
    LCD_Cmd(0x30);LCD_Cmd(0x30);
                    /*bit4:DL=1,8bit傳輸,
                      bit2:RE=0,使用基本指令*/    
    LCD_Cmd(0x0F);/*0000 1100,顯示幕ON,顯示游標,游標閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=1,顯示游標
	                bit0:B=1,游標閃爍*/
    LCD_Cmd(0x01); //清除顯示幕
	LCD_Cmd(0x05);/*0000 0101,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=1,游標移位致能*/    
   
    LCD_Cmd(0x02); //游標回原位  
}
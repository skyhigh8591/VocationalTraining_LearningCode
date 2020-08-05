//************* LCD3A.c *********************
//*動作：在LCD顯示上下午12小時電子鐘的變化
//*******************************************
#include "..\MPC82.H"   //暫存器及組態定義
main()
{
   char hor=11,min=58,sec=52;//設定時、分、秒初值
   LCD_init();           //重置及清除LCD    
   while(1)
   {
    LCD_Cmd(0x82);        //由第一行開始顯示 
	if (hor<12) {LCD_Data('A');LCD_Data('M');}
	else  {LCD_Data('P');LCD_Data('M');}
	LCD_Data(' ');
    LCD_Data(hor%12/10+'0'); //時的十位數到LCD顯示
    LCD_Data(hor%12%10+'0'); //時的個位數到LCD顯示
    LCD_Data(':');
    
    LCD_Data(min/10+'0'); //分的十位數到LCD顯示
    LCD_Data(min%10+'0'); //分的個位數到LCD顯示
    LCD_Data(':');
    
    LCD_Data(sec/10+'0'); //秒的十位數到LCD顯示
    LCD_Data(sec%10+'0'); //秒的個位數到LCD顯示
    
	Delay_ms(500);
    sec++;              //秒加一
    if (sec < 60) continue; //若秒小於60到loop處   
    sec=0; min++;       //秒等於60則令秒=0，分加一
    if (min < 60) continue; //若分小於60到loop處   
    min=0; hor++;       //若分等於60則令分=0，時加一
    if (hor <25)  continue; //若時小於25到loop處
    hor=1;min=0; sec=0;//若時=25則令時=1、分=0、秒=0 
	
   }
}
/***********************************************************
*函數名稱: LCD_Data
*功能描述: 傳送資料到文字型LCD
*輸入參數：dat
************************************************************/
void LCD_Data(unsigned char dat)  //傳送資料到LCD
{
    unsigned char dly=2;
	Data=dat;      //資料送到BUS
    RS=1;RW=0;EN=1;//資料寫入到LCD內
    while(dly--);
	EN=0;          //禁能LCD 
	LCD_wait();    //LCD等待寫入完成  
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd(unsigned char Cmd) //傳送命令到LCD
{
    unsigned char dly=2;
	Data=Cmd;       //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    while(dly--);
    EN=0;           //禁能LCD
	LCD_wait(); //LCD等待寫入完成 
}
/***************************************************************
*函數名稱: LCD_Cmd
*功能描述: 傳送命令到文字型LCD
*輸入參數：Cmd
************************************************************/
void LCD_Cmd_Init(unsigned char Cmd) //傳送命令到LCD
{
	Data=Cmd;       //命令送到BUS
    RS=0;RW=0;EN=1; //命令寫入到LCD內
    Delay_ms(1);
    EN=0;           //禁能LCD
    Delay_ms(1);
}
/***************************************************************
*函數名稱: LCD_init
*功能描述: 啟始化文字型LCD
*****************************************************************/
void LCD_init(void)    //LCD的啟始程式  
{
    LCD_Cmd_Init(0x38);//0011 1000,8bit傳輸,顯示2行,5*7字型
    LCD_Cmd_Init(0x38);//bit4:DL=1,8bit傳輸,
    LCD_Cmd_Init(0x38);//bit3:N=1,顯示2行
                       //bit2:F=0,5*7字型    
    LCD_Cmd(0x0c);/*0000 1100,顯示幕ON,不顯示游標,游標不閃爍
                    bit2:D=1,顯示幕ON
                    bit1:C=0,不顯示游標
	                bit0:B=0,游標不閃爍*/
    LCD_Cmd(0x06);/*0000 0110,//顯示完游標右移,游標移位禁能 
                    bit1:I/D=1,顯示完游標右移,
                    bit0:S=0,游標移位禁能*/  
    LCD_Cmd(0x01); //清除顯示幕  
    LCD_Cmd(0x02); //游標回原位  
}
/**************************************************
*函數名稱: LCD_wait
*功能描述: LCD等待忙碌旗標BF
****************************************************/
void LCD_wait(void)
{
  unsigned char status;  //定義LCD讀取狀態
  Data=0xff; //P0設定為輸入埠
  do
  {
    RS=0;RW=1;EN=1;//讀取命令
    status= Data;	//輸入LCD的命令
    EN=0;			//禁能LCD
  }
  while(status & 0x80); //等待忙碌旗標BF=0
}

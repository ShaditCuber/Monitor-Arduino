#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
#include <TouchScreen.h>



const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9325
const int TS_LEFT=187,TS_RT=920,TS_TOP=163,TS_BOT=907;
uint16_t ID;
uint8_t Orientation = 0; 



#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF





void setup(void)
{


    tft.reset();
    ID = tft.readID();
    tft.begin(ID);
    Serial.begin(115200);
    tft.setRotation(Orientation);

      //Carga de datos CPU
      tft.fillScreen(BLACK);
      tft.setTextColor(WHITE,BLACK);
      tft.setCursor(10, 35);
      tft.setTextSize(2);
      tft.print("CPU Temp:");
      tft.setCursor(tft.width()-30, 28);
      tft.setTextSize(3);
      tft.println("C");
      tft.setCursor(10,75);
      tft.setTextSize(2);
      tft.print("CPU Load:");
      tft.setTextSize(3);
      tft.setCursor(tft.width()-30, 75 );
      tft.println("%");

      //Carga de datos HDD
      tft.setCursor(10,  130);
      tft.setTextSize(2);
      tft.print("HDD Temp:");
      tft.setCursor(tft.width()-30, 125);
      tft.setTextSize(3);
      tft.println("C");
      tft.setCursor(10,170);
      tft.setTextSize(2);
      tft.print("HDD Load:");
      tft.setTextSize(3);
      tft.setCursor(tft.width()-30, 170 );
      tft.println("%");

      //Carga de datos SSD
      tft.setCursor(10,  225);
      tft.setTextSize(2);
      tft.print("SSD Temp:");
      tft.setCursor(tft.width()-30, 220);
      tft.setTextSize(3);
      tft.println("C");
      tft.setCursor(10,265);
      tft.setTextSize(2);
      tft.print("SSD Load:");
      tft.setTextSize(3);
      tft.setCursor(tft.width()-30, 265 );
      tft.println("%");
}

void loop()
{   
    String x =" ";
    char str[40];
    char s[2] = ",";
    char *token;
    int aux[6];
    
    while(!Serial.available());
      x=Serial.readString();
      x.toCharArray(str,40);
      token = strtok(str,s);
      int i=0;
      while(token!=NULL){
        aux[i]=atoi(token);
        i++;
        token = strtok(NULL, s); 
      }
      String cputemp,cpuload,hddtemp,hddload,ssdtemp,ssdload;
      String bcputemp,bcpuload,bhddtemp,bhddload,bssdtemp,bssdload;

      bcputemp = cputemp;
      cputemp=String(aux[0]);
      if( bcputemp != cputemp){
        if(aux[0]<10){
          cputemp="0"+cputemp;
        }
        if(aux[0]==100){
          cputemp="99";
        }
        
        if(aux[0]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK);
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 25 );
        tft.print(cputemp);
      }
      
      bcpuload=cpuload;
      cpuload=String(aux[1]);
      if( bcpuload != cpuload){
        if(aux[1]<10){
          cpuload="0"+cpuload;
        }
        if(aux[1]==100){
          cpuload="99";
        }
        
        if(aux[1]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK);
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 70 );
        tft.print(cpuload);
      }

      bhddtemp=hddtemp;
      hddtemp=String(aux[2]);
      if( bhddtemp != hddtemp){
        if(aux[2]<10){
          hddtemp="0"+hddtemp;
        }
        if(aux[2]==100){
          hddtemp="99";
        }
        
        if(aux[2]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK); 
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 123 );
        tft.print(hddtemp);
      }

      bhddload=hddload;
      hddload=String(aux[3]);
      if( bhddload != hddload){
        if(aux[3]<10){
          hddload="0"+hddload;
        }
        if(aux[3]==100){
          hddload="99";
        }
        
        if(aux[3]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK); 
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 170 );
        tft.print(hddload);
      }

      bssdtemp=ssdtemp;
      ssdtemp=String(aux[4]);
      if( bssdtemp != ssdtemp){
        if(aux[4]<10){
          ssdtemp="0"+ssdtemp;
        }
        if(aux[4]==100){
          ssdtemp="99";
        }
        
        if(aux[4]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK); 
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 215 );
        tft.print(ssdtemp);
      }
      
      bssdload=ssdload;
      ssdload=String(aux[5]);
      if( bssdload != ssdload){
        if(aux[5]<10){
          ssdload="0"+ssdload;
        }
        if(aux[5]==100){
          ssdload="99";
        }
        
        if(aux[5]>=70){
          tft.setTextColor(RED,BLACK);
        }else{
          tft.setTextColor(GREEN,BLACK); 
        }
        tft.setTextSize(4);
        tft.setCursor(tft.width()-100, 265 );
        tft.print(ssdload);
      }
      delay (1000);
     

}

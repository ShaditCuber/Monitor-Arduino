import serial
import time
import wmi
#Conectamos al arduino en el puerto en donde se encuentra conectado
arduino = serial.Serial('COM5', 115200, timeout=.1)
def write_read(x): #funcion para enviar datos al arduino
    arduino.write(bytes(x,'utf-8'))

while 1:
    
    w = wmi.WMI(namespace="root/OpenHardwareMonitor") #open Hardware Monitor
    temperature_infos = w.Sensor()
    cpu_temp = 0
    cpu_load = 0
    hdd_temp = 0
    hdd_load = 0
    ssd_temp = 0
    ssd_load = 0


    for sensor in temperature_infos: 
        
        #Buscamos por el tipo de sensor y el nombre que aparece en Open Hardware Monitor
        if sensor.SensorType==u'Temperature' and sensor.Name==u'CPU Package' :
              cpu_temp=sensor.Value 
              
        if sensor.SensorType==u'Load' and sensor.Name==u'CPU Total' :
              cpu_load=sensor.Value 
                       
        if sensor.SensorType==u'Temperature' and sensor.Name==u'Temperature HDD' :
              hdd_temp=sensor.Value 
             
        if sensor.SensorType==u'Load' and sensor.Name==u'Used Space HDD' :
              hdd_load=sensor.Value 
              
        if sensor.SensorType==u'Temperature' and sensor.Name==u'Temperature':
              ssd_temp=sensor.Value 
              
        if sensor.SensorType==u'Load' and sensor.Name==u'Used Space':
              ssd_load=sensor.Value 
              
        
              
    A = str(round(cpu_temp,2))
    B = str(round(cpu_load,2))
    C = str(round(hdd_temp,2))
    D = str(round(hdd_load,2))
    E = str(round(ssd_temp,2))
    F = str(round(ssd_load,2))
    finalString = A + "," + B + "," + C + "," + D + "," + E + "," + F + "\n" #Creamos el string a enviar al arduino
    write_read(finalString)#llamamos a la funcion para enviar el string
    time.sleep(2)#esperamos 2 segundos para que el arduino reciba el string y lo procese
    

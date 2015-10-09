import serial
import time
arduino = serial.Serial('COM4', 9600, timeout=.1)
ms = str(int(round(time.perf_counter()*1000.0)))
arduino.write(ms.encode())
incr = 0;
msf = 0
while True:
    data = arduino.readline()#the last bit gets rid of the new-line chars
    if data:
                msn = int(data.decode())
                ms = str(int(round(time.perf_counter()*1000.0*1000.0)))
                if incr == 10000:
                    #print(ms)
                    #print(msn)
                    #print(str((int(ms)-msn)))
                    print("latence: "+str((int(ms)-msn)/(1000.0))+"ms")
                    incr = 0
                    print("freq:" + str(10000.0*1000.0*1000.0/(int(ms)-msf)))
                    msf = int(ms)
                incr+=1
                ms = ms + '\n'
                arduino.write(ms.encode())


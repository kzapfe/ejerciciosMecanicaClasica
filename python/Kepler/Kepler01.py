"""Programa que resuelve las trayectorias del problema clasico
gravitacional de dos cuerpos """
#La constante gravitatoria es 1, la masa del Sol viene abajo

import numpy as np
MasaSol=1.000

class Planeta:
    """Un planeta, con posicion y velocidad, masa=1"""
    def __init__(self, qxini,qyini,pxini,pyini):
        #Valores iniciales
        self.qxini=qxini
        self.qyini=qyini
        self.pxini=pxini
        self.pyini=pyini
        self.radini=np.sqrt(qxini*qxini+qyini*qyini)
        #ArcoTangente con signo de numpy
        self.thetaini=np.arctan2(qyini,qxini)
        
        #variables dinamicas
        self.qx=qxini
        self.qy=qyini
        self.px=pxini
        self.py=pyini
        

        #Constantes de movimiento
        self.MomAng=self.qx*self.py-self.qy*self.px
        
        self.RungeLenz=np.array([self.py*self.MomAng-MasaSol*self.qx/self.radini,
                                 -self.px*self.MomAng-MasaSol*self.qy/self.radini])
    
        
    def radio(self):
        radio=np.sqrt(self.qx*self.qx+self.qy*self.qy)
        return radio

    def theta(self):
        theta=np.arctan2(qy,qx)
        return theta


        
def Hamiltoniana(Uno):
    Energia=((Uno.px)*(Uno.px)+(Uno.py*Uno.py))/2 - MasaSol/Uno.radio()
    return Energia



def Fuerza(Uno):
    r=Uno.radio()
    tam=MasaSol/(r*r*r)
    fuerza=np.array([-Uno.qx, -Uno.qy])*tam
    return fuerza




dt=0.005
tmax=35000

Orbitas=open("Orbitas.dat", "w")

MomentoInicial=0.3

Tierra=Planeta( 0.00, 10.0, MomentoInicial, 0.000)
print(Hamiltoniana(Tierra))
casos=30


for k in range(0, casos):

    anguloaux=-np.pi/7+2*np.pi*k/(7*casos)
    px=MomentoInicial*np.cos(anguloaux)
    py=MomentoInicial*np.sin(anguloaux)
    Tierra=Planeta( 0.00, 10.0, px, py)
    
    
    for t in range(0, tmax):
    
    
        Qpunto=dt*np.array([Tierra.px, Tierra.py])
    
        Tierra.qx+=Qpunto[0]
        Tierra.qy+=Qpunto[1] 

        Ppunto=Fuerza(Tierra)*dt
   # print(Ppunto)
    
        Tierra.px+=Ppunto[0]
        Tierra.py+=Ppunto[1]
    
        if(t%100==0):
            print(Tierra.qx, Tierra.qy, Hamiltoniana(Tierra), Tierra.pyini,
                  file=Orbitas)

    print("", file=Orbitas)


print(Hamiltoniana(Tierra))
    

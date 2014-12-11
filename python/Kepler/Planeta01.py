""" La clase Planeta """

from numpy import sqrt, arctan2, array

class Planeta:
    """Un planeta, con posicion y velocidad, masa=1"""
    def __init__(self, qxini,qyini,pxini,pyini):
        #Valores iniciales
        self.qxini=qxini
        self.qyini=qyini
        self.pxini=pxini
        self.pyini=pyini
        self.radini=sqrt(qxini*qxini+qyini*qyini)
        #ArcoTangente con signo de numpy
        self.thetaini=arctan2(qyini,qxini)
        
        #variables dinamicas
        self.qx=qxini
        self.qy=qyini
        self.px=pxini
        self.py=pyini
        

        #Constantes de movimiento
        self.MomAng=self.qx*self.py-self.qy*self.px

        #Esto no es propiedad de tu Planeta, es del sistema!
        #self.RungeLenz=array([self.py*self.MomAng-MasaSol*self.qx/self.radini,
         ##                        -self.px*self.MomAng-MasaSol*self.qy/self.radini])
    
        
    def radio(self):
        radio=sqrt(self.qx*self.qx+self.qy*self.qy)
        return radio

    def theta(self):
        theta=arctan2(self.qy,self.qx)
        return theta



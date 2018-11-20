
 coding: utf-8


import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm




### datos de las diferentes trayectorias:
trayectoria_10=np.loadtxt('10.txt',float,delimiter=',');
trayectoria_20=np.loadtxt('20.txt',float,delimiter=',');
trayectoria_30=np.loadtxt('30.txt',float,delimiter=',');
trayectoria_40=np.loadtxt('40.txt',float,delimiter=',');
trayectoria_50=np.loadtxt('50.txt',float,delimiter=',');
trayectoria_60=np.loadtxt('60.txt',float,delimiter=',');
trayectoria_70=np.loadtxt('70.txt',float,delimiter=',');
trayectoria_45=np.loadtxt('proyectil.txt',float,delimiter=',');




###graficamos las trayectorias del proyectil para los diferentes angulos:
plt.plot(trayectoria_10[:,1],trayectoria_10[:,2]);
plt.hold(True);
plt.plot(trayectoria_20[:,1],trayectoria_20[:,2]);
plt.hold(True);
plt.plot(trayectoria_30[:,1],trayectoria_30[:,2]);
plt.hold(True);
plt.plot(trayectoria_40[:,1],trayectoria_40[:,2]);
plt.hold(True);
plt.plot(trayectoria_50[:,1],trayectoria_50[:,2]);
plt.hold(True);
plt.plot(trayectoria_60[:,1],trayectoria_60[:,2]);
plt.hold(True);
plt.plot(trayectoria_70[:,1],trayectoria_70[:,2]);
plt.hold(True);
plt.plot(trayectoria_45[:,1],trayectoria_45[:,2]);
plt.hold(False);
plt.xlabel('posición x')
plt.ylabel('posición y')
plt.legend(('10°','20°','30°','40°','50°','60°','70°','45°'),loc='upper right')
plt.savefig('trayectorias.pdf',dpi=300)
plt.close()




## graficar problema de las diferencias finitas:
malla=np.loadtxt('malla.txt',float, delimiter=',');
caso1=np.loadtxt('solucion_primer_caso.txt',float,delimiter=',',usecols=range(36));
caso2=np.loadtxt('segundo_caso.txt',float,delimiter=',',usecols=range(36));
caso3=np.loadtxt('tercer_caso.txt',float,delimiter=',',usecols=range(36));
x=np.transpose(malla[:,1])
y=np.transpose(malla[:,2])




##graficas del caso 1:


T=caso1[0,:]
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('primer_caso_t_0.pdf')

fig.clear()
T=caso1[9999,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('primer_caso_t_t_final.pdf')

##estados intermedios:
fig.clear()
T=caso1[500,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('primer_caso_t_1500s.pdf')
fig.clear()

T=caso1[2000,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('primer_caso_t_6000s.pdf')

##Temperatura promedio de la placa en funcion del tiempo:
fig.clear()
T_promedio=np.zeros(10000)
for i in range(10000):
    T_promedio[i]=sum(caso1[i,:])/36
t=np.linspace(0,30000,num=10000)    
plt.plot(t,T_promedio)
plt.xlabel('tiempo')
plt.ylabel('Temperatura promedio')
plt.savefig('temperatura_promedio_primer_caso.pdf')



# el segundo caso:
#condicion inicial
T=caso2[0,:]
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('segundo_caso_t0.pdf')

##condicion final
fig.clear()
T=caso2[9999,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('segundo_caso_tt_final.pdf')
##condiciones intermedias
fig.clear()
T=caso2[500,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('segundo_caso_t15000.pdf')
fig.clear()
T=caso2[2000,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('segundo_caso_t30000.pdf')
##temperatura promedio
fig.clear()
T_promedio=np.zeros(10000)
for i in range(10000):
    T_promedio[i]=sum(caso2[i,:])/36
t=np.linspace(0,30000,num=10000)      
plt.plot(t,T_promedio)
plt.xlabel('tiempo')
plt.ylabel('Temperatura promedio')
plt.savefig('temperatura_promedio_segundo_caso.pdf')

#tercer caso:
#condicion inicial
T=caso3[0,:]
fig = plt.figure()
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('tercer_caso_t=0.pdf')
##condicion final
fig.clear()
T=caso2[9999,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('tercer_caso_t=t_final.pdf')
##condiciones intermedias
fig.clear()
T=caso2[500,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('tercer_caso_t=50000.pdf')
fig.clear()
T=caso2[2000,:]
ax = fig.gca(projection='3d')
ax.plot_trisurf(x, y, T, linewidth=0.2, antialiased=True,cmap=plt.cm.Spectral)
fig.savefig('tercer_caso_t=100000.pdf')
##temperatura promedio
fig.clear()
T_promedio=np.zeros(10000)
for i in range(10000):
    T_promedio[i]=sum(caso2[i,:])/36
t=np.linspace(0,30000,num=10000)  
plt.plot(t,T_promedio)
plt.xlabel('tiempo')
plt.ylabel('Temperatura promedio')
plt.savefig('temperatura_promedio_tercer_caso.pdf')


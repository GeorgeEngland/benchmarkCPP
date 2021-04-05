import cv2
import numpy as np
BWIM=np.average(np.array(cv2.imread('000001.png')),axis=2)
hist,bins=np.histogram(BWIM,[0,10,20,30,40,50,60,70,80,90,255])
print(hist,np.sum(hist))
center = int(BWIM.shape[0]/2)
np.savetxt('data_1152.csv',BWIM,delimiter=',',fmt='%d')
halfIM = BWIM[center-512:center+512,center-512:center+512]
np.savetxt('data_1024.csv',halfIM,delimiter=',',fmt='%d')
print(halfIM.shape)

halfIM = BWIM[center-256:center+256,center-256:center+256]
np.savetxt('data_512.csv',halfIM,delimiter=',',fmt='%d')
print(halfIM.shape)


halfIM = BWIM[center-128:center+128,center-128:center+128]
print(halfIM.shape)
np.savetxt('data_256.csv',halfIM,delimiter=',',fmt='%d')

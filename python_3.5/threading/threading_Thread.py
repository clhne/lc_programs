import threading
from time import *

loops = [4,2]

def loop(nloop,nsec):
    print("start loop :%s  at: %s\n" % (nloop, ctime()))
    sleep(nsec)
    print("loop %s done at: %s\n" % (nloop, ctime()))

def main():
    print("starting at: %s\n" %ctime())
    threads = []
    nloops = range(len(loops))
    for i in nloops:
        t = threading.Thread(target=loop,args=(i,loops[i]))
        threads.append(t)
    # start threads
    for i in nloops:
        threads[i].start()
##        threads[i].join()
    # wait for all threads to finish
    for i in nloops:
        threads[i].join()
    print("all done at: %s" %ctime())

if __name__=='__main__':
    main()

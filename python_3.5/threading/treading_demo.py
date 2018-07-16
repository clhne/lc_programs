import threading
import time
def music(func):
    for i in range(2):
        print('I was listening to music. %s. %s' %(func,time.ctime())) 
        time.sleep(4)

def move(func):
    for i in range(2):
        print('I was at the movies! %s! %s' %(func,time.ctime()))
        time.sleep(5)
threads = []
t1 = threading.Thread(target = music, args=(u'we are family',))
threads.append(t1)
t2 = threading.Thread(target = move, args=(u'Big Bang',))
threads.append(t2)
if __name__ == '__main__':
    '''music(u'we are family')
    move(u'Big Bang')
    '''
    for t in threads:
        t.setDaemon(True)
        t.start()
    t.join()
    print ('all over %s' %time.ctime()) 


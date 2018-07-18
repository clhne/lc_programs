import threading
import time

def run():
    time.sleep(2)
    print('Current thread name is: %s\n' % threading.current_thread().name)
    time.sleep(2)

if __name__ == '__main__':
    start_time = time.time()
    print('This is main Thread: %s\n' % threading.current_thread().name)
    thread_list = []
    for i in range(5):
        t = threading.Thread(target = run)
        thread_list.append(t)

    for t in thread_list:
        t.setDaemon(True)
        t.start()
        t.join()

    print('Main Thread end! %s\n' % threading.current_thread().name)
    print('Total time: %s\n' % (time.time() - start_time))
##    print('thread_list%s\n' %thread_list)

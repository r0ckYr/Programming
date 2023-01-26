#!/usr/bin/env python3
import os
import time
import sys
import socket

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.setblocking(1)
    s.bind(("0.0.0.0", 80))
    s.listen(5)
    conn = None
    add = None
    conn, addr = s.accept()
    print(str(addr)+" \n"+str(conn))
    data = conn.recv(100024).decode()
    time.sleep(1)
    print(data)
    filename = data.split()[1].replace('/', '')
    print(filename)
    data = data.split("  ")
    with open(filename, 'w') as f:
        for d in data:
            if d != '':
                f.write(d)
                f.write('\n')
        f.write('\n')


    conn.close()
    s.close()


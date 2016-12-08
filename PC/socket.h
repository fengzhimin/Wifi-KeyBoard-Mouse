#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
#include <sys/wait.h> 
#include <sys/time.h>

/*************************
 *function: 开启网络监听
 *return: -1 = 失败  >0 = socketfd
 *para：server_addr:socket地址结构体
	_port:开启监听的端口号
**************************/
int startService(struct sockaddr_in *server_addr, int _port);

#endif

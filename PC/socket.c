#include "socket.h"
#include "config.h"

int startService(struct sockaddr_in *server_addr, int _port)
{
	int socketfd;
	int err;
	/*****************socket()***************/  
	socketfd = socket(AF_INET,SOCK_STREAM,0); //建立一个序列化的，可靠的，双向连接的的字节流  
	if(socketfd < 0)  
	{  
		perror("server socket create error: ");  
		return -1;  
	}  


	/******************bind()****************/  
	//初始化地址结构  
	memset(server_addr,0,sizeof(*server_addr));  
	server_addr->sin_family = AF_INET;           //协议族  
	server_addr->sin_addr.s_addr = htonl(INADDR_ANY);   //本地地址  
	server_addr->sin_port = htons(_port);  

	err = bind(socketfd, (const struct sockaddr *)server_addr, sizeof(struct sockaddr));  
	if(err < 0)  
	{  
		perror("bind error: ");
		return -1;  
	}  

	/*****************listen()***************/  
	err = listen(socketfd,BACKLOG);   //设置监听的队列大小  
	if(err < 0)  
	{  
		perror("listen error: ");  
		return -1;  
	}  
	
	return socketfd;
}

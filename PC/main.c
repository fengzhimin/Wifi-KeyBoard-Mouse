#include "module.h"
#include "config.h"
#include "socket.h"
  
void process_conn_mouse_server(int s);   
void process_conn_keyBoard_server(int s);
  
int ss_mouse,sc_mouse;  
int ss_keyboard,sc_keyboard; 

int strToNum(char *_ch)
{
	int _ret = 0;
	int _symbol = 1;
	char* _pstr = _ch;
	if(_ch[0] == '-')
	{
		_symbol = -1;
		_pstr = ++_ch;
	}
	int _length = strlen(_pstr);
	for(int i = 0; i < _length; i++)
	{
		if(i)
			_ret *= 10;
		_ret += (_pstr[i] - '0');
	}

	return _ret*_symbol;
}

int main(int argc,char *argv[])  
{  
	struct sockaddr_in server_addr_mouse, server_addr_keyboard; //存储服务器端socket地址结构  
	struct sockaddr_in client_addr_mouse, client_addr_keyboard; //存储客户端 socket地址结构   
	pid_t pid;  //分叉进行的ID  

	/*****************socket()***************/  
	ss_mouse = startService(&server_addr_mouse, MOUSE_PORT);
	ss_keyboard = startService(&server_addr_keyboard, KEYBOARD_PORT);
	pid = fork();
	if(pid == 0)
	{
		if(ss_mouse != -1)
	  	{
			for(;;)  
			{  
				socklen_t addrlen = sizeof(client_addr_mouse);  
				//accept返回客户端套接字描述符  
				sc_mouse = accept(ss_mouse,(struct sockaddr *)&client_addr_mouse,&addrlen);  //注，此处为了获取返回值使用 指针做参数  
				if(sc_mouse < 0)  //出错  
				{  
				    continue;   //结束此次循环  
				}  
				else  
				{  
				    printf("mouse server : connected\n");  
				}  

				//创建一个子线程，用于与客户端通信  
				pid_t pid_mouse = fork();  
				//fork 调用说明：子进程返回 0 ；父进程返回子进程 ID  
				if(pid_mouse == 0)        //子进程，与客户端通信  
				{  
				    close(ss_mouse);  
				    process_conn_mouse_server(sc_mouse);  
				}  
				else  
				{  
				    close(sc_mouse);  
				}  
			} 
		} 
		else
			printf("open mouse failure!\n");
	}
	else
	{
		if(ss_keyboard != -1)
	  	{
			for(;;)  
			{  
				socklen_t addrlen = sizeof(client_addr_keyboard);  
				//accept返回客户端套接字描述符  
				sc_keyboard = accept(ss_keyboard,(struct sockaddr *)&client_addr_keyboard,&addrlen);  //注，此处为了获取返回值使用 指针做参数  
				if(sc_keyboard < 0)  //出错  
				{  
				    continue;   //结束此次循环  
				}  
				else  
				{  
				    printf("keyBoard server : connected\n");  
				}  

				//创建一个子线程，用于与客户端通信  
				pid_t pid_keyBoard = fork();  
				//fork 调用说明：子进程返回 0 ；父进程返回子进程 ID  
				if(pid_keyBoard == 0)        //子进程，与客户端通信  
				{  
				    close(ss_keyboard);  
				    process_conn_keyBoard_server(sc_keyboard);  
				}  
				else  
				{  
				    close(sc_keyboard);  
				}  
			} 
		} 
		else
			printf("open keyBoard failure!\n");
	}
}  


//通过套接字 s 与客户端进行通信  
void process_conn_mouse_server(int s)  
{  
	ssize_t size = 0;  
	char buffer[BUFSIZE];  //定义数据缓冲区  
	int fd_mouse; 
	fd_mouse = open(MOUSE_EVENT,O_RDWR); 
	if(fd_mouse<=0){
		printf("error open mouse\n");
		close(s);
		return ;
	}
	for(;;)  
	{  
		memset(buffer, 0, sizeof(buffer));
		//等待读
		int temp = 0;
		char _ch = '0';
		while(_ch != ' ')
		{
			size = recv(s,&_ch,1,0);  
			if(size < 0)
			{
				temp = -1;
				break;
			}
			if(_ch == ' ')
				continue;
			//a = left down   b = left up    c = right down    d = right up
			switch(_ch)
			{
			case 'a':
				simulate(fd_mouse, BTN_LEFT, 1);
				break;
			case 'b':
				simulate(fd_mouse, BTN_LEFT, 0);
				break;
			case 'c':
				simulate(fd_mouse, BTN_RIGHT, 1);
				break;
			case 'd':
				simulate(fd_mouse, BTN_RIGHT, 0);
				break;
			}
			if(_ch < 'a' || _ch > 'd')
				buffer[temp++] = _ch;
		}
		if(temp == -1)
			break;
		char _chx[10], _chy[10];
		memset(_chx, 0, sizeof(_chx));
		memset(_chy, 0, sizeof(_chy));
		temp = 0;
		int _point_y = 0;
		for(int i = 0; i < strlen(buffer); i++)
		{
			if(buffer[i] == ',')
			{
				temp = 1;
				continue;
			}
			if(temp)
			{
				_chy[_point_y++] = buffer[i];
			}
			else
				_chx[i] = buffer[i];
		}
		int x = strToNum(_chx);
		int y = strToNum(_chy);
		//输出从客户端接收到的数据  
		//printf("%s\n", buffer);
		//printf("%s\t%s\n", _chx, _chy);
		//printf("%d\t%d\n", x, y);
		//fflush(stdout);

		simulate_mouse(fd_mouse, x, y);
	}  
	close(fd_mouse);
	close(s);
}  

//通过套接字 s 与客户端进行通信  
void process_conn_keyBoard_server(int s)  
{  
	ssize_t size = 0;  
	char buffer[BUFSIZE];  //定义数据缓冲区  
	int fd_keyBoard; 
	fd_keyBoard = open(KEYBOARD_EVNET,O_RDWR); 
	if(fd_keyBoard <= 0){
		printf("error open keyBoard\n");
		close(s);
		return ;
	}
	for(;;)  
	{ 
		memset(buffer, 0, sizeof(buffer));
		//等待读
		int temp = 0; 
		char _ch = '0';
		while(_ch != ' ')
		{
			size = recv(s,&_ch,1,0);  
			if(size < 0)
			{
				temp = -1;
				break;
			}
			if(_ch == ' ')
				continue;
			switch(_ch)
			{
			case 'f':
				simulate_NoSyn(fd_keyBoard, KEY_LEFTSHIFT, 1);
				break;
			case 'g':
				simulate_NoSyn(fd_keyBoard, KEY_RIGHTSHIFT, 1);
				break;
			case 'h':
				simulate_NoSyn(fd_keyBoard, KEY_LEFTCTRL, 1);
				break;
			case 'i':
				simulate_NoSyn(fd_keyBoard, KEY_RIGHTCTRL, 1);
				break;
			case 'j':
				simulate_NoSyn(fd_keyBoard, KEY_KPASTERISK, 1);
				break;
			case 'k':
				simulate_NoSyn(fd_keyBoard, KEY_KPASTERISK, 1);
				break;
			case 'l':
				simulate_NoSyn(fd_keyBoard, KEY_LEFTALT, 1);
				break;
			case 'm':
				simulate_NoSyn(fd_keyBoard, KEY_RIGHTALT, 1);
				break;
			}
			if(_ch < 'f' || _ch > 'm')
				buffer[temp++] = _ch;
		}
		if(temp == -1)
			break;
		int code = strToNum(buffer);

		simulate_keyBoard(fd_keyBoard, code);
	}  
	close(fd_keyBoard);
	close(s);
}  

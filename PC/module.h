#ifndef __MODULE_H__
#define __MODULE_H__

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <stdio.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <string.h>  

#define BTN_LEFT		0x110   //鼠标左键
#define BTN_RIGHT		0x111   //鼠标右键

#define KEY_CAPSLOCK		58      //大小写开关
#define KEY_LEFTSHIFT		42
#define KEY_RIGHTSHIFT		54
#define KEY_LEFTCTRL		29
#define KEY_RIGHTCTRL		97
#define KEY_KPASTERISK		55
#define KEY_LEFTALT		56
#define KEY_RIGHTALT		100


/*************************
 *function: 模拟鼠标
 *para：fd:打开鼠标的fd
	x:移动x大小
	y:移动y大小
**************************/
void simulate_mouse(int fd, int x, int y);

/*************************
 *function: 按键模拟
 *para: fd：打开输入设备的fd
		code: 键盘编码 
		value： 1 = 按下   0 = 弹起
**************************/
void simulate(int fd, int code, int value);


/*************************
 *function: 按键模拟不马上同步
 *para: fd：打开输入设备的fd
		code: 键盘编码 
		value： 1 = 按下   0 = 弹起
**************************/
void simulate_NoSyn(int fd, int code, int value);


/*************************
 *function: 模拟键盘
 *para：fd:打开键盘的fd
	code：键盘编码
**************************/
void simulate_keyBoard(int fd, int code);

#endif

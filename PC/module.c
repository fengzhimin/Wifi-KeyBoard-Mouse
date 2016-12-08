#include "module.h"

void simulate_mouse(int fd, int x, int y)
{
	struct input_event event;
	memset(&event, 0, sizeof(event));
	gettimeofday(&event.time, NULL);
	event.type = EV_REL;
	event.code = REL_X;
	event.value = x;
	write(fd, &event, sizeof(event));

	event.type = EV_REL;
	event.code = REL_Y;
	event.value = y ;
	write(fd, &event, sizeof(event));

	event.type = EV_SYN;
	event.code = SYN_REPORT;
	event.value = 0;
	write(fd, &event, sizeof(event));
}

void simulate(int fd, int code, int value)
{
	struct input_event event;
	memset(&event, 0, sizeof(event));
	gettimeofday(&event.time, NULL);
	event.type = EV_KEY;
	event.code = code;
	event.value = value;
	write(fd, &event, sizeof(event));
	event.type = EV_SYN;
	event.code = SYN_REPORT;
	event.value = 0;
	write(fd, &event, sizeof(event));
}

void simulate_NoSyn(int fd, int code, int value)
{
	struct input_event event;
	memset(&event, 0, sizeof(event));
	gettimeofday(&event.time, NULL);
	event.type = EV_KEY;
	event.code = code;
	event.value = value;
	write(fd, &event, sizeof(event));
}

void simulate_keyBoard(int fd, int code)
{
	simulate(fd, code, 1);    //按下
	simulate(fd, code, 0);    //弹起
}

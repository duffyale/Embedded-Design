#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

class WiimoteBtns{
	private:
	int fd;
	int code;
	int value;
	public:
	WiimoteBtns();
	~WiimoteBtns();
	void Listen();
	void ButtonEvent(int code, int value);
};

#endif

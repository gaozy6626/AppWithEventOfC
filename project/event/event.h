#ifndef _EVENT_H
#define _EVENT_H

enum app_event
{
	EVENT_OF_ONE = 0,
	EVENT_OF_TWO,
	EVENT_OF_THREE,
	EVENT_OF_FOUR,
	EVENT_OF_FIVE,
	
	EVENT_OF_ONE_STATUS = 50,
	EVENT_OF_TWO_STATUS,
	EVENT_OF_THREE_STATUS,
	EVENT_OF_FOUR_STATUS,
	EVENT_OF_FIVE_STATUS,
};

typedef struct event
{
	int name;
	void (*callback)(void *ptr, void *data);
}event_t;

event_t * create();

#endif //_EVENT_H
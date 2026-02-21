#include <czmq.h>

int main(void)
{
	zsock_t* responder = zsock_new(ZMQ_REP);
	int r = zsock_bind(responder, "tcp://*:5555");
	if (r != 5555) {
		printf("Failed to connect to port\n");
	}
	while (true) {
		char* msg = zstr_recv(responder);
		if (!strcmp(msg, "low level")) {
			zstr_send(responder, "Gang");
		}
		free(msg);
	}
	zsock_destroy(&responder);
	return 0;
}
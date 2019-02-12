#include "network.h"
int read_stream(int conn_fd, uint8_t *buf, int len) {
	int ptr;
	int retval;
	int read_bytes;
	int remaining_bytes;
	
	ptr = 0;
	remaining_bytes = len;
	if (conn_fd < 0 || len <= 0) {
		return -1;
	}
	while(1) {
		read_bytes = read(conn_fd, buf + ptr, remaining_bytes);
		if (read_bytes <= 0) {
			retval = read_bytes;
			break;
		}
		ptr += read_bytes;
		remaining_bytes -= read_bytes;
		if (remaining_bytes == 0) {
			retval = len;
			break;
		}
	}
	return retval;
}

int write_stream(int conn_fd, uint8_t *buf, int len) {
	int ptr;
	int retval;
	int written_bytes;
	int remaining_bytes;

	ptr = 0;
	remaining_bytes = len;
	if (conn_fd < 0 || len <= 0) {
		return -1;
	}	
	while (1) {
		written_bytes = write(conn_fd, buf + ptr, remaining_bytes);
		if (written_bytes <= 0) {
			retval = written_bytes;
			break;
		}
		ptr += written_bytes;
		remaining_bytes -= written_bytes;
		if (remaining_bytes == 0) {
			retval = len;
			break;
		}
	}
	return retval;
}
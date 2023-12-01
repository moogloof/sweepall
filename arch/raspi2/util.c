void memzero(char* start, char* end) {
	for (char* c = start; c < end; c++) {
		*c = 0;
	}
}

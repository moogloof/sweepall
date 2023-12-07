#include <image.h>

// Preprocess image
void preprocess_image(bmp_header* image) {
	int* image_buffer = (int*)((unsigned int)image + image->offset);
	// Do stuff
	// Reverse the buffer bytewise by row and per pixel
	unsigned int pitch = image->bits_per_pixel * image->width / 32;
	int i2 = image->height - 1;
	for (int i1 = 0; i1 < image->height / 2; i1++) {
		for (unsigned int j = 0; j < pitch; j++) {
			int temp = image_buffer[pitch*i1 + j];
			image_buffer[pitch*i1 + j] = image_buffer[pitch*i2 + j];
			image_buffer[pitch*i2 + j] = temp;
		}
		i2--;
	}
}

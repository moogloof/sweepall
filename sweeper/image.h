#ifndef IMAGE_H
#define IMAGE_H

// BMP image
typedef struct {
	unsigned short type; // Must be 0x4d42
	unsigned int size; // Bytes size
	unsigned int reserved;
	unsigned int offset; // Offset to image data in bytes
	unsigned int dib_header_size; // DIB Header size
	int width; // Width of image in pixels
	int height; // Height of image in pixels
	unsigned short num_planes; // Number of color planes
	unsigned short bits_per_pixel; // Bits per pixel, should be 24
	unsigned int compression; // Compression type
	unsigned int image_size_bytes; // Size of image in bytes
	int x_resolution_ppm; // Pixels per meter
	int y_resolution_ppm;
	unsigned int num_colors; // Number of colors
	unsigned int important_colors; // Important colors
} __attribute__((packed)) bmp_header;

// Preprocess BMP image to be drawable
void preprocess_image(bmp_header*);

#endif

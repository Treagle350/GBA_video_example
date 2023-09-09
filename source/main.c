#include "palette_vid.h"
#include <unistd.h>

int main(void)
{
	// Write into the I/O registers, setting video display parameters.
	volatile unsigned char *ioram = (unsigned char *)0x04000000;
	ioram[0] = 0x03; // Use video mode 3 (in BG2, a 16bpp bitmap in VRAM)
	ioram[1] = 0x04; // Enable BG2 (BG0 = 1, BG1 = 2, BG2 = 4, ...)

	int x_gba_screen_limit = 240;
	int y_gba_screen_limit = 160;
	volatile unsigned short *vram = (unsigned short *)0x06000000;

	while(1){
		for(int j=0; j<(out000000001_entries); j++){
			for(int i=0; i<(y_gba_screen_limit*x_gba_screen_limit); i++){
				vram[i] = out000000001_data[j][i];
			}
			sleep(1);//Nada 
			//Doesn't seem to be doing anything but don't feel like having the refresh rate decided by the
			//limits of the computational power of the gba
		}
	}
	return 0;
}

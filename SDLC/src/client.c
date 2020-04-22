#include <stdio.h>
#include "display.h"

int main(int argc, char **argv) {
	//Nifty trick to getting pointers to structs w/o malloc
	Display display,*dp;
	dp = &display;

	hollow_display(&dp);
	init_display("Display Wrapper",640,480,&dp,TRUE);

	/* Game Loop Staples */
	update_display(&dp);
	delay_display(2000);
	/********************/

	close_display(&dp);
	
	printf("Display Dimensions: %d x %d\n",get_width(&dp),get_height(&dp));
	printf("Display Caption: %s\n",get_caption(&dp));
	free(dp->caption);

	return 0;
}

#include <stdio.h>

int main(){
	float um, dois, tres, a, b, c;
	scanf("%f %f %f", &um, &dois, &tres);
	if(um <= dois && um <= tres){
		if(dois <= tres){
			a = tres;
			b = dois;
			c = um;
		} else {
			a = dois;
			b = tres;
			c = um;
		}
	} else {
		if(dois <= um && dois <= tres){
			if(um <= tres){
				a = tres;
				b = um;
				c = dois;
			} else {
				a = um;
				b = tres;
				c = dois;
			}
		} else {
			if(um <= dois){
				a = dois;
				b = um;
				c = tres;
			} else {
				a = um;
				b = dois;
				c = tres;
			}
		}
	}
	printf("%.2f, %.2f, %.2f", c, b, a);
	return 0;
}
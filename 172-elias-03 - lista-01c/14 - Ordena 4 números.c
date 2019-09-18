#include <stdio.h>

int main(){
	float um, dois, tres, quatro, a, b, c, d;
	scanf("%f %f %f %f", &um, &dois, &tres, &quatro);
	if(um <= dois && um <= tres && um <= quatro){
		//1xxx
		if(dois <= tres && dois <= quatro){
			//12xx
			if(tres <= quatro){
				//1234
				a = quatro;
				b = tres;
				c = dois;
				d = um;
			} else {
				//1243
				a = tres;
				b = quatro;
				c = dois;
				d = um;
			}
		} else {
			//1xxx
			if(tres <= dois && tres <= quatro){
				//13xx
				if(dois <= quatro){
					//1324
					a = quatro;
					b = dois;
					c = tres;
					d = um;
				} else {
					//1342
					a = dois;
					b = quatro;
					c = tres;
					d = um;
				}
			} else {
				//14xx
				if(dois <= tres){
					//1423
					a = tres;
					b = dois;
					c = quatro;
					d = um;
				} else {
					//1432
					a = dois;
					b = tres;
					c = quatro;
					d = um;
				}
			}
		}
	} else {
		//xxxx
		if(dois <= um && dois <= tres && dois <= quatro){
			//2xxx
			if(um <= tres && um <= quatro){
				//21xx
				if(tres <= quatro){
					//2134
					a = quatro;
					b = tres;
					c = um;
					d = dois;
				} else {
					//2143
					a = tres;
					b = quatro;
					c = um;
					d = dois;
				}
			} else {
				if(tres <= um && tres <= quatro){
					//23xx
					if(um <= quatro){
						//2314
						a = quatro;
						b = um;
						c = tres;
						d = dois;
					} else {
						//2341
						a = um;
						b = quatro;
						c = tres;
						d = dois;
					}
				} else {
					//24xx
					if(um <= tres){
						//2413
						a = tres;
						b = um;
						c = quatro;
						d = dois;
					} else {
						//2431
						a = um;
						b = tres;
						c = quatro;
						d = dois;
					}
				}
			}
		} else {
			//xxxx
			if(tres <= um && tres <= dois && tres <= quatro){
				//3xxx
				if(um <= dois && um <= quatro){
					//31xx
					if(dois <= quatro){
						//3124
						a = quatro;
						b = dois;
						c = um;
						d = tres;
					} else {
						//3142
						a = dois;
						b = quatro;
						c = um;
						d = tres;
					}
				} else {
					//3xxx
					if(dois <= um && dois <= quatro){
						//32xx
						if(um <= quatro){
							//3214
							a = quatro;
							b = um;
							c = dois;
							d = tres;
						} else {
							//3241
							a = um;
							b = quatro;
							c = dois;
							d = tres;
						}
					} else {
						//34xx
						if(um <= dois){
							//3412
							a = dois;
							b = um;
							c = quatro;
							d = tres;
						} else {
							//3421
							a = um;
							b = dois;
							c = quatro;
							d = tres;
						}
					}
				}
			} else {
				//4xxx
				if(um <= dois && um <= tres){
					//41xx
					if(dois <= tres){
						//4123
						a = tres;
						b = dois;
						c = um;
						d = quatro;
					} else {
						//4132
						a = dois;
						b = tres;
						c = um;
						d = quatro;
					}
				} else {
					//4xxx
					if(dois <= um && dois <= tres){
						//42xx
						if(um <= tres){
							//4213
							a = tres;
							b = um;
							c = dois;
							d = quatro;
						} else {
							//4231
							a = um;
							b = tres;
							c = dois;
							d = quatro;
						}
					} else {
						//4xxx
						if(tres <= um && tres <= dois){
							//43xx
							if(um <= dois){
								//4312
								a = dois;
								b = um;
								c = tres;
								d = quatro;
							} else {
								//4321
								a = um;
								b = dois;
								c = tres;
								d = quatro;
								//finalmente!
							}
						}
					}
				}
			}
		}
	}
	printf("%.2f, %.2f, %.2f, %.2f", d, c, b, a);
	return 0;
}
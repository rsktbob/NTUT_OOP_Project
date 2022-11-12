#ifndef COOKIE_H
#define COOKIE_H

double max_dv(int n, int* array) {
	if(n < 0) {
		return -1;
	}
	for(int i = 0; i < n; i++){
		int dv = array[i];
		if(dv < 0 || dv > 100){
			return -1;
		}
	}
	int to = 0;
    for(int i = 0; i < n; i = i+2) {
        to = to+array[i];
    }
	int te = 0;
    for(int i = 1; i < n; i = i+2) {
        te = te+array[i];
    }
	return to >= te ? to : te;
}

#endif

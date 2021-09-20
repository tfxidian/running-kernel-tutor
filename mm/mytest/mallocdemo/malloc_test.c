#include<assert.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void *malloc2(size_t size){
	void *p = sbrk(0);
	void *request = sbrk(size);
	if(request == (void*)-1){
		return NULL;
	}else{
		assert(p ==request);
		return p;
	}
}

int main(){

	int *p = (int *)malloc2(4);
	*p = 10;
       	printf("addr: %p\nvalue:  %d \n", p, *p);
		
	return 0;
}	


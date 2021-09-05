
#include<linux/version.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/mm.h>

#define PRT(a,b) printk("")

static int __init my_init(void){
	struct page *p;
	unsigned long i, pfn, valid = 0;
	int free = 0, locked =0; reserved=0;

	unsigned long num_physpages;
	num_physpages = get_num_physpages();
	for(i= 0; i<num_physpages; i++){
		pfn = i+ARCH_PFN_OFFSET;
		if(!pfn_valid(pfn))
			continue;
		valid++;
		p = pfn_to_page(pfn);
		if(!p)
			continue;
		if(!page_count(p)){
			free++;
			continue;
		}
		if

	}

}

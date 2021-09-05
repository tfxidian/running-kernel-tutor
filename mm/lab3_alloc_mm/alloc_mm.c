#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/vmalloc.h>

static int mem = 64;

#define MB (1024*1024)

static int __init my_init(void)
{	
	pr_info("PAGE_SIZE: %ld", PAGE_SIZE);
	char *kbuf = (char *)__get_free_page(GFP_ATOMIC);
	unsigned long addr = __get_free_page(GFP_ATOMIC); 
	if(!kbuf){
		pr_info(" __get_free_page failed\n");
		return 0;
	}	
	pr_info("addr: 0x%lx\n", addr);
	pr_info(" __get_free_page start address 0x%lx!\n",(unsigned long)kbuf);
	free_page((unsigned long)kbuf);
	free_page(addr);


	char *buf2 = kmalloc((size_t)PAGE_SIZE, GFP_ATOMIC);
	if(!buf2){
		pr_info("kmalloc failed\n");
	}
	pr_info(" kmalloc start addess 0x%lx\n", (unsigned long)buf2);
	kfree(buf2);
	
	char *buf3 = kmalloc((size_t)32, GFP_ATOMIC);
	if(!buf3){
		pr_info("kmalloc failed\n");
	}
	pr_info(" kmalloc start addess 0x%lx\n", (unsigned long)buf3);
	kfree(buf3);

	char *vm_buf = vmalloc(PAGE_SIZE);
	if(!vm_buf){
		pr_info("vmalloc failed...\n");
		return 0;
	}

	pr_info("vmalloc start addres 0x%lx\n", (unsigned long)vm_buf);




	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Module exit\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ben ShuShu");
MODULE_LICENSE("GPL v2");

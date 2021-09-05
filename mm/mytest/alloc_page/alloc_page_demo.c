
#include<linux/init.h>
#include<linux/module.h>
#include<linux/gfp.h>
#include<linux/mm_types.h>
#include<linux/mm.h>


static page *pages = NULL;

static int __init alloc_pages_init(void){
	pages = alloc_pages(GFP_KERNEL,0);
	if(!pages){
		return -ENOMEM;
	}
	else{
		printk("alloc page successfully!\n");
		printk("page num is 0x%lx ", pages);
	}
	return 0;
}

static void __exit alloc_pages_exit(void)

{

       if(pages)

       {

              __free_pages(pages,0);   //释放所分配的8个页

              printk("<0>__free_pages ok!\n");

       }

       printk("<0>exit\n");

}

MODULE_LICENSE("GPL");
module_init(alloc_pages_init);

module_exit(alloc_pages_exit);

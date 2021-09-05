#include <linux/module.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/init.h>

static char *kbuf;
static int size = 21*PAGE_SIZE;
struct kmem_cache *my_cache;
module_param(size, int, 0644);

static int __init my_init(void)
{
	my_cache = kmem_cache_create("mycache", size, 0, SLAB_HWCACHE_ALIGN,NULL);
	if(!my_cache){
		pr_info("kmem_cache_create failed.\n");
		return 0;
	}
	pr_info("kmem_cache_create ok\n");
	kbuf = kmem_cache_alloc(my_cache, GFP_ATOMIC);
	if(!kbuf){
		pr_info("kmem_cache_alloc failed\n");
		return 0;
	}
	pr_info("kmem_cache_alloc ok \n");
	//pr_info("object size: %u\n", my_cache->object_size);
	//pr_info("size %d\n", my_cache->size);	
	kmem_cache_free(my_cache, kbuf);
	kmem_cache_destroy(my_cache);
	pr_info("destroyed my_cache\n");
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("destroyed mycache\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Ben ShuShu");

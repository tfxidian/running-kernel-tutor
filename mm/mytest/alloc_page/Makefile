
# modify right kernel PATH for your system
BASEINCLUDE ?= /home/rlk/rlk_basic/runninglinuxkernel_4.0
#BASEINCLUDE ?= /lib/modules/`uname -r`/build
obj-m	:=  alloc_page_demo.o
all :
	$(MAKE) -C $(BASEINCLUDE) M=$(PWD) modules;

clean:
	$(MAKE) -C $(BASEINCLUDE) SUBDIRS=$(PWD) clean;
	rm -f *.ko;



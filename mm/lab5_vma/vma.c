#include <linux/module.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/sched.h>

static int pid;
module_param(pid, int, 0644);

static void printit(struct task_struct *tsk)
{
	struct mm_struct *mm;
	struct vm_area_struct *vma;
	mm = tsk->mm;
	pr_info("mm = %p\n", mm);
	vma = mm->mmap;
	unsigned long start, end, length;
	while(vma){
		start = vma->vm_start;
		end = vma->vm_end;
		length = end -start;
		pr_info("vma: %p, start: %x, end: %x, length: %ld\n", vma, start, end, length);
		vma = vma->vm_next;
	}

	pr_info("printit...\n");
}

static int __init my_init(void)
{
	struct task_struct *tsk;
	if(pid ==0){
		tsk = current;   //get current process task
		pid = current->pid;
	}else{
		tsk = pid_task(find_vpid(pid), PIDTYPE_PID);//get input pid task
	}
	if(!tsk) return -1;
	pr_info("tsk pid: %d, command :%s", pid, tsk->comm);
	printit(tsk);
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Module exit\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL v2");

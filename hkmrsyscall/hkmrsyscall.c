#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
extern int hkmr;

//HKMR
///
// syscall no.
//
// 359     i386    hkmrsyscall             sys_hkmr
//

extern struct console *console_drivers;

//#define TASK_RUNNING     0
//#define TASK_INTERRUPTIBLE  1
//#define TASK_UNINTERRUPTIBLE   2
//#define __TASK_STOPPED      4
//#define __TASK_TRACED    8
//#define EXIT_DEAD     16
//#define EXIT_ZOMBIE      32
//#define EXIT_TRACE    (EXIT_ZOMBIE | EXIT_DEAD)
/* in tsk->state again */
//#define TASK_DEAD     64
//#define TASK_WAKEKILL    128
//#define TASK_WAKING      256
//#define TASK_PARKED      512
//#define TASK_NOLOAD      1024
//#define TASK_STATE_MAX      2048

//#define TASK_STATE_TO_CHAR_STR "RSDTtXZxKWPN"

/* Convenience macros for the sake of set_task_state */
//#define TASK_KILLABLE    (TASK_WAKEKILL | TASK_UNINTERRUPTIBLE)
//#define TASK_STOPPED     (TASK_WAKEKILL | __TASK_STOPPED)
//#define TASK_TRACED      (TASK_WAKEKILL | __TASK_TRACED)

//#define TASK_IDLE     (TASK_UNINTERRUPTIBLE | TASK_NOLOAD)

/* Convenience macros for the sake of wake_up */
//#define TASK_NORMAL      (TASK_INTERRUPTIBLE | TASK_UNINTERRUPTIBLE)
//#define TASK_ALL      (TASK_NORMAL | __TASK_STOPPED | __TASK_TRACED)

/* get_task_state() */
//#define TASK_REPORT      (TASK_RUNNING | TASK_INTERRUPTIBLE | \
             TASK_UNINTERRUPTIBLE | __TASK_STOPPED | \
             __TASK_TRACED | EXIT_ZOMBIE | EXIT_DEAD)



asmlinkage long sys_hkmr(int k){  // HKMR'S OWN SYS CALL

	struct task_struct *task;

	hkmr=k;	

	//printk("\n<all tasks>\n");
	for_each_process(task){
		if(k==task->pid){
			printk("comm=%s,pid=%d,state=%ld,on_rq=%d", task->comm, task->pid, task->state, task->on_rq);
			switch(task->state){
				case TASK_RUNNING: 			printk("RUNNING"); 			break;
				case TASK_INTERRUPTIBLE: 	printk("INTERRUPTIBLE");	break;
				case TASK_STOPPED: 			printk("STOPPED");			break;
			}
			printk("\n");
		}
	}


	//printk("\n<current task>\n");
	//struct  task_struct *this = current;
	//printk("(%s[%d])", this->comm, this->pid);
	
	
	return 0;
}

#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <thread>
#include <chrono>
#include "Matrix.h"
#include "MatrixThreadData.h"
#include "ThreadQueue.h"
#include "MatrixMultiplication.h"

class Worker {
public:
	Worker ( int id, ThreadQueue* queue );
	virtual ~Worker();

	/**
 	 * Worker method, receive tasks from queue task 
 	 * and execute simple linear combination 
 	 * and write result to final matrix.
	 */
	void do_job ();
	
	/**
 	 * Called when executor stop generate tasks
 	 */ 
	void stop_task_generation();


private:
	const int m_id;
	ThreadQueue* m_queue;

	int are_task_generated;
};

#endif
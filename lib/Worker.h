#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <thread>
#include <chrono>
#include "Matrix.h"
#include "MatrixThreadData.h"
#include "ThreadQueue.h"

class Worker {
public:
	Worker ( int id, ThreadQueue* queue );
	virtual ~Worker();

	void do_job ();
	void stop();


private:
	ThreadQueue* m_queue;

	const int m_id;
	int is_running;
};

#endif
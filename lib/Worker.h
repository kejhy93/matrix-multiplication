#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <thread>
#include <chrono>
#include <queue>
#include "Matrix.h"
#include "MatrixThreadData.h"

class Worker {
public:
	Worker ( int id, std::queue<MatrixThreadData*>& queue );
	virtual ~Worker();

	void do_job ();
	void stop();


private:
	std::queue<MatrixThreadData*>& m_queue;

	const int m_id;
	int is_running;
};

#endif
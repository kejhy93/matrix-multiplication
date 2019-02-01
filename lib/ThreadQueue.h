#ifndef __THREAD_QUEUE_H__
#define __THREAD_QUEUE_H__

#include <iostream>
#include <queue>
#include <mutex>

#include "MatrixThreadData.h"

class ThreadQueue {
public:
	ThreadQueue();
	virtual ~ThreadQueue();

	void push ( MatrixThreadData* data);
	MatrixThreadData* pop();

	bool is_empty();
	int size();

private:
	std::queue<MatrixThreadData*> m_queue;
	std::mutex m_queue_mutex;
};

#endif
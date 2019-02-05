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

	/**
 	 * Push new task to queue thread.
 	 * Thread-safe as possible.
 	 */
	void push ( MatrixThreadData* data);

	/**
 	 * Pop task from queue task.
 	 * Thread-safe as possible.
 	 */
	MatrixThreadData* pop();

	/**
 	 * Pop task from queue task.
 	 * Thread-safe as possible.
 	 */
	bool is_empty();
	/**
 	 * Check if queue task is empty.
 	 */
	int size();

private:
	std::queue<MatrixThreadData*> m_queue;
	std::mutex m_queue_mutex;
};

#endif
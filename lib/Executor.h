#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__

#include <list>
#include "Worker.h"
#include "MatrixThreadData.h"
#include "ThreadQueue.h"
#include "Matrix.h"

class Executor {
public:
	Executor ( int number_of_workers);
	virtual ~Executor();

	/**
	 * Generate task and inserted into queue task
	 */
	void execute ( const Matrix& left, const Matrix& right, Matrix& result);

private:
	Worker** workers;
	std::thread** threads;

	const int m_number_of_workers;

	ThreadQueue* queue_of_tasks;
};

#endif
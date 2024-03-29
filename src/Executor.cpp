#include "Executor.h"

Executor::Executor ( int number_of_workers) : m_number_of_workers(number_of_workers) {
	// Create threads
	threads = new std::thread*[m_number_of_workers];
	// Create workers
	workers = new Worker*[m_number_of_workers];
	// Initiate queue task
	queue_of_tasks = new ThreadQueue();

	for ( int index = 0 ; index < m_number_of_workers ; ++ index ) {
		workers[index] = new Worker(queue_of_tasks);
		// start worker thread 
		threads[index] = new std::thread(&Worker::do_job, workers[index] );
	}
}

Executor::~Executor() {
	for ( int index = 0 ; index < m_number_of_workers ; ++ index) {
		threads[index]->join();
		delete threads[index];
		delete workers[index];
	}
	delete queue_of_tasks;
	delete[] threads;
	delete[] workers;
}

/**
 * Generate task and inserted into queue task
 */
void Executor::execute ( const Matrix& left, const Matrix& right, Matrix& result) {
	// Size of final matrix
	int final_row = left.get_row();
	int final_col = right.get_col();

	
	const int number_of_tasks = final_row * final_col;

	for ( int index = 0 ; index < number_of_tasks ; ++ index ) {
		int row_index = index / final_row;
		int col_index = index % final_col;

		// Create data for queue task
		MatrixThreadData * data = new MatrixThreadData(left, right, result, row_index, col_index, index );
		// Insert task into queue task
		queue_of_tasks->push(data);
	}

	// All tasks were generated and inserted into queue task. 
	// Signalize worker thread that there are no more task to be created.
	for ( int worker_index = 0 ; worker_index < m_number_of_workers ; ++ worker_index ) {
		workers[worker_index]->stop_task_generation();
	}
}
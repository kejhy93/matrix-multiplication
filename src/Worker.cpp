#include "Worker.h"

Worker::Worker ( int id, ThreadQueue* queue) : m_id ( id), m_queue(queue) {
	are_task_generated = 0;
}

Worker::~Worker() {
}

/**
 * Worker method, receive tasks from queue task 
 * and execute simple linear combination 
 * and write result to final matrix.
 */
void Worker::do_job () {
	std::cout << "Worker-1 starts" << std::endl;
	// Run until task generation is finished and queue task is empty
	// task generation condition ensure to not close worker method in case of slow task generation :)
	while ( are_task_generated == 0 || m_queue->size() != 0 ) {
		MatrixThreadData* task;
		if ( m_queue->is_empty() ) {
			// Queue task is empty, if task generation is not finished just continue, there will be some task.
			// If task generation is finished, just continue and worker method will be terminated.
		} else {
			task = m_queue->pop();

			if ( task != nullptr ) {

				double sum = MatrixMultiplication::linear_combination(task->m_left_matrix, task->m_right_matrix, task->m_row, task->m_col);

				task->m_final_matrix.set_value(task->m_row, task->m_col, sum);
				delete task;
			}
		}
	}
}

/**
 * Called when executor stop generate tasks
 */ 
void Worker::stop_task_generation() {
	are_task_generated = 1;
}
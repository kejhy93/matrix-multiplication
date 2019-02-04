#include "Worker.h"

Worker::Worker ( int id, ThreadQueue* queue) : m_id ( id), m_queue(queue) {
	is_running = 0;
}

Worker::~Worker() {
}

void Worker::do_job () {
	while ( is_running == 0 || m_queue->size() != 0 ) {
		MatrixThreadData* task;
		if ( m_queue->is_empty() ) {
		} else {
			task = m_queue->pop();

			if ( task != nullptr ) {

				double sum = 0.0;
				for ( int index = 0 ; index < task->m_left_matrix.get_col() ; ++ index ) {
					sum += task->m_left_matrix.get_value(task->m_row, index) * task->m_right_matrix.get_value(index, task->m_col);
				}

				task->m_final_matrix.set_value(task->m_row, task->m_col, sum);
				delete task;
			}
		}
	}
}

void Worker::stop() {
	is_running = 1;
}
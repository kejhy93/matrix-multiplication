#include "Worker.h"

Worker::Worker ( int id, ThreadQueue* queue) : m_id ( id), m_queue(queue) {
	is_running = 0;

	std::cout << "[Worker-" << m_id << "] Start" << std::endl;
}

Worker::~Worker() {
	std::cout << "[Worker-" << m_id << "] destruction" << std::endl;
}

void Worker::do_job () {
	while ( is_running == 0 || m_queue->size() != 0 ) {
		std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] is_running=" << is_running << std::endl;
		MatrixThreadData* task;
		if ( m_queue->is_empty() ) {
			std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] Queue is empty" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		} else {
			std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] Queue has " << m_queue->size() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			task = m_queue->pop();

			if ( task != nullptr ) {
				std::cout << "[Worker-" << m_id << "][Task-" << task->m_id << "] Received task" << std::endl;

				double sum = 0.0;
				for ( int index = 0 ; index < task->m_left_matrix.get_col() ; ++ index ) {
					sum += task->m_left_matrix.get_value(task->m_row, index) * task->m_right_matrix.get_value(index, task->m_col);
				}

				task->m_final_matrix.set_value(task->m_row, task->m_col, sum);
				delete task;
			}
		}
	}
	std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] is not runnig" << std::endl;
}

void Worker::stop() {
	std::cout << "[Worker-" << m_id << "] Stop" << std::endl;
	is_running = 1;
}
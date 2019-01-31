#include "Worker.h"

Worker::Worker ( int id, std::queue<MatrixThreadData*>& queue) : m_id ( id), m_queue(queue) {
	is_running = 0;

	std::cout << "[Worker-" << m_id << "] Start" << std::endl;
}

Worker::~Worker() {
	std::cout << "[Worker-" << m_id << "] destruction" << std::endl;
}

void Worker::do_job () {
	while ( is_running == 0 || !m_queue.empty() ) {
		std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] is_running=" << is_running << std::endl;
		if ( m_queue.empty() ) {
			std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] Queue is empty" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		} else {
			std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] Queue has " << m_queue.size() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			if ( !m_queue.empty() )
				m_queue.pop();
		}
	}
	std::cout << "[Worker-" << m_id << "][threadId=" << std::this_thread::get_id() << "] is not runnig" << std::endl;
}

void Worker::stop() {
	std::cout << "[Worker-" << m_id << "] Stop" << std::endl;
	is_running = 1;
}
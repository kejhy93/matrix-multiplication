#include "ThreadQueue.h"

ThreadQueue::ThreadQueue() {

}

ThreadQueue::~ThreadQueue() {
	// TODO: clean queue if not empty
}

/**
 * Push new task to queue thread.
 * Thread-safe as possible.
 */
void ThreadQueue::push ( MatrixThreadData* data) {
	m_queue_mutex.lock();

	m_queue.push(data);

	m_queue_mutex.unlock();
}

/**
 * Pop task from queue task.
 * Thread-safe as possible.
 */
MatrixThreadData* ThreadQueue::pop() {
	m_queue_mutex.lock();
	if ( m_queue.size() == 0 ) {
		m_queue_mutex.unlock();
		return nullptr;
	}

	MatrixThreadData* pop_data = m_queue.front();
	m_queue.pop();
	m_queue_mutex.unlock();

	return pop_data;
}

/**
 * Check if queue task is empty.
 */
bool ThreadQueue::is_empty() {
	m_queue_mutex.lock();

	bool is_empty = m_queue.empty();

	m_queue_mutex.unlock();

	return is_empty;
}

/**
 * Return size of queue.
 */
int ThreadQueue::size() {
	m_queue_mutex.lock();
	int size = m_queue.size();
	m_queue_mutex.unlock();

	return size;
}
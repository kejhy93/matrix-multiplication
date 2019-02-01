#include "Executor.h"

Executor::Executor ( int number_of_workers) : m_number_of_workers(number_of_workers) {

	threads = new std::thread*[m_number_of_workers];

	workers = new Worker*[m_number_of_workers];

	queue_of_tasks = new ThreadQueue();
	for ( int index = 0 ; index < m_number_of_workers ; ++ index ) {
		std::cout << "Create worker id=" << index << std::endl;
		workers[index] = new Worker(index, queue_of_tasks);

		std::cout << "Start worker id=" << index << std::endl;
		threads[index] = new std::thread(&Worker::do_job, workers[index] );
	}
}

Executor::~Executor() {
	std::cout << "Executor desctruction start" << std::endl;
	for ( int index = 0 ; index < m_number_of_workers ; ++ index) {
		std::cout << "Executor desctruction thread id=" << index << " started" << std::endl;
		threads[index]->join();
		delete threads[index];
		delete workers[index];
		std::cout << "Executor desctruction thread id=" << index << " finished" << std::endl;
	}
	delete queue_of_tasks;
	delete[] threads;
	delete[] workers;
	std::cout << "Executor desctruction finished" << std::endl;
}

void Executor::execute ( const Matrix& left, const Matrix& right, Matrix& result) {
	int final_row = left.get_row();
	int final_col = right.get_col();

	const int number_of_tasks = final_row * final_col;

	// std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	for ( int index = 0 ; index < number_of_tasks ; ++ index ) {
		int row_index = index / final_row;
		int col_index = index % final_col;
		std::cout << "[Executor] Create task [" << row_index << ";" << col_index << "]" << std::endl;

		MatrixThreadData * data = new MatrixThreadData(left, right, result, row_index, col_index, index );

		queue_of_tasks->push(data);
	}

	std::cout << "Executor computation is finished" << std::endl;
	for ( int worker_index = 0 ; worker_index < m_number_of_workers ; ++ worker_index ) {
		workers[worker_index]->stop();
	}
}
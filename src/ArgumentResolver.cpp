#include "ArgumentResolver.h"

ArgumentResolver::ArgumentResolver(int argument_count, char** arguments) 
	: m_argument_count(argument_count), m_arguments(arguments) {

}

ArgumentResolver::~ArgumentResolver() {

}

int ArgumentResolver::parse_command_line_arguments() {

	for ( int argument_index = 1 ; argument_index < m_argument_count ;  ) {
		if ( strcmp(m_arguments[argument_index], random_matrix_param.c_str()) == 0 ) {
			// generate random matrix row_left col_left row_right col_right
			if ( parse_number(ROW_LEFT, argument_index + 1) != 0 ) {
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index+1] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;
				return 1;
			}
			if ( parse_number(COL_LEFT, argument_index + 2) != 0 ) {
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index+2] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;
				return 2;
			}
			if ( parse_number(ROW_RIGHT, argument_index + 3) != 0 ) {
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index+3] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;
				return 3;
			}
			if ( parse_number(COL_RIGHT, argument_index + 4) != 0 ) {
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index+4] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;
				return 4;
			}

			GENERATE_RANDOM_MATRIX = 0;

			argument_index += 5;
		} else if ( strcmp(m_arguments[argument_index], multithread.c_str()) == 0 ) {
			if ( parse_number(THREAD_COUNT, argument_index+1) == 0 ) {
				// multithread #thread-count
				argument_index += 2;
				MULTITHREAD = 0;
			} else {
				// multithread 
				argument_index += 1;
				MULTITHREAD = 0;
			}

		} else if ( strcmp(m_arguments[argument_index], help.c_str()) == 0 ) {
			// help
			std::cout << std::endl;
			argument_index += 1;
		} else if ( strcmp(m_arguments[argument_index], left_matrix_arg.c_str()) == 0 ) {
			// left_matrix path_to_file
			if ( parse_file(path_to_file_left_matrix, argument_index+1) != 0 ) {
				std::cerr << "Wrong argument, expected file, got " << m_arguments[argument_index+1] << std::endl;
				std::cerr << "expected " << left_matrix_arg << " path_to_file" << std::endl;
				return 5;
			}

			argument_index += 2;
		} else if ( strcmp(m_arguments[argument_index], right_matrix_arg.c_str()) == 0 ) {
			// right_matrix path_to_file
			if ( parse_file(path_to_file_right_matrix, argument_index+1) != 0 ) {
				std::cerr << "Wrong argument, expected file, got " << m_arguments[argument_index+1] << std::endl;
				std::cerr << "expected " << right_matrix_arg << " path_to_file" << std::endl;
				return 6;	
			}

			argument_index += 2;
		} else if ( strcmp(m_arguments[argument_index], result_matrix_arg.c_str()) == 0 ) {
			// result_matrix path_to_file
			if ( parse_file(path_to_file_result_matrix, argument_index+1) != 0 ) {
				std::cerr << "Wrong argument, expected file, got " << m_arguments[argument_index+1] << std::endl;
				std::cerr << "expected " << result_matrix_arg << " path_to_file" << std::endl;
				std::cerr << "result matrix will not be exported" << std::endl;
			}

			argument_index += 2;
		} else {
			// ERROR
			std::cerr << "Unknown argument " << m_arguments[argument_index] << std::endl;
			return -1;
		}
	}

	if ( path_to_file_left_matrix.compare("") == 0 ) {
		std::cerr << "Left matrix has to be specified" << std::endl;
		return 1;
	}
	if ( path_to_file_right_matrix.compare("") == 0 ) {
		std::cerr << "Right matrix has to be specified" << std::endl;
		return 1;
	}


	return 0;
}

int ArgumentResolver::parse_number ( int &result, const int index) const {
	if ( index == m_argument_count) {
		return 1;
	}

	std::stringstream ss(m_arguments[index]);
	int number;

	if ( ss >> number ) {
		result = number;
		return 0;
	} else {
		return 1;
	}
}

int ArgumentResolver::parse_file ( std::string& result, const int index) const {
	if ( index == m_argument_count) {
		return 1;
	}

	std::stringstream ss(m_arguments[index]);
	std::string file;

	if ( ss >> file ) {
		result = file;

		std::ifstream fileCheck(file);
		if ( fileCheck.good() ) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}
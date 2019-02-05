#ifndef __ARGUMENT_RESOLVER_H__
#define __ARGUMENT_RESOLVER_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

class ArgumentResolver {

public:
	
	ArgumentResolver(const int argument_count, char** arguments);
	virtual ~ArgumentResolver();

	int parse_command_line_arguments();

	bool shouldIGenerateRandomMatrices() const {
		return GENERATE_RANDOM_MATRIX == 0;
	}

	bool shouldIRunMultiThread() const {
		return MULTITHREAD == 0;
	}

	bool shouldIExportResultMatrix() const {
		return path_to_file_result_matrix.compare("");
	}

	int how_many_threads() const {
		return THREAD_COUNT;
	}

	int get_left_matrix_row() const {
		return ROW_LEFT;
	}
	int get_left_matrix_col() const {
		return COL_LEFT;
	}
	int get_right_matrix_row() const {
		return ROW_RIGHT;
	}
	int get_right_matrix_col() const {
		return COL_RIGHT;
	}

	std::string get_path_to_left_matrix() const {
		return path_to_file_left_matrix;
	}

	std::string get_path_to_right_matrix() const {
		return path_to_file_right_matrix;
	}

	std::string get_path_to_result_matrix() const {
		return path_to_file_result_matrix;
	}

private:
	int m_argument_count;
	char ** m_arguments;

	int GENERATE_RANDOM_MATRIX = 1;
	int ROW_LEFT = 0;
	int COL_LEFT = 0;
	int ROW_RIGHT = 0;
	int COL_RIGHT = 0;
	const std::string random_matrix_param = "-generate-random-matrix";

	int MULTITHREAD = 1;
	const std::string multithread = "-multithread";

	int THREAD_COUNT = 8;

	const std::string help = "-help";

	std::string path_to_file_left_matrix = "";
	const std::string left_matrix_arg = "-left_matrix";

	std::string path_to_file_right_matrix = "";
	const std::string right_matrix_arg = "-right_matrix";

	std::string path_to_file_result_matrix = "";
	const std::string result_matrix_arg = "-result_matrix"; 

	int parse_number ( int &result, const int index) const;
	int parse_file ( std::string &result, const int index) const;
};

#endif
#include "ArgumentResolver.h"

ArgumentResolver::ArgumentResolver(int argument_count, char **arguments)
	: m_argument_count(argument_count), m_arguments(arguments)
{
}

ArgumentResolver::~ArgumentResolver()
{
}

void print_help()
{
	std::cout << "Usage for single thread solution: " << std::endl << "./MatrixMult -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix" << std::endl << std::endl;
	std::cout << "Usagefor multithread solution with count_of_threads threads:" << std::endl  << "./MatrixMult -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix -multithread count_of_threads" << std::endl << std::endl;
	std::cout << "Usage for exporting final matrix to file:" << std::endl << "./MatrixMult -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix -result_matrix path_to_result_matrix" << std::endl << std::endl;
	std::cout << "Usage for generating random matrices:" << std::endl << " ./MatrixMult -left_matrix path_to_left_matrix -right_matrix path_to_right_matrix -generate-random-matrix left_row left_col right_row right_col" << std::endl;
}

/**
 * Parse command line arguments and verify all mandatory arguments.
 */
int ArgumentResolver::parse_command_line_arguments()
{

	if (m_argument_count == 1)
	{
		// No arguments given. Print help
		// ./MatrixMult
		print_help();
		return 100;
	}

	// start from 1, 0 is name of the program
	for (int argument_index = 1; argument_index < m_argument_count;)
	{
		if (strcmp(m_arguments[argument_index], random_matrix_param.c_str()) == 0)
		{
			// generate random matrix row_left col_left row_right col_right
			if (parse_number(ROW_LEFT, argument_index + 1) != 0)
			{
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index + 1] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;

				// Print help
				print_help();
				return 1;
			}
			if (parse_number(COL_LEFT, argument_index + 2) != 0)
			{
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index + 2] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;

				// Print help
				print_help();
				return 2;
			}
			if (parse_number(ROW_RIGHT, argument_index + 3) != 0)
			{
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index + 3] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;

				// Print help
				print_help();
				return 3;
			}
			if (parse_number(COL_RIGHT, argument_index + 4) != 0)
			{
				std::cerr << "Wrong argument, expected number, but got " << m_arguments[argument_index + 4] << std::endl;
				std::cerr << "expected " << random_matrix_param << " row_left col_left row_right col_right" << std::endl;

				// Print help
				print_help();
				return 4;
			}

			GENERATE_RANDOM_MATRIX = 0;

			argument_index += 5;
		}
		else if (strcmp(m_arguments[argument_index], multithread.c_str()) == 0)
		{
			if (parse_number(THREAD_COUNT, argument_index + 1) == 0)
			{
				// multithread #thread-count
				argument_index += 2;
				MULTITHREAD = 0;
			}
			else
			{
				// multithread
				argument_index += 1;
				MULTITHREAD = 0;
			}
		}
		else if (strcmp(m_arguments[argument_index], help.c_str()) == 0)
		{
			// help
			print_help();
			argument_index += 1;
			return 100;
		}
		else if (strcmp(m_arguments[argument_index], left_matrix_arg.c_str()) == 0)
		{
			// left_matrix path_to_file
			if (parse_file(path_to_file_left_matrix, argument_index + 1) != 0)
			{
				std::cerr << "Wrong argument, expected file, got " << m_arguments[argument_index + 1] << std::endl;
				std::cerr << "expected " << left_matrix_arg << " path_to_file" << std::endl;

				// Print help
				print_help();
				return 5;
			}

			argument_index += 2;
		}
		else if (strcmp(m_arguments[argument_index], right_matrix_arg.c_str()) == 0)
		{
			// right_matrix path_to_file
			if (parse_file(path_to_file_right_matrix, argument_index + 1) != 0)
			{
				std::cerr << "Wrong argument, expected file, got " << m_arguments[argument_index + 1] << std::endl;
				std::cerr << "expected " << right_matrix_arg << " path_to_file" << std::endl;

				// Print help
				print_help();
				return 6;
			}

			argument_index += 2;
		}
		else if (strcmp(m_arguments[argument_index], result_matrix_arg.c_str()) == 0)
		{
			// result_matrix path_to_file
			parse_file(path_to_file_result_matrix, argument_index + 1);

			argument_index += 2;
		}
		else
		{
			// ERROR
			std::cerr << "Unknown argument " << m_arguments[argument_index] << std::endl;

			// Print help
			print_help();
			return -1;
		}
	}

	// Check if mandatory arguments were saved
	if (path_to_file_left_matrix.compare("") == 0)
	{
		std::cerr << "Left matrix has to be specified" << std::endl;
		return 1;
	}
	if (path_to_file_right_matrix.compare("") == 0)
	{
		std::cerr << "Right matrix has to be specified" << std::endl;
		return 1;
	}

	return 0;
}

/**
 * Parse number from command line argument at index.
 *
 * return 0 for success, otherwise error
 */
int ArgumentResolver::parse_number(int &result, const int index) const
{
	// if tested index is out of range
	if (index == m_argument_count)
	{
		return 1;
	}

	std::stringstream ss(m_arguments[index]);
	int number;

	if (ss >> number)
	{
		result = number;
		return 0;
	}
	else
	{
		return 1;
	}
}

/**
 * Parse string from command line argument at index and test if file exist.
 *
 * return 0 for success, otherwise error
 */
int ArgumentResolver::parse_file(std::string &result, const int index) const
{
	if (index == m_argument_count)
	{
		return 1;
	}

	std::stringstream ss(m_arguments[index]);
	std::string file;

	if (ss >> file)
	{
		result = file;

		std::ifstream fileCheck(file);
		if (fileCheck.good())
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}
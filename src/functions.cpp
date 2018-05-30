#include <iostream>
#include <cassert>
#include <stdlib.h>

/**
 *@brief Creation of matrix.
 *@name Function "create_matrix"
 *@param n is a constant integer, the size of matrix.
 *@return char** is a pointer to a pointer to char, nxn matrix.
 */
char** create_matrix ( const int n )
{	
	assert ( n > 0 );
	char** matrix = 0;
	matrix = new char* [n];
	for ( int i = 0; i < n; ++i ) {
		matrix[i] = new char [n];
	}
	return matrix;
}

/**
 *@brief Initialization of matrix.
 *@name Function "initialize_matrix"
 *@param n a constant integer, the size of matrix.
 *@param matrix is a pointer to a pointer to char, char**.
 *@return void, function does not return a value.
 */
void initialize_matrix ( const int n, char** matrix )
{   
	assert ( n > 0 );
	for ( int i = 0; i < n; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			matrix[i][j] = '0';
		}
	}
}

/**
 *@brief This function prints the matrix.
 *@name Function "print"
 *@param n is a constant integer, the size of matrix.
 *@param matrix is a pointer to a pointer to char, char**.
 *@return void, function does not return a value.
 */
void print ( const int n, char** matrix )
{ 	
	assert ( n > 0 );
	for ( int i = 0; i < n; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

/**
 *@name Function "print_result_matrix"
 *@brief The function prints the matrix (the sea) in the end of the game. Prints without ones.
 *@param n is a constant integer number, the size of matrix.
 *@param matrix is a pointer to pointer to char, char**. 
 *@return void, function does not return a value.
 */
void print_result_matrix ( const int n, char** matrix ) 
{	assert ( n > 0 );
	for ( int i = 0; i < n; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			if ('1' == matrix[i][j] ) {
				matrix[i][j] = '0';
				std::cout << matrix[i][j] << ' ';
			} else {
				std::cout << matrix[i][j] << ' ';
			}
		}
		std::cout << std::endl;
	}
}

/**
 *@name Function "random_number"
 *@brief The function generates an integer number in range [0-9] and returns it.
 *@param The function doesn't have parameters.
 *@return The function returns an integer number.
 */
int random_number ()
{
	int a = rand() % 10;
	return a;
}

/**
 *@brief Function sets a horizontal ship the  in sea (in matrix).
 *@name Function "set_horizontal"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return void, function does not return a value.
 */
void set_horizontal ( char** matrix, const int x, const int y, const int size )
{
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert (size > 0 && size < 5);
	for ( int i = 0; i < size; ++i ) {
		matrix[x][y + i] = '2';
	}
}

/**
 *@brief Function sets a vertical  ship in sea (in matrix).
 *@name Function "set_vertical"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return void, function does not return a value.
 */
void set_vertical ( char** matrix, const int x, const int y, const int size )
{	
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert ( size > 0 && size < 5 );
	for ( int i = 0; i < size; ++i ) {
		matrix[x + i][y] = '2';
	}
}

/**
 *@brief Function chechks, if there can be a horizontal ship.
 *@name Function "check_for_horizontal"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return bool. Function returns true if there can be a horizontal ship. Return false if there cann't be a horizontal ship.
 */
bool check_for_horizontal (char** matrix, const int x, const int y, const int size )
{
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert ( size > 0 && size < 5 );

	for ( int i = 0; i <= size; ++i ) {
		if ( matrix[x][y + i] != '0' ) {
			return false;
		} else {
			return true;
			}
	}
}

/**
 *@brief Function chechks, if there can be a vertical ship.
 *@name Function "check_for_vertical"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return bool. Function returns true if there can be a vertical ship. Return false if there cann't be a vertical ship.
 */
bool check_for_vertical (char** matrix, const int x, const int y, const int size )
{	
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert ( size > 0 && size < 5 );
	for ( int i = 0; i <=  size; ++i ) { 
		if ( matrix[x + i][y] != '0' )
			return false;
		else return true;
	}    
}

/**
 *@brief Function sets "1" around horizontal ship.
 *@name Function "set_around_horizontal"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return void. Function doesn't return a value.
 */
void set_around_horizontal ( char** matrix, const int x, const int y, const int size )
{	
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert ( size > 0 && size < 5 );
	int angle;
	angle = y + size - 1;
	if ( 0 == x ) {
		if ( 0 == y ) {
			for ( int i = 0; i <= size; ++i ) {
				matrix[x + 1][y + i] = '1';
			}
			matrix[x][y + size] = '1';
		} else if ( 9 == angle ) {
			for ( int i = -1; i < size; ++i ) {
				matrix[x + 1][y + i] = '1';
			}
			matrix[x][y - 1] = '1';
		}   else {
			for ( int i = -1; i <= size; ++i ) {
				matrix[x + 1][y + i] = '1';
			}
			matrix[x][y - 1] = '1';
			matrix[x][y + size] = '1';
		}
	} else if ( 9 == x ) {
		if ( 0 == y ) {
			for ( int i = 0; i <= size; ++i ) {
				matrix[x - 1][y + i] = '1';
			}
			matrix[x][y + size] = '1';
		} else if ( 9 == angle ) {
			for ( int i = -1; i < size; ++i ) {
				matrix[x - 1][y + i] = '1';
			}
			matrix[x][y - 1] = '1';
		}  else {
			for ( int i = -1; i <= size; ++i ) {
				matrix[x - 1][y + i] = '1';
			}
			matrix[x][y - 1] = '1';
			matrix[x][y + size] = '1';
		}
	} else {
		if (0 == y ) {
			for ( int i = -1; i < 2; i += 2 ) {
				for ( int j = 0; j <= size; ++j ) {
					matrix[x + i][y + j] = '1';
				}
			}
			matrix[x][y + size] = '1';
		} else if ( 9 == angle ) {
			for ( int i = -1; i < 2; i += 2 ) {
				for ( int j = -1; j < size; ++j ) {
					matrix[x + i][y + j] = '1';
				}
			}
			matrix[x][y - 1] = '1';
		} else {
			for ( int i = -1; i < 2; i += 2 ) {
				for ( int j = -1; j <= size; ++j ) {
					matrix[x + i][y + j] = '1';
				}
			}
			matrix[x][y - 1] = '1';
			matrix[x][y + size] = '1';
		}
	}
}


/**
 *@brief Function sets "1" around vertical  ship.
 *@name Function "set_around_vertical"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@param size is a constant integer, the size of ship (1, 2, 3 or 4).
 *@return void. Function doesn't return a value.
 */
void  set_around_vertical ( char** matrix, const int x, const int y, const int size )
{	
	assert ( x >= 0 );
	assert ( y >= 0 );
	assert (size > 0 );
	assert ( size < 5 );
	int angle;
	angle = x + size - 1;
	if ( 0 == y ) {
		if ( 0 == x ) {
			for ( int i = 0; i <= size; ++i ) {
				matrix[x + i][y + 1] = '1';  
			}
			matrix[x + size][y] = '1';  
		} else if ( 9 == angle ) {
			for ( int i = -1; i < size; ++i ) {
				matrix[x + i][y + 1] = '1';
			}
			matrix[x - 1][y] = '1';
		}  else {
			for ( int i = -1; i <= size; ++i ) {
				matrix[x + i][y + 1] = '1';
			}
			matrix[x - 1][y] = '1';
			matrix[x + size][y] = '1';
		}
	} else if ( 9 == y ) {
		if ( 0 == x ) {
			for ( int i = 0; i <= size; ++i ) {
				matrix[x + i][y - 1] = '1';
			}   
			matrix[x + size][y] = '1';
		} else if ( 9 == angle ) {
			for ( int i = -1; i < size; ++i ) {
				matrix[x + i][y - 1] = '1';
			}
			matrix[x - 1][y] = '1';
		} else {
			for (int i = -1; i <= size; ++i ) {
				matrix[x + i][y - 1] = '1';
			}
			matrix[x - 1][y] = '1';
			matrix[x + size][y] = '1';
		}
	} else {
		if ( 0 == x ) {
			for ( int i = 0; i <= size; ++i ) {
				for ( int j = -1; j < 2; j += 2 ) {
					matrix[x + i][y + j] = '1';
				}
				matrix[x + size][y] = '1';
			}
		} else if ( 9 == angle ) {
			for ( int i = -1; i < size; ++i ) {
				for ( int j = -1; j < 2; j += 2 ) {
					matrix[x + i][y + j] = '1';
				}
				matrix[x - 1][y] = '1';
			}
		} else {
			for ( int i = -1; i <= size; ++i ) {
				for ( int j = -1; j < 2; j += 2 ) {
					matrix[x + i][y + j] = '1';
				}
				matrix[x - 1][y] = '1';
				matrix[x + size][y] = '1';
			}
		}
	}
}

/**
 *@brief Function sets a ship, sets "2" in the field of the ship
 *@name Function "set_ship"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@return void. Function doesn't return a value.
 */
bool set_ship ( char** matrix, const int x, const int y, const int size )
{	assert ( x >= 0 );
	assert ( y >= 0 );
	assert ( size > 0 );
	assert ( size < 5 );
	int type;
	while ( true ) {
		if ( x + size < 10 ) {
			type = 1;
			break;
		} else if ( y + size < 10 ) {
			type = 0;
			break;
		} else {
			type = random_number() % 2;
		}
	}

	if ( 0 == type ) {
		assert ( y + size <= 10 );
		if ( check_for_horizontal ( matrix, x, y, size ) ) { 
			set_horizontal ( matrix, x, y, size );
			set_around_horizontal ( matrix, x, y, size );
			return true;
		}  else {
			return false;
		}
	} else {
		assert ( x + size <= 10 );
		if ( check_for_vertical ( matrix, x, y, size ) ) {
			set_vertical ( matrix, x, y, size );
			set_around_vertical ( matrix, x, y, size );
			return true;
		} else {
			return false;
		}
	}
}

/**
 *@name Function "set_all_ships"
 *@brief Function sets ships in the sea.
 *@param matrix is a pointer to a pointer to char, char**. In this case this is the sea.
 *@return void. Function doesn't return a value.
 */
int set_all_ships ( char** matrix )
{	
	int count = 3;
	int fields = 0;
	while ( count ){
		srand ( time ( 0 ) );
		int x = random_number();
		int y = random_number();
		int size = x % 4 + 1;
		int type = y % 2;
		if ( set_ship ( matrix, x, y, size ) ) {
			fields += size;
			--count;
		} else continue;
	}
	return fields;
}

/**
 *@brief Shooting. If in the field of ship is "2" prints "The field is damaged", else "The field is empty"
 *@name Function "Shoot"
 *@param matrix is a pointer to a pointer to char, char**.
 *@param x is a constant integer, the abscissa of the field.
 *@param y is a constant integer, the ordinate of the field.
 *@return void. Function doesn't return a value.
 */
void shoot ( char** matrix,const int x, const int y, int& count )
{	assert ( x >= 0 );
	assert(y >= 0);
	if('2' == matrix[x][y] ) {
		std::cout << "The field was damaged." << std::endl;
		matrix[x][y] = 'X';
		--count;
	}
	else {	
		std::cout << "The field is empty." << std::endl;
		matrix[x][y] = '*';
	}
}

/**
 *@name Function "game"
 *@brief The function provides game between user and computer
 *@param sea the sea of the game. The matrix.
 *@param count the count of 2s in the sea.
 *@return void. The function doesn't return a value.
 */
void game ( char** sea, int count )
{	
	while (count) {
		int x;
		int y;
		char yes_no;
		std::cout << "Please enter the coordinates of a field in range of[0-9]: ";
		std::cin >> x >> y;
		assert ( x > 0 );
		assert ( x < 10 );
		assert ( y > 0 );
		assert ( y < 10 );
		shoot ( sea, x, y, count );
		std::cout << std::endl;
		std::cout << "Do you want to continue y/n: " ;
		std::cin >> yes_no;
		if ( yes_no == 'y' ) {
			continue;
		} else if ( yes_no == 'n' ) {
			break;
		} else {
			std::cout << "Type y (yes) or n (no). Try again";
		}

	}
	std::cout << "Game over" << std::endl;
}

/**
 *@name Function "delete"
 *@brief The function deletes the matrix from dynamic memory.
 *@param matrix is a pointer to a pointer to char.
 *@param size is a constant integer number, the size of  matrix.
 *@return void. Function does not return a value.
 */
void delete_matrix ( char** matrix, const int size ) 
{
	for ( int i = 0; i < size; ++i ) {
		delete matrix[i];
	}
	delete matrix;
}

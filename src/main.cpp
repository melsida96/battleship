#include <iostream>
#include <functions.h>

int main()
{
	int x, y;
	const int size = 10;
	char** sea = create_matrix(size);
	initialize_matrix(size, sea);
	int count = set_all_ships(sea);
	print(size, sea);
	game(sea, count);
	print_result_matrix(size, sea);
	delete_matrix(sea, size);
	return 0;
}


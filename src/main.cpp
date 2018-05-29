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
	while(count){
		std::cout << "Please enter the coordinates of a field: ";
		std::cin >> x >> y;
		shoot(sea, x, y, count);
		std::cout << std::endl;
		}
	std::cout << "The game is over. You win." << std::endl;
	print_result_matrix(size, sea);
	delete_matrix(sea, size);
	return 0;
}


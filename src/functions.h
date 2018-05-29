char** create_matrix(const int);
void initialize_matrix(const int, char**);
void print(const int, char**);
void set_horizontal(char**, const int, const int, const int);
void set_vertical(char**, const int, const int, const int);
bool check_for_horizontal(char**, const int, const int, const int);
bool check_for_vertical(char**, const int, const int, const int);
void set_around_horizontal(char**, const int, const int, const int);
void set_around_vertical(char**, const int, const int, const int);
void set_ship(char**, const int, const int, const int);
void shoot(char**, const int, const int, int&);
int set_all_ships(char**);
int random_number();
void print_result_matrix(const int, char**);
void delete_matrix(char**, const int);

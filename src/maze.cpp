/* Here in the .cpp you should define and implement everything declared in the
 * .h file.
 */

#include "maze.h"

string *build_matrix(int rows) {
  string *matrix = new string[rows];
  return matrix;
}

void fill_matrix(string *matrix, int rows) {
  for (int j = 0; j < rows; j++) {
    getline(cin, matrix[j]);
  }
}

// Free function!
void print_matrix(const string *matrix, int rows) {
  for (int j = 0; j < rows; j++) {
    cout << matrix[j] << "\n";
  }
}

void delete_matrix(string *&matrix) {
  delete[] matrix;
  matrix = nullptr;
}

void find_start(string *matrix, int rows, int &row, int &col) {
  // find s in maze for start position
  // asume all row and collom same lenght ..this is wrong check nput
  // change code
  // static cast
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < static_cast<int>(matrix[i].length()); j++) {
      if (matrix[i][j] == 'S') {
        row = i;
        col = j;
        return;
      }
    }
  }
}

// backtracking - see example
// up down ,left right
// use valid_move
//  chnag up down to direction -might be ssue as error direction south
// chnage to valid directions
// working

bool find_exit(string *matrix, int row, int col) {
  if (valid_move(matrix, row, col, "NORTH")) {
    if (at_end(matrix, row - 1, col))
      return true;
    matrix[row - 1][col] = '@';
    if (find_exit(matrix, row - 1, col))
      return true;
    matrix[row - 1][col] = ' ';
  }

  if (valid_move(matrix, row, col, "SOUTH")) {
    if (at_end(matrix, row + 1, col))
      return true;
    matrix[row + 1][col] = '@';
    if (find_exit(matrix, row + 1, col))
      return true;
    matrix[row + 1][col] = ' ';
  }

  if (valid_move(matrix, row, col, "EAST")) {
    if (at_end(matrix, row, col + 1))
      return true;
    matrix[row][col + 1] = '@';
    if (find_exit(matrix, row, col + 1))
      return true;
    matrix[row][col + 1] = ' ';
  }

  if (valid_move(matrix, row, col, "WEST")) {
    if (at_end(matrix, row, col - 1))
      return true;
    matrix[row][col - 1] = '@';
    if (find_exit(matrix, row, col - 1))
      return true;
    matrix[row][col - 1] = ' ';
  }
  return false;
}

// end = E

bool at_end(const string *matrix, int row, int col) {
  if (matrix[row][col] == 'E')
    return true;
  else {
    return false;
  }
}
// check
// n--s++w--e++
bool valid_move(const string *matrix, int row, int col,
                const string &direction) {
  if (direction == "NORTH") {
    if (matrix[row - 1][col] == '|' || matrix[row - 1][col] == 'S' ||
        matrix[row - 1][col] == '@')
      return false;

    else if (matrix[row - 1][col] == ' ' || matrix[row - 1][col] == 'E')
      return true;
  }

  else if (direction == "SOUTH") {
    if (matrix[row + 1][col] == '|' || matrix[row + 1][col] == 'S' ||
        matrix[row + 1][col] == '@')
      return false;

    else if (matrix[row + 1][col] == ' ' || matrix[row + 1][col] == 'E')
      return true;
  }

  else if (direction == "EAST") {
    if (matrix[row][col + 1] == '|' || matrix[row][col + 1] == 'S' ||
        matrix[row][col + 1] == '@')
      return false;

    else if (matrix[row][col + 1] == ' ' || matrix[row][col + 1] == 'E')
      return true;
  }

  else if (direction == "WEST") {
    if (matrix[row][col - 1] == '|' || matrix[row][col - 1] == 'S' ||
        matrix[row][col - 1] == '@')
      return false;

    else if (matrix[row][col - 1] == ' ' || matrix[row][col - 1] == 'E')
      return true;
  }
  return false;
}

#include <iostream>
#include <string.h>

// Custom conio.h for Linux
#include "conio.h"

using namespace std;

int life = 3, score = 0, stars = 0;
int pacman[2] = { 5, 5 };
int enemy[][2] =
{
  { 31, 7 },
  { 7, 11 },
  { 51, 4 },
  { 56, 14 }
};
int enemyCount = sizeof(enemy) / sizeof(enemy[0]);

string map[] = {
  "======================================================================",
  "=    *                                                               =",
  "=     =========                     *                                =",
  "=                                           =====                    =",
  "=            *                                                       =",
  "=                                                   *                =",
  "=             =========                                              =",
  "=                                                                    =",
  "=         *                                                          =",
  "=                                      *                             =",
  "=                                                                    =",
  "=                               ==========                           =",
  "=                           *                                        =",
  "=          =====                                                     =",
  "=                                                  *                 =",
  "=       *                                                            =",
  "=                                       ========                *    =",
  "=                                                                    =",
  "======================================================================",
};

void playerMove(char);
void updateMap();
void checkCollision();
int random(int, int);
void enemyMove();
void updateEnemy(int);

int main()
{
  srand((unsigned) time(0));

  while (1) {
    system("clear");
    checkCollision();

    cout << "Life = " << life << endl;
    cout << "Score = " << score << endl << endl;

    updateMap();

    if (stars == 0 | life == 0) {
      break;
    }

    playerMove(getch());
    enemyMove();
  }

  if (life > 0) {
    cout << endl << "You Win !";
  } else {
    cout << endl << "You Lose !";
  }
}

void playerMove(char control)
{
  switch (control) {
    case 'w':
      if (map[pacman[1] - 1][pacman[0]] != '=') {
        pacman[1]--;
      }
      break;

    case 's':
      if (map[pacman[1] + 1][pacman[0]] != '=') {
        pacman[1]++;
      }
      break;

    case 'a':
      if (map[pacman[1]][pacman[0] - 1] != '=') {
        pacman[0]--;
      }
      break;

    case 'd':
      if (map[pacman[1]][pacman[0] + 1] != '=') {
        pacman[0]++;
      }
      break;
  }
}

void updateMap()
{
  int height = sizeof(map) / sizeof(map[0]);
  int temp = 0;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < map[0].length(); j++) {

      for (int k = 0; k < enemyCount; k++) {
        if (i == enemy[k][1] && j == enemy[k][0]) {
          map[enemy[k][1]].replace(enemy[k][0], 1, "E");
        }
      }

      if (i == pacman[1] && j == pacman[0]) {
        cout << "V";
      } else {
        temp = (map[i][j] == '*') ? ++temp : temp;
        cout << map[i][j];
      }
    }
    cout << endl;
  }

  stars = temp;
}

void checkCollision()
{
  if (map[pacman[1]][pacman[0]] == '*') {
    map[pacman[1]].replace(pacman[0], 1, " ");
    score++;
    stars--;
  }

  for (int i = 0; i < enemyCount; i++) {
    if (pacman[1] == enemy[i][1] && pacman[0] == enemy[i][0]) {
      life--;
    }
  }
}

int random(int min, int max)
{
	return min + (rand() % ( max - min + 1 ));
}

void enemyMove()
{
  for (int i = 0; i < enemyCount; i++) {
    int temp = random(0, 3);

    updateEnemy(i);
    switch (temp) {
      case 0:
        if (map[enemy[i][1] - 1][enemy[i][0]] != '=' &&
            map[enemy[i][1] - 1][enemy[i][0]] != '*') {
          enemy[i][1]--;
        }
        break;

      case 1:
        if (map[enemy[i][1] + 1][enemy[i][0]] != '=' &&
            map[enemy[i][1] + 1][enemy[i][0]] != '*') {
          enemy[i][1]++;
        }
        break;

      case 2:
        if (map[enemy[i][1]][enemy[i][0] - 1] != '=' &&
            map[enemy[i][1]][enemy[i][0] - 1] != '*') {
          enemy[i][0]--;
        }
        break;

      case 3:
        if (map[enemy[i][1]][enemy[i][0] + 1] != '=' &&
            map[enemy[i][1]][enemy[i][0] + 1] != '*') {
          enemy[i][0]++;
        }
        break;
    }
  }
}

void updateEnemy(int index)
{
  map[enemy[index][1]].replace(enemy[index][0], 1, " ");
}

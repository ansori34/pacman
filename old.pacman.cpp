#include <iostream>
#include <stdio.h>

using namespace std;

int width = 30, height = -20;
bool status = true;

// Pacman Coordinates
int pacman[2] = {
  width / 2,
  height / 2
};

// Enemies Coordinates
// int enemy[4][2] = {
//   [0, 0],
//   [width, 0],
//   [0, height],
//   [width, height]
// }

void createMap(bool active)
{
  for (int i = 0; i < -height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == pacman[0] && i == -pacman[1]) {
        cout << "V ";
      } else {
        if (j > 0 && j < width - 1 && i > 0 && i < -height - 1) {
          if (active) {
            cout << "* ";
          } else {
            cout << "  ";
          }
        } else {
            cout << "0 ";
        }
      }
    }
    cout << endl;
  }
}

void control()
{
  // cout << "Koordinat Awal : " << "(" << pacman[0] << ", " << pacman[1] << ")";
  // cout << endl;

  while (1) {
    char control;

    cout << "Input Keyboard = ";
    cin >> control;

    if (control == 'a') {
      if (pacman[0] > 1 && pacman[0] <= width) {
        pacman[0]--;
      }
    } else if (control == 'd') {
      if (pacman[0] >= 0 && pacman[0] < width - 2) {
        pacman[0]++;
      }
    } else if (control == 'w') {
      if (pacman[1] < -1 && pacman[1] >= height) {
        pacman[1]++;
      }
    } else if (control == 's') {
      if (pacman[1] <= 0 && pacman[1] > height + 2) {
        pacman[1]--;
      }
    }

    system("clear");
    createMap(status);

    // cout << "Koordinat Sekarang : " << "(" << pacman[0] << ", " << pacman[1] << ")";
    // cout << endl;
  }
}

int main()
{
  createMap(status);
  control();
}

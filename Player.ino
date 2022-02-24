/*
   Player CLASS
   Author @squareoctopus
*/
class Player {
  private:
    byte x;
    byte y;

    byte currDirection = LEFT_DIRECTION;
    byte currBullet = 0;

    Bullet _bullet[4]; // Creates a pool of bullets to recycle

    void getInput() {
      if (arduboy.pressed(RIGHT_BUTTON)) {
        x++;
        currDirection = RIGHT_DIRECTION;
      } else if (arduboy.pressed(LEFT_BUTTON)) {
        x--;
        currDirection = LEFT_DIRECTION;
      }

      if (arduboy.pressed(DOWN_BUTTON)) {
        y++;
        currDirection = DOWN_DIRECTION;
      } else if (arduboy.pressed(UP_BUTTON)) {
        y--;
        currDirection = UP_DIRECTION;
      }

      if (arduboy.justPressed(A_BUTTON)) {
        shoot();
      }
    }

    void shoot() {
      _bullet[currBullet].resurrect(x, y, currDirection);
      currBullet++;
      if (currBullet > 3) {
        currBullet = 0;
      }
    }

    void checkBounds() {
      if (x < 1) {
        x = 1;
      } else if (x > WIDTH - 2) {
        x = WIDTH - 2;
      }

      if (y < 1) {
        y = 1;
      } else if (y > HEIGHT - 2) {
        y = HEIGHT - 2;
      }
    }

    
  public:
    Player() {} // Default constructor

    Player(byte x, byte y) {
      this->x = x;
      this->y = y;
    }

    byte getX() {
      return x;
    }

    byte getY() {
      return y;
    }

    // Loop
    void update() {

      getInput();
      checkBounds();

      // Find a better way to deal with the rendering of objects
      _bullet[0].update();
      _bullet[1].update();
      _bullet[2].update();
      _bullet[3].update();

      arduboy.drawRect(x, y, 2, 2, 1);

    }
};

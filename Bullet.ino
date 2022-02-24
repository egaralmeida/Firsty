/*
   Bullet CLASS
   Author @squareoctopus
*/
class Bullet {
 
  private:
    byte x;
    byte y;
    bool alive;

    byte direction = LEFT_DIRECTION;
    
    // Put all movement code here, it will be called on update()
    void calculateMovement() {
      if (direction == UP_DIRECTION) {
        y-=3;
      } else if (direction == DOWN_DIRECTION) {
        y+=3;
      } else if (direction == LEFT_DIRECTION) {
        x-=3;
      } else {
        x+=3;
      }
    }
    void checkBounds() {
      if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
        kill();
      }
    }

  public:
    // Default constructor, just "kills" the object. Combine with resurrect(..) for recycling
    Bullet() {
      kill();
    }

    // Secondary constructor, makes the bullet act immediately.
    Bullet(byte x, byte y, byte direction) {
      resurrect(x, y, direction);
    }

    byte getX() {
      return x;
    }

    byte getY() {
      return y;
    }

    void kill() {
      alive = false;
    }

    // Resets the actor and makes it play. Intended to be used after construction or after kill.
    void resurrect(byte x, byte y, byte direction) {
      this->x = x;
      this->y = y;
      this->direction = direction;

      alive = true;
    }

    // Loop
    void update() {

      // Only does something if alive
      if (!alive) {
        return;
      }

      calculateMovement();
      checkBounds();
      arduboy.drawRect(x, y, 1, 1, 1); // TODO create draw() for this.

    }
};

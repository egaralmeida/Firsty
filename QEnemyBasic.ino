/*
   Basic Enemy CLASS
   Author @squareoctopus
*/
class EnemyBasic {
  private:
    byte x;
    byte y;
    bool alive;

    Player _player;

    // Put all movement code here, it will be called on update()
    void calculateMovement() {
     /* byte deltaX = x - _player.x;
      byte deltaY = y - _player.y;

      x -= deltaX;
      y -= deltaY;*/
    }
    
    void checkBounds() {
      if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
        kill();
      }
    }

  public:
    // Default constructor, just "kills" the object. Combine with resurrect(..) for recycling
    EnemyBasic() {
      kill();
    }

    // Secondary constructor, makes the enemy act immediately.
    EnemyBasic(byte x, byte y, Player _player) {
      resurrect(x, y, _player);
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
    void resurrect(byte x, byte y, Player _player) {
      this->x = x;
      this->y = y;
      this->_player = _player;
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

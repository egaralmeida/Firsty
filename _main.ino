/*
   Main
   Author @squareoctopus
*/

byte x = WIDTH / 2;
byte y = HEIGHT / 2;

Player _player = Player(x, y);
EnemyBasic _enemy[1] = EnemyBasic(WIDTH, HEIGHT, _player);

void setup() {
  // Initiate arduboy instance
  arduboy.begin();

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  arduboy.setFrameRate(30);
}

void loop() {

  if (!arduboy.nextFrame()) {
    return;
  }

  arduboy.clear();
  
  arduboy.pollButtons();
  
  _player.update();
  _enemy[0].update();

  arduboy.display();
}

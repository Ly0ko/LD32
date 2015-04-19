package;

import flixel.FlxG;
import flixel.FlxSprite;

class Blue extends FlxSprite
{
  public function new(X:Float, Y:Float)
  {
    super(X, Y);

    loadGraphic("assets/images/blue.png", 32, 32);
  }
}

package;

import flixel.FlxG;
import flixel.FlxSprite;

class Green extends FlxSprite
{
  public function new(X:Float, Y:Float)
  {
    super(X, Y);

    loadGraphic("assets/images/green.png", 32, 32);
  }
}

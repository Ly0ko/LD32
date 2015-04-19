package;

import flixel.FlxG;
import flixel.FlxSprite;

class Red extends FlxSprite
{
  public function new(X:Float, Y:Float)
  {
    super(X, Y);

    loadGraphic("assets/images/red.png", true, 32, 32);
    animation.add("float", [0, 1], 3, true);
  }

  override public function update()
  {
    animation.play("float");

    super.update();
  }
}

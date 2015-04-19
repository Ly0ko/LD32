package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.util.FlxColor;

class Bullet extends FlxSprite
{
  public var _velocity = 500;

  public function new(X:Float, Y:Float, bColor:Int)
  {
    super(X, Y);

    makeGraphic(4, 2, bColor);

    velocity.x = _velocity;
  }

  override public function update()
  {
    super.update();
  }

  override public function destroy()
  {
    super.destroy();
  }
}

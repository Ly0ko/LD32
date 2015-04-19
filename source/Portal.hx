package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.system.FlxSound;

class Portal extends FlxSprite
{
  public var _active:Bool;
  public var finished:Bool;

  public var _portalSound:FlxSound;

  public function new(X:Float, Y:Float)
  {
    super(X, Y);

    loadGraphic("assets/images/portal.png", 16, 16);

    animation.add("idle", [0]);
    animation.add("active", [0, 1, 2, 3], 3, true);

    _portalSound = FlxG.sound.load("assets/sounds/portal.wav", 0.4);

    _active = false;
  }

  override public function update()
  {
    if (_active && !finished) animation.play("active");
    else animation.play("idle");

    super.update();
  }

  override public function destroy()
  {
    super.destroy();
  }
}

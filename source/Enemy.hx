package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.tile.FlxTilemap;
import flixel.util.FlxColor;
import flixel.util.FlxPoint;

class Enemy extends FlxSprite
{
  private var _moveSpeed:Int = 100;
  private var _gravity:Int = 1200;
  private var _maxFallSpeed:Int = 800;

  public var eColor:Int;
  public var _health = 10;

  public var patrolling:Bool;

  public function new(X:Float, Y:Float, _color:Int)
  {
    super(X, Y);

    loadGraphic("assets/images/enemy.png", 16, 32);
    animation.add("idle", [0]);
    animation.add("moving", [0, 1, 2], 10, true);

    setFacingFlip(FlxObject.LEFT, true, false);
    setFacingFlip(FlxObject.RIGHT, false, false);

    facing = FlxObject.LEFT;

    health = _health;

    eColor = _color;
    color = _color;

    maxVelocity.y = _maxFallSpeed;
    acceleration.y = _gravity;

    patrolling = true;
  }

  override public function update():Void
  {
    if (patrolling) patrol();
    attack();
    animate();

    if (y > FlxG.height) kill();

    super.update();
  }

  override public function destroy():Void
  {
    super.destroy();
  }

  public function animate():Void
  {
    if (velocity.x == 0) animation.play("idle");
    else animation.play("moving");
  }

  public function attack():Void
  {
    if (x + 126 >= Reg.state.player.x && x <= Reg.state.player.x) {
      patrolling = false;
      facing = FlxObject.RIGHT;
      velocity.x = _moveSpeed + 130;
    } else if (x - 126 <= Reg.state.player.x && x >= Reg.state.player.x) {
      patrolling = false;
      facing = FlxObject.LEFT;
      velocity.x = -(_moveSpeed + 130);
    } else {
      patrolling = true;
    }
  }

  public function patrol():Void
  {
    if (facing == FlxObject.RIGHT) {
      velocity.x = _moveSpeed;
      if (justTouched(FlxObject.RIGHT)) {
        facing = FlxObject.LEFT;
        velocity.x = -_moveSpeed;
      }
    } else {
      velocity.x = -_moveSpeed;
      if (justTouched(FlxObject.LEFT)) {
        facing = FlxObject.RIGHT;
        velocity.x = _moveSpeed;
      }
    }
  }

}

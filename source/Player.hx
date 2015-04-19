package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.system.FlxSound;
import flixel.group.FlxGroup;
import flixel.util.FlxColor;
import flixel.util.FlxMath;
import flixel.tweens.FlxEase;
import flixel.tweens.FlxTween;
import flixel.util.FlxTimer;

class Player extends FlxSprite
{
  private var _maxSpeed:Int = 300;
  private var _maxAcceleration:Int = 1600;
  private var _drag:Int = 1000;
  private var _gravity:Int = 1200;
  private var _maxFallSpeed:Int = 800;
  private var _jumpForce:Int = 500;

  public var hasRed:Bool = false;

  public var bullets:FlxGroup;
  public var bullet:Bullet;
  private var bulletDelay:Int;

  public var bColor:Int;
  private var colors:Array<Int>;

  public var _shootSound:FlxSound;
  public var _deathSound:FlxSound;

  public function new(X:Float, Y:Float)
  {
    super(X, Y);

    loadGraphic("assets/images/player.png", 16, 32);
    animation.add("idle", [0]);
    animation.add("jumping", [8]);
    animation.add("walking", [0, 1, 2, 3, 4, 5, 6, 7], 20, true);

    setFacingFlip(FlxObject.LEFT, true, false);
    setFacingFlip(FlxObject.RIGHT, false, false);

    _shootSound = FlxG.sound.load("assets/sounds/shoot.wav", 0.4);
    _deathSound = FlxG.sound.load("assets/sounds/death.wav", 0.4);

    maxVelocity.y = _maxFallSpeed;
    acceleration.y = _gravity;
    drag.x = _drag;

    bullets = new FlxGroup();
    bulletDelay = 5;

    colors = new Array<Int>();
    colors[0] = FlxColor.RED;
    colors[1] = FlxColor.GREEN;
    colors[2] = FlxColor.BLUE;

    bColor = colors[0];
  }

  override public function update()
  {
    controls();
    animate();

    if (y > FlxG.height) y = Reg.state.currentLevel.fullHeight - 64;

    super.update();
  }

  override public function destroy()
  {
    super.destroy();
  }

  override public function kill():Void
	{
		alive = false;
    _deathSound.setPosition(x, y);
    _deathSound.play(true);
		scale.set(1.5, 1.5);
		FlxTween.tween(scale, { x:1, y:1 }, 0.5, { ease:FlxEase.elasticOut, complete:finishKill });
		acceleration.y = 1200;
		velocity.y = -200;
		allowCollisions = FlxObject.NONE;
		new FlxTimer(1, Reg.state.gameOver);
	}

	function finishKill(_):Void
	{
		exists = false;
	}

  public function controls():Void
  {
    var xForce:Float = 0;
    var jumping:Bool = false;

    if (FlxG.keys.pressed.LEFT) {
      xForce--;
      facing = FlxObject.LEFT;
    }
    if (FlxG.keys.pressed.RIGHT) {
      xForce++;
      facing = FlxObject.RIGHT;
    }

    if (FlxG.keys.justPressed.SPACE) jumping = true;
    if (FlxG.keys.justReleased.SPACE) velocity.y = velocity.y * 0.5;

    xForce = FlxMath.bound(xForce, -1, 1);

    maxVelocity.x = _maxSpeed;
    acceleration.x = xForce * _maxAcceleration;

    if (jumping && isTouching(FlxObject.FLOOR)) {
      var finalJumpForce:Float = -(_jumpForce + Math.abs(velocity.x * 0.25));
      velocity.y = finalJumpForce;
    }

    bulletDelay--;

    if (FlxG.keys.justPressed.A && bulletDelay < 0) {
      if (facing == FlxObject.LEFT) {
        bullet = new Bullet(x + width / 2 - 8, y + height / 2 - 2, bColor);
        bullet.velocity.x = -bullet._velocity;
        bullets.add(bullet);
      } else {
        bullet = new Bullet(x + width / 2 + 7, y + height / 2 - 2, bColor);
        bullets.add(bullet);
      }

      _shootSound.setPosition(x, y);
			_shootSound.play(true);
    }

    if (FlxG.keys.justPressed.S) switchBulletColor();
  }

  public function animate():Void
  {
    if (velocity.x == 0 && isTouching(FlxObject.FLOOR)) animation.play("idle");
    else if(!isTouching(FlxObject.FLOOR)) animation.play("jumping");
    else animation.play("walking");
  }

  public function switchBulletColor():Void
  {
    if (bColor == colors[0]) bColor = colors[1];
    else if (bColor == colors[1]) bColor = colors[2];
    else if (bColor == colors[2]) bColor = colors[0];
  }
}

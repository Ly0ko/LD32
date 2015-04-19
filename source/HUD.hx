package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.ui.FlxBar;
import flixel.util.FlxColor;

class HUD extends FlxSpriteGroup
{
  private var healthDisplay:FlxText;
  private var levelDisplay:FlxText;
  private var ammo:FlxSprite;
  private var player:Player;

  public var hp:Int;
  public var maxHp:Int;
  public var level:Int;

  public function new(_player:Player)
  {
    super();

    scrollFactor.x = 0;
    scrollFactor.y = 0;

    player = _player;

    healthDisplay = new FlxText(2, 2);
    healthDisplay.size = 10;
    hp = 100;
    maxHp = 100;
    add(healthDisplay);

    levelDisplay = new FlxText(2, 12);
    levelDisplay.size = 10;
    level = 1;
    add(levelDisplay);

    if (player.bColor == FlxColor.RED) {
      remove(ammo);
      ammo = new Red(2, 15);
      add(ammo);
    } else if (player.bColor == FlxColor.GREEN) {
      remove(ammo);
      ammo = new Green(2, 15);
      add(ammo);
    } else if (player.bColor == FlxColor.BLUE) {
      remove(ammo);
      ammo = new Blue(2, 15);
      add(ammo);
    }
  }

  override public function update()
  {
    healthDisplay.text = "Health: " + hp + "/" + maxHp;
    levelDisplay.text = "Level " + level;

    if (player.bColor == FlxColor.RED) {
      remove(ammo);
      ammo = new Red(2, 15);
      add(ammo);
    } else if (player.bColor == FlxColor.GREEN) {
      remove(ammo);
      ammo = new Green(2, 15);
      add(ammo);
    } else if (player.bColor == FlxColor.BLUE) {
      remove(ammo);
      ammo = new Blue(2, 15);
      add(ammo);
    }
  }

  public function addHealth(num:Int):Void
  {
    hp += num;
    if (hp > maxHp) hp = maxHp;
    if (hp <= 0) FlxG.switchState(new MenuState());
  }
}

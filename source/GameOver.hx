package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxSpriteUtil;

class GameOver extends FlxState
{
  override public function create():Void
	{
		super.create();

		var gameOver:FlxText = new FlxText(0, 0, 0, "GAME OVER");
    gameOver.scrollFactor.set(0, 0);
		gameOver.size = 12;
		FlxSpriteUtil.screenCenter(gameOver);
		add(gameOver);

    var restart:FlxText = new FlxText(0, gameOver.y + 30, 0, "Press any key to restart.");
    restart.size = 12;
    FlxSpriteUtil.screenCenter(restart, true, false);
    add(restart);
	}

	override public function destroy():Void
	{
		super.destroy();
	}

	override public function update():Void
	{
		super.update();

		if (FlxG.keys.justPressed.ANY) FlxG.switchState(new PlayState());
	}
}

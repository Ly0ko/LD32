package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxSpriteUtil;

class MenuState extends FlxState
{

	override public function create():Void
	{
		super.create();

		var startGame:FlxText = new FlxText(0, 0, 0, "Press 'Space' to start.");
		startGame.size = 12;
		FlxSpriteUtil.screenCenter(startGame);
		add(startGame);
	}

	override public function destroy():Void
	{
		super.destroy();
	}

	override public function update():Void
	{
		super.update();

		if (FlxG.keys.pressed.SPACE) FlxG.switchState(new PlayState());
	}
}

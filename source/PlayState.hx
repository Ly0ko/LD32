package;

import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.FlxCamera;
import flixel.text.FlxText;
import flixel.ui.FlxButton;
import flixel.group.FlxGroup;
import flixel.util.FlxMath;
import flixel.util.FlxSpriteUtil;
import flixel.util.FlxTimer;
import flixel.util.FlxColor;

class PlayState extends FlxState
{
	public var level1:LevelLoader;
	public var player:Player;
	public var enemies:FlxGroup;
	public var portal:Portal;
	public var hud:HUD;
	public var currentLevel:LevelLoader;

	public var timer:FlxTimer;
	public var timerText:FlxText;
	public var enemiesLeft:Int;
	public var enemiesLeftText:FlxText;

	public var won:Bool = false;

	override public function create():Void
	{
		super.create();

		FlxG.mouse.visible = false;

		FlxG.camera.bgColor = 0xFF545454;

		Reg.state = this;

		level1 = new LevelLoader("assets/data/level1.tmx");
		currentLevel = level1;
		add(level1.foregroundTiles);

		player = new Player(64, currentLevel.fullHeight - 64);
		add(player);

		add(player.bullets);

		enemies = new FlxGroup();

		addEnemies();

		FlxG.camera.follow(player, FlxCamera.STYLE_PLATFORMER);

		portal = new Portal(1513, 368);
		add(portal);

		hud = new HUD(player);
		add(hud);

		timerText = new FlxText(FlxG.width / 2, 100);
		timerText.size = 12;
		timerText.scrollFactor.x = 0;
		add(timerText);

		enemiesLeftText = new FlxText(FlxG.width / 2, 100);
		enemiesLeftText.text = "";
		enemiesLeftText.size = 12;
		enemiesLeftText.scrollFactor.x = 0;
		add(enemiesLeftText);

		enemiesLeft = enemies.length;
	}

	override public function destroy():Void
	{
		super.destroy();
	}

	override public function update():Void
	{
		FlxG.collide(player, currentLevel.foregroundTiles);
		FlxG.collide(player.bullets, currentLevel.foregroundTiles, bulletHitMap);
		FlxG.collide(enemies, currentLevel.foregroundTiles);
		FlxG.collide(player.bullets, enemies, bulletHitEnemy);
		FlxG.collide(player, enemies, enemyHitPlayer);
		FlxG.overlap(player, portal, playerOverlapPortal);

		if (timer != null) {
			timerText.text = "" + timer.timeLeft;

			if (timer.finished) {
				remove(timerText);
				portal._active = false;
				portal.finished = true;
			}
		}

		if (portal.finished) {
			enemiesLeftText.text = "Enemies left: " + enemiesLeft;
		}

		if (won && FlxG.keys.justPressed.ENTER) FlxG.switchState(new PlayState());

		super.update();
	}

	public function bulletHitMap(bulletRef:FlxObject, levelRef:FlxObject):Void
	{
		player.bullets.remove(bulletRef);
	}

	public function bulletHitEnemy(bulletRef:FlxObject, enemyRef:Enemy):Void
	{
		player.bullets.remove(bulletRef);

		if (player.bColor == enemyRef.eColor) {
			enemyRef.health -= 2;
		}

		if (enemyRef.health <= 0) {
			enemyRef.kill();
			enemiesLeft--;

			enemies.remove(enemyRef, true);

			if (portal.finished) {
				if (enemiesLeft == 0) {
					gameWin();
				}
			}
		}
	}

	public function enemyHitPlayer(playerRef:Player, enemyRef:FlxObject):Void
	{
		hud.hp -= 1;

		if (hud.hp == 0) playerRef.kill();
	}

	public function playerOverlapPortal(playerRef:Player, portalRef:Portal):Void
	{
		if (!portalRef._active && !portalRef.finished) {
			portalRef._active = true;

			new FlxTimer(20, addEnemies, 3);
			timer = new FlxTimer(60);

			portalRef._portalSound.setPosition(playerRef.x, playerRef.y);
			portalRef._portalSound.play(true);
		}
	}

	public function addEnemies(?t:FlxTimer):Void
	{
		if (timer != null) {
			enemies.add(new Enemy(384, 288, FlxColor.RED));
			enemies.add(new Enemy(832, 416, FlxColor.GREEN));
			enemies.add(new Enemy(1120, 416, FlxColor.BLUE));
			enemies.add(new Enemy(2016, 192, FlxColor.GREEN));
			enemies.add(new Enemy(2272, 416, FlxColor.BLUE));
			enemies.add(new Enemy(2880, 416, FlxColor.BLUE));
			enemies.add(new Enemy(3072, 192, FlxColor.GREEN));
			enemiesLeft = enemiesLeft + 7;
		} else {
			enemies.add(new Enemy(384, 288, FlxColor.RED));
			enemies.add(new Enemy(832, 416, FlxColor.GREEN));
			enemies.add(new Enemy(544, 416, FlxColor.BLUE));
			enemies.add(new Enemy(1120, 416, FlxColor.BLUE));
			enemies.add(new Enemy(1472, 352, FlxColor.RED));
			enemies.add(new Enemy(2016, 192, FlxColor.GREEN));
			enemies.add(new Enemy(2144, 64, FlxColor.RED));
			enemies.add(new Enemy(2272, 416, FlxColor.BLUE));
			enemies.add(new Enemy(2624, 320, FlxColor.RED));
			enemies.add(new Enemy(2880, 416, FlxColor.BLUE));
			enemies.add(new Enemy(3072, 192, FlxColor.GREEN));
		}

		add(enemies);
	}

	public function gameOver(?t:FlxTimer):Void
	{
		FlxG.switchState(new GameOver());
	}

	public function gameWin():Void
	{
		remove(enemiesLeftText);

		won = true;

		var winText = new FlxText(0, 0, 0, "You won!");
		winText.scrollFactor.x = 0;
		winText.size = 12;
		FlxSpriteUtil.screenCenter(winText);
		add(winText);

		var restart:FlxText = new FlxText(0, winText.y + 30, 0, "Press 'ENTER' to play again.");
		restart.scrollFactor.x = 0;
		restart.size = 12;
		FlxSpriteUtil.screenCenter(restart, true, false);
		add(restart);
	}
}

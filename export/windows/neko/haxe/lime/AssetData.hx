package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("assets/data/data-goes-here.txt", "assets/data/data-goes-here.txt");
			type.set ("assets/data/data-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/level1.tmx", "assets/data/level1.tmx");
			type.set ("assets/data/level1.tmx", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/test.tmx", "assets/data/test.tmx");
			type.set ("assets/data/test.tmx", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/data/tilesheet.png", "assets/data/tilesheet.png");
			type.set ("assets/data/tilesheet.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/blue.png", "assets/images/blue.png");
			type.set ("assets/images/blue.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/enemy.png", "assets/images/enemy.png");
			type.set ("assets/images/enemy.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/green.png", "assets/images/green.png");
			type.set ("assets/images/green.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/images-go-here.txt", "assets/images/images-go-here.txt");
			type.set ("assets/images/images-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/images/player.png", "assets/images/player.png");
			type.set ("assets/images/player.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/portal.png", "assets/images/portal.png");
			type.set ("assets/images/portal.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/red.png", "assets/images/red.png");
			type.set ("assets/images/red.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/images/tilesheet.png", "assets/images/tilesheet.png");
			type.set ("assets/images/tilesheet.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/music/music-goes-here.txt", "assets/music/music-goes-here.txt");
			type.set ("assets/music/music-goes-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/death.wav", "assets/sounds/death.wav");
			type.set ("assets/sounds/death.wav", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/portal.wav", "assets/sounds/portal.wav");
			type.set ("assets/sounds/portal.wav", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/shoot.wav", "assets/sounds/shoot.wav");
			type.set ("assets/sounds/shoot.wav", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/sounds-go-here.txt", "assets/sounds/sounds-go-here.txt");
			type.set ("assets/sounds/sounds-go-here.txt", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("assets/sounds/beep.ogg", "assets/sounds/beep.ogg");
			type.set ("assets/sounds/beep.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			path.set ("assets/sounds/flixel.ogg", "assets/sounds/flixel.ogg");
			type.set ("assets/sounds/flixel.ogg", Reflect.field (AssetType, "sound".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData

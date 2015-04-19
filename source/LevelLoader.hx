package;

import openfl.Assets;
import haxe.io.Path;
import haxe.xml.Parser;
import flixel.FlxG;
import flixel.FlxObject;
import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import flixel.addons.editors.tiled.TiledMap;
import flixel.addons.editors.tiled.TiledObject;
import flixel.addons.editors.tiled.TiledObjectGroup;
import flixel.addons.editors.tiled.TiledTileSet;

class LevelLoader extends TiledMap
{
  private inline static var c_PATH_LEVEL_TILESHEETS = "assets/images/";

  public var foregroundTiles:FlxGroup;
  public var backgroundTiles:FlxGroup;
  private var collidableTileLayers:Array<FlxTilemap>;

  public function new(level:Dynamic)
  {
    super(level);

    foregroundTiles = new FlxGroup();
    backgroundTiles = new FlxGroup();

    FlxG.camera.setBounds(0, 0, fullWidth, fullHeight, true);

    for (tileLayer in layers)
    {
      var tileSheetName:String = tileLayer.properties.get("tileset");

      if (tileSheetName == null)
        throw "'tileset' property not defined for the '" + tileLayer.name + "' layer.";

      var tileSet:TiledTileSet = null;
      for (ts in tilesets)
      {
        if (ts.name == tileSheetName)
        {
          tileSet = ts;
          break;
        }
      }

      if (tileSet == null)
        throw "Tileset '" + tileSheetName + "' not found. Did you mispell the 'tilesheet' property?";

      var imagePath = new Path(tileSet.imageSource);
      var processedPath = c_PATH_LEVEL_TILESHEETS + imagePath.file + "." + imagePath.ext;

      var tilemap:FlxTilemap = new FlxTilemap();
      tilemap.widthInTiles = width;
      tilemap.heightInTiles = height;
      tilemap.loadMap(tileLayer.tileArray, processedPath, tileSet.tileWidth, tileSet.tileHeight, 0, 1, 1, 1);

      if (tileLayer.properties.contains("nocollide"))
      {
        backgroundTiles.add(tilemap);
      } else {
        if (collidableTileLayers == null)
          collidableTileLayers = new Array<FlxTilemap>();

        foregroundTiles.add(tilemap);
        collidableTileLayers.push(tilemap);
      }
    }
  }

}

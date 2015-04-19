#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_LevelLoader
#include <LevelLoader.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledLayer
#include <flixel/addons/editors/tiled/TiledLayer.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledMap
#include <flixel/addons/editors/tiled/TiledMap.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledPropertySet
#include <flixel/addons/editors/tiled/TiledPropertySet.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledTileSet
#include <flixel/addons/editors/tiled/TiledTileSet.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif

Void LevelLoader_obj::__construct(Dynamic level)
{
HX_STACK_FRAME("LevelLoader","new",0x19e79d09,"LevelLoader.new","LevelLoader.hx",25,0x32a09687)
HX_STACK_THIS(this)
HX_STACK_ARG(level,"level")
{
	HX_STACK_LINE(26)
	super::__construct(level);
	HX_STACK_LINE(28)
	::flixel::group::FlxGroup _g = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	this->foregroundTiles = _g;
	HX_STACK_LINE(29)
	::flixel::group::FlxGroup _g1 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(29)
	this->backgroundTiles = _g1;
	HX_STACK_LINE(31)
	::flixel::FlxG_obj::camera->setBounds((int)0,(int)0,this->fullWidth,this->fullHeight,true);
	HX_STACK_LINE(33)
	{
		HX_STACK_LINE(33)
		int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(33)
		Array< ::Dynamic > _g11 = this->layers;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(33)
		while((true)){
			HX_STACK_LINE(33)
			if ((!(((_g2 < _g11->length))))){
				HX_STACK_LINE(33)
				break;
			}
			HX_STACK_LINE(33)
			::flixel::addons::editors::tiled::TiledLayer tileLayer = _g11->__get(_g2).StaticCast< ::flixel::addons::editors::tiled::TiledLayer >();		HX_STACK_VAR(tileLayer,"tileLayer");
			HX_STACK_LINE(33)
			++(_g2);
			HX_STACK_LINE(35)
			::String tileSheetName = tileLayer->properties->keys->get(HX_CSTRING("tileset"));		HX_STACK_VAR(tileSheetName,"tileSheetName");
			HX_STACK_LINE(37)
			if (((tileSheetName == null()))){
				HX_STACK_LINE(38)
				HX_STACK_DO_THROW(((HX_CSTRING("'tileset' property not defined for the '") + tileLayer->name) + HX_CSTRING("' layer.")));
			}
			HX_STACK_LINE(40)
			::flixel::addons::editors::tiled::TiledTileSet tileSet = null();		HX_STACK_VAR(tileSet,"tileSet");
			HX_STACK_LINE(41)
			for(::cpp::FastIterator_obj< ::flixel::addons::editors::tiled::TiledTileSet > *__it = ::cpp::CreateFastIterator< ::flixel::addons::editors::tiled::TiledTileSet >(this->tilesets->iterator());  __it->hasNext(); ){
				::flixel::addons::editors::tiled::TiledTileSet ts = __it->next();
				if (((ts->name == tileSheetName))){
					HX_STACK_LINE(45)
					tileSet = ts;
					HX_STACK_LINE(46)
					break;
				}
;
			}
			HX_STACK_LINE(50)
			if (((tileSet == null()))){
				HX_STACK_LINE(51)
				HX_STACK_DO_THROW(((HX_CSTRING("Tileset '") + tileSheetName) + HX_CSTRING("' not found. Did you mispell the 'tilesheet' property?")));
			}
			HX_STACK_LINE(53)
			::haxe::io::Path imagePath = ::haxe::io::Path_obj::__new(tileSet->imageSource);		HX_STACK_VAR(imagePath,"imagePath");
			HX_STACK_LINE(54)
			::String processedPath = (((HX_CSTRING("assets/images/") + imagePath->file) + HX_CSTRING(".")) + imagePath->ext);		HX_STACK_VAR(processedPath,"processedPath");
			HX_STACK_LINE(56)
			::flixel::tile::FlxTilemap tilemap = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(tilemap,"tilemap");
			HX_STACK_LINE(57)
			tilemap->widthInTiles = this->width;
			HX_STACK_LINE(58)
			tilemap->heightInTiles = this->height;
			HX_STACK_LINE(59)
			Array< int > _g21 = tileLayer->get_tileArray();		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(59)
			tilemap->loadMap(_g21,processedPath,tileSet->tileWidth,tileSet->tileHeight,(int)0,(int)1,(int)1,(int)1);
			HX_STACK_LINE(61)
			if ((tileLayer->properties->keys->exists(HX_CSTRING("nocollide")))){
				HX_STACK_LINE(63)
				this->backgroundTiles->add(tilemap);
			}
			else{
				HX_STACK_LINE(65)
				if (((this->collidableTileLayers == null()))){
					HX_STACK_LINE(66)
					Array< ::Dynamic > _g3 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(66)
					this->collidableTileLayers = _g3;
				}
				HX_STACK_LINE(68)
				this->foregroundTiles->add(tilemap);
				HX_STACK_LINE(69)
				this->collidableTileLayers->push(tilemap);
			}
		}
	}
}
;
	return null();
}

//LevelLoader_obj::~LevelLoader_obj() { }

Dynamic LevelLoader_obj::__CreateEmpty() { return  new LevelLoader_obj; }
hx::ObjectPtr< LevelLoader_obj > LevelLoader_obj::__new(Dynamic level)
{  hx::ObjectPtr< LevelLoader_obj > result = new LevelLoader_obj();
	result->__construct(level);
	return result;}

Dynamic LevelLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LevelLoader_obj > result = new LevelLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

::String LevelLoader_obj::c_PATH_LEVEL_TILESHEETS;


LevelLoader_obj::LevelLoader_obj()
{
}

void LevelLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LevelLoader);
	HX_MARK_MEMBER_NAME(foregroundTiles,"foregroundTiles");
	HX_MARK_MEMBER_NAME(backgroundTiles,"backgroundTiles");
	HX_MARK_MEMBER_NAME(collidableTileLayers,"collidableTileLayers");
	::flixel::addons::editors::tiled::TiledMap_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LevelLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(foregroundTiles,"foregroundTiles");
	HX_VISIT_MEMBER_NAME(backgroundTiles,"backgroundTiles");
	HX_VISIT_MEMBER_NAME(collidableTileLayers,"collidableTileLayers");
	::flixel::addons::editors::tiled::TiledMap_obj::__Visit(HX_VISIT_ARG);
}

Dynamic LevelLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"foregroundTiles") ) { return foregroundTiles; }
		if (HX_FIELD_EQ(inName,"backgroundTiles") ) { return backgroundTiles; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"collidableTileLayers") ) { return collidableTileLayers; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LevelLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 15:
		if (HX_FIELD_EQ(inName,"foregroundTiles") ) { foregroundTiles=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		if (HX_FIELD_EQ(inName,"backgroundTiles") ) { backgroundTiles=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"collidableTileLayers") ) { collidableTileLayers=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LevelLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("foregroundTiles"));
	outFields->push(HX_CSTRING("backgroundTiles"));
	outFields->push(HX_CSTRING("collidableTileLayers"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("c_PATH_LEVEL_TILESHEETS"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(LevelLoader_obj,foregroundTiles),HX_CSTRING("foregroundTiles")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(LevelLoader_obj,backgroundTiles),HX_CSTRING("backgroundTiles")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(LevelLoader_obj,collidableTileLayers),HX_CSTRING("collidableTileLayers")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("foregroundTiles"),
	HX_CSTRING("backgroundTiles"),
	HX_CSTRING("collidableTileLayers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LevelLoader_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(LevelLoader_obj::c_PATH_LEVEL_TILESHEETS,"c_PATH_LEVEL_TILESHEETS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LevelLoader_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(LevelLoader_obj::c_PATH_LEVEL_TILESHEETS,"c_PATH_LEVEL_TILESHEETS");
};

#endif

Class LevelLoader_obj::__mClass;

void LevelLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("LevelLoader"), hx::TCanCast< LevelLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void LevelLoader_obj::__boot()
{
	c_PATH_LEVEL_TILESHEETS= HX_CSTRING("assets/images/");
}


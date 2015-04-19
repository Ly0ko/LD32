#ifndef INCLUDED_TestLevel
#define INCLUDED_TestLevel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/addons/editors/tiled/TiledMap.h>
HX_DECLARE_CLASS0(TestLevel)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS4(flixel,addons,editors,tiled,TiledMap)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)


class HXCPP_CLASS_ATTRIBUTES  TestLevel_obj : public ::flixel::addons::editors::tiled::TiledMap_obj{
	public:
		typedef ::flixel::addons::editors::tiled::TiledMap_obj super;
		typedef TestLevel_obj OBJ_;
		TestLevel_obj();
		Void __construct(Dynamic level);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TestLevel_obj > __new(Dynamic level);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TestLevel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TestLevel"); }

		::flixel::group::FlxGroup foregroundTiles;
		::flixel::group::FlxGroup backgroundTiles;
		Array< ::Dynamic > collidableTileLayers;
		static ::String c_PATH_LEVEL_TILESHEETS;
};


#endif /* INCLUDED_TestLevel */ 

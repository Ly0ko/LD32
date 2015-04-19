#ifndef INCLUDED_HUD
#define INCLUDED_HUD

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/group/FlxSpriteGroup.h>
HX_DECLARE_CLASS0(HUD)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxSpriteGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)


class HXCPP_CLASS_ATTRIBUTES  HUD_obj : public ::flixel::group::FlxSpriteGroup_obj{
	public:
		typedef ::flixel::group::FlxSpriteGroup_obj super;
		typedef HUD_obj OBJ_;
		HUD_obj();
		Void __construct(::Player _player);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HUD_obj > __new(::Player _player);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HUD_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HUD"); }

		::flixel::text::FlxText healthDisplay;
		::flixel::text::FlxText levelDisplay;
		::flixel::FlxSprite ammo;
		::Player player;
		int hp;
		int maxHp;
		int level;
		virtual Void update( );

		virtual Void addHealth( int num);
		Dynamic addHealth_dyn();

};


#endif /* INCLUDED_HUD */ 

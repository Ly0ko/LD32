#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS0(HUD)
HX_DECLARE_CLASS0(LevelLoader)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS0(Portal)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS4(flixel,addons,editors,tiled,TiledMap)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxSpriteGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedSpriteGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,util,FlxTimer)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		::LevelLoader level1;
		::Player player;
		::flixel::group::FlxGroup enemies;
		::Portal portal;
		::HUD hud;
		::LevelLoader currentLevel;
		::flixel::util::FlxTimer timer;
		::flixel::text::FlxText timerText;
		int enemiesLeft;
		::flixel::text::FlxText enemiesLeftText;
		bool won;
		virtual Void create( );

		virtual Void destroy( );

		virtual Void update( );

		virtual Void bulletHitMap( ::flixel::FlxObject bulletRef,::flixel::FlxObject levelRef);
		Dynamic bulletHitMap_dyn();

		virtual Void bulletHitEnemy( ::flixel::FlxObject bulletRef,::Enemy enemyRef);
		Dynamic bulletHitEnemy_dyn();

		virtual Void enemyHitPlayer( ::Player playerRef,::flixel::FlxObject enemyRef);
		Dynamic enemyHitPlayer_dyn();

		virtual Void playerOverlapPortal( ::Player playerRef,::Portal portalRef);
		Dynamic playerOverlapPortal_dyn();

		virtual Void addEnemies( ::flixel::util::FlxTimer t);
		Dynamic addEnemies_dyn();

		virtual Void gameOver( ::flixel::util::FlxTimer t);
		Dynamic gameOver_dyn();

		virtual Void gameWin( );
		Dynamic gameWin_dyn();

};


#endif /* INCLUDED_PlayState */ 

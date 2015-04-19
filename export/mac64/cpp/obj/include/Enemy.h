#ifndef INCLUDED_Enemy
#define INCLUDED_Enemy

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Enemy)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)


class HXCPP_CLASS_ATTRIBUTES  Enemy_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Enemy_obj OBJ_;
		Enemy_obj();
		Void __construct(Float X,Float Y,int _color);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Enemy_obj > __new(Float X,Float Y,int _color);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Enemy_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Enemy"); }

		int _moveSpeed;
		int _gravity;
		int _maxFallSpeed;
		int eColor;
		int _health;
		bool patrolling;
		virtual Void update( );

		virtual Void destroy( );

		virtual Void animate( );
		Dynamic animate_dyn();

		virtual Void attack( );
		Dynamic attack_dyn();

		virtual Void patrol( );
		Dynamic patrol_dyn();

};


#endif /* INCLUDED_Enemy */ 

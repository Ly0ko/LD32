#include <hxcpp.h>

#ifndef INCLUDED_GameOver
#include <GameOver.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxGame
#include <flixel/FlxGame.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxInput
#include <flixel/interfaces/IFlxInput.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObject
#include <openfl/_legacy/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_DisplayObjectContainer
#include <openfl/_legacy/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_InteractiveObject
#include <openfl/_legacy/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Sprite
#include <openfl/_legacy/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif

Void GameOver_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("GameOver","new",0x1f3caa78,"GameOver.new","GameOver.hx",11,0x71ca4bf8)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(11)
	super::__construct(MaxSize);
}
;
	return null();
}

//GameOver_obj::~GameOver_obj() { }

Dynamic GameOver_obj::__CreateEmpty() { return  new GameOver_obj; }
hx::ObjectPtr< GameOver_obj > GameOver_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< GameOver_obj > result = new GameOver_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic GameOver_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameOver_obj > result = new GameOver_obj();
	result->__construct(inArgs[0]);
	return result;}

Void GameOver_obj::create( ){
{
		HX_STACK_FRAME("GameOver","create",0xc687ebe4,"GameOver.create","GameOver.hx",14,0x71ca4bf8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(15)
		this->super::create();
		HX_STACK_LINE(17)
		::flixel::text::FlxText gameOver = ::flixel::text::FlxText_obj::__new((int)0,(int)0,(int)0,HX_CSTRING("GAME OVER"),null(),null());		HX_STACK_VAR(gameOver,"gameOver");
		HX_STACK_LINE(18)
		gameOver->scrollFactor->set((int)0,(int)0);
		HX_STACK_LINE(19)
		gameOver->set_size((int)12);
		HX_STACK_LINE(20)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(gameOver,null(),null());
		HX_STACK_LINE(21)
		this->add(gameOver);
		HX_STACK_LINE(23)
		::flixel::text::FlxText restart = ::flixel::text::FlxText_obj::__new((int)0,(gameOver->y + (int)30),(int)0,HX_CSTRING("Press any key to restart."),null(),null());		HX_STACK_VAR(restart,"restart");
		HX_STACK_LINE(24)
		restart->set_size((int)12);
		HX_STACK_LINE(25)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(restart,true,false);
		HX_STACK_LINE(26)
		this->add(restart);
	}
return null();
}


Void GameOver_obj::destroy( ){
{
		HX_STACK_FRAME("GameOver","destroy",0x0381f312,"GameOver.destroy","GameOver.hx",31,0x71ca4bf8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(31)
		this->super::destroy();
	}
return null();
}


Void GameOver_obj::update( ){
{
		HX_STACK_FRAME("GameOver","update",0xd17e0af1,"GameOver.update","GameOver.hx",35,0x71ca4bf8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(36)
		this->super::update();
		HX_STACK_LINE(38)
		if ((::flixel::FlxG_obj::keys->justPressed->get_ANY())){
			HX_STACK_LINE(38)
			::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(38)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
	}
return null();
}



GameOver_obj::GameOver_obj()
{
}

Dynamic GameOver_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameOver_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void GameOver_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameOver_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameOver_obj::__mClass,"__mClass");
};

#endif

Class GameOver_obj::__mClass;

void GameOver_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("GameOver"), hx::TCanCast< GameOver_obj> ,sStaticFields,sMemberFields,
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

void GameOver_obj::__boot()
{
}


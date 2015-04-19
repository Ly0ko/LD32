#include <hxcpp.h>

#ifndef INCLUDED_Blue
#include <Blue.h>
#endif
#ifndef INCLUDED_Green
#include <Green.h>
#endif
#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_MenuState
#include <MenuState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Red
#include <Red.h>
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
#ifndef INCLUDED_flixel_group_FlxSpriteGroup
#include <flixel/group/FlxSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedSpriteGroup
#include <flixel/group/FlxTypedSpriteGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
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

Void HUD_obj::__construct(::Player _player)
{
HX_STACK_FRAME("HUD","new",0xf45a2509,"HUD.new","HUD.hx",22,0xe7d70e87)
HX_STACK_THIS(this)
HX_STACK_ARG(_player,"_player")
{
	HX_STACK_LINE(23)
	super::__construct(null(),null(),null());
	HX_STACK_LINE(25)
	this->scrollFactor->set_x((int)0);
	HX_STACK_LINE(26)
	this->scrollFactor->set_y((int)0);
	HX_STACK_LINE(28)
	this->player = _player;
	HX_STACK_LINE(30)
	::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((int)2,(int)2,null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->healthDisplay = _g;
	HX_STACK_LINE(31)
	this->healthDisplay->set_size((int)10);
	HX_STACK_LINE(32)
	this->hp = (int)100;
	HX_STACK_LINE(33)
	this->maxHp = (int)100;
	HX_STACK_LINE(34)
	this->add(this->healthDisplay);
	HX_STACK_LINE(36)
	::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new((int)2,(int)12,null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(36)
	this->levelDisplay = _g1;
	HX_STACK_LINE(37)
	this->levelDisplay->set_size((int)10);
	HX_STACK_LINE(38)
	this->level = (int)1;
	HX_STACK_LINE(39)
	this->add(this->levelDisplay);
	HX_STACK_LINE(41)
	if (((this->player->bColor == (int)-65536))){
		HX_STACK_LINE(42)
		this->remove(this->ammo,null());
		HX_STACK_LINE(43)
		::Red _g2 = ::Red_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(43)
		this->ammo = _g2;
		HX_STACK_LINE(44)
		this->add(this->ammo);
	}
	else{
		HX_STACK_LINE(45)
		if (((this->player->bColor == (int)-16744448))){
			HX_STACK_LINE(46)
			this->remove(this->ammo,null());
			HX_STACK_LINE(47)
			::Green _g3 = ::Green_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(47)
			this->ammo = _g3;
			HX_STACK_LINE(48)
			this->add(this->ammo);
		}
		else{
			HX_STACK_LINE(49)
			if (((this->player->bColor == (int)-16776961))){
				HX_STACK_LINE(50)
				this->remove(this->ammo,null());
				HX_STACK_LINE(51)
				::Blue _g4 = ::Blue_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(51)
				this->ammo = _g4;
				HX_STACK_LINE(52)
				this->add(this->ammo);
			}
		}
	}
}
;
	return null();
}

//HUD_obj::~HUD_obj() { }

Dynamic HUD_obj::__CreateEmpty() { return  new HUD_obj; }
hx::ObjectPtr< HUD_obj > HUD_obj::__new(::Player _player)
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct(_player);
	return result;}

Dynamic HUD_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct(inArgs[0]);
	return result;}

Void HUD_obj::update( ){
{
		HX_STACK_FRAME("HUD","update",0x5060c100,"HUD.update","HUD.hx",57,0xe7d70e87)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->healthDisplay->set_text((((HX_CSTRING("Health: ") + this->hp) + HX_CSTRING("/")) + this->maxHp));
		HX_STACK_LINE(59)
		this->levelDisplay->set_text((HX_CSTRING("Level ") + this->level));
		HX_STACK_LINE(61)
		if (((this->player->bColor == (int)-65536))){
			HX_STACK_LINE(62)
			this->remove(this->ammo,null());
			HX_STACK_LINE(63)
			::Red _g = ::Red_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(63)
			this->ammo = _g;
			HX_STACK_LINE(64)
			this->add(this->ammo);
		}
		else{
			HX_STACK_LINE(65)
			if (((this->player->bColor == (int)-16744448))){
				HX_STACK_LINE(66)
				this->remove(this->ammo,null());
				HX_STACK_LINE(67)
				::Green _g1 = ::Green_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(67)
				this->ammo = _g1;
				HX_STACK_LINE(68)
				this->add(this->ammo);
			}
			else{
				HX_STACK_LINE(69)
				if (((this->player->bColor == (int)-16776961))){
					HX_STACK_LINE(70)
					this->remove(this->ammo,null());
					HX_STACK_LINE(71)
					::Blue _g2 = ::Blue_obj::__new((int)2,(int)15);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(71)
					this->ammo = _g2;
					HX_STACK_LINE(72)
					this->add(this->ammo);
				}
			}
		}
	}
return null();
}


Void HUD_obj::addHealth( int num){
{
		HX_STACK_FRAME("HUD","addHealth",0xf0531706,"HUD.addHealth","HUD.hx",77,0xe7d70e87)
		HX_STACK_THIS(this)
		HX_STACK_ARG(num,"num")
		HX_STACK_LINE(78)
		hx::AddEq(this->hp,num);
		HX_STACK_LINE(79)
		if (((this->hp > this->maxHp))){
			HX_STACK_LINE(79)
			this->hp = this->maxHp;
		}
		HX_STACK_LINE(80)
		if (((this->hp <= (int)0))){
			HX_STACK_LINE(80)
			::flixel::FlxState State = ::MenuState_obj::__new(null());		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(80)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(HUD_obj,addHealth,(void))


HUD_obj::HUD_obj()
{
}

void HUD_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HUD);
	HX_MARK_MEMBER_NAME(healthDisplay,"healthDisplay");
	HX_MARK_MEMBER_NAME(levelDisplay,"levelDisplay");
	HX_MARK_MEMBER_NAME(ammo,"ammo");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(hp,"hp");
	HX_MARK_MEMBER_NAME(maxHp,"maxHp");
	HX_MARK_MEMBER_NAME(level,"level");
	::flixel::group::FlxTypedSpriteGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HUD_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(healthDisplay,"healthDisplay");
	HX_VISIT_MEMBER_NAME(levelDisplay,"levelDisplay");
	HX_VISIT_MEMBER_NAME(ammo,"ammo");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(hp,"hp");
	HX_VISIT_MEMBER_NAME(maxHp,"maxHp");
	HX_VISIT_MEMBER_NAME(level,"level");
	::flixel::group::FlxTypedSpriteGroup_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HUD_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"hp") ) { return hp; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ammo") ) { return ammo; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"maxHp") ) { return maxHp; }
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addHealth") ) { return addHealth_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"levelDisplay") ) { return levelDisplay; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"healthDisplay") ) { return healthDisplay; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HUD_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"hp") ) { hp=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"ammo") ) { ammo=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"maxHp") ) { maxHp=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"levelDisplay") ) { levelDisplay=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"healthDisplay") ) { healthDisplay=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HUD_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("healthDisplay"));
	outFields->push(HX_CSTRING("levelDisplay"));
	outFields->push(HX_CSTRING("ammo"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("hp"));
	outFields->push(HX_CSTRING("maxHp"));
	outFields->push(HX_CSTRING("level"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,healthDisplay),HX_CSTRING("healthDisplay")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,levelDisplay),HX_CSTRING("levelDisplay")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,ammo),HX_CSTRING("ammo")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(HUD_obj,player),HX_CSTRING("player")},
	{hx::fsInt,(int)offsetof(HUD_obj,hp),HX_CSTRING("hp")},
	{hx::fsInt,(int)offsetof(HUD_obj,maxHp),HX_CSTRING("maxHp")},
	{hx::fsInt,(int)offsetof(HUD_obj,level),HX_CSTRING("level")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("healthDisplay"),
	HX_CSTRING("levelDisplay"),
	HX_CSTRING("ammo"),
	HX_CSTRING("player"),
	HX_CSTRING("hp"),
	HX_CSTRING("maxHp"),
	HX_CSTRING("level"),
	HX_CSTRING("update"),
	HX_CSTRING("addHealth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#endif

Class HUD_obj::__mClass;

void HUD_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("HUD"), hx::TCanCast< HUD_obj> ,sStaticFields,sMemberFields,
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

void HUD_obj::__boot()
{
}


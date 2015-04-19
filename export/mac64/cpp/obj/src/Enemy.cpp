#include <hxcpp.h>

#ifndef INCLUDED_Enemy
#include <Enemy.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif

Void Enemy_obj::__construct(Float X,Float Y,int _color)
{
HX_STACK_FRAME("Enemy","new",0x35d4571a,"Enemy.new","Enemy.hx",10,0xbda88996)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
HX_STACK_ARG(_color,"_color")
{
	HX_STACK_LINE(17)
	this->_health = (int)10;
	HX_STACK_LINE(14)
	this->_maxFallSpeed = (int)800;
	HX_STACK_LINE(13)
	this->_gravity = (int)1200;
	HX_STACK_LINE(12)
	this->_moveSpeed = (int)100;
	HX_STACK_LINE(23)
	super::__construct(X,Y,null());
	HX_STACK_LINE(25)
	this->loadGraphic(HX_CSTRING("assets/images/enemy.png"),null(),(int)16,(int)32,null(),null());
	HX_STACK_LINE(26)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(27)
	this->animation->add(HX_CSTRING("moving"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2),(int)10,true);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Enemy.hx",29,0xbda88996)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , true,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(29)
	this->_facingFlip->set((int)1,_Function_1_1::Block());
	struct _Function_1_2{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Enemy.hx",30,0xbda88996)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , false,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(30)
	this->_facingFlip->set((int)16,_Function_1_2::Block());
	HX_STACK_LINE(32)
	this->set_facing((int)1);
	HX_STACK_LINE(34)
	this->health = this->_health;
	HX_STACK_LINE(36)
	this->eColor = _color;
	HX_STACK_LINE(37)
	this->set_color(_color);
	HX_STACK_LINE(39)
	this->maxVelocity->set_y(this->_maxFallSpeed);
	HX_STACK_LINE(40)
	this->acceleration->set_y(this->_gravity);
	HX_STACK_LINE(42)
	this->patrolling = true;
}
;
	return null();
}

//Enemy_obj::~Enemy_obj() { }

Dynamic Enemy_obj::__CreateEmpty() { return  new Enemy_obj; }
hx::ObjectPtr< Enemy_obj > Enemy_obj::__new(Float X,Float Y,int _color)
{  hx::ObjectPtr< Enemy_obj > result = new Enemy_obj();
	result->__construct(X,Y,_color);
	return result;}

Dynamic Enemy_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Enemy_obj > result = new Enemy_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Enemy_obj::update( ){
{
		HX_STACK_FRAME("Enemy","update",0xcf0e6f8f,"Enemy.update","Enemy.hx",46,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(47)
		if ((this->patrolling)){
			HX_STACK_LINE(47)
			this->patrol();
		}
		HX_STACK_LINE(48)
		this->attack();
		HX_STACK_LINE(49)
		this->animate();
		HX_STACK_LINE(51)
		if (((this->y > ::flixel::FlxG_obj::height))){
			HX_STACK_LINE(51)
			this->kill();
		}
		HX_STACK_LINE(53)
		this->super::update();
	}
return null();
}


Void Enemy_obj::destroy( ){
{
		HX_STACK_FRAME("Enemy","destroy",0xe44998b4,"Enemy.destroy","Enemy.hx",58,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->super::destroy();
	}
return null();
}


Void Enemy_obj::animate( ){
{
		HX_STACK_FRAME("Enemy","animate",0x3a10465b,"Enemy.animate","Enemy.hx",63,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(63)
		if (((this->velocity->x == (int)0))){
			HX_STACK_LINE(63)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		else{
			HX_STACK_LINE(64)
			this->animation->play(HX_CSTRING("moving"),null(),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,animate,(void))

Void Enemy_obj::attack( ){
{
		HX_STACK_FRAME("Enemy","attack",0x2818e54e,"Enemy.attack","Enemy.hx",69,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(69)
		if (((bool(((this->x + (int)126) >= ::Reg_obj::state->player->x)) && bool((this->x <= ::Reg_obj::state->player->x))))){
			HX_STACK_LINE(70)
			this->patrolling = false;
			HX_STACK_LINE(71)
			this->set_facing((int)16);
			HX_STACK_LINE(72)
			this->velocity->set_x((this->_moveSpeed + (int)130));
		}
		else{
			HX_STACK_LINE(73)
			if (((bool(((this->x - (int)126) <= ::Reg_obj::state->player->x)) && bool((this->x >= ::Reg_obj::state->player->x))))){
				HX_STACK_LINE(74)
				this->patrolling = false;
				HX_STACK_LINE(75)
				this->set_facing((int)1);
				HX_STACK_LINE(76)
				this->velocity->set_x(-(((this->_moveSpeed + (int)130))));
			}
			else{
				HX_STACK_LINE(78)
				this->patrolling = true;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,attack,(void))

Void Enemy_obj::patrol( ){
{
		HX_STACK_FRAME("Enemy","patrol",0x36e33a12,"Enemy.patrol","Enemy.hx",84,0xbda88996)
		HX_STACK_THIS(this)
		HX_STACK_LINE(84)
		if (((this->facing == (int)16))){
			HX_STACK_LINE(85)
			this->velocity->set_x(this->_moveSpeed);
			HX_STACK_LINE(86)
			if (((bool((((int(this->touching) & int((int)16))) > (int)0)) && bool((((int(this->wasTouching) & int((int)16))) <= (int)0))))){
				HX_STACK_LINE(87)
				this->set_facing((int)1);
				HX_STACK_LINE(88)
				this->velocity->set_x(-(this->_moveSpeed));
			}
		}
		else{
			HX_STACK_LINE(91)
			this->velocity->set_x(-(this->_moveSpeed));
			HX_STACK_LINE(92)
			if (((bool((((int(this->touching) & int((int)1))) > (int)0)) && bool((((int(this->wasTouching) & int((int)1))) <= (int)0))))){
				HX_STACK_LINE(93)
				this->set_facing((int)16);
				HX_STACK_LINE(94)
				this->velocity->set_x(this->_moveSpeed);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Enemy_obj,patrol,(void))


Enemy_obj::Enemy_obj()
{
}

Dynamic Enemy_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"eColor") ) { return eColor; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"attack") ) { return attack_dyn(); }
		if (HX_FIELD_EQ(inName,"patrol") ) { return patrol_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { return _health; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"animate") ) { return animate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { return _gravity; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_moveSpeed") ) { return _moveSpeed; }
		if (HX_FIELD_EQ(inName,"patrolling") ) { return patrolling; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { return _maxFallSpeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Enemy_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"eColor") ) { eColor=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { _health=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { _gravity=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_moveSpeed") ) { _moveSpeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"patrolling") ) { patrolling=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { _maxFallSpeed=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Enemy_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_moveSpeed"));
	outFields->push(HX_CSTRING("_gravity"));
	outFields->push(HX_CSTRING("_maxFallSpeed"));
	outFields->push(HX_CSTRING("eColor"));
	outFields->push(HX_CSTRING("_health"));
	outFields->push(HX_CSTRING("patrolling"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Enemy_obj,_moveSpeed),HX_CSTRING("_moveSpeed")},
	{hx::fsInt,(int)offsetof(Enemy_obj,_gravity),HX_CSTRING("_gravity")},
	{hx::fsInt,(int)offsetof(Enemy_obj,_maxFallSpeed),HX_CSTRING("_maxFallSpeed")},
	{hx::fsInt,(int)offsetof(Enemy_obj,eColor),HX_CSTRING("eColor")},
	{hx::fsInt,(int)offsetof(Enemy_obj,_health),HX_CSTRING("_health")},
	{hx::fsBool,(int)offsetof(Enemy_obj,patrolling),HX_CSTRING("patrolling")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_moveSpeed"),
	HX_CSTRING("_gravity"),
	HX_CSTRING("_maxFallSpeed"),
	HX_CSTRING("eColor"),
	HX_CSTRING("_health"),
	HX_CSTRING("patrolling"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("animate"),
	HX_CSTRING("attack"),
	HX_CSTRING("patrol"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Enemy_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Enemy_obj::__mClass,"__mClass");
};

#endif

Class Enemy_obj::__mClass;

void Enemy_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Enemy"), hx::TCanCast< Enemy_obj> ,sStaticFields,sMemberFields,
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

void Enemy_obj::__boot()
{
}


#include <hxcpp.h>

#ifndef INCLUDED_Portal
#include <Portal.h>
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
#ifndef INCLUDED_flixel_animation_FlxAnimationController
#include <flixel/animation/FlxAnimationController.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif

Void Portal_obj::__construct(Float X,Float Y)
{
HX_STACK_FRAME("Portal","new",0xf4c2e5be,"Portal.new","Portal.hx",15,0xbfa99b72)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
{
	HX_STACK_LINE(16)
	super::__construct(X,Y,null());
	HX_STACK_LINE(18)
	this->loadGraphic(HX_CSTRING("assets/images/portal.png"),null(),(int)16,(int)16,null(),null());
	HX_STACK_LINE(20)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(21)
	this->animation->add(HX_CSTRING("active"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3),(int)3,true);
	HX_STACK_LINE(23)
	::flixel::system::FlxSound _g = ::flixel::FlxG_obj::sound->load(HX_CSTRING("assets/sounds/portal.wav"),0.4,null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(23)
	this->_portalSound = _g;
	HX_STACK_LINE(25)
	this->_active = false;
}
;
	return null();
}

//Portal_obj::~Portal_obj() { }

Dynamic Portal_obj::__CreateEmpty() { return  new Portal_obj; }
hx::ObjectPtr< Portal_obj > Portal_obj::__new(Float X,Float Y)
{  hx::ObjectPtr< Portal_obj > result = new Portal_obj();
	result->__construct(X,Y);
	return result;}

Dynamic Portal_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Portal_obj > result = new Portal_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Portal_obj::update( ){
{
		HX_STACK_FRAME("Portal","update",0xe1939f6b,"Portal.update","Portal.hx",29,0xbfa99b72)
		HX_STACK_THIS(this)
		HX_STACK_LINE(30)
		if (((bool(this->_active) && bool(!(this->finished))))){
			HX_STACK_LINE(30)
			this->animation->play(HX_CSTRING("active"),null(),null());
		}
		else{
			HX_STACK_LINE(31)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		HX_STACK_LINE(33)
		this->super::update();
	}
return null();
}


Void Portal_obj::destroy( ){
{
		HX_STACK_FRAME("Portal","destroy",0x064e4958,"Portal.destroy","Portal.hx",38,0xbfa99b72)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->super::destroy();
	}
return null();
}



Portal_obj::Portal_obj()
{
}

void Portal_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Portal);
	HX_MARK_MEMBER_NAME(_active,"_active");
	HX_MARK_MEMBER_NAME(finished,"finished");
	HX_MARK_MEMBER_NAME(_portalSound,"_portalSound");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Portal_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_active,"_active");
	HX_VISIT_MEMBER_NAME(finished,"finished");
	HX_VISIT_MEMBER_NAME(_portalSound,"_portalSound");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Portal_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_active") ) { return _active; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { return finished; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_portalSound") ) { return _portalSound; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Portal_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_active") ) { _active=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"finished") ) { finished=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_portalSound") ) { _portalSound=inValue.Cast< ::flixel::system::FlxSound >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Portal_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_active"));
	outFields->push(HX_CSTRING("finished"));
	outFields->push(HX_CSTRING("_portalSound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Portal_obj,_active),HX_CSTRING("_active")},
	{hx::fsBool,(int)offsetof(Portal_obj,finished),HX_CSTRING("finished")},
	{hx::fsObject /*::flixel::system::FlxSound*/ ,(int)offsetof(Portal_obj,_portalSound),HX_CSTRING("_portalSound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_active"),
	HX_CSTRING("finished"),
	HX_CSTRING("_portalSound"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Portal_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Portal_obj::__mClass,"__mClass");
};

#endif

Class Portal_obj::__mClass;

void Portal_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Portal"), hx::TCanCast< Portal_obj> ,sStaticFields,sMemberFields,
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

void Portal_obj::__boot()
{
}


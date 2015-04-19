#include <hxcpp.h>

#ifndef INCLUDED_Red
#include <Red.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
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

Void Red_obj::__construct(Float X,Float Y)
{
HX_STACK_FRAME("Red","new",0x66b91ea3,"Red.new","Red.hx",9,0x32f8c62d)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
{
	HX_STACK_LINE(10)
	super::__construct(X,Y,null());
	HX_STACK_LINE(12)
	this->loadGraphic(HX_CSTRING("assets/images/red.png"),true,(int)32,(int)32,null(),null());
	HX_STACK_LINE(13)
	this->animation->add(HX_CSTRING("float"),Array_obj< int >::__new().Add((int)0).Add((int)1),(int)3,true);
}
;
	return null();
}

//Red_obj::~Red_obj() { }

Dynamic Red_obj::__CreateEmpty() { return  new Red_obj; }
hx::ObjectPtr< Red_obj > Red_obj::__new(Float X,Float Y)
{  hx::ObjectPtr< Red_obj > result = new Red_obj();
	result->__construct(X,Y);
	return result;}

Dynamic Red_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Red_obj > result = new Red_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Red_obj::update( ){
{
		HX_STACK_FRAME("Red","update",0x28ae43a6,"Red.update","Red.hx",17,0x32f8c62d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(18)
		this->animation->play(HX_CSTRING("float"),null(),null());
		HX_STACK_LINE(20)
		this->super::update();
	}
return null();
}



Red_obj::Red_obj()
{
}

Dynamic Red_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Red_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Red_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Red_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Red_obj::__mClass,"__mClass");
};

#endif

Class Red_obj::__mClass;

void Red_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Red"), hx::TCanCast< Red_obj> ,sStaticFields,sMemberFields,
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

void Red_obj::__boot()
{
}


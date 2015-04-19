#include <hxcpp.h>

#ifndef INCLUDED_Blue
#include <Blue.h>
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
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif

Void Blue_obj::__construct(Float X,Float Y)
{
HX_STACK_FRAME("Blue","new",0x5804f4ac,"Blue.new","Blue.hx",9,0x87db4444)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
{
	HX_STACK_LINE(10)
	super::__construct(X,Y,null());
	HX_STACK_LINE(12)
	this->loadGraphic(HX_CSTRING("assets/images/blue.png"),null(),(int)32,(int)32,null(),null());
}
;
	return null();
}

//Blue_obj::~Blue_obj() { }

Dynamic Blue_obj::__CreateEmpty() { return  new Blue_obj; }
hx::ObjectPtr< Blue_obj > Blue_obj::__new(Float X,Float Y)
{  hx::ObjectPtr< Blue_obj > result = new Blue_obj();
	result->__construct(X,Y);
	return result;}

Dynamic Blue_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Blue_obj > result = new Blue_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Blue_obj::Blue_obj()
{
}

Dynamic Blue_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Blue_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Blue_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Blue_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Blue_obj::__mClass,"__mClass");
};

#endif

Class Blue_obj::__mClass;

void Blue_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Blue"), hx::TCanCast< Blue_obj> ,sStaticFields,sMemberFields,
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

void Blue_obj::__boot()
{
}


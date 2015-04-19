#include <hxcpp.h>

#ifndef INCLUDED_Bullet
#include <Bullet.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_LevelLoader
#include <LevelLoader.h>
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
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledMap
#include <flixel/addons/editors/tiled/TiledMap.h>
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
#ifndef INCLUDED_flixel_system_FlxSound
#include <flixel/system/FlxSound.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Player_obj::__construct(Float X,Float Y)
{
HX_STACK_FRAME("Player","new",0x8d5554f3,"Player.new","Player.hx",14,0xa27fc9dd)
HX_STACK_THIS(this)
HX_STACK_ARG(X,"X")
HX_STACK_ARG(Y,"Y")
{
	HX_STACK_LINE(23)
	this->hasRed = false;
	HX_STACK_LINE(21)
	this->_jumpForce = (int)500;
	HX_STACK_LINE(20)
	this->_maxFallSpeed = (int)800;
	HX_STACK_LINE(19)
	this->_gravity = (int)1200;
	HX_STACK_LINE(18)
	this->_drag = (int)1000;
	HX_STACK_LINE(17)
	this->_maxAcceleration = (int)1600;
	HX_STACK_LINE(16)
	this->_maxSpeed = (int)300;
	HX_STACK_LINE(37)
	super::__construct(X,Y,null());
	HX_STACK_LINE(39)
	this->loadGraphic(HX_CSTRING("assets/images/player.png"),null(),(int)16,(int)32,null(),null());
	HX_STACK_LINE(40)
	this->animation->add(HX_CSTRING("idle"),Array_obj< int >::__new().Add((int)0),null(),null());
	HX_STACK_LINE(41)
	this->animation->add(HX_CSTRING("jumping"),Array_obj< int >::__new().Add((int)8),null(),null());
	HX_STACK_LINE(42)
	this->animation->add(HX_CSTRING("walking"),Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)3).Add((int)4).Add((int)5).Add((int)6).Add((int)7),(int)20,true);
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",44,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , true,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(44)
	this->_facingFlip->set((int)1,_Function_1_1::Block());
	struct _Function_1_2{
		inline static Dynamic Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",45,0xa27fc9dd)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , false,false);
				__result->Add(HX_CSTRING("y") , false,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(45)
	this->_facingFlip->set((int)16,_Function_1_2::Block());
	HX_STACK_LINE(47)
	::flixel::system::FlxSound _g = ::flixel::FlxG_obj::sound->load(HX_CSTRING("assets/sounds/shoot.wav"),0.4,null(),null(),null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(47)
	this->_shootSound = _g;
	HX_STACK_LINE(48)
	::flixel::system::FlxSound _g1 = ::flixel::FlxG_obj::sound->load(HX_CSTRING("assets/sounds/death.wav"),0.4,null(),null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(48)
	this->_deathSound = _g1;
	HX_STACK_LINE(50)
	this->maxVelocity->set_y(this->_maxFallSpeed);
	HX_STACK_LINE(51)
	this->acceleration->set_y(this->_gravity);
	HX_STACK_LINE(52)
	this->drag->set_x(this->_drag);
	HX_STACK_LINE(54)
	::flixel::group::FlxGroup _g2 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(54)
	this->bullets = _g2;
	HX_STACK_LINE(55)
	this->bulletDelay = (int)5;
	HX_STACK_LINE(57)
	Array< int > _g3 = Array_obj< int >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(57)
	this->colors = _g3;
	HX_STACK_LINE(58)
	this->colors[(int)0] = (int)-65536;
	HX_STACK_LINE(59)
	this->colors[(int)1] = (int)-16744448;
	HX_STACK_LINE(60)
	this->colors[(int)2] = (int)-16776961;
	HX_STACK_LINE(62)
	this->bColor = this->colors->__get((int)0);
}
;
	return null();
}

//Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hx::ObjectPtr< Player_obj > Player_obj::__new(Float X,Float Y)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(X,Y);
	return result;}

Dynamic Player_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Player_obj::update( ){
{
		HX_STACK_FRAME("Player","update",0xf1f8df56,"Player.update","Player.hx",66,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(67)
		this->controls();
		HX_STACK_LINE(68)
		this->animate();
		HX_STACK_LINE(70)
		if (((this->y > ::flixel::FlxG_obj::height))){
			HX_STACK_LINE(70)
			this->set_y((::Reg_obj::state->currentLevel->fullHeight - (int)64));
		}
		HX_STACK_LINE(72)
		this->super::update();
	}
return null();
}


Void Player_obj::destroy( ){
{
		HX_STACK_FRAME("Player","destroy",0x4e80f70d,"Player.destroy","Player.hx",77,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(77)
		this->super::destroy();
	}
return null();
}


Void Player_obj::kill( ){
{
		HX_STACK_FRAME("Player","kill",0x1b5c5bab,"Player.kill","Player.hx",81,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(82)
		this->set_alive(false);
		HX_STACK_LINE(83)
		{
			HX_STACK_LINE(83)
			::flixel::system::FlxSound _this = this->_deathSound;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(83)
			_this->x = this->x;
			HX_STACK_LINE(83)
			_this->y = this->y;
		}
		HX_STACK_LINE(84)
		this->_deathSound->play(true);
		HX_STACK_LINE(85)
		this->scale->set(1.5,1.5);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",86,0xa27fc9dd)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , (int)1,false);
					__result->Add(HX_CSTRING("y") , (int)1,false);
					return __result;
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( hx::ObjectPtr< ::Player_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Player.hx",86,0xa27fc9dd)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::elasticOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(86)
		::flixel::tweens::FlxTween_obj::tween(this->scale,_Function_1_1::Block(),0.5,_Function_1_2::Block(this));
		HX_STACK_LINE(87)
		this->acceleration->set_y((int)1200);
		HX_STACK_LINE(88)
		this->velocity->set_y((int)-200);
		HX_STACK_LINE(89)
		this->allowCollisions = (int)0;
		HX_STACK_LINE(90)
		::flixel::util::FlxTimer_obj::__new((int)1,::Reg_obj::state->gameOver_dyn(),null());
	}
return null();
}


Void Player_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Player","finishKill",0x3332f55e,"Player.finishKill","Player.hx",95,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(95)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Player_obj,finishKill,(void))

Void Player_obj::controls( ){
{
		HX_STACK_FRAME("Player","controls",0xc9328d03,"Player.controls","Player.hx",99,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(100)
		Float xForce = (int)0;		HX_STACK_VAR(xForce,"xForce");
		HX_STACK_LINE(101)
		bool jumping = false;		HX_STACK_VAR(jumping,"jumping");
		HX_STACK_LINE(103)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)37,::flixel::FlxG_obj::keys->pressed->checkStatus))){
			HX_STACK_LINE(104)
			(xForce)--;
			HX_STACK_LINE(105)
			this->set_facing((int)1);
		}
		HX_STACK_LINE(107)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)39,::flixel::FlxG_obj::keys->pressed->checkStatus))){
			HX_STACK_LINE(108)
			(xForce)++;
			HX_STACK_LINE(109)
			this->set_facing((int)16);
		}
		HX_STACK_LINE(112)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
			HX_STACK_LINE(112)
			jumping = true;
		}
		HX_STACK_LINE(113)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)32,::flixel::FlxG_obj::keys->justReleased->checkStatus))){
			HX_STACK_LINE(113)
			this->velocity->set_y((this->velocity->y * 0.5));
		}
		HX_STACK_LINE(115)
		{
			HX_STACK_LINE(115)
			Float lowerBound;		HX_STACK_VAR(lowerBound,"lowerBound");
			HX_STACK_LINE(115)
			if (((xForce < (int)-1))){
				HX_STACK_LINE(115)
				lowerBound = (int)-1;
			}
			else{
				HX_STACK_LINE(115)
				lowerBound = xForce;
			}
			HX_STACK_LINE(115)
			if (((lowerBound > (int)1))){
				HX_STACK_LINE(115)
				xForce = (int)1;
			}
			else{
				HX_STACK_LINE(115)
				xForce = lowerBound;
			}
		}
		HX_STACK_LINE(117)
		this->maxVelocity->set_x(this->_maxSpeed);
		HX_STACK_LINE(118)
		this->acceleration->set_x((xForce * this->_maxAcceleration));
		HX_STACK_LINE(120)
		if (((bool(jumping) && bool((((int(this->touching) & int((int)4096))) > (int)0))))){
			HX_STACK_LINE(121)
			Float _g = ::Math_obj::abs((this->velocity->x * 0.25));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(121)
			Float finalJumpForce = -(((this->_jumpForce + _g)));		HX_STACK_VAR(finalJumpForce,"finalJumpForce");
			HX_STACK_LINE(122)
			this->velocity->set_y(finalJumpForce);
		}
		HX_STACK_LINE(125)
		(this->bulletDelay)--;
		HX_STACK_LINE(127)
		if (((  ((::flixel::FlxG_obj::keys->checkStatus((int)65,::flixel::FlxG_obj::keys->justPressed->checkStatus))) ? bool((this->bulletDelay < (int)0)) : bool(false) ))){
			HX_STACK_LINE(128)
			if (((this->facing == (int)1))){
				HX_STACK_LINE(129)
				Float _g1 = this->get_width();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(129)
				Float _g2 = (Float(_g1) / Float((int)2));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(129)
				Float _g3 = (this->x + _g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(129)
				Float _g4 = (_g3 - (int)8);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(129)
				Float _g5 = this->get_height();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(129)
				Float _g6 = (Float(_g5) / Float((int)2));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(129)
				Float _g7 = (this->y + _g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(129)
				Float _g8 = (_g7 - (int)2);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(129)
				::Bullet _g9 = ::Bullet_obj::__new(_g4,_g8,this->bColor);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(129)
				this->bullet = _g9;
				HX_STACK_LINE(130)
				this->bullet->velocity->set_x(-(this->bullet->_velocity));
				HX_STACK_LINE(131)
				this->bullets->add(this->bullet);
			}
			else{
				HX_STACK_LINE(133)
				Float _g10 = this->get_width();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(133)
				Float _g11 = (Float(_g10) / Float((int)2));		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(133)
				Float _g12 = (this->x + _g11);		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(133)
				Float _g13 = (_g12 + (int)7);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(133)
				Float _g14 = this->get_height();		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(133)
				Float _g15 = (Float(_g14) / Float((int)2));		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(133)
				Float _g16 = (this->y + _g15);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(133)
				Float _g17 = (_g16 - (int)2);		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(133)
				::Bullet _g18 = ::Bullet_obj::__new(_g13,_g17,this->bColor);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(133)
				this->bullet = _g18;
				HX_STACK_LINE(134)
				this->bullets->add(this->bullet);
			}
			HX_STACK_LINE(137)
			{
				HX_STACK_LINE(137)
				::flixel::system::FlxSound _this = this->_shootSound;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(137)
				_this->x = this->x;
				HX_STACK_LINE(137)
				_this->y = this->y;
			}
			HX_STACK_LINE(138)
			this->_shootSound->play(true);
		}
		HX_STACK_LINE(141)
		if ((::flixel::FlxG_obj::keys->checkStatus((int)83,::flixel::FlxG_obj::keys->justPressed->checkStatus))){
			HX_STACK_LINE(141)
			this->switchBulletColor();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,controls,(void))

Void Player_obj::animate( ){
{
		HX_STACK_FRAME("Player","animate",0xa447a4b4,"Player.animate","Player.hx",146,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(146)
		if (((bool((this->velocity->x == (int)0)) && bool((((int(this->touching) & int((int)4096))) > (int)0))))){
			HX_STACK_LINE(146)
			this->animation->play(HX_CSTRING("idle"),null(),null());
		}
		else{
			HX_STACK_LINE(147)
			if ((!(((((int(this->touching) & int((int)4096))) > (int)0))))){
				HX_STACK_LINE(147)
				this->animation->play(HX_CSTRING("jumping"),null(),null());
			}
			else{
				HX_STACK_LINE(148)
				this->animation->play(HX_CSTRING("walking"),null(),null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,animate,(void))

Void Player_obj::switchBulletColor( ){
{
		HX_STACK_FRAME("Player","switchBulletColor",0x84e38a00,"Player.switchBulletColor","Player.hx",153,0xa27fc9dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(153)
		if (((this->bColor == this->colors->__get((int)0)))){
			HX_STACK_LINE(153)
			this->bColor = this->colors->__get((int)1);
		}
		else{
			HX_STACK_LINE(154)
			if (((this->bColor == this->colors->__get((int)1)))){
				HX_STACK_LINE(154)
				this->bColor = this->colors->__get((int)2);
			}
			else{
				HX_STACK_LINE(155)
				if (((this->bColor == this->colors->__get((int)2)))){
					HX_STACK_LINE(155)
					this->bColor = this->colors->__get((int)0);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Player_obj,switchBulletColor,(void))


Player_obj::Player_obj()
{
}

void Player_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Player);
	HX_MARK_MEMBER_NAME(_maxSpeed,"_maxSpeed");
	HX_MARK_MEMBER_NAME(_maxAcceleration,"_maxAcceleration");
	HX_MARK_MEMBER_NAME(_drag,"_drag");
	HX_MARK_MEMBER_NAME(_gravity,"_gravity");
	HX_MARK_MEMBER_NAME(_maxFallSpeed,"_maxFallSpeed");
	HX_MARK_MEMBER_NAME(_jumpForce,"_jumpForce");
	HX_MARK_MEMBER_NAME(hasRed,"hasRed");
	HX_MARK_MEMBER_NAME(bullets,"bullets");
	HX_MARK_MEMBER_NAME(bullet,"bullet");
	HX_MARK_MEMBER_NAME(bulletDelay,"bulletDelay");
	HX_MARK_MEMBER_NAME(bColor,"bColor");
	HX_MARK_MEMBER_NAME(colors,"colors");
	HX_MARK_MEMBER_NAME(_shootSound,"_shootSound");
	HX_MARK_MEMBER_NAME(_deathSound,"_deathSound");
	::flixel::FlxSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Player_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_maxSpeed,"_maxSpeed");
	HX_VISIT_MEMBER_NAME(_maxAcceleration,"_maxAcceleration");
	HX_VISIT_MEMBER_NAME(_drag,"_drag");
	HX_VISIT_MEMBER_NAME(_gravity,"_gravity");
	HX_VISIT_MEMBER_NAME(_maxFallSpeed,"_maxFallSpeed");
	HX_VISIT_MEMBER_NAME(_jumpForce,"_jumpForce");
	HX_VISIT_MEMBER_NAME(hasRed,"hasRed");
	HX_VISIT_MEMBER_NAME(bullets,"bullets");
	HX_VISIT_MEMBER_NAME(bullet,"bullet");
	HX_VISIT_MEMBER_NAME(bulletDelay,"bulletDelay");
	HX_VISIT_MEMBER_NAME(bColor,"bColor");
	HX_VISIT_MEMBER_NAME(colors,"colors");
	HX_VISIT_MEMBER_NAME(_shootSound,"_shootSound");
	HX_VISIT_MEMBER_NAME(_deathSound,"_deathSound");
	::flixel::FlxSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Player_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { return _drag; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"hasRed") ) { return hasRed; }
		if (HX_FIELD_EQ(inName,"bullet") ) { return bullet; }
		if (HX_FIELD_EQ(inName,"bColor") ) { return bColor; }
		if (HX_FIELD_EQ(inName,"colors") ) { return colors; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bullets") ) { return bullets; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"animate") ) { return animate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { return _gravity; }
		if (HX_FIELD_EQ(inName,"controls") ) { return controls_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_maxSpeed") ) { return _maxSpeed; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_jumpForce") ) { return _jumpForce; }
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletDelay") ) { return bulletDelay; }
		if (HX_FIELD_EQ(inName,"_shootSound") ) { return _shootSound; }
		if (HX_FIELD_EQ(inName,"_deathSound") ) { return _deathSound; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { return _maxFallSpeed; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_maxAcceleration") ) { return _maxAcceleration; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"switchBulletColor") ) { return switchBulletColor_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Player_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"_drag") ) { _drag=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"hasRed") ) { hasRed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bullet") ) { bullet=inValue.Cast< ::Bullet >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bColor") ) { bColor=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colors") ) { colors=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"bullets") ) { bullets=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"_gravity") ) { _gravity=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_maxSpeed") ) { _maxSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_jumpForce") ) { _jumpForce=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bulletDelay") ) { bulletDelay=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_shootSound") ) { _shootSound=inValue.Cast< ::flixel::system::FlxSound >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_deathSound") ) { _deathSound=inValue.Cast< ::flixel::system::FlxSound >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { _maxFallSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_maxAcceleration") ) { _maxAcceleration=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Player_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_maxSpeed"));
	outFields->push(HX_CSTRING("_maxAcceleration"));
	outFields->push(HX_CSTRING("_drag"));
	outFields->push(HX_CSTRING("_gravity"));
	outFields->push(HX_CSTRING("_maxFallSpeed"));
	outFields->push(HX_CSTRING("_jumpForce"));
	outFields->push(HX_CSTRING("hasRed"));
	outFields->push(HX_CSTRING("bullets"));
	outFields->push(HX_CSTRING("bullet"));
	outFields->push(HX_CSTRING("bulletDelay"));
	outFields->push(HX_CSTRING("bColor"));
	outFields->push(HX_CSTRING("colors"));
	outFields->push(HX_CSTRING("_shootSound"));
	outFields->push(HX_CSTRING("_deathSound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Player_obj,_maxSpeed),HX_CSTRING("_maxSpeed")},
	{hx::fsInt,(int)offsetof(Player_obj,_maxAcceleration),HX_CSTRING("_maxAcceleration")},
	{hx::fsInt,(int)offsetof(Player_obj,_drag),HX_CSTRING("_drag")},
	{hx::fsInt,(int)offsetof(Player_obj,_gravity),HX_CSTRING("_gravity")},
	{hx::fsInt,(int)offsetof(Player_obj,_maxFallSpeed),HX_CSTRING("_maxFallSpeed")},
	{hx::fsInt,(int)offsetof(Player_obj,_jumpForce),HX_CSTRING("_jumpForce")},
	{hx::fsBool,(int)offsetof(Player_obj,hasRed),HX_CSTRING("hasRed")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(Player_obj,bullets),HX_CSTRING("bullets")},
	{hx::fsObject /*::Bullet*/ ,(int)offsetof(Player_obj,bullet),HX_CSTRING("bullet")},
	{hx::fsInt,(int)offsetof(Player_obj,bulletDelay),HX_CSTRING("bulletDelay")},
	{hx::fsInt,(int)offsetof(Player_obj,bColor),HX_CSTRING("bColor")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Player_obj,colors),HX_CSTRING("colors")},
	{hx::fsObject /*::flixel::system::FlxSound*/ ,(int)offsetof(Player_obj,_shootSound),HX_CSTRING("_shootSound")},
	{hx::fsObject /*::flixel::system::FlxSound*/ ,(int)offsetof(Player_obj,_deathSound),HX_CSTRING("_deathSound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_maxSpeed"),
	HX_CSTRING("_maxAcceleration"),
	HX_CSTRING("_drag"),
	HX_CSTRING("_gravity"),
	HX_CSTRING("_maxFallSpeed"),
	HX_CSTRING("_jumpForce"),
	HX_CSTRING("hasRed"),
	HX_CSTRING("bullets"),
	HX_CSTRING("bullet"),
	HX_CSTRING("bulletDelay"),
	HX_CSTRING("bColor"),
	HX_CSTRING("colors"),
	HX_CSTRING("_shootSound"),
	HX_CSTRING("_deathSound"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	HX_CSTRING("controls"),
	HX_CSTRING("animate"),
	HX_CSTRING("switchBulletColor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Player_obj::__mClass,"__mClass");
};

#endif

Class Player_obj::__mClass;

void Player_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Player"), hx::TCanCast< Player_obj> ,sStaticFields,sMemberFields,
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

void Player_obj::__boot()
{
}


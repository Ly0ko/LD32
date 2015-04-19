#include <hxcpp.h>

#ifndef INCLUDED_Enemy
#include <Enemy.h>
#endif
#ifndef INCLUDED_GameOver
#include <GameOver.h>
#endif
#ifndef INCLUDED_HUD
#include <HUD.h>
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
#ifndef INCLUDED_Portal
#include <Portal.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
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
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledMap
#include <flixel/addons/editors/tiled/TiledMap.h>
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
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyList
#include <flixel/input/keyboard/FlxKeyList.h>
#endif
#ifndef INCLUDED_flixel_input_keyboard_FlxKeyboard
#include <flixel/input/keyboard/FlxKeyboard.h>
#endif
#ifndef INCLUDED_flixel_input_mouse_FlxMouse
#include <flixel/input/mouse/FlxMouse.h>
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
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif
#ifndef INCLUDED_flixel_util_FlxTimer
#include <flixel/util/FlxTimer.h>
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

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",16,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(30)
	this->won = false;
	HX_STACK_LINE(16)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",33,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(34)
		this->super::create();
		HX_STACK_LINE(36)
		::flixel::FlxG_obj::mouse->set_visible(false);
		HX_STACK_LINE(38)
		::flixel::FlxG_obj::camera->bgColor = (int)-11250604;
		HX_STACK_LINE(40)
		::Reg_obj::state = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(42)
		::LevelLoader _g = ::LevelLoader_obj::__new(HX_CSTRING("assets/data/level1.tmx"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		this->level1 = _g;
		HX_STACK_LINE(43)
		this->currentLevel = this->level1;
		HX_STACK_LINE(44)
		this->add(this->level1->foregroundTiles);
		HX_STACK_LINE(46)
		::Player _g1 = ::Player_obj::__new((int)64,(this->currentLevel->fullHeight - (int)64));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(46)
		this->player = _g1;
		HX_STACK_LINE(47)
		this->add(this->player);
		HX_STACK_LINE(49)
		this->add(this->player->bullets);
		HX_STACK_LINE(51)
		::flixel::group::FlxGroup _g2 = ::flixel::group::FlxGroup_obj::__new(null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(51)
		this->enemies = _g2;
		HX_STACK_LINE(53)
		this->addEnemies(null());
		HX_STACK_LINE(55)
		::flixel::FlxG_obj::camera->follow(this->player,(int)1,null(),null());
		HX_STACK_LINE(57)
		::Portal _g3 = ::Portal_obj::__new((int)1513,(int)368);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(57)
		this->portal = _g3;
		HX_STACK_LINE(58)
		this->add(this->portal);
		HX_STACK_LINE(60)
		::HUD _g4 = ::HUD_obj::__new(this->player);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(60)
		this->hud = _g4;
		HX_STACK_LINE(61)
		this->add(this->hud);
		HX_STACK_LINE(63)
		::flixel::text::FlxText _g5 = ::flixel::text::FlxText_obj::__new((Float(::flixel::FlxG_obj::width) / Float((int)2)),(int)100,null(),null(),null(),null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(63)
		this->timerText = _g5;
		HX_STACK_LINE(64)
		this->timerText->set_size((int)12);
		HX_STACK_LINE(65)
		this->timerText->scrollFactor->set_x((int)0);
		HX_STACK_LINE(66)
		this->add(this->timerText);
		HX_STACK_LINE(68)
		::flixel::text::FlxText _g6 = ::flixel::text::FlxText_obj::__new((Float(::flixel::FlxG_obj::width) / Float((int)2)),(int)100,null(),null(),null(),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(68)
		this->enemiesLeftText = _g6;
		HX_STACK_LINE(69)
		this->enemiesLeftText->set_text(HX_CSTRING(""));
		HX_STACK_LINE(70)
		this->enemiesLeftText->set_size((int)12);
		HX_STACK_LINE(71)
		this->enemiesLeftText->scrollFactor->set_x((int)0);
		HX_STACK_LINE(72)
		this->add(this->enemiesLeftText);
		HX_STACK_LINE(74)
		this->enemiesLeft = this->enemies->length;
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",79,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(79)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",83,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(84)
		::flixel::FlxG_obj::overlap(this->player,this->currentLevel->foregroundTiles,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(85)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->currentLevel->foregroundTiles,this->bulletHitMap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(86)
		::flixel::FlxG_obj::overlap(this->enemies,this->currentLevel->foregroundTiles,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(87)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->enemies,this->bulletHitEnemy_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(88)
		::flixel::FlxG_obj::overlap(this->player,this->enemies,this->enemyHitPlayer_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(89)
		::flixel::FlxG_obj::overlap(this->player,this->portal,this->playerOverlapPortal_dyn(),null());
		HX_STACK_LINE(91)
		if (((this->timer != null()))){
			struct _Function_2_1{
				inline static Float Block( hx::ObjectPtr< ::PlayState_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","PlayState.hx",92,0xb30d7781)
					{
						HX_STACK_LINE(92)
						::flixel::util::FlxTimer _this = __this->timer;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(92)
						return (_this->time - _this->_timeCounter);
					}
					return null();
				}
			};
			HX_STACK_LINE(92)
			this->timerText->set_text((HX_CSTRING("") + _Function_2_1::Block(this)));
			HX_STACK_LINE(94)
			if ((this->timer->finished)){
				HX_STACK_LINE(95)
				this->remove(this->timerText,null());
				HX_STACK_LINE(96)
				this->portal->_active = false;
				HX_STACK_LINE(97)
				this->portal->finished = true;
			}
		}
		HX_STACK_LINE(101)
		if ((this->portal->finished)){
			HX_STACK_LINE(102)
			this->enemiesLeftText->set_text((HX_CSTRING("Enemies left: ") + this->enemiesLeft));
		}
		HX_STACK_LINE(105)
		if (((  ((this->won)) ? bool(::flixel::FlxG_obj::keys->checkStatus((int)13,::flixel::FlxG_obj::keys->justPressed->checkStatus)) : bool(false) ))){
			HX_STACK_LINE(105)
			::flixel::FlxState State = ::PlayState_obj::__new(null());		HX_STACK_VAR(State,"State");
			HX_STACK_LINE(105)
			::flixel::FlxG_obj::game->_requestedState = State;
		}
		HX_STACK_LINE(107)
		this->super::update();
	}
return null();
}


Void PlayState_obj::bulletHitMap( ::flixel::FlxObject bulletRef,::flixel::FlxObject levelRef){
{
		HX_STACK_FRAME("PlayState","bulletHitMap",0x3db4899c,"PlayState.bulletHitMap","PlayState.hx",112,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(levelRef,"levelRef")
		HX_STACK_LINE(112)
		this->player->bullets->remove(bulletRef,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitMap,(void))

Void PlayState_obj::bulletHitEnemy( ::flixel::FlxObject bulletRef,::Enemy enemyRef){
{
		HX_STACK_FRAME("PlayState","bulletHitEnemy",0xe87a5148,"PlayState.bulletHitEnemy","PlayState.hx",116,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(enemyRef,"enemyRef")
		HX_STACK_LINE(117)
		this->player->bullets->remove(bulletRef,null());
		HX_STACK_LINE(119)
		if (((this->player->bColor == enemyRef->eColor))){
			HX_STACK_LINE(120)
			hx::SubEq(enemyRef->health,(int)2);
		}
		HX_STACK_LINE(123)
		if (((enemyRef->health <= (int)0))){
			HX_STACK_LINE(124)
			enemyRef->kill();
			HX_STACK_LINE(125)
			(this->enemiesLeft)--;
			HX_STACK_LINE(127)
			this->enemies->remove(enemyRef,true);
			HX_STACK_LINE(129)
			if ((this->portal->finished)){
				HX_STACK_LINE(130)
				if (((this->enemiesLeft == (int)0))){
					HX_STACK_LINE(131)
					this->gameWin();
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitEnemy,(void))

Void PlayState_obj::enemyHitPlayer( ::Player playerRef,::flixel::FlxObject enemyRef){
{
		HX_STACK_FRAME("PlayState","enemyHitPlayer",0xf1606c9d,"PlayState.enemyHitPlayer","PlayState.hx",138,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(playerRef,"playerRef")
		HX_STACK_ARG(enemyRef,"enemyRef")
		HX_STACK_LINE(139)
		hx::SubEq(this->hud->hp,(int)1);
		HX_STACK_LINE(141)
		if (((this->hud->hp == (int)0))){
			HX_STACK_LINE(141)
			playerRef->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,enemyHitPlayer,(void))

Void PlayState_obj::playerOverlapPortal( ::Player playerRef,::Portal portalRef){
{
		HX_STACK_FRAME("PlayState","playerOverlapPortal",0xa9ad01e1,"PlayState.playerOverlapPortal","PlayState.hx",146,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(playerRef,"playerRef")
		HX_STACK_ARG(portalRef,"portalRef")
		HX_STACK_LINE(146)
		if (((bool(!(portalRef->_active)) && bool(!(portalRef->finished))))){
			HX_STACK_LINE(147)
			portalRef->_active = true;
			HX_STACK_LINE(149)
			::flixel::util::FlxTimer_obj::__new((int)20,this->addEnemies_dyn(),(int)3);
			HX_STACK_LINE(150)
			::flixel::util::FlxTimer _g = ::flixel::util::FlxTimer_obj::__new((int)60,null(),null());		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(150)
			this->timer = _g;
			HX_STACK_LINE(152)
			{
				HX_STACK_LINE(152)
				::flixel::system::FlxSound _this = portalRef->_portalSound;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(152)
				_this->x = playerRef->x;
				HX_STACK_LINE(152)
				_this->y = playerRef->y;
			}
			HX_STACK_LINE(153)
			portalRef->_portalSound->play(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,playerOverlapPortal,(void))

Void PlayState_obj::addEnemies( ::flixel::util::FlxTimer t){
{
		HX_STACK_FRAME("PlayState","addEnemies",0xc6b109f6,"PlayState.addEnemies","PlayState.hx",158,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(159)
		if (((this->timer != null()))){
			HX_STACK_LINE(160)
			::Enemy _g = ::Enemy_obj::__new((int)384,(int)288,(int)-65536);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(160)
			this->enemies->add(_g);
			HX_STACK_LINE(161)
			::Enemy _g1 = ::Enemy_obj::__new((int)832,(int)416,(int)-16744448);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(161)
			this->enemies->add(_g1);
			HX_STACK_LINE(162)
			::Enemy _g2 = ::Enemy_obj::__new((int)1120,(int)416,(int)-16776961);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(162)
			this->enemies->add(_g2);
			HX_STACK_LINE(163)
			::Enemy _g3 = ::Enemy_obj::__new((int)2016,(int)192,(int)-16744448);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(163)
			this->enemies->add(_g3);
			HX_STACK_LINE(164)
			::Enemy _g4 = ::Enemy_obj::__new((int)2272,(int)416,(int)-16776961);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(164)
			this->enemies->add(_g4);
			HX_STACK_LINE(165)
			::Enemy _g5 = ::Enemy_obj::__new((int)2880,(int)416,(int)-16776961);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(165)
			this->enemies->add(_g5);
			HX_STACK_LINE(166)
			::Enemy _g6 = ::Enemy_obj::__new((int)3072,(int)192,(int)-16744448);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(166)
			this->enemies->add(_g6);
			HX_STACK_LINE(167)
			this->enemiesLeft = (this->enemiesLeft + (int)7);
		}
		else{
			HX_STACK_LINE(169)
			::Enemy _g7 = ::Enemy_obj::__new((int)384,(int)288,(int)-65536);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(169)
			this->enemies->add(_g7);
			HX_STACK_LINE(170)
			::Enemy _g8 = ::Enemy_obj::__new((int)832,(int)416,(int)-16744448);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(170)
			this->enemies->add(_g8);
			HX_STACK_LINE(171)
			::Enemy _g9 = ::Enemy_obj::__new((int)544,(int)416,(int)-16776961);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(171)
			this->enemies->add(_g9);
			HX_STACK_LINE(172)
			::Enemy _g10 = ::Enemy_obj::__new((int)1120,(int)416,(int)-16776961);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(172)
			this->enemies->add(_g10);
			HX_STACK_LINE(173)
			::Enemy _g11 = ::Enemy_obj::__new((int)1472,(int)352,(int)-65536);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(173)
			this->enemies->add(_g11);
			HX_STACK_LINE(174)
			::Enemy _g12 = ::Enemy_obj::__new((int)2016,(int)192,(int)-16744448);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(174)
			this->enemies->add(_g12);
			HX_STACK_LINE(175)
			::Enemy _g13 = ::Enemy_obj::__new((int)2144,(int)64,(int)-65536);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(175)
			this->enemies->add(_g13);
			HX_STACK_LINE(176)
			::Enemy _g14 = ::Enemy_obj::__new((int)2272,(int)416,(int)-16776961);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(176)
			this->enemies->add(_g14);
			HX_STACK_LINE(177)
			::Enemy _g15 = ::Enemy_obj::__new((int)2624,(int)320,(int)-65536);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(177)
			this->enemies->add(_g15);
			HX_STACK_LINE(178)
			::Enemy _g16 = ::Enemy_obj::__new((int)2880,(int)416,(int)-16776961);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(178)
			this->enemies->add(_g16);
			HX_STACK_LINE(179)
			::Enemy _g17 = ::Enemy_obj::__new((int)3072,(int)192,(int)-16744448);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(179)
			this->enemies->add(_g17);
		}
		HX_STACK_LINE(182)
		this->add(this->enemies);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,addEnemies,(void))

Void PlayState_obj::gameOver( ::flixel::util::FlxTimer t){
{
		HX_STACK_FRAME("PlayState","gameOver",0x64a21997,"PlayState.gameOver","PlayState.hx",187,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(187)
		::flixel::FlxState State = ::GameOver_obj::__new(null());		HX_STACK_VAR(State,"State");
		HX_STACK_LINE(187)
		::flixel::FlxG_obj::game->_requestedState = State;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PlayState_obj,gameOver,(void))

Void PlayState_obj::gameWin( ){
{
		HX_STACK_FRAME("PlayState","gameWin",0xd3b41939,"PlayState.gameWin","PlayState.hx",191,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(192)
		this->remove(this->enemiesLeftText,null());
		HX_STACK_LINE(194)
		this->won = true;
		HX_STACK_LINE(196)
		::flixel::text::FlxText winText = ::flixel::text::FlxText_obj::__new((int)0,(int)0,(int)0,HX_CSTRING("You won!"),null(),null());		HX_STACK_VAR(winText,"winText");
		HX_STACK_LINE(197)
		winText->scrollFactor->set_x((int)0);
		HX_STACK_LINE(198)
		winText->set_size((int)12);
		HX_STACK_LINE(199)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(winText,null(),null());
		HX_STACK_LINE(200)
		this->add(winText);
		HX_STACK_LINE(202)
		::flixel::text::FlxText restart = ::flixel::text::FlxText_obj::__new((int)0,(winText->y + (int)30),(int)0,HX_CSTRING("Press 'ENTER' to play again."),null(),null());		HX_STACK_VAR(restart,"restart");
		HX_STACK_LINE(203)
		restart->scrollFactor->set_x((int)0);
		HX_STACK_LINE(204)
		restart->set_size((int)12);
		HX_STACK_LINE(205)
		::flixel::util::FlxSpriteUtil_obj::screenCenter(restart,true,false);
		HX_STACK_LINE(206)
		this->add(restart);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,gameWin,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(level1,"level1");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(enemies,"enemies");
	HX_MARK_MEMBER_NAME(portal,"portal");
	HX_MARK_MEMBER_NAME(hud,"hud");
	HX_MARK_MEMBER_NAME(currentLevel,"currentLevel");
	HX_MARK_MEMBER_NAME(timer,"timer");
	HX_MARK_MEMBER_NAME(timerText,"timerText");
	HX_MARK_MEMBER_NAME(enemiesLeft,"enemiesLeft");
	HX_MARK_MEMBER_NAME(enemiesLeftText,"enemiesLeftText");
	HX_MARK_MEMBER_NAME(won,"won");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(level1,"level1");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(enemies,"enemies");
	HX_VISIT_MEMBER_NAME(portal,"portal");
	HX_VISIT_MEMBER_NAME(hud,"hud");
	HX_VISIT_MEMBER_NAME(currentLevel,"currentLevel");
	HX_VISIT_MEMBER_NAME(timer,"timer");
	HX_VISIT_MEMBER_NAME(timerText,"timerText");
	HX_VISIT_MEMBER_NAME(enemiesLeft,"enemiesLeft");
	HX_VISIT_MEMBER_NAME(enemiesLeftText,"enemiesLeftText");
	HX_VISIT_MEMBER_NAME(won,"won");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hud") ) { return hud; }
		if (HX_FIELD_EQ(inName,"won") ) { return won; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { return timer; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"level1") ) { return level1; }
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"portal") ) { return portal; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enemies") ) { return enemies; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"gameWin") ) { return gameWin_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameOver") ) { return gameOver_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timerText") ) { return timerText; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"addEnemies") ) { return addEnemies_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enemiesLeft") ) { return enemiesLeft; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentLevel") ) { return currentLevel; }
		if (HX_FIELD_EQ(inName,"bulletHitMap") ) { return bulletHitMap_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bulletHitEnemy") ) { return bulletHitEnemy_dyn(); }
		if (HX_FIELD_EQ(inName,"enemyHitPlayer") ) { return enemyHitPlayer_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"enemiesLeftText") ) { return enemiesLeftText; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"playerOverlapPortal") ) { return playerOverlapPortal_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"hud") ) { hud=inValue.Cast< ::HUD >(); return inValue; }
		if (HX_FIELD_EQ(inName,"won") ) { won=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"timer") ) { timer=inValue.Cast< ::flixel::util::FlxTimer >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"level1") ) { level1=inValue.Cast< ::LevelLoader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"portal") ) { portal=inValue.Cast< ::Portal >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enemies") ) { enemies=inValue.Cast< ::flixel::group::FlxGroup >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"timerText") ) { timerText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"enemiesLeft") ) { enemiesLeft=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"currentLevel") ) { currentLevel=inValue.Cast< ::LevelLoader >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"enemiesLeftText") ) { enemiesLeftText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("level1"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("enemies"));
	outFields->push(HX_CSTRING("portal"));
	outFields->push(HX_CSTRING("hud"));
	outFields->push(HX_CSTRING("currentLevel"));
	outFields->push(HX_CSTRING("timer"));
	outFields->push(HX_CSTRING("timerText"));
	outFields->push(HX_CSTRING("enemiesLeft"));
	outFields->push(HX_CSTRING("enemiesLeftText"));
	outFields->push(HX_CSTRING("won"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::LevelLoader*/ ,(int)offsetof(PlayState_obj,level1),HX_CSTRING("level1")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,player),HX_CSTRING("player")},
	{hx::fsObject /*::flixel::group::FlxGroup*/ ,(int)offsetof(PlayState_obj,enemies),HX_CSTRING("enemies")},
	{hx::fsObject /*::Portal*/ ,(int)offsetof(PlayState_obj,portal),HX_CSTRING("portal")},
	{hx::fsObject /*::HUD*/ ,(int)offsetof(PlayState_obj,hud),HX_CSTRING("hud")},
	{hx::fsObject /*::LevelLoader*/ ,(int)offsetof(PlayState_obj,currentLevel),HX_CSTRING("currentLevel")},
	{hx::fsObject /*::flixel::util::FlxTimer*/ ,(int)offsetof(PlayState_obj,timer),HX_CSTRING("timer")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,timerText),HX_CSTRING("timerText")},
	{hx::fsInt,(int)offsetof(PlayState_obj,enemiesLeft),HX_CSTRING("enemiesLeft")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,enemiesLeftText),HX_CSTRING("enemiesLeftText")},
	{hx::fsBool,(int)offsetof(PlayState_obj,won),HX_CSTRING("won")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("level1"),
	HX_CSTRING("player"),
	HX_CSTRING("enemies"),
	HX_CSTRING("portal"),
	HX_CSTRING("hud"),
	HX_CSTRING("currentLevel"),
	HX_CSTRING("timer"),
	HX_CSTRING("timerText"),
	HX_CSTRING("enemiesLeft"),
	HX_CSTRING("enemiesLeftText"),
	HX_CSTRING("won"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("bulletHitMap"),
	HX_CSTRING("bulletHitEnemy"),
	HX_CSTRING("enemyHitPlayer"),
	HX_CSTRING("playerOverlapPortal"),
	HX_CSTRING("addEnemies"),
	HX_CSTRING("gameOver"),
	HX_CSTRING("gameWin"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
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

void PlayState_obj::__boot()
{
}


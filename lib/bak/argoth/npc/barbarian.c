#include <lib.h>
#include "../argoth.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
    SetKeyName("Grizshnak");
    SetShort("Grizshnak the Uhnga-Warggrad");
    SetId( ({ "grizshnak", "barbarian" }) );
    SetLong("Grizshnak is a large, barbarous looking orc who has taken up "
    "camp in the city of Karak Varn.  He looks like a loner, and he also "
    "looks like he could fend for himself with absolutely no difficulty.");
    SetRace("orc");
  SetClass("fighter");
    SetLevel(45);
  SetGender("male");
  SetPlayerTitles( ([
    "newbie"  : "the Bludgeoner",
    "mortal"  : "the Stomper",
    "hm"      : "the Bloodsoaked",
    "legend"  : "the Uhnga-Warggrad",
    "avatar"  : "the Grul-Whardan of the Barbarians",
    "ranger"  : "the Wanderer",
    "fighter" : "the Pulverizer",
       ]) );
    SetTown("Karak");
    SetInventory( ([
    ARGOTH_OBJ + "bar_axe.c" : "wield axe",
    ]) );
    SetFreeEquip( ([
    ARGOTH_OBJ + "newbie_axe.c" : 1,
    ]) );
    SetAction(5, ({
    "!emote shifts his weight slightly, looking for signs of danger.",
    "!emote has visible difficulty scratching an itch on his back.",
    "!emote snorts loudly.",
    }) );
    SetCombatAction(5, ({
    "!emote roars ferociously, revelling in battle.",
    "!say Grizshnak smash!!!!",
    "!say Die, puny little thing!",
    "!say I crush your head like a rock!",
    }) );
 }

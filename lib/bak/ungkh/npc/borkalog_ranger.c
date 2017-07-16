#include <lib.h>
#include <std.h>
#include "../ungkh.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetTown("Ungkh");
  SetKeyName("Borkalog");
  SetShort("Borkalog the Animal");
  SetLong(
    "Of all the rangers in Ungkh, Borkalog is the "
    "nastiest.  The rangers of Ungkh are of a different "
    "breed than the other across Kailie.  Those of Ungkh "
    "are more animal like, and Borkalog proves this point "
    "the best.");
  SetId( ({ "borkalog","animal" }) );
  SetRace("ogre");
  SetGender("male");
  RemoveLanguage("Gnollish");
  SetLanguage("Uruk",100,1);
  SetClass("ranger");
  SetLevel(50);
  SetPlayerTitles( ([
    "newbie" : "the Brutal Dog",
    "mortal" : "the Unmerciful Wolf",
    "hm"     : "the Pitiless Bear",
    "legend" : "the Savage Lion",
    "avatar" : "the Inhuman Demon",
    ]) );
  SetAction(1, ({
    "!emote growls ferociously.",
    "!emote drools like a rabid wolf.",
    }) );
  SetTaughtSpheres( ({
    "natural", "natural evokation", "natural healing"
    }) );
  SetCombatAction(1, ({
    }) );
  SetInventory( ([
    "/std/weapon/slash/longsword" : "wield sword",
    ]) );
  SetUniqueSkills( ([
    "slash defense" : 0,
    "slash attack" : 0,
    "hack attack" : 1,
    "hack defense" : 1,
    "evokation" : 1,
    "projectile attack" : 3,
    "projectile defense" : 3,
    ]) );
  SetFreeEquip( ([
     "/std/weapon/hack/hand-axe" : 2,
    ]) );
  }

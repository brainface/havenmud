#include <lib.h>
#include <daemons.h>
#include <domains.h>
#include <std.h>
inherit LIB_NPC;
int Fighty();

static void create() {
  npc::create();
  SetKeyName("bandit");
  SetShort("a rough looking bandit");
  SetLong("This is a large rough looking bandit.  His demeanor suggests "
          "that combat is nothing new to him.");
  SetId( ({ "bandit", "rough looking bandit" }) );
  SetAdjectives( ({ "rough", "rough looking" }) );
  SetClass("fighter");
  SetMorality(-200);
  SetLevel(random(2)+1);
  SetFriends( ({ "bandit" }) );
  SetGender("male");
  SetRace("human");
  SetCurrency("ducats",random(20));
  SetInventory( ([
       AVERATH_OBJ + "shield" : "wear shield on right arm",
       AVERATH_OBJ + "battleaxe" : "wield battleaxe",
       STD_FARMING "temperate/potato" : 2,
         ]) );
  }


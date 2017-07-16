#include <lib.h>

inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("guard");
  SetRace("nosferatu");
  SetClass("priest");
  SetLevel(100);
  SetSkill("melee combat", 100, 1);
  SetGender("male");
  SetMorality(-1000);
  SetId( ({
    "guard",
    }) );
  SetAdjectives( ({
    "hall",
    }) );
  SetShort("a guard of the hall");
  SetLong("This stoic guard keeps constant vigil on his post.  "
          "With dark black skin and an evil glare, he seems "
          "to truely be a force upon Kailie.");
  SetAction(4, ({
    "!growl",
    }) );
  SetReligion("Saahagoth");
  SetSpellBook( ([
    "purify"         : 100,
    "wall of souls"  : 100,
    "cause bleeding" : 100,
    ]) );
  SetCombatAction(25, ({
    "!cast purify",
    "!cast wall of souls",
    "!cast cause bleeding",
    }) );
  SetFriends( ({ "guard" }) );
  SetInventory( ([
    "/std/armour/pants/studded_leather_pants" : "wear pants",
    ]) );
  SetCurrency("crystals",250 + random(150) );
  }

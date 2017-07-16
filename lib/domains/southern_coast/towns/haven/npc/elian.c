/*  Elian Valen, a trainer */
#include <lib.h>
#include "../haven.h"
inherit LIB_TRAINER;

static void create() {
  ::create();
  SetKeyName("elian");
  SetId( ({ "elian", "trainer" }) );
  SetRace("elf");
  SetGender("female");
  SetClass("evoker");
  SetSkill("evokation",1,1);
  SetSkill("enchantment",1,1);
  SetSkill("conjuring",1,1);
  SetSkill("melee combat",1,2);
  SetTown("Haven");
  SetLevel(40);
  SetMorality(250);
  SetShort("Elian Valen, a trainer of magical skills");
  SetLong("Elian Valen is a mage of some reknown.  She is also an "
    			"teacher in the ways of magic. Perhaps you could ask her to"
    			" teach you something?");
  SetAdjectives( ({ }) );
  SetSpellBook( ([
    "fireball" 						 : 100,
    "bolt"           			 : 100,
    "energy field"   			 : 100,
    "chain lightning"			 : 100,
    "haste"								 : 100,
    "create magic reserve" : 100,
    "planar durability"    : 100,
    "planar strength"      : 100,
  	]) );
  SetAction(5, ({
    "!speak Would you like to be trained?",
    "!cast energy field",
    "!cast haste",
    "!cast planar strength",
    "!cast planar durability",
	  }) );
  SetCombatAction(60, ({
    "!cast fireball",
    "!cast chain lightning",
    "!cast bolt",
    "!cast energy field",
    }) );
 }

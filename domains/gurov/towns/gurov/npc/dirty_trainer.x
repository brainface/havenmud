#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../gurov.h";
inherit LIB_TRAINER;


static void create() {
  ::create();
  SetKeyName("old man");
  SetShort("a shadowy old man");
  SetRace("human");
  SetBaseLanguage("Gurovian");
  SetClass("rogue");
  SetSkill("dirty tricks",1);
  AddTrainingSkill("dirty tricks");
  AddTrainingSkill("knife combat");
  AddTrainingSkill("stealth");
  AddTrainingSkill("lockpicking");
  SetLevel(350);
  //SetInvis(1);
  SetGender("male");
  SetId( ({ "man" }) );
  SetAdjectives( ({ "shadowy", "old" }) );
  SetLong("The old man is covered by shadows slowly bending around his body. "
          "The shadows cover his form but he appears to be human and quite "
          "old, older then any human. The shadows cover the rest of his features "
          "but an intense energy and power radiates from every glance he makes.");
  SetMorality(-1000);
  SetInventory( ([
      STD_CLOTHING + "body/gray_robe" : "wear robe",
      GUROV_OBJ + "dirty_knife" : "wield switchblade",
  ]) );

  SetCombatAction( 50, ({
    "!hock",
    "!bumrush",
    "!fade",
    "!hamstring", //not yet in
    "!gut", //not yet in
    "!gouge", //away, you can
    "!gouge", //away
  }) );

  // creeping this guy up.
  SetDie("A drab gray robe falls to the ground. No evidence of the man you were just fighting remains.");
  SetNoCorpse(1);
}


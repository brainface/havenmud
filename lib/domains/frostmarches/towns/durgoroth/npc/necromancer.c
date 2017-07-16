
#include <lib.h>
#include <std.h>
#include <daemons.h>
#include "../durgoroth.h"

inherit LIB_LEADER;
 
static void create() {
  leader::create();
  SetKeyName("Mekrzi");
  SetRace("daemon");
  SetClass("necromancer");
  SetSkill("poison magic",1,1);
  SetLevel(240);
  SetGender("male");
  SetShort("Mekrzi the Lich");
  SetId( ({ "mekrzi","necromancer","daemon", "durg_nocombat" }) );
  SetLong("A massive daemon of questionable stability,"
          " Mekrzi has made a life out of playing with"
          " the dead and rotting. His entire body is"
          " covered in bits and pieces of other"
          " daemons and his scales look to be"
          " permanently stained with blood. He looks"
          " more than capable of defending himself"
          " and as though he might enjoy the challenge."
          " His knowledge in magical necromancy is"
          " unsurpassed in these parts and young"
          " daemons with an affliction for dominance"
          " and control of the dead would be wise"
          " to learn from Mekzri.");
  SetTaughtSpheres( ({
      "necromancy",
      "magical evokation",
      "magical necromancy",
      }) );
  SetUniqueSkills( ([
      "stealth" : 0,
      "knife combat" : 1,
      "natural armour" : 2,
    ]) );
  SetSpellBook( ([
    "vampiric touch"     : 100,
    "hunger"             : 100,
    "soultap"            : 100,
    "wither"             : 100,
    "flamestrike"        : 100,
    "curse"              : 100,
    "temperature shield" : 100,
     ]) );
  SetAction(10, ({
    "!roar",
    "!cackle",
    "!speak Do you wish to join my army? No? Then leave"
           " me in peace before I destroy you.",
    }) );
  SetCombatAction(50, ({
    "!cast curse",
    "!cast vampiric touch",
    "!cast soultap",
    "!cast wither",
    "!cast flamestrike",
    "!cast hunger",
    "!cackle",
    "!cast temperature shield",
    }) );
  SetReligion("Saahagoth","Saahagoth");
  SetTown("Durgoroth");
  SetMorality(-3000);
  SetPlayerTitles( ([
      "newbie"   : "the Necrophile",
      "mortal"   : "the Necrotic Nuisance",
      "hm"       : "the Harbinger of Death",
      "legend"   : "Lich $N the Perverter of Life",
      "avatar"   : "the Long-Lived Reaper of Souls",
       "fighter"  : "Revenant $N the Scythe of Annihilation",
     ]) );
  SetFreeEquip( ([
     "/std/weapon/pole/freeknife" : 1,
     DURG_OBJ "scale_robe" : 1,
     ]) );
  SetInventory( ([
     DURG_OBJ "necro_knife" : "wield knife",
     DURG_OBJ "necro_robe"  : "wear robe",
     DURG_OBJ "bone_horseshoe" : "wear 1st shoe on left hoof",
     DURG_OBJ "bone_horseshoe2" : "Wear 1st shoe on right hoof",
     ]) );
  SetCurrency("crystals", 5000);
  SetFirstCommands( ({ 
    "cast temperature shield",
    "cast temperature shield",
    "cast temperature shield",
    "cast temperature shield",
    "cast temperature shield",
    }) );

  }


void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 5) {
    eventForce("cast temperature shield");

  }
}

//
// filename: guard2
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../firecastle.h"
inherit LIB_SENTIENT;
inherit LIB_FEAR;
void eventSpecial();

static void create() {
  ::create();
  SetKeyName("elemental guard");
  SetId( ({ "guard" }) );
  SetShort("an elemental guard");
  SetLong(
          "This elemental is completely composed of brightly burning fire. It "
          "is considerably larger then other elementals that exist on the "
          "plane of Fire but like the others its volatile temper is only "
          "matched by its fire."
  );
  SetAdjectives( ({ "elemental", "fire" }) );
  SetFearType("elemental fear");
  SetResistLevel(159);
  SetFearLength(10);
  SetRace("elemental");
  SetClass("necromancer");
  SetClass("cavalier");
  SetLevel(160);
  AddLimb ("right arm","torso",2,({A_SHIELD,A_BODY_ARMOUR}));
  AddLimb ("left arm","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("right leg","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("left leg","torso",2,({A_BODY_ARMOUR}));
  AddLimb ("right hand","right arm",4,({A_WEAPON,A_BODY_ARMOUR}));
  AddLimb ("left hand","left arm",4, ({A_WEAPON,A_BODY_ARMOUR}));
  AddLimb ("right foot","right leg",4,({A_BODY_ARMOUR}));
  AddLimb ("left foot","left leg",4,({A_BODY_ARMOUR}));
  SetLanguage("Archaic", 100, 1);
  RemoveLanguage("Elementalish");
  SetStat("intelligence", 300, 1);
  SetStat("wisdom", 300, 1);
  SetNoCorpse(1);
  SetDie("The elemental dissipates into the air."); 
  SetResistance(WATER, "weakness");
  SetResistance(COLD, "weakness");
  SetResistance(MAGIC, "high");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(SLASH, "immune");
  SetResistance(PIERCE, "immune");
  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "high");
  SetSpellBook( ([
    "flamestrike" : 100,
    "temporal barrier" : 100,
    "mage's bane"    : 100,
    "chain lightning" : 100,
    ]) );
  SetCombatAction(10, ({ 
    "!cast flamestrike",
    "!cast chain lightning",
     }) );
  SetInventory ( ([
    FCASTLE_OBJ "/elem_rapier" : "wield rapier",
    FCASTLE_OBJ "/elem_knife2" : "wield knife",
    FCASTLE_OBJ "/thronekey" : 1,
    ]) );  
  SetFirstCommands( ({ 
    "cast temporal barrier", 
    "cast temporal barrier",
    "cast temporal barrier",
  }) );

  }

void init() {
  ::init();
  fear::init();

  }

void heart_beat() {
  ::heart_beat();
  if (sizeof(GetMagicProtectionNames()) < 3) {
    eventForce("cast temporal barrier");
  }
}

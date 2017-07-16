//
// filename: irogue
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../firecastle.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("elemental rogue");
  SetId( ({ "rogue" }) );
  SetShort("an elemental rogue");
  SetLong(
          "This elemental is completely composed of brightly burning fire. It "
          "is considerably larger then other elementals that exist on the "
          "plane of Fire but like the others its volatile temper is only "
          "matched by its fire."
  );
  SetAdjectives( ({ "elemental", "fire" }) );
  SetInvis(1);
  SetRace("elemental");
  SetClass("rogue");
  SetLevel(200);
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
  SetStat("durability", 300, 1);
  SetStat("strength", 300, 1);
  SetStat("luck", 300, 1);
  SetStat("wisdom", 300, 1);
  SetStat("charisma", 300, 1);
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
  SetInventory ( ([
    FCASTLE_OBJ "/eknife2" : "wield knife",
    FCASTLE_OBJ "/elem_knife" : "wield knife",
    ]) );  
    SetCombatStyle("blade dancing");
  SetFirstCommands( ({ "wield knives" }) );
    SetCombatStyleLevel("blade dancing", 100);
  }

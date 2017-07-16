//
// filename: lord
// Thoin@Haven 01-16-06
//

#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../firecastle.h"
inherit LIB_SENTIENT;
inherit LIB_FEAR;
void eventSpecial();
int eventCheckPlayer();

static void create() {
  ::create();
  SetKeyName("Lord Scharix");
  SetId( ({ "lord", "Scharix", "scharix" }) );
  SetShort("Lord Scharix");
  SetLong(
          "This elemental figure is larger then all others. It's eyes glow with "
          "a brilliant blue light making it stand apart from all others. But it "
          "shares the volatile temper of its kin."
  );
  SetAdjectives( ({ "elemental", "fire" }) );
  SetFearType("elemental fear");
  SetResistLevel(199);
  SetFearLength(10);
  SetRace("elemental");
  SetClass("necromancer");
  SetClass("cavalier");
  SetLevel(250);
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
  SetResistance(MAGIC, "high");
  SetResistance(HEAT, "immune");
  SetResistance(BLUNT, "immune");
  SetResistance(COLD, "immune");
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
    FCASTLE_OBJ "/lsword" : "wield sword",
    FCASTLE_OBJ "/lsword2" : "wield sword",
    ]) );  
  SetFirstCommands( ({ 
    "cast temporal barrier", 
    "cast temporal barrier",
  }) );
  SetEncounter( (: eventCheckPlayer :) );
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

int eventCheckPlayer() {
  object who = this_player();
  if (userp(who)) {
     SetAttack(who);
     eventForce("speak You shall regret intruding on me, fool!");
     return 1;
    }
  else return 0;
 }

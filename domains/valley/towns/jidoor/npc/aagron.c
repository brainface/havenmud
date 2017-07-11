//Aagar (creator)
//Feb. 99
//moranm@muss.cis.mcmaster.ca
//Desc:  Avatar of the Elementalists.

#include <lib.h>
#include "../jidoor.h"
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
inherit LIB_NPC;

static void create ()   {
    npc::create();

  SetKeyName ("Aagron");
  SetId ( ({"Aagron","jidoor_npc",}) );
  SetAdjectives("the","elememtal");
  SetShort ("Aagron, the Elemental");
  SetLong (
    "Aagron stands at least twenty feet in height.  His hair and beard are "
    "pure flame, while his clothing seems woven from the earth itself.  "
    "His eyes glow bright with the light of magic, and his gaze can "
    "penetrate the depths of the soul.  He is one with the elements, and "
    "his power to control them is unequalled.");

  SetRace ("elemental");
  SetGender ("male");
  AddLimb ("right arm","torso",2,({A_SHIELD,A_BODY_ARMOUR}));
  AddLimb ("left arm","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("right leg","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("left leg","torso",2,({A_BODY_ARMOUR}));
  AddLimb ("right hand","right arm",4,({A_BODY_ARMOUR}));
  AddLimb ("left hand","left arm",4, ({A_WEAPON,A_BODY_ARMOUR}));
  AddLimb ("right foot","right leg",4,({A_BODY_ARMOUR}));
  AddLimb ("left foot","left leg",4,({A_BODY_ARMOUR}));
  SetClass("fighter");
  SetSkill("evokation",1,1);
  SetSkill("natural magic",1,1);
  SetSkill("conjuring",1,1);
  SetSkill("shock magic",1,2);
  SetSkill("ice magic",1,2);
  SetSkill("fire magic",1,2);
  SetLevel(150);
  SetUnique(1);
  SetSize(SIZE_LARGE);

  //lol no SetStat("wisdom", 100000, 1);
  SetResistance(ALL_ELEMENTS, "immune");
  SetResistance(MAGIC, "medium");
  SetResistance(ALL_PHYSICAL, "weakness"); // fuckit

  SetResistance(HUNGER, "medium");
  SetResistance(DISEASE, "medium");

  SetInventory ( ([
    JID_OBJ + "/air_helm" : "wear helm",
    JID_OBJ + "/earth_armour" : "wear armour on torso and right arm and left arm and left leg and right leg",
    JID_OBJ + "/flame_sword" : "wield sword",
    JID_OBJ + "/ice_shield" : "wear shield on right arm",
    ]) );

  SetAction (3, ({
    "!emote intones a prayer to the Lord of Elemental Energies.",
    "!say Lord Zaxan be with you, my child.",
    "!say One who seeks to know the world must first understand "
      "the elements that compose it.",
  }) );

  SetSpellBook ( ([
    "fireball"           : 100,
    "chain lightning"    : 100,
    "temperature shield" : 100,
    "ice ball"           : 100,
    "lunar blast"        : 100,
    "heat"               : 100,
    "natural charge"     : 100,
    "wall of wood"       : 100,
    "flamestrike"        : 100,
    "plant strike"       : 100,
    "ice storm"          : 100,
    ]) );

  SetCombatAction (40, ({
    "!cast fireball",
    "!cast chain lightning",
    "!cast temperature shield",
    "!cast ice ball"
    "!cast lunar blast",
    "!cast heat",
    "!cast natural charge",
    "!cast wall of wood",
    "!cast flamestrike",
    "!cast plant strike",
    "!cast ice storm",
    "!emote channels the power of the elements to vanquish you.",
    "!say Lord Zaxan, I beseech you, destroy this heathen!",
    "!emote swings his fiery sword, igniting the very air in its "
      "wake.",
  }) );

  SetLanguage ("Blaodric",100,1);
  SetLanguage ("Eltherian", 100,1);
  SetLanguage ("Sprith", 100,1);
  SetLanguage ("Uruk", 100,1);
  SetLanguage ("Barian", 100,1);
  SetLanguage ("Heyami", 100,1);
  SetLanguage ("Oiseau",100,1);
  SetLanguage ("Gobyshkin", 100,1);
  SetLanguage ("Barian", 100,1);
}


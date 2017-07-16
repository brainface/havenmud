//Aagar (creator)
//Feb. 99
//moranm@muss.cis.mcmaster.ca
//Desc:  Avatar of the Elementalists.

#include <lib.h>
#include "../jidoor.h"
#include <armour_types.h>
inherit LIB_NPC;

static void create ()   {
    npc::create();

  SetKeyName ("Aagron");
  SetId ("Aagron");
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
  SetClass ("enchanter");
  SetClass ("fighter");
    SetSkill ("enchantment", 1,1);
    SetSkill ("evokation", 1,1);
    SetSkill ("pole attack", 1,1);
    SetSkill ("conjuring", 1,1);
    SetSkill ("slash defense", 1,2);
    SetSkill ("projectile defense", 1,2);
    SetSkill ("melee defense", 1,2);
    SetSkill ("elemental magic", 1,1);
    SetSkill ("healing", 1,2);
    SetSkill ("divination", 1,2);
    SetSkill ("pole defense" ,1,2);
  SetLevel (150);
  SetUnique (1);
  
  SetInventory ( ([
    JID_OBJ + "/air_helm" : "wear helm",
    JID_OBJ + "/earth_armour" : "wear armour",
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

    "enhanced fireball" : 100,
    "chain lightning" : 100,
    "aura" : 100,
    "ice ball" : 100,
    "acid blast" : 100,
    "heat" : 100,
    "enhanced natural shield" : 100,
    "enhanced energy wall" : 100,
    ]) );

  SetCombatAction (11, ({
  "!cast enhanced fireball",
  "!cast ice ball"
  "!cast enhanced energy wall",
  "!cast chain lightning",
  "!cast heat",
  "!cast enhanced natural shield",
  "!cast aura",
  "!cast acid blast",
  "!emote channels the power of the elements to vanquish you.",
  "!say Lord Zaxan, I beseech you, destroy this heathen!",
  "!emote swings his fiery sword, igniting the very air in its "
  "wake.",
  }) );
  
  SetLanguage ("Blaodric",100,1);
  SetLanguage ("Eltherian", 100,1);
  SetLanguage ("Sprith", 100,1);
  SetLanguage ("Uruk", 100,1);
  SetLanguage ("Shangtai", 100,1);
  SetLanguage ("Barian", 100,1);
  SetLanguage ("Heyami", 100,1);
  SetLanguage ("Oiseau",100,1);
  SetLanguage ("Gobyshkin", 100,1);
  SetLanguage ("Barian", 100,1);
}

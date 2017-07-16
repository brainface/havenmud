#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_NPC;
#include "../maze.h"

static void create() {
  npc::create();
  SetKeyName("minotaur");
  SetResistance(ALL_PHYSICAL, "high");   
  SetRace("elemental", "minotaur");
  SetGender ("male");
  AddLimb ("right arm","torso",2,({A_BODY_ARMOUR}));
  AddLimb ("left arm","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("right leg","torso",2, ({A_BODY_ARMOUR}));
  AddLimb ("left leg","torso",2,({A_BODY_ARMOUR}));
  AddLimb ("right hand","right arm",4,({A_WEAPON, A_BODY_ARMOUR}));
  AddLimb ("left hand","left arm",4, ({A_WEAPON, A_BODY_ARMOUR}));
  AddLimb ("right hoof","right leg",4,({A_BODY_ARMOUR}));
  AddLimb ("left hoof","left leg",4,({A_BODY_ARMOUR}));
  AddLimb ("left horn","head",5);  
  AddLimb ("right horn","head",5);
  SetEncounter(100);    
  SetClass("valkyr");
  SetLevel(random(100) + 150);
  SetCombatAction(5, ({ "!grunt", "!growl" }));
  SetInventory ( ([
    MAZE_OBJ + "club" : "wield clubs",
    MAZE_OBJ + "club" : "wield clubs",    
  ]) );
  SetShort("a huge minotaur");
  SetAdjectives( ({ "huge" }) );
  SetId( ({ "minotaur" }) );
  SetLong("This huge creature is extremely well built, with incredibly tough "
    "skin. He is covered in thick, curled black fur. The drool dripping from "
    "this foul creature's evil-looking grinning mouth suggests that he is "
    "hungry, and doesn't particularly care who, or what he eats. His horns "
    "look like they have been sharpened on rocks, and seem incredibly "
    "dangerous.");  
}

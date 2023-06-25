// Roving Estergrym undead, reduced everything
// Funny SetId i used to link friendlys to other Estergrym Undead
// If Undead bad on mainroad, dont use it. Not Aggro.
// Urien@Haven 25JUN2023
 

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("human","undead corpse");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(3)+2);
  SetKeyName("corpse");
  SetId( ({ "corpse","undead_wander"}) );
  SetShort("a walking corpse");
  SetAdjectives( ({ "walking", "undead" }) );
  SetLong("A humanoid approximatly of average height and build but "
          "completely rotted. Exposed body parts and internal organs "
          "can be seen infested with other detritus. It looks rather "
          "ancient with the exposed skull bleached from the natural "
          "elements. The bottom jaw of the walking corpse is missing "
          "showing the back throat and dried, blackened blood. Both "
          "eyes are missing below the aged melted nose of the undead "
          "human. It seems undetermined, as if the mission it was "
          "resurrected by dark magics for has expired or forgotten and "
          "ignores the surroundings almost completely.");
  SetUndead(1);
  SetWander(2);   //I want this super slow, 1 did nothing.
  SetDie("The corpse falls over, completely lifeless.");
  SetInventory( ([
  WORLD_OBJ + "wand_wcross"   : "wield crossbow",
  ]) );
  SetMorality(-35);
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}

// An aggro NPC to trigger the invasions
// No players should ever access this room
// Anything with a body will die.
// Urien@Haven 8/27/13

#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../invas.h"  

inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("meat grinder");
  SetId( ({ "grinder"}) );
  SetShort("a heavily used meat grinder");
  SetAdjectives( ({ "grinder","meat" }) );
  SetLong("This meat grinder is completely covered in blood. "
          "It is a marvel of what orcs tied to a chain and "
          "prodded repeatedly with a pointy stick can accomplish. It "
          "is made of pure steel and is massive in size. The main "
          "blade spins so fast it is a complete blur. The panels "
          "on the inside are protected with other mini blades which "
          "spin aggressively. It appears to be powered by pure "
          "evil and malice.");
  SetMorality(1000);
  SetInventory( ([
        INVAS_OBJ+ "sawblade02" : "wield blade",
  ]) );
  SetClass("fighter");
  SetLevel(5000); // High combat, Low spam
  SetRace("elemental");
  SetGender("female");
  SetEncounter(500);
  SetFirstCommands( ({
    "emote accelerates itself enthusiastically.",
    "emote awaits your command.",
   }) );
  SetDie("The grinder breaks down and explodes!");
  SetNoCorpse(1);
}
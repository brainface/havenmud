#include <lib.h>
#include <daemons.h>
#include <damage_types.h>
inherit LIB_NPC;

static void create() {
  ::create();

  // spells lib autoreplaces $race with race
  SetShort("a rotting animated $r zombie");
  SetLong("A rotting corpse of $r, animated into a crude "
	  "semblance of life by dark arts.");
  SetId("zombie");
  SetKeyName("$r zombie");
  SetAdjectives( ({"rotting","animated"}) );
  SetDie("The zombie crumbles into dust.");
  
  SetResistance(BLUNT|SOUND,"low"); 
  SetResistance(SLASH|HEAT,"weakness");
  SetResistance(GAS|POISON|HUNGER|DISEASE,"immune");  
  
  SetNoCorpse(1);
  SetUndead(1);
  SetUndeadType("zombie");
}

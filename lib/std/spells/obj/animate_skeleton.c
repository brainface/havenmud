#include <lib.h>
#include <daemons.h>
#include <damage_types.h>

inherit LIB_NPC;

static void create() {
  ::create();

  // spells lib autoreplaces $race with race
  SetShort("a clacking $r skeleton"); 
  SetLong("The mobile, rattling skeleton of $r, held upright "
	  "and angry by necrotic command.");
  SetId("skeleton");
  SetKeyName("skeletal $r");
  SetAdjectives( ({"skeletal","clacking"}) ); 
  SetDie("The skeleton collapses noisily into a heap of broken bones.");

  SetResistance(ALL_ELEMENTS|PIERCE|SLASH,"low"); 
  SetResistance(BLUNT|SOUND,"weakness");
  SetResistance(GAS|POISON|HUNGER|DISEASE,"immune");  
  
  SetNoCorpse(1);
  SetUndead(1);
  SetUndeadType("skeleton");
}

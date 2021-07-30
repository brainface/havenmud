#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("Minkin's Cellar");
  SetExits( ([
    "up"  : PARVA_ROOM "tavern",
  ]) );
  SetClimate("indoors");
  SetAmbientLight(30);
  SetInventory( ([
    PARVA_NPC "vamp_leader" : 1,
  ]) );
  SetLong( 
    "This is the cleverly hidden spot where Minkin hides his kegs of rum. Muddy footprints "
    "of various size through puddles of water on the ground reveal you were not the first "
    "to find them, by far. A flickering lantern hangs low, providing a dim bit of light "
    "to illuminate area, while black cloth covers the small windows. For some reason, a "
    "saltwater-logged coffin stands in the corner. The ladder leads back "
    "up to the tavern floor."
  );
  SetListen("The ceiling creaks and groans from the weight of the tavern above.");
  SetSmell("You can barely smell the drunken vomit over the seawater soaked wood and loam.");
  SetItems( ([
    ({ "windows", "sailcloth", "window" }) : 
      "The cellar windows are covered in black sailcloth.",
    ({ "kegs", "keg" }) :
      "Large kegs hold rum ready to be watered down to grog.",
    ({ "ceiling", "beams" }) :
      "Wooden beams at a worrisome level of decay are holding up the ceiling, each footstep "
      "of the tavern goers above visibly shakes them.",
    ({ "floor", "ground", "puddles" }) :
      "Saltwater pools in various spots on the unfinished muddy floor.",
    ({ "ladder" }) :
      "A wooden ladder leads back up to the main floor.",            
    ({ "lantern" }) :
      "A lantern hanging from the ceiling provides dim light.",
    ({ "footprints" }) :
      "Dainty slipper-prints, toeless boots, barefoot orcish feet, and at least one dog "
      "has pawed through here.",
    ({ "coffin" }) :
      "Empty bottles of rum and a few old dresses and hats are tucked into the coffin.",
    ]) );        
}

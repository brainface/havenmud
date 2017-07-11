#include <lib.h>
#include "../parva.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("Minkin's Inn");
  SetExits( ([
    "out" : PARVA_ROOM "wharf5",
    "up"  : PARVA_ROOM "tavern2",
    ]) );
  SetClimate("indoors");
  SetAmbientLight(35);
  SetInventory( ([
    PARVA_NPC "barkeep" : 1,
    PARVA_NPC "barmaid" : 1,
    PARVA_NPC "armour_equipper" : 1,
    PARVA_NPC "treasurehunter" : 1,
    ]) );
  SetNewsgroups( ({"player.general"}) );
  SetLong(
    "This tavern offers everything a sailor could hope for while on shore "
    "leave. The long treastle tables and benches are kept waxed and clean, "
    "if marred with somewhat rough use. The walls are lined with tastefully "
    "erotic tapestries, which are subtly lit by sconces above. A richly "
    "carpeted oaken staircase leads into a second level of the inn."
    );
  SetListen("Unobstrusive, yet seductive music comes from somewhere in the inn.");
  SetSmell("The tavern has mixtures of smells from spilled grog to women's perfume.");
  SetItems( ([
    ({ "table", "tables", "bench", "benches" }) : "The tables and benches are wooden "
        "and designed for maximum seating rather than comfort.",
    ({ "tapestry", "tapestries" }) : "The tapestries are erotic but tasteful, with "
        "images of men and women posed to excite without revealing much.",
    ({ "staircase" })  : "The staircase leads to a more intimate level of the tavern.",
    ]) );        

}

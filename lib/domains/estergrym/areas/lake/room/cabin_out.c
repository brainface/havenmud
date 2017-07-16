// Coded by Zeratul 11-26-99
#include <lib.h>
#include "../lake.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetDomain("Estergrym");
  SetClimate("temperate");
  SetShort("outside a cabin");
  SetDayLong("Sun shines down here through the trees lighting the area "
     "peacfully. The trees are cleared around here a bit with a cabin "
     "standing in the center. Small bushes grow around the cabin's "
     "base. Long grass grows about with a small path leading up through it "
     "to the cabin's door. "
     );
  SetNightLong("The moon shines down here through the trees lighting "
     "the area peacefully. The trees are cleared around here a bit with "
     "a cabin standing in the center. Small bushes grow around the "
     "cabin's base. Long grass grows about with a small path leading up "
     "through it to the cabin's door."
     );
  SetListen( ([
     "default" : "Crickets and other wildlife can be heard.",
     ]) );
  SetSmell( ([
     "default" : "The air smells cool and fresh.",
     ]) );
  SetItems( ([
  ({"cabin",}) : "A cabin stands here in the middle of the "
     "clearing. It is made completely of evergreen trees from the "
     "surrounding area.",
     ({"path","trail"}) : "This small path leads through the tall grass "
     "making its way up to the cabin's door.",
     ({"trees","evergreen","forest"}) : "These big tress look like giant "
     "mothers protecting their children as they loom over the plantlife "
     "and provide shade to the surrounding area.",
     ]) );
  SetItemAdjectives( ([
     "trees" : ({"large","mother like","protective"}),
     "cabin" : ({"small","wood"}),
     "path" : ({"small","leading"}),
     ]) );
  SetDoor("cabin", LAKE_OBJ + "/cabin_door");
  SetEnters( ([
     "cabin" : LAKE_ROOM + "/cabin_foyer",
     ]) );
  SetExits( ([
     "southwest" : LAKE_ROOM + "/wood_cut",
     "northwest" : LAKE_ROOM + "/lake3",
     ]) );
}

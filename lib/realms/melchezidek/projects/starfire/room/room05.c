#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "../starfire.h"

inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetShort("the eastern wing in the temple");
  SetLong(
      "This large alcove appears to have been a place for quiet reflection. The"
      " domed ceiling depicts a large, blue, winged reptile shrouded in flames"
      " standing on its hind legs roaring towards the heavens. The walls below"
      " the mural are made of the same yellow sandstone found throughout the"
      " temple. Access to the temple proper is granted to the west. The remains"
      " of a wooden bench can be seen near the northern wall."
      );
  SetExits( ([
      "west"  : SF_ROOM "room03" 
      ]) );
  SetItems( ([
      ({ "dome", "mural", "alcove" }) : (: GetLong :),
      ({ "dragon", "reptile", "flames" }) :
        "The reptile looks very proud and vigorous. Its proud stance and defiant"
        " roar boasts of its vitality and power. Clearly this mural was meant"
        " to inspire awe and respect for this magnificient creature from whomever"
        "  beheld it. The red-orange of the flames provides a vivid contrast to"
        " the bright azure tone of the reptiles scales.",
      ({ "bench" }) :
        "The shattered remains of a wooden bench are seen on the northern side of"
        " the alcove. While one cannot know for sure, the way the remains lay on"
        " the floor hint at violence and not natural rot.",
      ({ "wall", "walls", "stone", "sandstone" }) :
        "The walls are made of yellow sandstone held together with yellow mortar.",
      ({ "sand", "floor", "pile", "piles" }) :
        "The floor is covered with a thin layer of sand. In some spots it has collected"
        " into small piles making it hard to determine any specifics about the"
        " underlying construction.",
      ]) );
  SetItemAdjectives( ([
      "dome"   : ({ "large", "domed" }),
      "dragon" : ({ "large", "blue", "shrouded", "winged", "roaring" }),
      "bench"  : ({ "shattered", "wooden", "northern" }),
      "wall"   : ({ "yellow", "sandstone" }),
      "sand"   : ({ "thin", "piled" }),
      ]) );
  SetInventory( ([
      SF_OBJ "eastlamp" : 1,
     ]) );
  }

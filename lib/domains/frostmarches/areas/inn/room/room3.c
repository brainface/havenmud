#include "../inn.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("a nice room");
  SetAmbientLight(35);
  SetLong("Compared to the others in the inn, this room is very nice.  There "
          "is a comfortable looking bed with clean, white sheets.  Against "
          "the north wall there is a sturdy table and a chair in front of "
          "it.  A flickering oil lamp embedded in the table provides adequate "
          "illumination for the entire room.  Shadows seem to dance on the "
          "walls.");
  SetItems( ([ 
             ({ "dancing shadows", "shadows", "dancing shadow",
                "shadow" }) :
                "The shadows on the walls from the lamp appear to dance "
                "a beautiful, mesmerizing dance together.",
             ({ "flickering oil lamp", "flickering lamp", "oil lamp",
                "lamp", "basic oil lamp", "basic lamp", "tin lamp",
                "cheap tin lamp" }) :
                "It is a basic oil lamp, made mostly of cheap tin",
             ({ "basically constructed chair",
                "uncomfortable bit of furniture", "basic chair",
                "bit of furniture", "furniture", "chair" }) :
                "This chair is basically constructed and seeminly an "
                "uncomfortable bit of furniture.",
             ({ "walls", "wall" }) :
                "These are walls with nothing on them.  Most buildings have "
                "walls such as these in order to hold up the ceiling and a "
                "second floor if one exists.",
             ({ "north wall" }) :
                "This is the north wall, as opposed to the south wall.",
             ({ "south wall" }) :
                "This is the south wall, as opposed to the north wall.",
             ({ "comfortable bed", "bed" }) :
                "The bed looks somewhat old, but fairly comfortable.",
             ({ "clean white sheets", "clean white sheet", "white sheets",
                "white sheet", "sheets", "sheet" }) :
                "The sheets look freshly cleaned, and quite soft.",
             ({ "well made table", "sturdy table", "table", "flat top",
                "top" }) :
                "This is a well made table with a flat top.  It is probably "
                "meant for travelling merchants to write on."
             ]) );
  SetSmell( ([ 
             "default" : "The unusually sweet smell of burning oil fills "
                         "the room." 
             ]) );
  SetObviousExits("east");
  SetExits( ([ "east" : I_ROOM + "/hall2" ]) );
  SetClimate("indoors");
}

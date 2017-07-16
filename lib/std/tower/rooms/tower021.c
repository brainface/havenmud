#include <mudlib.h>
#include "../rooms.h"
inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_light(1);
  set_short("southwest level 2");
  set_terrain(TER_INSIDE);
  set_long("\
The southwestern corner of the tower looks out over the forest \n\
in a huge panoramic view.  From the window, you can see out over\n\
the forest for miles.  Far off in the distance, you think you can\n\
see a mountain range.  The hall itself seems to be less imposing \n\
here, with a less aged quality about it.  The walls are adorned \n\
with paintings, and flags and standards clutter what little space\n\
has been unfilled by pictures.\n");

  add_look(({"window","view","forest"}),"\
The forest seems serene from here, above it all.\n");

  add_look(({"painting","paintings"}),"\
You see scenes of carnage and battle raging across the known lands.\n\
You see the banner of Rath-Khan being raised from Darkwind City\n\
to the far-off lands of Kerei.  You even fancy you see Souvraeli\n\
warlords bowing and paying homage to the might of Rath-Khan.\n");

  add_look("tapestry","\
Many tapestries line the walls.  They seem to be the loot of \n\
a hundred or more years of warfare on the world\n");

  add_look(({"flag","flags"}),"\
Notable flags include the last of Darkwind's true kings, \n\
The Minister of State of some Kerei Warlord's personal banner,\n\
and a Souvraeli banner you are unfamiliar with.\n");

  add_trigger("sit","You cannot sit here!\n");

  add_exit("north", TOWER + "/tower013");
  add_exit("east",  TOWER + "/tower014");
  replace_program(ROOM);
}

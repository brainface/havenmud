
/*  This is a basic workroom object that connects
 *  your workroom to Olympus, the home of the GodBoard.
 *  Please make sure to read that board at least once per
 *  day, as it is the prime means of communication.
 *  Created by Duuktsaryth@Haven
 *  Minor editing by Laoise@Haven
 *  Edited further by Vaashan@Haven 9/01/09
 */
#include <lib.h>
#include <std.h>
#include <dirs.h>
#include "vaashan.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetDomain("Averath");
  SetShort("Vaashan's workroom");
  SetLong(
    "This room appears to have been hastily constructed from stone "
    "and dark wood.  The walls are rough and unfinished, and "
    "the wood has yet to be sanded down smooth.  Burgundy drapes "
    "hang from the walls, blocking out any light that might "
    "otherwise enter through the tall windows.  Along one wall "
    "is a large wooden desk, covered in a jumble of quills, inks, "
    "and papers written in various tongues.  A high-backed leather "
    "chair sits in front of it."
  );

    SetItems( ([
    ({"wall", "walls" }) : "The walls are crafted of rough, recently hewn stone.",
    "drapes" : "The drapes are made of a thick velvet the color of blood.",
    "windows" : "Looking past the drapes reveals that the window frames are "
    	          "in fact sealed with more stone.",
    "desk" : "This desk appears to be old and well used.",
    "quills" : "These writing instruments are razor sharp.",
    "inks" : "These inks appear to be mixed with human blood!",
    "papers" : "The writing on these papers seems to shift and blur beyond "
     				   "recognition.",
    "ground" : "The ground is remarkably clean, with nary a speck of dust.",
  ]) );

  SetItemAdjectives( ([
    "drapes" : "burgundy",
  ]) );

  SetListen( ([
    "default" : "The room is very quiet.",
  ]) );

  SetSmell( ([
    "default" : "The room smells of musty old papers.",
  ]) );

  SetInventory( ([
     VAAS_NPC "jeeves" : 1,
  ]) );

  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
    "east" : STD_AREA "room/basic",
  ]) );
}

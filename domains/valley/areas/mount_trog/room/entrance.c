/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <domains.h>
#include "../trog.h"
inherit LIB_ROOM;



static void create() {
  ::create();
  SetShort("inside Mount Trog");
  SetClimate("underground");
  SetAmbientLight(15);
  SetExits( ([
//    "west" : VALLEY_TOWNS "underland/room/road05",
    "east" : TROG_ROOM "tunnel01",
    ]) );
  SetLong(
    "Here at the entrance to the caves under Mount Trog there is a well-travelled "
    "path leading both into and out of the caves. The walls of the cave here are "
    "well supported, showing that the initial sections of the cave are well-mined. "
    "A path leads deep into the mountain to the east."
    );
  SetSmell("The cave is damp and musty.");
  SetListen("Somewhere deep in the tunnels water is dripping.");
}
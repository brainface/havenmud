/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../underland.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("inside the Hospital");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "out" : "road08",
    ]) );
  SetLong(
    "Inside this small hospital several gnome-sized beds line the walls. "
    "The room is warm and relaxing, offering the very best in gnomish "
    "medicine. "
    );
  SetInventory( ([
    UNDER_NPC "healer" : 1,
    ]) );
}
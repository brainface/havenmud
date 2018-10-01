/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include <domains.h>
#include "../underland.h"
inherit LIB_ROOM;

int PreExit();

static void create() {
  ::create();
  SetExits( ([
    "west" : UNDER_ROOM "road04",
    ]) );
  AddExit("east", VALLEY_AREAS "mount_trog/room/entrance", (: PreExit :) );
  SetShort("by the entrance to Mount Trog");
  SetItems( ([
    "hall" : "This is the Hall of Magic.",
    ]) );
  SetEnters( ([
    "hall" : UNDER_ROOM "magic",
    ]) );
}

int PreExit() {
  if (!userp(this_player())) {
    if (this_player()->GetOwner() == "")
      return 0;
    }
  return 1;
}

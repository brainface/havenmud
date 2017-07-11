/* A template room.  If you don't know why you'd need this
 * don't ask.
 */
#include <lib.h>
#include "../sheep.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("near a pastoral manor house");
  SetExits( ([
    "west" : SHEEP_ROOM "field5",
    ]) );
  SetLong(
    "The field stops here in front of a large pastoral manor house. The house is built of "
    "around a sturdy wood frame, and is surrounded by a small wooden fence large enough "
    "only to keep the cows and sheep from wandering into the house. The fields open to the west, "
    "where the estate's cows and sheep aimlessly feed. Far to the west the inviting shores of "
    "the Ruined Sea beckon relief from the mindlessness of watching grass grow and animals eat."
    );
  SetSmell("The smell of sheep, while lessened here, is still strong.");
  SetListen("The sounds of the estate livestock come from the fields.");
  SetItems( ([
    ({ "house", "manor" }) : "The manor house is a large wooden structure that seems particularly oversized for "
              "such a small farm estate.",
    "fence" : "The fence is arranged in a manner consistant with keeping medium sized animals from "
              "roaming free.",
    ]) );
  SetItemAdjectives( ([
    "house" : ({ "manor" }),
    ]) );
  SetEnters( ([
    "house" : SHEEP_ROOM "manor1",
    ]) );
}
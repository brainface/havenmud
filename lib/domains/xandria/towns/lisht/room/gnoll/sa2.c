//Selket@Haven
//2006
#include <lib.h>
#include <domains.h>
#include "../../lisht.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("arid");
  SetShort("On Sorcerer's Alley");
  SetLong(
    "Here is a narrow alleyway that on which the southern side is "
    "completely walled off by the Great Library of Lisht. The "
    "library is only slightly larger than the temple off to the "
    "west. The eastern entrance stands firmly here, and another is "
    "west on the other end of the alley. The Wall Road is to the "
    "east."
    );
  SetItems( ([
    ({"door", "doors" }) : 
    "The door is huge and metallic.",
    ({"library" }) : 
    "The Great Library is tall, towering over the alley like an "
    "angry giant.",
    ]) );
  SetExits( ([
   "east" : LISHT_ROOM "gnoll/wr2",
   "west" : LISHT_ROOM "gnoll/sa1",
    ]) );
  SetEnters( ([
   "library" : LISHT_ROOM "gnoll/lib2",
    ]) );
  SetSmell("The scent of incense flows from the temple.");
  SetListen("The street is quiet, as if few come here.");
}

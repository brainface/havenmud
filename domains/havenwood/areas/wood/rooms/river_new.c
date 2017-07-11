//coded by Syra 8/97
/*  added checks by Portia  5-14-99
 */

#include <lib.h>
#include "../wood.h"
inherit LIB_FISHING;

int AcceptableCheck();

static void create() {
  fishing::create();
  SetDomain("Havenwood");
  SetShort("a large riverbank");
  SetLong("This large river runs swiftly through this section of "
    "the HavenWood. A few rocky pools are scattered along the shore "
    "providing a good hiding place for the inhabitants of the "
    "river. The animal trail continues to the east of here "
    "as there is no way to cross the river. There seem to be a "
    "great number of fish in this part of the river.  There is also a "
    "small shack off to the north end of the bank.");
  SetItems( ([
    ({"river", "shore"}) : (:GetLong:),
    ({"shack", "small shack"}) : "The shack looks old yet used frequently.",
    ({"pools"}) : "These rocky pools would make excellent hiding "
        "spots for small creatures.",
    ({"trail"}) : "The animal trail continues eastward.",
    ]) );
  SetItemAdjectives( ([
    "shack" : "old",
    "river" : ({"large", "swift"}),
    "pools" : ({"scattered", "rocky", "few"}),
    "trail" : "animal",
    ]) );
  SetExits( ([
             "east" : HWD_ROOM + "/trail4",
     ]) );
  SetInventory( ([ 
   "/domains/havenwood/areas/darkorderguild/guard" : 1,
             HWD_NPC + "/dunerabbit" : 2,
     ]) );
  SetSmell( ([
    "default" : "The area smells of fish.",
    ]) );
  SetListen( ([
        "default" : "Sounds of rushing water are here. ",
        "river" : "The water in the river "
          "bubbles and glugs as it moves along. ",
     ]) );
  SetSpeed(6);
  SetFish( ([
               HWD_OBJ + "/salmonfish" : 100,
         ]) );
  SetChance(30);
  SetMaxFishing(13);

  AddEnter("shack", "/domains/havenwood/areas/darkorderguild/main", (:AcceptableCheck:));
  }

int AcceptableCheck() {
  object who = this_player();
  object guard = present("guard", this_object());

  if (!guard) return 1;
  if (who->GetGuild() != "darkorder") {
    message("system", who->GetName() + " tries to enter the shack.",
        this_object());
    guard->eventForce("say you are not permitted to enter here.");
    return 0;
    }
  return 1;
  }



/* Approved by Amelia on Thu Sep 11 23:24:15 1997. */

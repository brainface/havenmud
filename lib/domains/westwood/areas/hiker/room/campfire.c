#include <lib.h>
inherit LIB_ROOM;
#include "../hiker.h"

string NightFire();

static void create() {
   room::create();
   SetShort("around a campfire");
   SetNightLight(10);
   SetDayLong("A ring of rocks circles some burned-out ash from the "
              "chill night before.  The ground is bare and plain, "
              "well-trampled and slightly rocky, but bare of the "
              "trees and plants of the West Wood until a little "
              "distance off, where they continue to fill the "
              "world.  To the east, a small path leads out.  A couple "
              "tents crowd near the fire.");
   SetNightLong("The night sky smiles down from above on the cheery "
                "fire in the middle of this camping around.  The ground "
                "is rocky, but free of plants ands trees until a "
                "ways off, beyond the tents.  The tents seem to bend "
                "towards the fire, and a trail is barely visible as "
                "it leads out to the east.");
   SetItems( ([
                ({ "ring of rocks","ring","rocks","rock","burned-out "
                   "ash","ash","cheery fire","fire","fresh ashes",
                   "ashes","debris" }) :
                   (: NightFire :),
                ({ "rocky ground","ground" }) :
                   "The ground is plain, bare, and rather rocky.  "
                   "It seems to get a bit smoother and less rocky to "
                   "the east along the trail.",
                ({ "west wood","wood","woods","trees","plants",
                   "tree","plant" }) :
                   "The immediate area is bare of all trees and plants, "
                   "but out of the way, beyond the tents, the West Wood "
                   "starts up again.  There, they flourish happily and "
                   "well.  They also crowd around the trail.",
                ({ "brown tent","tent","tents" }) :
                   "The brown tent is the more south of the tents, and "
                   "it looks like it would be the most vulnerable to "
                   "rain if it were not for the tarp hung above it.",
                ({ "brown tarp","tarp" }) :
                   "The tarp was designed so that it would direct water "
                   "away from whatever lay below it.  It hangs over the "
                   "brown tent.",
                ({ "blue tent","tent","tents","tough material","material",
                   "beads of water","water","bead of water","beads",
                   "bead" }) :
                   "The blue tent is made of a tough material that shows "
                   "beads of water hanging onto it.  Those inside "
                   "probably don't worry too much when it rains.",
                ({ "small path","trail","path" }) :
                   "Half-hidden by the West Wood, a small path heads "
                   "away from the camp going east.",
                ({ "nice camp","camp" }) : 
                   (: GetLong :),
           ]) );
   SetListen( ([
                 "default" : "Noises come from the tents.",
                 ({ "brown tent","blue tent" }) : "The tents have "
                    "occupants currently, it seems, since noise comes "
                    "from inside.",
            ]) );
   SetSmell( ([
                "default" : "The smell of smoke lingers in the air.",
                "campfire" : "It smells smokey, like most do.",
           ]) );
   SetExits( ([
                "east" : H_ROOM + "trail_14",
           ]) );
   SetEnters( ([
                 "blue tent"  : H_ROOM + "tent_bl",
                 "brown tent" : H_ROOM + "tent_br",
            ]) );
   SetInventory( ([
                    H_NPC + "camp_ex" : 2+random(2),
                    H_NPC + "camp_qu" : 2+random(3),
                    H_NPC + "camp_sng" : 3+random(2),
               ]) );
}

string NightFire() {
   if(query_night()) {
      return "The fire sparks and crackles cheerily, dancing around "
        "in the night.  Some ashes hang around it, having once been "
        "part of the fire, now just part of the debris.";
   }
   return "There must have been a fire here last night, since "
          "there are many fresh ashes.";
}

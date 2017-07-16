#include <lib.h>
#include "ditmar.h"
inherit LIB_CHAPEL;

int PreExit();

static void create() {
   chapel::create();
   SetTown("Ditmar");
   SetReligion("Marn","Marn");
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("Marn Temple of Worship");
   SetLong("Sculptures of the most beautiful ice and stone "
           "in all of Kailie decorate the Marn Temple of "
           "Worship.  Each sculpture is elevated on granite "
           "platforms, scattered about the temple.  An exit "
           "goes out to the north.");
   SetItems( ([
                ({ "kailie" }) :
                   "Kailie is here.",
                ({ "Marn Temple of Worship","temple","temple of "
                   "worship" }) :
                   (: GetLong :),
                ({ "beautiful sculptures","sculptures","sculpture",
                   "ice","stone" }) :
                   "The sculptures sit complacently above the ground "
                   "on granite platforms.  They have been placed at "
                   "proper levels for easy and comprehensive viewing."
                   "One particularly large sculpture made from both "
                   "rock and ice is in the back of the room.",
                ({ "large sculpture","sculpture" }) :
                   "The largest sculpture is up against the back "
                   "of the temple.  It is set high into the air.  "
                   "The ice and stone are blended together to form "
                   "the shape of an awesome creature.  Below the "
                   "sculpture is a small doorway leading south.",
                ({ "small doorway","doorway" }) :
                   "The doorway glows slightly.",
                ({ "granite platforms","platforms","platform" }) :
                   "The granite platforms call little attention upon "
                   "themselves.  Their sole purpose inside the temple "
                   "is to hold the sculptures up because without the "
                   "platforms, they would surely fall to the ground."
           ]) );
   SetItemAdjectives( ([
                         "temple" : ({ "marn" }),
                         "sculptures" : ({ "ice","stone","beautiful" }),
                         "large sculpture" : ({ "largest","ice","stone" }),
                         "platforms" : ({ "granite" }),
                    ]) );
   SetObviousExits("north");
   AddExit("south",D_ROOM + "/relig", (: PreExit :));
   SetExits( ([
                "north" : D_ROOM + "/cave_c",
           ]) );
   SetInventory( ([
                    D_NPC + "/priest" : 1,
               ]) );
}

int PreExit() {
   if(this_player()->GetReligion() == "Marn") return 1;
   if(immortalp(this_player())) return 1;
   return 0;
}
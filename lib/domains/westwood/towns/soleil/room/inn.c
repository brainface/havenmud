// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"
 
string TorchCheck();

static void create() {
   room::create();
   
   SetTown("Soleil");
   SetClimate("indoors");
   SetAmbientLight(35);
   SetShort("Soleil's inn and tavern");
   SetLong("Hard wood makes up the floor of this establishment, "
           "Soleil's Inn and Tavern.  Tables and benches of a similiar "
           "wood are scattered around in a seemingly random manner.  "
           "A counter spans the north wall, and plain stools are lain "
           "out in front of it.  Torches line the walls, mounted in "
           "carefully, so as to avoid accidently tipping.  The only "
           "exit is out.");
   SetItems( ([
                ({ "torched-lined walls","torches","walls","wall",
                   "torch" }) :
                   (: TorchCheck :),
                ({ "plain stools","plain stool","stool","stools" }) :
                   "The stools are identical to the benches and "
                   "tables, on taller so that one can sit more comfortable "
                   "at the counter.",
                ({ "hard wood floor","hard wood","floor","wood floor",
                   "hard floor","wood" }) :
                   "The floor is stained from spilled beer and other "
                   "spillage associated with taverns.  It is, however, "
                   "swept mostly free of dirt and ruffage from the trees.",
                ({ "soleil's inn and tavern","inn","tavern","room",
                   "main room" }) :
                   (: GetLong :),
                ({ "tables and benches","tables","benches","table",
                   "bench","wood" }) :
                   "The tables and benches seem rather rough and "
                   "easy to recieve splinters from, but adequate to "
                   "to serve the normal population of a tavern.",
                ({ "north wall counter","counter","north wall",
                   "north","wall","walls" }) :
                   "The counter is made of the same wood the rest of the "
                   "tavern has, but it has been sanded down and smoothed "
                   "for the barkeeper.",
              ]) );
   SetExits( ([
                "out" : S_ROOM + "pool",
           ]) );
   SetObviousExits("out");
   SetInventory( ([
                    S_NPC + "barkeep_alamus" : 1,
               ]) );
}

string TorchCheck() {
   if(query_night()) {
      return "The torches blaze sullenly in up against the walls.";
   }
   else return "The torches are all set to be lit, but it is unnecessary "
               "since light still comes in from outside.";
}
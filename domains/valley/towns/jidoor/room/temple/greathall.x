//Coded by Aagar
//Feb. 99
//moranm@muss.cis.mcmaster.ca


#include <lib.h>
#include "../../jidoor.h"
inherit LIB_ROOM;

int PreExit(string dir);

static void create()    {
    room::create();

  SetTown ("Jidoor");
  SetDomain ("Valley");
  SetClimate ("indoors");
  SetAmbientLight (40);

  SetShort ("the Great Hall of the Elements");
  SetLong (
    "The great antechamber has been hollowed out from the earth of "
    "Kailie, and connects the mortal realm to the four elemental "
    "planes of of existence.  It is roughly spherical, dipping roughly "
    "10 feet into the center, with a ceiling that cannot be seen "
    "through the darkness.  Natural springs burst forth from the walls, "
    "depositing their charge into a pool in the center of the chamber.  "
    "The room is lit by huge pillars of fire spread evenly along the "
    "walls.  A network of roots form walkways from the center of the "
    "chamber to four portals.  The portal to the north leads to the plane "
    "of fire, while opposite to it in the south leads to the plane of "
    "water.  To the east lies the portal to the plane of earth, "
    "while the portal to the west leads to the plane of air.  A wyrmhole "
    "in the center of the chamber leads back to the grove of the "
    "Magildan Temple.");

  SetItems ( ([

    ({"antechamber","earth","temple"}) : (:GetLong:),

    ({"center","pool","mist","flame"}) :
       "The pool is dark and murky.  It is shrouded in mist, while "
       "a flame burns brightly on its surface.  Here, the four "
       "elements are brought together by the power of Zaxan.",

    ({"ceiling"}) :
       "The darkness obscures any view of a ceiling... if there is one.",

    ({"spring","springs","charge"}) :
       "These natural springs carry water to the pool.  One can only "
       "guess their source.",

    ({"wall","walls"}) :
       "The walls are clay baked by elemental fire.",

    ({"root","roots","walkway","walkways"}) :
       "The roots intertwine to form solid walkways roughly 5 feet wide."
       "  The walkway forms a circle 10 feet above the pool, and diverges "
       "north, south, east and west.",

    ({"pillar","pillars","fire"}) :
      "Pillars of fire burn brightly, keeping the antechamber well lit.",

    ({"portal","portals"}) :
       "The four magical portals lead to the four elemental planes.",

    ({"wyrmhole","hole"}) :
       "The hole will transport anyone back to the mortal realm of "
       "Kailie.",
    ]) );

  SetItemAdjectives( ([
    "antechamber" : ({"great","hollowed","sperical","dipping"}),
    "pool" : ({"dark","murky","shrouded","burning"}),
    "ceiling" : ({"obscured"}),
    "spring" : ({"natural","bursting","depositing"}),
    "wall" : ({"clay","baked"}),
    "root" : ({"intertwining","solid","diverging","circular","network",
               "of"}),
    "fire" : ({"pillar","of","burning","huge","bright"}),
    "portal" : ({"magical"}),
    ]) );

  SetInventory ( ([
    JID_NPC + "/aagron" : 1,
    ]) );

  SetSmell ( ([
    "default" : "The smell of freshly churned earth fills the "
                "antechamber."]) );

  SetListen ( ([
    "default" : "The sounds of rushing water reverberate through "
                "the chamber."]) );

  AddExit("south", JID_ROOM + "/temple/water_tower", (: PreExit :));
  AddExit("west", JID_ROOM + "/temple/air_tower", (: PreExit :));
  AddExit("east", JID_ROOM + "/temple/earth_tower", (: PreExit :));
  AddExit("north", JID_ROOM + "/temple/fire_tower", (: PreExit :));
  SetEnters ( ([
    "wyrmhole" : JID_ROOM + "/temple/grove",
    ]) );

}

 int PreExit(string dir) {
  if(!archp(this_player()) ) {
      send_messages("slam",
         "$agent_name $agent_verb into a wall of force blocking "
         "$agent_objective from going " + dir + ".",
           this_player(), 0, environment(this_player()) );
      return 0;
   }
  return 1;
 }

void init() {
   ::init();
   add_action("peer", "peer");
}

int peer() {
   message("system", "A mystical force prevents you from "
           "peering in that directcion.", this_player());
   return 1;
}


/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor 
// Filename: merchant_tower2.c
// Author: Derek Noble
// Immortal: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: This is the merchant's tower in Jidoor.
// Revision History: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../../jidoor.h"

inherit LIB_ROOM;

static void create() {
  room::create();
  SetTown("Jidoor");
  SetDomain("Valley");
  SetClimate("indoors");
  SetAmbientLight(50);
  SetShort("the top floor of a small tower");
  SetLong("This is the living quarters of the tower. Finely decorated in "
          "many objects of wealth including some artifacts and art. A "
          "beautiful canopy bed rests in the center of the room. A rolltop "
          "desk and chair rests near the wall. There are several chests "
          "on the floor as well. A staircase leads down.");
  SetItems( ([ 
     ({"top floor","floor","quarters","living quarters"}) : (: GetLong :),
     ({ "staircase" }) : "The small spiral staircase leads down to the "
         "entranceway of the tower.",
     ({"chest","chests"}) : "Locked and heavy, these chests seem to be "
         "full of valuables or something.",
     ({"desk"}) : "The beautiful rolltop oak desk is tidy and clean.",
     ({"chair"}) : "The comfortable looking chair sits by the rolltop "
         "desk",
     ({"bed"}) : "It is a huge and beautiful bed made from cedar.",
     ({"objects","objects of wealth","art","artifact",
       "artifacts"}) : "The objects of wealth around "
         "the room are an indication of the wealth of the person who "
         "lives here.",
  ]) );
  SetItemAdjectives( ([ 
            "desk" : ({ "oak","rolltop" }),
            "chair" : ({ "comfortable","comfortable looking" }),
            "chest" : ({ "several" }),
            "bed" : ({ "beautiful","canopy" }),
                   ]) );
  SetInventory( ([ 
/*
        JID_NPC "/yulisa" : 1
*/
              ]) );
  SetExits( ([ 
     "down" : JID_ROOM "/misc_buildings/merchant_tower1",
  ]) );
  SetListen( ([ 
      "default" : "It is relatively quiet here.",
           ]) );
  SetSmell( ([ 
      "default" : "The scent of perfume is here." 
           ] ));
}

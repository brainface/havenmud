/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: tower01.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 19th, 1998
// Abstract: This is the entryway of the tower.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetAmbientLight(40);
  SetDomain("Valley");
  SetClimate("indoors");
  SetShort("just inside the tower of P'alirith's Keep");
  SetDayLong(
            "Just inside the tower, the courtyard of the keep is plainly "
            "visible through the open archway at the base of the tower.  A "
            "set of stone steps lead up into the tower. Sunlight pours in "
            "through the archway and a small window on the western side of "
            "the tower."
            );
  SetNightLong(
            "Just inside the tower, the courtyard of the keep is plainly "
            "visible.  The torches outside cast just enough light in the "
            "base of the tower to keep it lit up.  A set of stone steps "
            "lead up into the tower.  Moonlight also helps illuminate the "
            "area as it pours in through the archway and a small window on "
            "the western wall."
              );
  SetItems( ([ 
          ({"base"}) : "The base of the tower simply consists of an archway "
              "leading out, steps leading up, and a small window.",
          ({"window"}) : "A small window on the western side of the tower "
              "allows extra light to illuminate this part of the tower.",
          ({"floor","ceiling"}) : "The floor and ceiling are both made out "
              "of the same stone as the walls.",
          ({"steps"}) : "The stone steps lead up into the tower and appear "
              "safe and sturdy.",
          ({"stone", "stones"}) : "The stones used to build the tower "
              "appears just as the ones used to build the keep except the "
              "ones inside the tower are not nearly as dark as the ones "
              "outside.",
          ({"wall", "walls"}) : "The stone walls of the tower are similiar "
              "to the walls of the keep except not quite as dark.",
          ({"western wall"}) : "The western part of the wall Contains a "
              "small window.",
          ({"archway"}) : "The archway leads out into the courtyard of the "
              "keep.",
          ({"tower"}) : "This inside of the tower is made from an aged "
              "stone an dark but not nearly as bad as the walls of the "
              "keep or the outside walls of the tower.",
          ({"torches", "torch"}) : "The torches aren't easily seen but the "
              "light they cause is.",
          ({"air"}) : "The air? No one can see that.",
          ({"courtyard", "keep"}) : "The courtyard of the keep is just "
              "outside."
          ]) );
  SetItemAdjectives( ([ 
            "window" : ({ "small" }),
            "steps" : ({ "stone","safe","sturdy","set of","set of stone" }),
            "stones" : ({ "dark","aged" }),
            "stone" : ({ "dark","aged" }),
            "walls" : ({ "stone","dark","aged" }),
            "wall" : ({ "stone","dark","aged" }),
            "western wall" : ({ "stone","dark","aged" }),
            "tower" : ({ "dark","aged","stone" }),
                   ]) );
  SetListen( ([ 
            "default" : "The area is strangely quiet except for the wind "
               "whistling through the keep outside."
           ]) );
  SetSmell( ([ 
            "default" : "The smell of oil from the torches is still "
               "noticeable even though there are no torches in the base of "
               "the tower.",
            "air" : "The air smells slightly musty."
          ]) );
  SetExits( ([
            "out" : d_room + "/courtyard01",
            "up" : d_room + "/tower02"]) );
  }

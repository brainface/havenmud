/* ----------------------------------------------------------------------- */
// Area Title: Jidoor Forest
// Filename: tower02.c
// Author: Derek Noble
// Angel: dylanthalus@haven
// Creation Date: August 20th, 1998
// Abstract: This is the greeting room and the 2nd level of the tower of 
//           P'alirith's Keep.
// Revision History: August 23rd, 1998 - Pre-Approved by Zaxan Zimtafarous
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
inherit LIB_ROOM;
#include "../jidoor_forest.h"
  static void create()
  {
  room::create();
  SetDayLight(40); /* from the window */
  SetNightLight(20); /* from the wall mounted candle */
  SetDomain("Valley");
  SetClimate("indoors");
  SetShort("a greeting room in the tower of P'alirith's Keep");
  SetDayLong(
            "This is obviously where the owner of the tower would greet "
            "their guests. A small coat rack stands near the wall on the "
            "southern side of the tower but only contains one coat at the "
            "moment. A glass window on the eastern side of the wall "
            "overlooks the courtyard of the keep but right now pretty much "
            "serves the purpose of the room with sunlight.  A set of stone "
            "steps wrap their way around the wall of the tower leading down "
            "and up from here."
            );
  SetNightLong(
            "Here on the second level of the tower is a modest entryroom "
            "containing only a coat rack with one coat hanging on it. A "
            "glass window on the eastern side of the wall overlooks the "
            "courtyard of the keep and the torches burning outside cast "
            "flickering shadows in the area. A small candle is burning near "
            "a set of stone steps lead up and down from here as they wrap "
            "themselves around the walls of the tower."
              );
  SetItems( ([ 
          ({"side"}) : "The sides of the tower are rounded and they "
               "contains stone steps leading up and down from here.",
          ({"entryroom"}) : "The entryroom is the second level in the "
               "tower.",
          ({"shadows"}) : "Shadows are dancing on the wall from the candle "
               "and the torch.",
          ({"window"}) : "A small glass window overlooks the courtyard of "
               "the keep.",
          ({"floor","ceiling"}) : "The floor and ceiling are both made out "
               "of the same stone as the walls.",
          ({"coat"}) : "A heavy coat hangs on a nearby coat rack. It "
               "appears to be the property of the owner of the keep and "
               "with closer inspection it seems to be stuck on the rack or "
               "something!",
          ({"rack", "coat rack"}) : "A coat rack standing near the wall "
               "contains only one coat.",
          ({"candle"}) : "A small candle is mounted on the wall just "
               "between the steps leading up and the ones leading down. "
               "It keeps the area somewhat lit at night.",
          ({"steps"}) : "The stone steps lead up into the tower and down "
               "to the entryway and appear safe and sturdy.",
          ({"stone", "stones"}) : "The stones used to build the tower "
               "appears just as the ones used to build the keep except the "
               "ones inside the tower are not nearly as dark as the ones "
               "outside.",
          ({"wall", "walls"}) : "The stone walls of the tower are made of "
               "aged stone and are clean.",
          ({"eastern wall"}) : "The eastern part of the wall contains a "
               "small glass window.",
          ({"tower"}) : "This inside of the tower is made from an aged "
               "stone an dark but not nearly as bad as the walls of the "
               "keep or the outside walls of the tower.",
          ({"torches", "torch"}) : "The torches aren't easily seen but the "
               "light they cause is.",
          ({"air"}) : "The air? No one can see that!",
          ({"courtyard", "keep"}) : "The courtyard of the keep is down and "
               "outside from here but visible through the window."
          ]) );
  SetItemAdjectives( ([ 
            "window" : ({ "small","glass" }),
            "steps" : ({ "stone","safe","sturdy","set of","set of stone"}),
            "stones" : ({ "aged" }),
            "stone" : ({ "aged" }),
            "walls" : ({ "stone","aged" }),
            "wall" : ({ "stone","aged" }),
            "eastern wall" : ({ "stone","aged" }),
                   ]) );
  SetListen( ([ 
            "default" : "It is relatively quiet here." 
           ]) );
  SetSmell( ([ 
            "default" : "It smells musty here, but not overbearing.",
            "air" : "The musty smell in the air appears to coming from "
                    "somewhere up in the tower." 
          ]) );
  SetExits( ([
            "down" : d_room + "/tower01",
            "up" : d_room + "/tower03" ]) );
  }

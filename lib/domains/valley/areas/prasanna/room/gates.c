#include <lib.h>
#include "prasanna.h"

inherit LIB_ROOM;

static void create() {
   room::create();
   SetTown("Prasanna");
   SetClimate("temperate");
  SetDomain("Valley");
   SetShort("gates of the ancient city Prasanna");
   SetLong("The colossal gates of the city rise up to meet any who would "
           "enter, the only sentries of a civilization long since vanished, "
           "with little left to protect.  A magnificently carved archway "
           "curves across the top of the gates, with an elaborately carved "
           "emblem of a brightly shining star carved deeply into the stone. "
           "Beyond the gates, the city's streets and avenues continue into "
           "the heart of town.");
   SetItems( ([ 
      ({ "colossal gates", "sentries","gates","gate" }) :   
         "These are large bronze doors built to keep would-be invaders at "
         "bay.  ", 
      ({ "doors","door" }) :
         "These six inch thick bronze doors look impervious to attack.",
      ({ "curves" }) :
         "The curves of the archway are graceful and elegant.",      ({ "carved archway", "archway" }) : 
         "An amazing piece of workmanship, is the archway, with the most "
         "elegant and graceful of curves. ",
      ({ "elaborately carved emblem", "carved emblem","emblem" }) : 
         "This emblem is a depiction of a brilliant star, with a foreign "
         "inscription beneath it. ", 
      ({ "walls","wall" }) :
         "The wall continues around the city for miles, keeping out unwanted "
         "visitors.",
      ({ "granite" }) :
         "The granite here looks as if it were mined from a far away quarry.",
      ({ "foreign inscription","inscription" }) : 
         "The inscription appears to read...'altaria tua virtutum'. ",
      ({ "brightly shining star","shining star","star" }) : 
         "A star carved into stone, but different in some way... ",
      ({ "stone" }) : 
         "More finely polished granite, from which the walls of the city as "
         "well as the archway are built from. ",
      ({ "streets","street","avenues","avenue" }) : 
         "The streets of Prasanna, devoid of any signs of life, but "
         "seemingly well maintained. ",
      ({ "city" }) : 
         "This sprawling city lies to the east, and seems to glow as the "
         "light hits it. The buildings are elegant and inviting." 
   ]) );
   SetExits( ([ 
      "west" : PR_ROOM "/whiteroad2",
      "east" : PR_ROOM "/talver1" ]) );
   SetInventory( ([ PR_NPC + "/guard" : 2, ]) );
}


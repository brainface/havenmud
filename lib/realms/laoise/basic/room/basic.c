/*  A basic room file used as an example
 *  Created by Duuktsaryth@Haven for his Angels.
 */

#include <lib.h>    // This should be in ALL files, not just rooms.
#include "../area.h" 

/* includes that use <> are telling the file to use .h files
 * from the /include directory. "" are telling them to look
 * in the local directory. "../" means one directory up
 * (type cd .. to see an example of .. use)
 */

inherit LIB_ROOM;  

/* This sets what type of file this is going to be. For
 * a room it's LIB_ROOM, for a non-player character (npc)
 * it could be LIB_NPC, for example. Setting the lib file
 * sets what kind of functions the file can use. For example
 * rooms can use SetItemAdjectives, while npcs cannot.
 */

static void create() {
  room::create();
/*  The above two lines are to get the object started. */
  SetShort("a small room"); // The first word has to be lower case
  SetClimate("indoors");
  SetAmbientLight(40);
  SetLong(
    "This is the long description of a small room. It contains "
    "nouns which must be defined in SetItems() and variously "
    "describes the general room. Use <more here> to see the "
    "code for this room, with comments. Go south of here to see "
    "a room that uses these features, without the extra comments."
  );
/*  A long description should be 4-6 lines of QUALITY description.
 *  Substituting useless color doesn't help, it needs to be good stuff.
 *  Don't ever use "you", or anything like it, and make sure to describe 
 *  any exits or nearby major landmarks, if in a city.
 */

  SetItems( ([
    ({ "noun", "nouns" }) : "This is a noun in SetItems()",
    "wall" : "The east wall contains an intricate tapestry",
    "tapestry" : "This tapestry is an amazing wash of colors.",
    "blanket" : "This is a fuzzy green blanket, which looks warm.",
    "fire" : "An invisible fire crackles here",
    "flower" : "A small flower.",
  ]) );
/*  SetItems() should describe every noun in the SetLong()
 *  It should also describe any noun used within SetItem
 *  descriptions. If you SetItem wall and talk about a 
 *  tapestry, tapestry then needs to be an item (even if the
 *  tapestry wasn't mentioned in the SetLong).
 */

  SetItemAdjectives( ([
    "noun" : ({"adjective1", "adjective2"}),
    "blanket" : ({"green", "fuzzy", "warm"}),
  ]) );
/*  SetItemAdjectives lets a player use <look adjective1 noun>
 *  and saves you from having to put every possible combination
 *  of nouns and adjectives into the set items. This allows players
 *  to look at "green blanket", "fuzzy blanket", etc in all
 *  possible combinations. Note that this function can only
 *  take one noun as an argument at a time (no ({"blanket", "blankets"}))
 */

  SetListen( ([
    "default" : "The room is very quiet.",
    "fire" : "The fire crackles quietly.",
  ]) );
/*  The default listen is displayed when a player looks at a room.
 *  You can set a listen for a particular item (e.g. "fire") that
 *  will return the message if player does <listen fire> or
 *  <listen to fire> (try it while in this room)
 *  NB: To do a specific listen or smell (e.g. fire) the same noun
 *  must exist as an argument in the SetItem function.
 */

  SetSmell( ([
    "default" : "The room has no smell.",
    "flower" : "This smells so lovely.",
  ]) );
/*  Works like a set listen, except players do <smell>
 *  e.g. <smell flower>
 */

  SetInventory( ([
     AREA_NPC + "squirrel" : 1,
  ]) );
/*  SetInventory() always requires a complete filename, which is
 *  why if you don't know how, you should ask someone how to create
 *  a .h file of your own. You do not need to include the .c of
 *  the file, and in fact should not because it looks messy.
 */

  SetExits( ([
    "east" : AREA_ROOM "room1",
    "south" : AREA_ROOM "angel_room",
  ]) );
/*  This sets the exits which a player can use to leave the room.
 */

  SetObviousExits("south");

/*  This is _not_ a required function for a basic room,
 *  but is a good way to do a hidden exit. For example,
 *  you can see here that this room has an east exit,
 *  which you cannot tell from looking at the room.
 *  Normally you'd hint about it in the desc or items.
 */

}

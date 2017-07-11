#include <lib.h>
#include "../vergoth.h"

inherit LIB_ROOM;
int PreEnter();
static void create() {
  room::create();
  SetShort("first floor storage room");
  SetLong("This appears to be a storage area for visitors gear and "
        "other strange stuff.  The walls and floor are cut from a gray "
        "stone and fitted together very tightly.  There are coat hooks "
        "along the side walls and heavy hooks closer to the ground.  "
        "Racks line the far wall, fitted for various weapons.  The exit "
        "lies to the north. A large and lonely looking barrel sits in"
        " the center of the room.");
  SetItems( ([ ({"hook", "hooks"}) : "The hooks up high appear to be for "
                "coats and cloaks while the hooks down low look sturdy "
                "enough to be for backpacks and the like.",
        "stone" : "The stone everything is made of has been cut very "
                "smooth and appears to be fitted in a nice tight pattern "
                "in the stairs, walls, and floor.",
        ({"floor","wall","walls"}) : "The floor and walls are cut from "
                "a cold and gray stone that was probaly cut in some mine "
                "by slaves miles away.  The only mystery is how much "
                "it actually took to build this tower.",
        ({"exit","north","n"}) : "The northern exit goes back to the "
                "waiting room.",
        ({"rack", "racks"}) : "The racks are fitted to hold swords, bows, "
                "axes, and just about any weapon imaginable.",
        ({"weapons", "swords", "weapon", "sword", "bow", "axe", "bows", 
                "axes"}) : "There aren't any here.",
        ({"coat", "coats", "cloak", "cloaks", "backpack", "backpacks"}) : 
                "There aren't any here",
        "barrel" : "This barrel is placed in the middle of the room"
                 " and covers what appears to be a trapdoor.",
        ({ "trapdoor", "trap", "door" }) :
                 "This trapdoor is not much of a door at all anymore."
                 " It appears to have been rotting for a long time, and"
                 " only a shell of a door remains. One could probably"
                 " go down if they were so inclined.",
          ]) );
  SetObviousExits("north");
  SetItemAdjectives( ([ "hook" : ({"coat","heavy","sturdy","low"}),
        "rack" : ({"fitted","far","weapon","sword","bow","axe"}),
        ]) );
  SetDomain("frostmarches");
  SetClimate("indoors");
  SetAmbientLight(30);
  SetListen( ([ "default" : "The storage room is very quiet." ]) );  
  SetSmell( ( [ "default" : "The storage room smells unused and ancient.",
         ]) );
  SetExits( ([ "north" : V_ROOM + "entry",
        ]) );
  AddExit("down", "/domains/frostmarches/areas/catacombs/room/stair1", (: PreEnter :));
}


int PreEnter() {
    int lvl = this_player()->GetLevel();
    if (creatorp(this_player())) return 1;  
    if ((this_player()->GetOwner() != "") && lvl >= 50 ) return 1;
    
    this_player()->eventPrint("A gust of wind erupts from the trapdoor"
                              " knocking you back.");         
    eventPrint("A devilish voice booms, \"You are too weak child , come"
               " back when you are legendary!\"");            
    return 0;
}


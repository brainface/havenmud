#include <domains.h>
#include <lib.h>
inherit LIB_ROOM;
int DomainCheck();

static void create() {
room::create();
        SetShort("Haven Road");
        SetDayLong("Two well worn roads meet at this small crossing, "
                   "one going east-west and the other northeast.  "
                   "A small path breaks off from the main roads, "
                   "leading towards a wood and brick structure "
                   "to the north, nestled between the two roads.  "
                   "The building is large and rectangular with a "
                   "brick chimney atop its roof.  A small sign hangs "
                   "over the door.  The sky here is warm, still, and "
                   "clear.  The sun hangs in the sky, illuminating the "
                   "entire area.");
        SetNightLong("Two well worn roads meet at this small crossing, "
                     "one going east-west and the other northeast.  "
                     "A small path breaks off from the main roads, "
                     "leading towards a wood and brick structure "
                     "to the north, nestled between the two roads.  "
                     "The building is large and rectangular with a "
                     "brick chimney atop its roof.  A small sign hangs "
                     "over the door.  The sky here is chilly, still, "
                     "and clear.  The moon hangs in the sky, illuminating "
                     "the entire area.");
        SetItems( ([ 
                     ({"two well worn roads","roads","well worn roads",
                       "worn roads","two worn roads","two roads","road",
                       "well worn road","worn road","main roads",
                       "main road","two main roads"}) :
                       "These two roads meet up at this crossing and "
                       "go their seperate ways, one east-west, the "
                       "other northeast.  They look to receive quite a"
                       "bit of foot traffic."
                    ,({"small dirt path","dirt path","small path",
                       "path","winding dirt path","winding path"}) :
                       "This small dirt path breaks off from the "
                       "main road and winds north towards a building "
                       "of some sort."
                    ,({"large rectangular building","rectangular building",
                       "large building","building","wood and brick structure",
                       "structure", "tavern", "pub", "dwelling",
                       "wood structure","brick structure","inn"}) :
                       "This large building is made of wood and brick.  A "
                       "brick chimney tops its roof and a small sign hangs "
                       "over its door.  It looks to be an Inn."
                    ,({"old heavy oak","old wood","heavy wood","wood",
                       "old oak","heavy oak","old heavy wood","oak"}) :
                       "The building's wooden sections look to be made "
                       "of old, heavy oak."
                    ,({"simple red brick","simple brick","red brick","brick"}) :
                       "Much of the building is made of this simple red brick."
                    ,({"short brick chimney","brick chimney","short chimney",
                       "chimney"}) :
                       "Perched atop the roof of the building is a short brick "
                       "chimney.  The upper bricks are black with soot."
                    ,({"black upper bricks","upper bricks","black bricks",
                       "bricks"}) :
                       "The highest bricks on the chimney are blackened by "
                       "soot, undoubtably the only thing left of countless "
                       "logs of wood."
                    ,({"dark black soot","black soot","dark soot","soot"}) :
                       "The dark black soot looks, well, dark and black."
                    ,({"sign over the door","small wooden sign","wooden sign",
                       "sign","picture","picture on sign","small sign",
                       "sign over door"}) :
                       "This small wooden sign juts out at a right angle "
                       "to the building, supported by an iron chain.  A "
                       "picture has been carved into the oak: that of "
                       "a man sleeping peacefully in a bed, the covers "
                       "pulled up to his chest."
                    ,({"thick iron chain","iron chain","thick chain","chain"}) :
                       "This thick iron chain supports a small wooden sign "
                       "over the door of the building."
                    ,({"plain wooden door","wooden door","plain door","door"}) :
                       "The entrance to the building is a plain wooden door."
                       "  A small wooden sign hangs over it."  
                ]) );
        SetInventory( ([
          SOUTHERN_COAST_VIRTUAL "sign/havenroad00" : 1
        ]) );
        SetExits( ([ "west" : SOUTHERN_COAST_VIRTUAL + "havenroad/-1,0",
                     "east" : SOUTHERN_COAST_VIRTUAL + "havenroad/1,0",
                     "south" : PENINSULA_VIRTUAL "vimp/0,6" ]) );                     
        AddExit("northeast", HAVENWOOD_VIRTUAL + "havenwoodroad/126,126", (: DomainCheck :) );
        SetEnters( ([
                     ({"large rectangular building","rectangular building",
                       "large building","building","wood and brick structure",
                       "wood structure","brick structure","inn", "structure",
                       "tavern","pub"}) :
                       SOUTHERN_COAST_AREAS + "wtraveller/room/wtraveller"
                 ]) );
}

int DomainCheck() {
  if (!OPEN_HAVENWOOD)
    this_player()->eventPrint("Further travel in that direction is not allowed right now.");
  return OPEN_HAVENWOOD;  
}

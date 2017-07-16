// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_FISHING;

static void create() {
   ::create();
   SetShort("beside the sea cliffs");
   SetLong("Waves crash against the sand, flowing in from the ocean "
           "that stretches as far as the eye can see to the east "
           "and south.  The beach meanders along the edge of the "
           "sea cliffs, continuing to the north and west.  "
           "The ocean has beached a large tree about a foot above "
           "the tide line.");
   SetItems( ([
                ({ "sea cliffs","cliffs","cliff" }) :
                   "The cliffs tower above the ocean, with few handholds "
                   "or footholds.",
                ({ "ocean","water","sea","tide","waves","wave" }) :
                   "The ocean is a deep, black-green-blue shade.",
                ({ "beach" }) : (: GetLong :),
                ({ "large tree","tree" }) :
                   "Soaked in water and splattered with a thin coating of "
                   "limpets and barnacles, the tree rests just above "
                   "the tide line, making it difficult for the ocean to "
                   "take it away again.",
                ({ "limpets and barnacles","limpets","limpet","barnacles",
                   "barnacle" }) :
                   "The barnacles and limpets cling to the log, waiting "
                   "for it to be submersed in water again.",
                ({ "tide line","line","seaweed" }) :
                   "The tide line is a strip of seaweed pushed up by "
                   "waves.",
           ]) );
   SetItemAdjectives( ([
                         "cliffs" : ({ "sea" }),
                         "tree" : ({ "large" }),
                         "line" : ({ "tide" }),
                    ]) );
   SetSmell( ([
                "default" : "The salty tang of the ocean is prevalent.",
                "ocean" : "The ocean has a distinctly salty smell.",
           ]) );
   SetListen( ([
                 "default" : "The ocean roars.",
                 "ocean" : "The ocean sends wave after wave smashing against "
                    "the beach.",
            ]) );
   SetExits( ([
               "north" : AVERATH_ISLAND + "10,-4,0",
               "west" : AVERATH_ISLAND + "9,-5,0",
               "east" : INNERSEA_VIRTUAL "ocean/11,-110",
               "south" : INNERSEA_VIRTUAL "ocean/10,-111",
           ]) );
   SetProperty("coastal", 1);        
   SetInventory( ([ 
                    FOREST_NPC + "immatureeagle" : 2,
                    FOREST_NPC + "baldeagle" : 3,
                    FOREST_NPC + "beachcomber" : 1,
               ]) );
  SetSpeed(2);
  SetFish( ([
              FOREST_OBJ + "sockeye" : 20,
              FOREST_OBJ + "chum" : 200,
              FOREST_OBJ + "dogshark" : 5,
         ]) );
  SetChance(55);
  SetMaxFishing(50);
}

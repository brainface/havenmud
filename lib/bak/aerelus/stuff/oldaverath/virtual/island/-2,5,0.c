/* Kilik 7-27-01
   -2,5,0.c 
   Pond for the cool fishers
 */
#include <lib.h>
#include <std.h>
#include <domains.h>

inherit LIB_FISHING;
int MakeCaptain();

static void create() {
  fishing::create();

  SetNoClean(1);
  SetShort("a small pond");
  SetLong("The grass fades away here to give way for thick ferns and "
          "tall reeds. The pond is crystal clear with a clay bottom. "
          "The water sparkles with minerals, it must be why animals "
          "would stop to drink here. There is a small beach of rich "
          "clay surrounding the pond which would be great to sit upon. "
          "A tall willow tree curves over the pond.");
  SetItems( ([
              ({ "grass","ferns","fern","reed","reeds"}) :
                "Ferns and reeds grow near the pond, while grass "
                "surround the area and back out to the planes.",
              ({ "pond","area","beach","water" }) :
                (: GetLong :),
              ({ "willow","tree" }) : 
                 "A tall willow tree grows from the side of the "
                 "pond and curves over the water. It casts a deep shadow "
                 "over the entire pond.", 
              ({ "minerals","mineral" }) :
                 "The water of the pond sparkles with iron ore and other "
                 "assorted minerals and metals.",
              ({ "clay","ground" }) :
                 "The ground is thick, packed, clay with a deep rich "
                 "color. Ferns and reeds grow well.",
            ]) );
  SetItemAdjectives( ([
     "tree" : ({"tall"}),
     "mineral" : ({"assorted"}),
     "clay" : ({"rich"}),
     ]) );

  SetClimate("temperate");
  SetListen("The wind whistles in the willow tree.");
  SetSmell("Fishy water and stale clay fills the air with a pungent "
           "scent.");
  SetExits( ([

     "east" : AVERATH_ISLAND + "-1,5,0",
     "south" : AVERATH_ISLAND + "-2,4,0",
     "west" : AVERATH_ISLAND + "-3,5,0", 
     "north" : INNERSEA_VIRTUAL + "ocean/0,-100",
      ]) );
  SetProperty("coastal", 1);
  SetInventory( ([
     AVERATH_OBJ "ferry" : 1,
    AVERATH_NPC "ferrycaptain" : 1,
    AVERATH_NPC + "fisher" : 1,
    ]) );
  SetSpeed(3);
  SetFish( ([
        AVERATH_OBJ + "trout" : 100,
        AVERATH_OBJ + "bass" : 100,
         ]) );
  SetChance(45);
  SetMaxFishing(50);
  }

int MakeCaptain() {
  object captain = new(AVERATH_NPC "ferrycaptain");
  object ferry = present("ferry", this_object());
  if (!captain) return 0;
  if (!ferry) return 0;
  captain->eventMove(ferry);
  return 1;
}

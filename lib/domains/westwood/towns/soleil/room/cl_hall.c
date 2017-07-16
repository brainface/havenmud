// Amelia@Haven

#include <lib.h>
inherit LIB_ROOM;
#include "../soleil.h"

static void create() {
   room::create();
   SetTown("Soleil");
   SetClimate("indoors");
   
   SetAmbientLight(34);
   SetShort("a bare room");
   SetLong("A wooden floor, wooden walls, and a wooden ceiling are "
           "about all this room has to offer to the eye.  A large "
           "window with black curtains faces the town.  A stairway "
           "heads down.  There is a glowing orb of light attached to the "
           "ceiling.");
   SetItems( ([
                ({ "steep narrow staircase","steep staircase",
                   "narrow staircase","narrow steep staircase",
                   "small staircase","staircase","stairs","stair" }) :
                   "The staircase is narrow and steep, with just enough "
                   "room for one person to walk down, but it would "
                   "be a tight fit.  Two people could pass by turning "
                   "sideways, but only barely, and if one wasn't too "
                   "large a person.",
                ({ "wooden floor","wooden walls","wooden wall",
                   "wooden ceiling","wood","wooden","floor","walls",
                   "wall","ceiling" }) :
                   "On one wall, a large window faces the town.  The "
                   "ceiling has a glowing orb of light hanging from it "
                   "to cast out the darkness that naturally comes with "
                   "being indoors.  Small curls of smoke seep out from "
                   "the floor on occasions.",
                ({ "small curls of smoke","small curl of smoke",
                   "smoke","curl of smoke","curls of smoke",
                   "small curl","small curls","curl","curls" }) :
                   "The culs of smoke are a vaporous white, raising from "
                   "the temple beneath this room, through the wooden "
                   "floor.",
                ({ "glowing orb of light","glowing orb","orb",
                   "light","orb of light","glowing light" }) :
                   "The light stays steady, changing only as the light "
                   "outside changes, to keep the level of light in this "
                   "room at a constant.",
                ({ "large window","window" }) :
                   "The window gives a good view of Soleil, as most "
                   "views go, since the hemlock and spruce trees have "
                   "a bad habit of blocking things from sight.",
                ({ "black curtains","curtains","curtain","black curtain" }) :
                   "The black curtains are simple and plain, pushed to the "
                   "side of the window to allow the view, but easy to "
                   "close if necessary.",
                ({ "good view of soleil","good view","view","view of "
                   "soleil","soleil" }) :
                   "Soleil is simple and yet beautiful from this hieght, "
                   "a town built not for sprawling streets and distances "
                   "that are long from one place to another, but rather "
                   "for the tight compactness that is best shared among "
                   "friends and easier to defend.",
                ({ "hemlock and spruce trees","hemlock trees","spruce "
                   "trees","tree","trees","hemlock tree","spruce tree", 
                   "hemlock","spruce" }) :
                   "The trees block out the sight of most of Soleil, but "
                   "the view is still beautiful.",
           ]) );
   SetSmell( ([
                "default" : "Sweet pine smells raise up from the floor, "
                   "mingling with vanilla and other pleasant scents.",
                "floor" : "It seems like smoke from the church below "
                   "has decided to go up into this room, for the "
                   "pine and vanilla are reminescent of the candles' "
                   "on the altar below.",
           ]) );
   SetExits( ([
                "down" : S_ROOM + "temple",
           ]) );
   SetObviousExits("down");
   SetNewsgroups( ({ "religion.eclat","ideas","magic.ideas","magic.announcements","magic.general" }) );
   SetInventory( ([
                    S_NPC + "healer_iuvo" : 1,
               ]) );
}

/*
int CanReceive() {
   if(immortalp(this_player())) return 1;
   if(this_player()->GetReligion()!="Eclat") return 0;
   return 1;
  SetNewsgroups( ({ "magic.ideas","magic.announcements","magic.general" }) );
}
*/

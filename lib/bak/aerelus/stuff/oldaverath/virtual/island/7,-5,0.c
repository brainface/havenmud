//Lilavae
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("a dark section of forest");
   SetDayLong("Protected by a thick covering of sun-dappled trees "
	      "this small patch of land is very cool and shaded. "
	      "Small brambles and wildflowers carpet the earth with "
	      "a riotous explosion of color.  A lone willow sapling "
              "stands underneath the larger trees.  To the north "
              "and east the trees almost cover the pathway leaving an "
	      "opening the size of a small ogre.  To the west and south "
	      "the pathway is completely clear. ");
   SetNightLong("The silver arcs of moonlight barely penetrate the "
	      "thick canopy of branches and leaves that protects this "
	      "part of the forest.  The blowing leaves draw slightly "
	      "ominous shadows on the ground, but the movement also "
              "highlights the innocuous flowers that cover the dirt. "
	      "A small willow tree stands silvered underneath the faint "
              "light.  The path leading to the north and east is "
              "almost covered by moonlit trees.  To the west and "
	      "south the path glows brightly under the ethereal light. ");
   SetItems( ([
              ({ "forest","patch","land", "part" }) :
		 (: GetLong :),
              ({ "covering","trees","canopy","branches","leaves" }) :
		 "Tall and stalwart, these gigantic trees shade this "
		 "section of the forest and steal its sunshine.  The "
		 "trees which create a moving canopy inhibit growth "
                 "beneath their ancient branches. ",
              ({ "brambles" }) :
		 "Sharp and prickly, these brambles wind around the "
		 "forest floor, injuring those unwise enough to step "
		 "upon them.  Serpentine, they surround the small "
		 "blossoms also inhabiting the ground.",
              ({ "wildflowers","flowers" }) :
		 "Everything from thorny wild red roses to delicate "
		 "dahlias graces this small flowerbed which lays at "
		 "the base of the tiny willow sapling.",
	      ({ "earth","ground","dirt" }) : 
		 "The ground looks very hardpacked, yet tendrils "
		 "of fresh shoots and buds emerge from the dirt and "
		 "mingle with the grass. ",
	      ({ "willow","sapling","tree" }) :
		 "Pliant and small, this lovely willow seems delicate "
		 "and hardly strong enough to survive.  Its white bark "
		 "glitters and dances with the shadows of its soft "
		 "green leaves. ",
	      ({ "shadows" }) :
		 "These ominous shadows, devoid of light, undulate "
		 "and roll across the forest floor.  Though seemingly "
		 "portentous, these spots of darkness are not hiding "
		 "anything - Are they?",
           ]) );
   SetItemAdjectives( ([
			 "patch" : ({ "small" }),
			 "covering" : ({ "thick" }),
			 "trees" : ({ "larger","sundappled" }),
			 "canopy" : ({ "thick" }),
			 "leaves" : ({ "blowing" }),
			 "brambles" : ({ "small" }),
			 "flowers" : ({ "innocuous" }),
                         "sapling" : ({ "lone","willow","small" }),
			 "shadows" : ({ "ominous" }),
                    ]) );
   SetListen( ([
                 "default" : "The screeching of some great bird pierces "
			      "the silence. ",
            ]) );
   SetSmell( ([
                "default" : "The scent of roses and wild onion wafts "
			      "along the breeze. ",
           ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "7,-4,0",
                "west" : AVERATH_ISLAND + "6,-5,0",
                "east" : AVERATH_ISLAND + "8,-5,0",
                "south" : AVERATH_ISLAND + "7,-6,0",
           ]) );
   SetInventory( ([
                    FOREST_NPC + "cat_giant1" : 1,
               ]) );
}

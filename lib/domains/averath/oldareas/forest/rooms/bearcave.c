//Lilavae
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetClimate("indoors");
   SetAmbientLight(15);
   SetShort("a darkened cavern");
   SetDayLong("Above, the cavern ceiling reflects the soft light of a "
	   "small ray of sun.  Long tendrils of ivy wind along the "
	   "walls.  The hard-packed earth below is covered with "
           "colourful leaves and grey pebbles.  At the far end of "
           "the cavern twigs and rotting leaves have gathered to form "
	   "a natural bed.");
   SetNightLong("Glittering with soft moonlight, every aspect of this "
	        "cavern glows in silver.  Through the low entrance, the "
	        "night sky blooms with pinpoints of faint stars.  Ivy "
                "covers the thick walls of the cave.  The earth below "
	        "is littered with smooth grey pebbles and long dead "
		"leaves.");
   SetItems( ([
                ({ "cavern","cave","walls" }) : (: GetLong :),
                ({ "ceiling" }) :
                   "The ceiling of the cavern is highly vaulted as if "
                   "a gigantic hand had scooped out the grey rock and "
		   "left a hole.",
                ({ "light","ray","sun","rays" }) : 
		   "Sharp as a the blade of a sword, the light burns "
		   "into the cave, playing over the lightly coloured "
		   "pebbles packed into the earth.",
                ({ "tendrils","ivy","tendril" }) :
		   "This softly coloured ivy marches down the walls of "
		   "the cavern, turning the walls into a veritable "
		   "wall of emerald green. ",
                ({ "earth","below","pebbles","pebble" }) :
		   "The earth floor of this cave boasts a bright red "
		   "soil.  Grey pebbles have become deeply embedded in "
                   "the earth and some groupings almost form pictures. ",
                ({ "leaves","twigs","bed","end","leaf","twig" }) :
		   "A red, gold, and green pathway created by leaves "
		   "leads to the end of the cavern.  Here, a swirl of "
		   "rotten leaves and long brown twigs has been formed "
		   "into a makeshift resting place. ",
		({ "moonlight" }) :
		   "Shining through the low entrance, the moonlight "
		   "pools around the soft edges of stone inside the "
		   "cave. ",
		({ "entrance" }) :
		   "The entrance to the cavern is a small archway "
		   "deeply recessed within the side of a great slab "
		   "of stone. ",
                ({ "sky","stars","star" }) :
		   "The night sky burns a soft and shining royal blue "
		   "which slowly fades into black in the west and purple "
		   "in the east.  Stars burst magnesium bright, like "
		   "jewels set into a piece of cloth. ",
           ]) );
   SetItemAdjectives( ([
			 "ceiling" : ({ "cavern" }),
			 "light" : ({ "soft","small","sun" }),
			 "tendrils" : ({ "long" }),
			 "earth" : ({ "hard","packed","hard-packed" }),
                         "leaves" : ({ "colourful","rotting","long-dead" }),
                         "pebbles" : ({ "grey","smooth" }),
			 "end" : ({ "far" }),
			 "bed" : ({ "natural" }),
                         "moonlight" : ({ "soft" }),
                         "entrance" : ({ "low" }),
                         "sky" : ({ "night" }),
                         "stars" : ({ "faint" }),
                         "walls" : ({ "thick" }),
                    ]) );
   SetSmell( ([ "default" : "The cavern smells vaguely of decay.",
           ]) );
   SetListen( ([ "default" : "The soft roar of animals creates a "
			     "cacophony outside.",
            ]) );
   SetExits( ([
		 "out" : AVERATH_ISLAND "7,-6,0",
	       ]) );
   SetInventory( ([
                    FOREST_NPC + "bear_large1" : 1,
               ]) );
}

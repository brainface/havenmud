//Lilavae
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create() {
   ::create();
   SetShort("a littered section of beach");
   SetDayLong("Shielded to the west by a craggy sea cliff, this small "
               "part of the beach is littered by long, slimy strands of "
	       "seaweed.  Sharp slices of sea shells shine through the "
	       "sand.  The ocean softly curls along the shore, splashing "
	       "against the large rocks embedded in the sand.  To the "
	       "north and south, the beach continues. ");
   SetNightLong("Moonlight creates odd shadows on the sea cliff that "
		 "protects this stretch of beach.  The sand is covered "
		 "by thick, pulpy pieces of kelp and sharp sea shells. "
                 "Deep impressions are created on the shore by the "
		 "pounding of the waves.  Large rocks stand on the edge "
		 "of the shore.  To the north and south, the beach "
		 "continues. ");
   SetItems( ([
               ({ "beach","part","sand","shore","stretch","edge" }) :
                  (: GetLong :),
	       ({ "cliff" }) :
		  "Tall and solid, this large sea cliff has eroded over "
		  "many years.  The surface is rough and craggy and "
		  "shadows hide the recesses in the stone. ",
               ({ "litter","strands","seaweed","pieces","kelp","strand",
		  "piece" }) :
		  "Thick and wet, strips of seaweed cover most of the "
		  "beach.  Some of the pulpy, green strands are as long "
		  "as a human. ",
               ({ "slices","shells","slice","shell" }) :
		  "Sparkling in rosy hues, small sea shells litter the "
		  "ground.  Many shells, fractured by the rough waves, "
		  "have become sharp and dangerous. ",
               ({ "ocean","waves","wave" }) :
		  "Seemingly infinite, the ocean beats against the rocks "
	       	  "and sand.  Topped by whitecaps, the water looks very "
		  "lovely and inviting. ",
               ({ "rocks","rock" }) :
		  "Standing at the edge of the shore, these gray rocks "
		  "have eroded into large smooth stepping stones "
		  "overlooking the ocean. ",
	       ({ "moonlight" }) :
		  "The silver light, watery and pale, washes against the "
		  "sand and stone creating fanciful shadows. ",
               ({ "shadows","shadow" }) :
		  "Grotesque and haunting, these shadows cover the cliff "
		  "at the western edge of the beach. ",
               ({ "impressions","impression" }) :
		  "These impressions were created by the powerful surf and "
                  "look simply like odd shaped holes, filled with water "
                  "and heavy sand. ",
           ]) );
   SetItemAdjectives( ([
                         "cliff" : ({ "craggy","sea" }),
                         "part" : ({ "small" }),
                         "strands" : ({ "long","slimy" }),
                         "slices" : ({ "sharp" }),
                         "shells" : ({ "sea","sharp" }),
                         "rocks" : ({ "large","standing" }),
                         "shadows" : ({ "odd" }),
                         "pieces" : ({ "thick","pulpy" }),
                         "impressions" : ({ "deep" }),
                    ]) );
   SetListen( ([
                 "default" : "The roaring of the waves drowns out any "
                	     "other sounds. ",
            ]) );
   SetSmell( ([
                "default" : "The sting of sea salts assaults the nose. ",
           ]) );
   SetExits( ([
                "north" : AVERATH_ISLAND + "10,-3,0",
                "south" : AVERATH_ISLAND + "10,-5,0",
                "east"  : INNERSEA_VIRTUAL "ocean/11,-109",
           ]) );
   SetProperty("coastal", 1);
}

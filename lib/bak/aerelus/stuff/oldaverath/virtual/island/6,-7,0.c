	
#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

static void create()  {
     room::create();
     SetClimate("temperate");
  SetProperty("coastal", 1);
     SetShort("a rocky beach");
     SetDayLong("The beach is covered in sharp, "
        "black stones of all different sizes and shapes. "
        "Large boulders shelter a tidepool deeper than a "
        "human and as wide as a tree. A few "
        "scraggly oaks brush the water's edge. To the "
        "north, the trees look much denser and on the "
        "cliffs to the northeast, they look like a "
        "veritable forest. On clear days, the sunlight "
        "glints off the dark gray water.");
     SetNightLong("The sharp, black stones of the " 
        "beach look like shattered bones of various "
        "shapes and sizes in the dark. The large "
        "boulders look like sleeping bears guarding "
        "the tidepool that shimmers when the "
        "moonlight hits it. The monsters heading "
        "for the water's edge are a few scraggly oaks. "
        "The demon army on the cliffs and to the " 
        "north is merely the forest. On clear nights, "
        "the moonlight plays off the water like ghostly "
        "orbs floating on the surface of the sea.");
     SetItems( ([
          ({"beach"  }) : (:GetLong:),
          ({ "stone","stones"}) :
                 "The sharp, black stones could easily "
                 "cut someone's bare foot.",
         ({ "boulder", "boulders", "bear", "bears"}):
                 "The large, rounded boulders protect a "
                 "huge tidepool. ",
         ({"tidepool"}) : 
               "The tidepool is huge, big enough to trap "
               "a large animal or fish.",
         ({"oak", "oaks", "tree", "trees", "forest", "cliff", 
             "cliffs"}) : 
               "A few oaks have managed to grow by the "
               "water's edge, but the salt air has forced "
               "them to be gnarled, stunted, and scraggly. "
               "The forest appears to be healthier and it "
               "holds more types of trees." ,
        ({"edge", "water"}) :
               "The dark gray water laps up against the "
               "the stony beach.",
        ({"sunlight"}) : 
              "On sunny days, the sunlight "
              "dazzles the eye as it reflects off the water. ",
        ({"moonlight", "orb", "orbs"}) : 
               "On clear nights, the moonlight "
               "creates ghostly images on the "
              "surface of the water. ",
         ({"bone", "bones"}) : 
              "What looks like bones at night reveals "
              "itself to be merely stones. ",
        ({"monster", "monsters"}) : 
              "An overactive imagination can easily "
              "turn a few scraggly oaks into monsters. ",             
        ({"demon", "army"}) : 
              "Fear and the imagination has turned "
              "a simple forest into a demonic army. "
           ]) );
    SetItemAdjectives( ([
                    "beach" : ({"stony", "rocky"}),
                    "stone" : ({"sharp", "black", "various"}),
                    "boulder" : ({"large", "rounded"}),
                    "bear" : ({"sleeping"}),
                    "oak" : 
                          ({"scraggly", "stunted", "gnarled"}),
                    "forest" : ({"dense", "healthy"}),
                    "edge" : ({"water's"}),
                     "water" : ({"dark", "gray"}),
                     "moonlight" : ({"ghostly"}),
                     "orb" : ({"ghostly"}), 
                     "bone" : ({"shattered"}),
                     "army" : ({"demon"})
                     ]) );
    SetSmell( ([
                "default" : "The distinctive scent of "         
                   "saltwater permeates the air. "
                       ]) );
    SetListen( ([
                "default" :  "The air reverberates with the "
                    "sound of crashing waves. "
             ]) );
    SetExits( ([
            "east" : AVERATH_ISLAND + "7,-7,0",
            "north" : AVERATH_ISLAND + "6,-6,0"
            ,
            "south" : INNERSEA_VIRTUAL "ocean/6,-113",
            "west"  : INNERSEA_VIRTUAL "ocean/5,-112",
                   ]) );
}
    

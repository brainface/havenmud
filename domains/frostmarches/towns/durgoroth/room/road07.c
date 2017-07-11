
#include <lib.h>
#include "../durgoroth.h"


inherit LIB_ROOM;

int BankEnter(string);

static void create() {
  ::create();
  SetClimate("sub-arctic"); SetShort("the eastern end of Durgoroth");
  SetLong("The building to the north looks as though"
          " it made it through the destruction of the"
          " nearly unscathed. A small hole near the door"
          " is the only indication that it was even in"
          " the same city as the rest of the ruins"
          " surrounding it. To the east a clearing"
          " has been dug out of the rubble. Off to the"
          " west a large pile of rubble can be seen which"
          " almost mirrors the remains of the library"
          " to the south.");
  SetItems( ([
          ({ "building", "north building", "bank" }) :
             "The building to the north looks relatively"
             " sound, given it's location. A small hole"
             " near the doorway is the only scar it bears"
             " from the destruction of the city. It"
             " looks as though it is inhabited by a"
             " bank.",
          ({ "library", "remains", "horizon", "towers" }) :
             "The remains of the various buildings such"
             " as the library and towers mar the horizon"
             " with their asymmetrical shapes, providing"
             " a bleak and chaotic appearance to this"
             " desolate ruin.",
          ({ "buildings", "ruins" }) :
             "The buildings here all lie in ruin after what"
             " must have been a mighty struggle. They appear"
             " to have been blasted apart from the insides"
             " scattering masonry wood and metal all around.",
          ({ "wood", "masonry", "metal", "debris", "litter" }) :
             "The debris that litters the ground is of varying"
             " shapes, sizes, and materials. It covers"
             " everything making it difficult to navigate"
             " through the ruins.",
          ({ "square", "town square", "fountain" }) :
             "To the west the town square and fountain can"
             " be seen.",
          ]) );
  SetSmell( ([ 
          "default" : "All throughout this area the smell"
          " of dried blood permeates.", 
          ]) );
  SetListen( ([ 
          "default" : "The distant rustling of survivors"
          " picking through the ruins can be heard", 
          ]) );
  SetInventory( ([
          DURG_NPC "toughcitizen2" : 2,
          ]) );
  SetEnters( ([
          "bank" : DURG_ROOM "bank", 
           ]) );
  SetExits( ([
          "west" : DURG_ROOM "road06",
          "east" : DURG_ROOM "road08",
          ]) );
}
 

int BankEnter(string dir) {
  if(this_player()->GetReligion() != "Saahagoth") {
   message("system", "%^CYAN%^A small waft of air calms you as you"
                     " enter the bank.%^RESET%^", this_player());
   return 1;
   }
   message("system", "%^RED%^%^BOLD%^Your savage rage is quelled"
                     " as you enter the bank.%^RESET%^", this_player());
   return 1;
}





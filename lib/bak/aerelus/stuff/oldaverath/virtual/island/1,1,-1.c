#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

varargs static void create(int x, int y, int z) {
  ::create(1,1,-1);
  SetClimate("underground");
  SetAmbientLight(10);
  SetShort("Inside a dark tunnel");
  SetLong("The stones underfoot are wet, dank, and slimy. The only light in "
          "the area comes from the entrance above, that leads through the "
          "fireplace far above into the Duke's keep. The exit into the keep "
          "can be reached by a narrow set of slippery stone steps, covered in "
          "a vile green fungus. The walls of the tunnel are curved upwards "
          "into darkness, above even the fireplace exit. Further down the "
          "tunnel, burning torches can be seen, barely managing to light "
          "their dark surroundings.");
  SetItems(
  ([
    ({ "exit", "fireplace" }) : "A meager light shines bleakly through exit "
       "from the sewers. The fireplace has been carved right out of the "
       "tunnel rock. Steps can be seen leading up to the exit.",
    ({ "steps", "stone steps" }) : "These slippery stone steps lead up to the "
       "exit above.",
    ({ "tunnel" }) : "The dark tunnel is shrowded in shadow. Off in the "
       "distance, faint torch light can be seen. However, the torches are "
       "few and far between.",
    ({ "fungus" }) : "The fungus is vile, green, and slippery.",
    ({ "torches" }) : "The distant torches are little more than flickering "
       "pinpricks of light.",
  ]) );
  SetEnters( (["fireplace" : AVERATH_CITY "keep5" ]) );
  RemoveExit("north");
  RemoveExit("east");
  RemoveExit("west");
  SetInventory( ([AVERATH_NPC + "prat" : 1 ]) );
}

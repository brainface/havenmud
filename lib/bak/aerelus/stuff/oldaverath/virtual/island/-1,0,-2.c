#include <lib.h>
#include <domains.h>

inherit AVERATH_LIB;

static void create() {
  ::create(-1,0,-2);

  SetLong("Small torches stretch the tunnel walls, giving just enough "
     "flickering light to see on to the passages to the north and east. "
     "The curved walls of the tunnel are wet and slimy from the waste "
     "that flows through here, indicating that the tunnel is a part of "
     "a sewer system. There is a large crack running down the stones on "
     "the southern part of the tunnel.");
  SetItems( ([
     ({"torch","torches"}) : "These small wooden torches hang from the "
       "walls randomly, and give off enough light for a dim veiw of the "
       "passages ahead.",
     ({"crack"}) : "This large crack runs almost the entire length of "
       "the tunnel wall and looks like a small opening has been dug "
       "along it at the bottom.",
     ({"wall","walls"}) : "The walls of the tunnel are made from a dark "
       "heavy stone, and they curve towards the center. They are as "
       "filthy as the floor, covered in muck and slime from the sewers. "
       "A large crack runs down the southern wall.",
     ({"muck","waste","slime"}) : "This dark gooey muck covers the floor "
       "and walls and anything else it comes into contact with.",
     ]) );
  SetEnters( ([
     "crack" : AVERATH_GOBLIN "ghovel"
     ]) );
  SetInventory( ([
     AVERATH_NPC "sgoblin" : 1,
     ]) );
  RemoveExit("west");
  RemoveExit("south");
   SetAmbientLight(26);
}

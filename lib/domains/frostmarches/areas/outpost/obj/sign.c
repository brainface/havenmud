#include <lib.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sign");
  SetPreventGet("You cannot take that.");
  SetLong("This is a huge sign with the same message written in several"
          " languages on it.");
  SetShort("a huge sign on a post");
  SetId( ({ "sign" }) );
  SetAdjectives( ({ "huge" }) );
  SetRead("default", 
    "                        %^RED%^BOLD%^!!! WARNING !!!%^RESET%^\n\n\n"
    "%^CYAN%^All brave and stupid souls attempting to enter the Ruins of Durgoroth\n"
    "do so at their own free will. Should you perish within the unforgiving \n"
    "walls of this desolate place, it is your own doing and the administration\n"
    "of this outpost take no responsibility for your stupidity. The beasts\n"
    "within are of a vicious nature and are extremely powerful. Be warned.\n\n"
    "  The Light and the Glory of the Lord of Order be upon thee.\n"
    "\n\n"
    "                                            -The Administration      \n"
    "                                               Grand Master Atariel Banewulf\n"
    "                                               Lord Euan Tunnelbreaker\n"
    "                                               ArchDeacon Rurik\n"
    "                                               Hajji Jalal Tahmid Ayman"   
    "%^RESET%^");
  }

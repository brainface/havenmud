//coded by Syra 8/97
//modified by Ranquest 2/99
// rabbitmeat removed: file no longer exists

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("rabbit");
    SetId( ({"brown rabbit","rabbit" }) ); 
    SetShort("a brown rabbit");
    SetLong("This speckled brown rabbit freezes in fear as you \n"
            "look at it. The rabbit has bears no resemblence to \n"
            "the soft, furry pets: it has a mangy dull coat, and \n"
            "isn't grossly overfed." );
    SetRace("rodent");
    SetGender("male");
    SetClass("animal");
    SetLevel(3);
  }

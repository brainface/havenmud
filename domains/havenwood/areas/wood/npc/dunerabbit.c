//coded by Syra 8/97

#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetKeyName("rabbit");
    SetId( ({"rabbit" }) ); 
    SetAdjectives( ({"brown","speckled"}) );
    SetShort("a brown rabbit");
    SetLong("This speckled brown rabbit freezes in fear as it is \n"
            "looked at. This rabbit bears no resemblence to the \n"
            "soft, furry pets: It has a mangy dull coat, and \n"
            "isn't grossly overfed." );
    SetRace("rodent");
    SetClass("animal");
    SetGender("male");
    SetLevel(3);
    SetAction(6, ({
            "!hop",
            "!emote nibbles on the nearby foliage.",
    }) );
    SetCorpseItems( ([
      "/domains/havenwood/areas/wood/obj/rabbitmeat" : 1,
    ]) );
}

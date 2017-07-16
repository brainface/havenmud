// Amelia
#include <lib.h>
#include <domains.h>
inherit LIB_NPC;

static void create() {
   ::create();
   SetKeyName("raven");
   SetShort("an ugly one-footed raven");
   SetId( ({ "raven" }) );
   SetAdjectives( ({ "ugly","one-footed" }) );
   SetLong("Missing one leg, this raven's body is marked by "
           "bald patches between the night-black feathers.");
   SetGender("male");
   SetRace("bird");
   RemoveLimb("left leg",0);
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(3);
}

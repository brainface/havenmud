#include <lib.h>
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("widow");
   SetId( ({ "widow" }) );
   SetAdjectives( ({ "saddened" }) );
   SetShort("a saddened widow");
   SetLong("This woman looks sad and tired as she performs chores "
          "around the house. Her eyes droop with exhaustion, and her "
          "face is framed in a web-work of wrinkles. Despite her sadness, "
          "she looks quite strong. Perhaps living without her husband "
          "has taught her much.");
   SetLevel(10);
   SetMorality(15);
   SetGender("female");
   SetRace("elf");
   SetClass("fighter");
   SetCurrency("imperials",50);
   SetAction(5, ({ "The widow sighs sadly and continues her work." }) );
   SetFriends( ({ "child" }) );
}

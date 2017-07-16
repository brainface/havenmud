#include <lib.h>
inherit LIB_NPC;

static void create() {
    npc::create();
    SetKeyName("mage");
    SetShort("a human mage");
    SetLong("This mage is in the service of Lord Beornwulf.  He is "
            "hunched over a magical tome, trying to devise a plan to save "
          "the inhabitants of the keep.");
    SetId(({"mage", "human mage"}));
    SetMorality(75);
    SetRace("human");
    SetClass("evoker");
    SetSkill("shock magic",1,2);
    SetLevel(13);
    SetGender("male");
    SetSpellBook( ([
       "capsule" : 100,
       "missile" : 100,
       "shock"   : 100,
    		]) );
    SetInventory( ([
       "/std/weapon/pole/small_halberd.c"  : "wield halberd",
    	 ]) );
    SetCurrency("imperials", random(50)+10);
    SetCombatAction(20, ({
       "!say Go away and let me save the castle!",
       "!cast capsule",
       "!cast missile",
       "!cast shock",
    	 }) );
}

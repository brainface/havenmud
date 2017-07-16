#include <lib.h>
inherit LIB_NPC;
#include "../monastery.h"

static void create() {
   ::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Kaya");
   SetShort("Kaya, a joyous teacher of Eclat");
   SetId( ({ "kaya","teacher","teacher of eclat" }) );
   SetAdjectives( ({ "joyous" }) );
   SetLong("Kaya smiles brightly, shining with joy at the world.  She "
           "looks very smart, and seems prepared to talk about "
           "anything having to do with Eclat.");
   SetGender("female");
   SetReligion("Eclat","Eclatish");
   SetClass("cleric");
   SetClass("fighter");
   SetRace("muezzin");
   SetLevel(45);
//   AddTalkResponse("symbol","The Eclat faith has no symbols of any "
//                   "kind.");
//   AddTalkResponse(({ "death","killing","taking life","taking lives",
//                      "kill" }),"It is acceptable to take a life only "
//                      "if that life is detrimental to joy.  Preferably, "
//                      "that life will be warned first.");
//   AddTalkResponse(({ "sacrilege","taboo" }),"Nothing is 'taboo' in "
//                      "Eclat aside from taking away from the joy of "
//                      "the world.");
//   AddTalkResponse(({ "eclat" }),"There is not much to be told about the "
//                      "Eclat faith.  We have no symbol or set way of "
//                      "being, and so long as others are not detracting "
//                      "from joy, we bear them no grief.");
   SetMorality(700);
   SetInventory( ([
				M_OBJ + "robes" : "wear robes",
		]) );
}

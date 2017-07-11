
#include <lib.h>
inherit LIB_ITEM;
inherit LIB_SMELL;

static void create() {
     ::create();
   SetKeyName("stewpot");
   SetShort("a pot of muezzin stew");
   SetId( ({ "stewpot","pot","stew" }) );
   SetAdjectives( ({ "pot of","muezzin" }) );
   SetLong("The pot of stew is securely attached to the ground with iron supports "
		"that keep it perched above the fire.  The metal glows with heat.  "
		"Large chunks of meat cling to humanoid bones in the thick, "
		"bowling stew.");
   SetMass(5000);
   SetPreventGet("The stew pot is firmly attached to the ground with iron spikes!");
   SetSmell("The stew smells delicious.  The tasty aroma of well-done meat rises from "
            "the pot.");
}

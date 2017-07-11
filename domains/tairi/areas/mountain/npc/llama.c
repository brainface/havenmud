#include <lib.h>
inherit LIB_NPC;

static void create(){
    npc::create();
    SetShort("Dali's pet llama");
    SetLong(
      "Dali's Llama is his constant companion and has been his friend for "
      "many years. His long neck and brown fur make excellent hugging material "
      "for times when Dali has become lonely here on the mountain."
      );
    SetRace("horse", "llama");
    SetGender("male");
    SetClass("animal");
    SetLevel(500);
    SetKeyName("Dali's llama");
    SetId( ({ "llama" }) );
    SetAdjectives( ({ "dali's", "dali" }) );
    SetFriends( ({ "dali" }) );
    SetLimit(1);
}


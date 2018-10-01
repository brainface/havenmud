#include <lib.h>
#include "../path.h"

inherit LIB_NPC;

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass);


static void create()
{
  npc::create();
  SetKeyName("rabbit");
  SetId( ({"rabbit", "bunny"}) );
  SetAdjectives( ({"little", "cute", "bunny"}) );
  SetShort("a little rabbit");
  SetLong("The bunny twitches when you look too closely.");
  SetLevel(1);
  SetRace("rodent");
  SetClass("animal");
  if(random(3))
    SetGender("male");
  else
    SetGender("female");
  SetAction(7,({ 
    "The rabbit quietly nibbles a clover.",
    "The bunny freezes for a moment."
  }) );
      
  SetSkinVars("pelt",100,20,10);
}

varargs int eventDie(object target)
{
  object ob;
  ob=new(GWONISH+"obj/generic_skin");

  ob->SetKeyName(GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetDamagePoints(GetProperty("durability"));
  ob->SetShort("a "+GetKeyName()+" "+GetProperty("skin_type"));
  ob->SetLong("This is a "+
        GetProperty("skin_type")+" from a " +
        GetKeyName()+".");
  ob->SetID( ( {
    GetProperty("skin_type"),
    GetKeyName()+" "+GetProperty("skin_type")
      }) );
  ob->SetValue(GetProperty("skin_value"));
  ob->SetMass(GetProperty("skin_mass"));

  ob->eventMove(environment(this_object()));

  npc::eventDie(target);
}

void SetSkinVars(string skin_type,int durability,int skin_value,int skin_mass)
{
  SetProperty("skin_type",skin_type);
  SetProperty("durability",durability);
  SetProperty("skin_value",skin_value);
  SetProperty("skin_mass",skin_mass);
}
